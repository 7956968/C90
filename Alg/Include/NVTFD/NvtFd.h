#ifndef __NVTFD__H__
#define __NVTFD__H__

#include <Type.h>
//#include <Debug.h>
#include <Perf.h>
#include "FileSysTsk.h"

#include "ife_lib.h"
#include "ime_lib.h"
#include "grph.h"
#include "ise_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#include "clock.h"
//#include "Debug.h"
#include "dma.h"
#include "kernel.h"
#include "pll.h"
#include "sdio.h"
#include "top.h"
#include "Type.h"
#include "uart.h"
#include "Utility.h"
#include "fde_lib.h"
#include "GxImage.h"

#define __660_CODE__     DISABLE

#if __660_CODE__
#include "IPL_Hal_IME_Info.h"
#else
#include "ipl_hal_ime_info.h"
#endif

#define NVTFD_COMPILE_FD1_MODEL     DISABLE // fd version1
#define NVTFD_COMPILE_FD2_MODEL		ENABLE  // fd version2


//nvt face detection interfaces

/**
    Detect faces from HW candidiates.
    @param[in] imgBuf: gray image info.
    @param[in && out] pFace: HW candidates input and detected faces output
    @param[in] nFace: HW candidates number
    @param[in] pBuff: FD buff addr
    @return detected faces number
*/
extern UINT32 NvtFD_DetectFaces(IMG_BUF *imgBuf, FACE *pFace, UINT32 nFace, UINT32 pBuff);

/**
    Draw face boxes and save the image.
    @param[in] imgBuf: gray image info.
    @param[in] pFace: faces to draw
    @param[in] nFace: faces number
    @param[in] flag: flag for saving images(0 - HW, 1 - ARC, 2 - NVT)
    @return void
*/
extern void NvtFD_SaveResultImage(IMG_BUF *imgBuf, FACE *pFace, UINT32 nFace, UINT32 flag);

/**
    Get the working buffer(no chache buffer) that NvtFD_DetectFaceOrNot need.
    @return UINT32: the size of no cache buffer that NvtFD_DetectFaceOrNot need.
*/
extern UINT32 NvtFD_GetBuffSize(VOID);

/**
    Detect the faces region which in imgBuf are true faces
    @param[in] imgBuf: gray image info.
    @param[in] pFace: pointer os faces, the faces could be array.
    @param[in] nFace: faces regions number that need to be detected.
    @param[in] pBuff: the no cache buffer pointer which size could be calculate by NvtFD_GetBuffSize
    @return UINT32: the true faces number.
*/
extern UINT32 NvtFD_DetectFaceOrNot(const IMG_BUF *imgBuf, FACE *pFace, UINT32 nFace, UINT32 pBuff);


//nvt face detection interfaces(new)

typedef enum
{
    NVTFD_FLIP_NEVER = 0,
    NVTFD_FLIP_ROT30,
    NVTFD_FLIP_ROT330,
    NVTFD_FLIP_LR,
    ENUM_DUMMY4WORD(NVTFD_FLIP_TYPE)
}NVTFD_FLIP_TYPE;

typedef struct
{
    UINT32 flag;
    NVTFD_FLIP_TYPE flip;
    INT32 *table;
    UINT8 **pbuf;
}NVTFD_DETECTOR_PRMS;

typedef struct
{
    IMG_BUF *imgbuf;
    FACE *faces;
    UINT32 facenum;
    UINT32 merge;
    UINT8 *buf;
}NVTFD_PRMS;

typedef struct
{
    FACE *faces;
    UINT32 facenum;
    UINT32 mode;
}NVTFD_MERGE_PRMS;


/**
    Get the working buffer size that nvtfd need
    @return UINT32: the working buffer size that nvtfd need.
*/
UINT32 nvtfd_calcbuffsize(VOID);


/**
    Enroll the detector for nvtfd.
    @param[in] detectorprms: detector info structures.
    @return VOID.
*/
VOID nvtfd_enrolldetector(NVTFD_DETECTOR_PRMS *detectorprms);


/**
    Detect faces from FDE proposals.
    @param[in] prms: detection info structures.
    @return VOID.
*/
UINT32 nvtfd_process(NVTFD_PRMS *prms);


/**
    Merge detected faces.
    @param[in && out] faces: detected faces.
    @param[in] facenum: the number of detected face.
    @param[in] mode: flag of how to merge detected faces(0 - not merge, 1 - prefer larger uiScroe, other - prepfer larger face size).
    @return UINT32: the true faces number.
*/
UINT32 nvtfd_mergefaces(NVTFD_MERGE_PRMS *prms);

/**
    save image of detected faces.
	@param[in] imgbuf: detected image.
    @param[in] faces: detected faces.
    @param[in] facenum: the number of detected face.
    @param[in] buf: buff need for saving image(size : 1920 * 1920).
	@param[in] sel: flag of saving HW result or NVT result(0 - HW-FDE result, 1 - NVT-ADABOOST result).
    @return VOID.
*/
VOID nvtfd_saverslt(IMG_BUF *imgbuf, FACE *faces, UINT32 facenum, UINT8 *buf, UINT32 sel);

/**
	FD2 function
*/
typedef struct
{
    UINT16 x, y, w, h;
    UINT32 score;
	UINT8  trgId;
}nvt_fd2_face;

typedef struct
{
    IMG_BUF       *img_buf;       //in
    nvt_fd2_face  *face_buf;      //in & out
    UINT32         face_num;      //in & out
    UINT32		   max_face_num;  //in
    UINT32		   score_th;	  //in score th (default 5)
    UINT32         face_pose;     //in support face poses (default all)
}nvt_fd2_prms;

/**
     support fd2 pose type

*/
typedef enum
{
    FD_SUPPORT_FRONT        = 0x0001,           ///<  support front face detection
    FD_SUPPORT_YAW45_LEFT   = 0x0002,           ///<  support yaw45 left face detection
    FD_SUPPORT_YAW45_RIGHT  = 0x0004,           ///<  support yaw45 right face detection
    FD_SUPPORT_YAW90_LEFT   = 0x0008,           ///<  support yaw90 left face detection
    FD_SUPPORT_YAW90_RIGHT  = 0x0010,           ///<  support yaw90 right face detection
    FD_SUPPORT_PITCH20_DOWN = 0x0020,           ///<  support pitchdown face detection
    FD_SUPPORT_PITCH20_UP   = 0x0040,           ///<  support pitchup face detection
    FD_SUPPORT_ROLL30_LEFT  = 0x0080,           ///<  support roll30 left face detection
    FD_SUPPORT_ROLL30_RIGHT = 0x0100,           ///<  support roll30 right face detection
    FD_SUPPORT_ALL_POSE     = 0x01FF,           ///<  support all face detection
    ENUM_DUMMY4WORD(FD_SUPPORT_POSE)
} FD_SUPPORT_POSE;

/**
    calculate buff size need by FD2.
    @param VOID.
    @return UINT32: buff size.
*/
UINT32 nvt_fd2_calcbuffsize(void);
/**
    calculate cache buff size need by FD2.
    @param VOID.
    @return UINT32: cache buff size(now no need, the value is 0).
*/
UINT32 nvt_fd2_calccachebuffsize(void);
/**
    init buff size need by FD2.
    @param buf: the address for buff.
	@param cachebuf: the address for cachebuff(now no need, the value is NULL).
    @return VOID.
*/
void nvt_fd2_init(UINT32 buf, UINT32 cachebuf);
/**
    init buff size need by FD2.
    @param pparams: nvt_fd2_prms(img_buf[in]: the image buff, face_buf[out]: detected faces, face_num[out]: number of detected faces).
    @return VOID.
*/
void nvt_fd2_process(nvt_fd2_prms *pparams);


#endif

