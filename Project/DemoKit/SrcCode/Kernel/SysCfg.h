/**
    Copyright   Novatek Microelectronics Corp. 2009.  All rights reserved.

    @file       SysCfg.h
    @ingroup

    @brief      Header file of SysCfg.c
                Config the task, event, semaphore, memory pool, memory layout, mailbox

    @note       Nothing.
*/

#ifndef _SYSCFG_H
#define _SYSCFG_H

#include "Type.h"
#include "SysKer.h"
#include "PrjCfg.h"

//===========================================================================

typedef enum _SX_MODE {
	SX_MODE_CPU1,
	SX_MODE_CPU2,
	SX_MODE_DSP1,
	SX_MODE_DSP2,
	SX_MODE_EXAM,
	ENUM_DUMMY4WORD(SX_MODE)
} SX_MODE;

//===========================================================================

typedef enum {
	CODE_SECTION_01 = 0,
	CODE_SECTION_02,
	CODE_SECTION_03,
	CODE_SECTION_04,
	CODE_SECTION_05,
	CODE_SECTION_06,
	CODE_SECTION_07,
	CODE_SECTION_08,
	CODE_SECTION_09,
	CODE_SECTION_10,
	CODE_SECTION_11,
	CODE_SECTION_12,
	CODE_SECTION_13,
	CODE_SECTION_14,
	CODE_SECTION_15,
	CODE_SECTION_16,
	ENUM_DUMMY4WORD(_CODE_SECTION_)
}
CODE_SECTION;

//===========================================================================

// Total number of kernel ID sources
#define MAX_TASK_COUNT              128 // 64
#ifdef __ECOS
#define MAX_FLAG_COUNT              192
#else
#define MAX_FLAG_COUNT              192
#endif
#define MAX_SEMAPHORE_COUNT         320
#define MAX_MAILBOX_COUNT           32
#define MAX_MEMPOOL_COUNT           32      //Arbit 1 memory pool cnt
#define BUF_NUM                     300

#ifdef __ECOS
//uitron resources should be limited by ecos resources!
STATIC_ASSERT(MAX_TASK_COUNT <= CYGNUM_UITRON_TASKS);
STATIC_ASSERT(MAX_SEMAPHORE_COUNT <= CYGNUM_UITRON_SEMAS);
STATIC_ASSERT(MAX_FLAG_COUNT <= CYGNUM_UITRON_FLAGS);
STATIC_ASSERT(MAX_MAILBOX_COUNT <= CYGNUM_UITRON_MBOXES);
STATIC_ASSERT(MAX_MEMPOOL_COUNT <= CYGNUM_UITRON_MEMPOOLFIXED);
#endif

//===========================================================================
extern void Install_Drv(void);

//===========================================================================
#define VDO_W   DISPLAY_VDO_W
#define VDO_H   DISPLAY_VDO_H
#define OSD_W   DISPLAY_OSD_W
#define OSD_H   DISPLAY_OSD_H

#define FB_W    VDO_W
#define FB_H    VDO_H
#define WIN_W   OSD_W
#define WIN_H   OSD_H

#define FHD_W   1920  //Full-HD buffer width: for H264 decoder, it must align to 16
#define FHD_H   1088  //Full-HD buffer height: for H264 decoder, it must align to 16

//===========================================================================
// User defined Task IDs
//===========================================================================

//===========================================================================
// User defined Semaphore IDs
//===========================================================================

//===========================================================================
//  User defined Mailbox IDs
//===========================================================================
extern UINT32 MBXID_SYS_EVENT;

//===========================================================================
//  User defined Mempool IDs
//===========================================================================
extern UINT32 POOL_ID_STORAGE_SDIO;
#if(COPYCARD2CARD_FUNCTION == ENABLE)
extern UINT32 POOL_ID_STORAGE_SDIO2;
#endif
extern UINT32 POOL_ID_STORAGE_NAND;
extern UINT32 POOL_ID_STORAGE_RAMDISK;
#if (FWS_FUNC == ENABLE)
extern UINT32 POOL_ID_FWS_BUFFER;
#endif
extern UINT32 POOL_ID_FS_BUFFER;
extern UINT32 POOL_ID_FSIPC;
#if (USE_DCF == ENABLE)
extern UINT32 POOL_ID_DCF_BUFFER;
#endif
#if (PST_FUNC == ENABLE)
extern UINT32 POOL_ID_PS_BUFFER;
#endif

extern UINT32 POOL_ID_WAV_PLAY_HEADER;
extern UINT32 POOL_ID_WAV_PLAY_DATA;
extern UINT32 POOL_ID_USER_PARTITION_RW_BUFFER;

#if (WIFI_FUNC == ENABLE)
extern UINT32 POOL_ID_WIFIIPC;
#endif
extern UINT32 POOL_ID_USOCKIPC;
extern UINT32 POOL_ID_DHCPIPC;
extern UINT32 POOL_ID_TEMP;
#if(FACE_GRADE_TEST==ENABLE)
extern UINT32 POOL_ID_FACEGIPC;
#endif
extern UINT32 POOL_ID_GFX_IMAGE;
extern UINT32 POOL_ID_GFX_STRING;
extern UINT32 POOL_ID_GFX_TEMP;
extern UINT32 POOL_ID_EXIF;
extern UINT32 POOL_ID_DATEIMPRINT;
#if (USE_FILEDB==ENABLE)
extern UINT32 POOL_ID_FILEDB;
#endif
extern UINT32 POOL_ID_DISP_OSD2;
extern UINT32 POOL_ID_DISP_OSD2TEMP;
extern UINT32 POOL_ID_DISP_OSD1;
extern UINT32 POOL_ID_DISP_OSD1TEMP;
extern UINT32 POOL_ID_DISP_VDO2;
extern UINT32 POOL_ID_DISP_VDO2TEMP;
extern UINT32 POOL_ID_DISP_VDO1;
extern UINT32 POOL_ID_DISP_VDO1TEMP;
//extern UINT32 POOL_ID_DISP_VDO1TEMP2;
//extern UINT32 POOL_ID_DISP_VDO1TEMP3;
extern UINT32 POOL_ID_APP;
extern UINT32 POOL_ID_APP_ARBIT2;
extern UINT32 POOL_ID_CPU2; //multi-core reserved
extern UINT32 POOL_ID_DSP; //multi-core reserved
#if (HFS_FUNC == ENABLE)
extern UINT32 POOL_ID_HFSIPC;
#endif
#if(YOUKU_SDK == ENABLE)
extern UINT32 POOL_ID_YOUKUIPC;
#endif
//#NT#2016/05/31#Ben Wang -begin
//#NT#Add UVC multimedia function.
#if(UVC_MULTIMEDIA_FUNC == ENABLE)
extern UINT32 POOL_ID_USBCMD;
#endif
//#NT#2016/05/31#Ben Wang -end
#if (IOT_P2P_FUNC == ENABLE)
extern UINT32 POOL_ID_P2PIPC;
#endif
extern UINT32 POOL_ID_NVTIPC;
extern UINT32 POOL_ID_NVTUCTRL;
extern UINT32 POOL_ID_CAL;
//#NT#2016/04/21#Lincy Lin -begin
//#NT#Support curl (http client)
#if (CURL_FUNC == ENABLE)
extern UINT32 POOL_ID_CURLNVT;
#endif
//#NT#2016/04/21#Lincy Lin -end

#if (UCTRL_FUNC==ENABLE)
extern UINT32 POOL_ID_UCTRL_NVT_STATUS;
#endif

//#NT#2016/07/27#Charlie Chang -begin
//#NT# support iqtool ipc
#if(IQTOOL_FUNC == ENABLE)
extern UINT32 POOL_ID_IQTOOLIPC;
#endif
//#NT#2016/07/27#Charlie Chang -end

//#NT#2016/11/11#Charlie Chang -begin
//#NT# support save face tracking snapshot
#if (FTG_SNAPSHOT_FUN == ENABLE)
extern UINT32 POOL_ID_FTG_SNAPSHOT;
#endif
//#NT#2016/11/11#Charlie Chang -end


//#NT#2016/08/19#Lincy Lin -begin
//#NT#Support linux cvhost function
#if (LINUX_CVHOST_FUNC == ENABLE)
extern UINT32 POOL_ID_CVHOST;
#endif
//#NT#2016/08/19#Lincy Lin -end

#if (MSDCVENDOR_NVT == ENABLE)
extern UINT32 POOL_ID_MSDCNVT;
#endif

#if (MSDCVENDOR_NVT_EXAM == ENABLE)
extern UINT32 POOL_ID_MSDCNVT_EXAM;
#endif

#if (LINUX_MSDC == ENABLE)
extern UINT32 POOL_ID_USBIPC;
#endif

#if (VIDEOSPRITEIPC != ENABLE)
extern UINT32 POOL_ID_VDS_BK;
#endif

#if (LOGFILE_FUNC==ENABLE)
extern UINT32 POOL_ID_LOGFILE;
#endif

#if defined(_ASR_ENABLE_)
extern UINT32 POOL_ID_ASR;
#endif

#if (defined(_NVT_ETHREARCAM_RX_))
extern UINT32 POOL_ID_ETHSOCKCLI_IPC;
extern UINT32 POOL_ID_ETHUDPSOCK_IPC;
#endif
#if (defined(_NVT_ETHREARCAM_TX_))
extern UINT32 POOL_ID_ETHSOCK_IPC;
#endif


#define POOL_CNT_STORAGE_NAND   1
#define POOL_CNT_STORAGE_RAMDISK 1
#define POOL_CNT_STORAGE_SDIO   1
#if (FWS_FUNC == ENABLE)
#define POOL_CNT_FWS_BUFFER     1
#endif
#if FS_MULTI_STRG_FUNC
//#NT#2016/12/09#Niven Cho -begin
//#NT#LINUX-EMMC-MULTI-STRG
#if defined(_CPU2_LINUX_) && defined(_EMBMEM_EMMC_)
#define POOL_CNT_FS_BUFFER      3 // 3rd is for linux-pstore mounted by filesys
#else
#define POOL_CNT_FS_BUFFER      2
#endif
//#NT#2016/12/09#Niven Cho -end
#if (USE_DCF == ENABLE)
#define POOL_CNT_DCF_BUFFER     2
#endif
#else
#define POOL_CNT_FS_BUFFER      1
#if (USE_DCF == ENABLE)
#define POOL_CNT_DCF_BUFFER     1
#endif
#endif
#define POOL_CNT_FSIPC          1
#if (PST_FUNC == ENABLE)
#define POOL_CNT_PS_BUFFER      1
#endif
#if (WIFI_FUNC == ENABLE)
#define POOL_CNT_WIFIIPC        1
#endif
#if 0//(USOCKET_CLIENT==ENABLE)
#define POOL_CNT_USOCKIPC       2
#else
#define POOL_CNT_USOCKIPC       1
#endif
#define POOL_CNT_DHCPIPC        1
#define POOL_CNT_TEMP           1
#define POOL_CNT_FTYPEIPC       1
#if(FACE_GRADE_TEST==ENABLE)
#define POOL_CNT_FACEGIPC       1
#endif
#define POOL_CNT_GFX_IMAGE      1
#define POOL_CNT_GFX_STRING     1
#define POOL_CNT_GFX_TEMP       1
#define POOL_CNT_EXIF           SENSOR_CAPS_COUNT
#define POOL_CNT_DATEIMPRINT    1
#if (USE_FILEDB==ENABLE)
#define POOL_CNT_FILEDB         1
#endif
#define POOL_CNT_PCC            1
#define POOL_CNT_AUD_AOUT       1
#define POOL_CNT_AUD_IPC        1
#define POOL_CNT_DISP_OSD2      1
#define POOL_CNT_DISP_OSD2TEMP  1
#define POOL_CNT_DISP_OSD1      1
#define POOL_CNT_DISP_OSD1TEMP  1
#define POOL_CNT_DISP_VDO2      1
#if (VDO_USE_ROTATE_BUFFER == ENABLE)
#define POOL_CNT_DISP_VDO2TEMP  2    //for QV rotate ping-pong buffer
#else
#define POOL_CNT_DISP_VDO2TEMP  1
#endif
#define POOL_CNT_DISP_VDO1      1
#define POOL_CNT_DISP_VDO1TEMP  1
#define POOL_CNT_DISP_VDO1TEMP3 2
#define POOL_CNT_APP            1
#define POOL_CNT_ARBIT2_APP     1
#define POOL_CNT_CPU2           1
#define POOL_CNT_DSP            1
#if (HFS_FUNC == ENABLE)
#define POOL_CNT_HFSIPC         1
#endif
#if(YOUKU_SDK == ENABLE)
#define POOL_CNT_YOUKUIPC       1
#endif
//#NT#2016/05/31#Ben Wang -begin
//#NT#Add UVC multimedia function.
#if(UVC_MULTIMEDIA_FUNC == ENABLE)
#define POOL_CNT_USBCMD         1
#endif
//#NT#2016/05/31#Ben Wang -end
#if (IOT_P2P_FUNC == ENABLE)
#define POOL_CNT_P2PIPC         1
#endif
#define POOL_CNT_NVTIPC         1
#define POOL_CNT_NVTUCTRL       1
#define POOL_CNT_CAL            1
//#NT#2016/04/21#Lincy Lin -begin
//#NT#Support curl (http client)
#if (CURL_FUNC == ENABLE)
#define POOL_CNT_CURLNVT        1
#endif
//#NT#2016/04/21#Lincy Lin -end
//#NT#Add memory pool for IPCAM snapshot using
#if (IPCAM_FUNC == ENABLE)
#define POOL_CNT_IPCAM_SNAPSHOT 1
#endif
//#NT#2016/06/28#Lincy Lin -end

//#NT#2016/07/27#Charlie Chang -begin
//#NT# support iqtoolipc
#define POOL_CNT_IQTOOLIPC    1
//#NT#2016/07/27#Charlie Chang -end

//#NT#2016/11/11#Charlie Chang -begin
//#NT# support save face tracking snapshot
#if (FTG_SNAPSHOT_FUN == ENABLE)
#define POOL_CNT_FTG_SNAPSHOT    1

#endif
//#NT#2016/11/11#Charlie Chang -end


//#NT#2016/08/19#Lincy Lin -begin
//#NT#Support linux cvhost function
#if (LINUX_CVHOST_FUNC == ENABLE)
#define POOL_CNT_CVHOST       1
#endif
//#NT#2016/08/19#Lincy Lin -end

#if (UCTRL_FUNC==ENABLE)
#define POOL_CNT_UCTRL_NVT_STATUS 1
#endif

#if (MSDCVENDOR_NVT == ENABLE)
#define POOL_CNT_MSDCNVT 1
#endif

#if (MSDCVENDOR_NVT == ENABLE)
#define POOL_CNT_MSDCNVT_EXAM 1
#endif

#if (LINUX_MSDC == ENABLE)
#define POOL_CNT_USBIPC 1
#endif

#if (VIDEOSPRITEIPC != ENABLE)
#define POOL_CNT_VDS_BK 1
#endif

#if (LOGFILE_FUNC == ENABLE)
#define POOL_CNT_LOGFILE 1
#endif

#define POOL_CNT_WAV_PLAY_HEADER	1
#define POOL_CNT_WAV_PLAY_DATA		1
#define POOL_CNT_USER_PARTITION_RW_BUFFER 1

#if defined(_ASR_ENABLE_)
#define POOL_CNT_ASR     1
#endif

#if (defined(_NVT_ETHREARCAM_RX_))
#define POOL_CNT_ETHSOCKCLI_IPC       4*ETH_REARCAM_CAPS_COUNT
#define POOL_CNT_ETHUDPSOCK_IPC       2
#endif
#if (defined(_NVT_ETHREARCAM_TX_))
#define POOL_CNT_ETHSOCK_IPC       4
#endif

#define POOL_SIZE_STORAGE_NAND  ALIGN_CEIL_64((_EMBMEM_BLK_SIZE_+(_EMBMEM_BLK_SIZE_>>2)))
#define POOL_SIZE_STORAGE_RAMDISK  ALIGN_CEIL_64(0x20000)
#define POOL_SIZE_STORAGE_SDIO  ALIGN_CEIL_64(512)

#if (FWS_FUNC == ENABLE)
/**
     POOL_SIZE_FWS_BUFFER

     For Partial Loading, In two case:
     1. un-compressed bin: set POOL_SIZE_FWS_BUFFER to 1 sector size (use STRG_GET_SECTOR_SIZE to get size)
     2. compressed bin: better to set it to (binsize + 2*sector_size)

*/
#define POOL_SIZE_FWS_BUFFER    ALIGN_CEIL_64(_EMBMEM_BLK_SIZE_)// 1 sector(block) size (for 2K Page)
#endif

//#NT#2016/06/27#Lincy Lin -begin
//#NT#Reduce IPCAM used memory pool size
//#NT#2016/12/09#Niven Cho -begin
//#NT#LINUX-EMMC-MULTI-STRG
#if defined(_CPU2_LINUX_)
#define POOL_SIZE_FS_BUFFER     16*1024
#else
#define POOL_SIZE_FS_BUFFER     (ALIGN_CEIL_64(0xEC000)+ALIGN_CEIL_64(0x80020))
								// R/W buf = 0xEC000 (FileSysInfo=32k, OpenFile=2K*N, BitMap=512k, Sectbuf1=128K, SectBuf2=128k, ScanBuf=128k, ResvBuf=8k, Total 944k = 0xEC000)
								// FAT buf = 0x80020 (FatBuff=512k + 32bytes reserved = 0x80020)
#endif
//#NT#2016/12/09#Niven Cho -end
//#NT#2016/06/27#Lincy Lin -end
#if defined(_CPU2_ECOS_)
#define POOL_SIZE_FSIPC         ALIGN_CEIL_64(2*1024)
#else
#define POOL_SIZE_FSIPC         ALIGN_CEIL_64(0)
#endif
#if (USE_DCF == ENABLE)
#define POOL_SIZE_DCF_BUFFER    ALIGN_CEIL_64(70*1024)
#endif
#if (PST_FUNC == ENABLE)
#define POOL_SIZE_PS_BUFFER     (ALIGN_CEIL_64(0x20000)+ALIGN_CEIL_64(0x20000))
#endif                                                                // 128K bytes = 1 block size + work
#if (WIFI_FUNC == ENABLE)
#define POOL_SIZE_WIFIIPC       ALIGN_CEIL_64(12*1024)
#endif
#define POOL_SIZE_USOCKIPC      ALIGN_CEIL_64(4112)
#define POOL_SIZE_DHCPIPC       ALIGN_CEIL_64(0x1580)
//#define POOL_SIZE_TEMP          ALIGN_CEIL_64(0x40100)
#define POOL_SIZE_TEMP          ALIGN_CEIL_64(0x40100)

#if (defined(_NVT_ETHREARCAM_RX_))
//#define POOL_SIZE_ETHSOCKCLI_IPC      ALIGN_CEIL_64((2*1024 + 8))//2K
//#define POOL_SIZE_ETHSOCKCLI_IPC      ALIGN_CEIL_64((4*1024 + 8))//4K
#define POOL_SIZE_ETHSOCKCLI_IPC      ALIGN_CEIL_64((48*1024 + 8))//24K
#define POOL_SIZE_ETHUDPSOCK_IPC      ALIGN_CEIL_64((2*1024 + 8))//24K
#endif
#if (defined(_NVT_ETHREARCAM_TX_))
#define POOL_SIZE_ETHSOCK_IPC      ALIGN_CEIL_64((2*1024 +8))
#endif

//#NT#2016/08/08#Lincy Lin -begin
//#NT#Reduce gxgfx buffer
#if (GXGFX_ADVANCED_STRING_FUNC)
#define POOL_SIZE_GFX_TEMP      ALIGN_CEIL_64((VDO_W*VDO_H*2)+(0x1000)) //at least 4k for Gxlib
#else
#define POOL_SIZE_GFX_TEMP      ALIGN_CEIL_64(4096) //at least 4k for Gxlib
#endif
//#NT#2016/08/08#Lincy Lin -end


#if(FACE_GRADE_TEST==ENABLE)
#define POOL_SIZE_FACEGIPC      ALIGN_CEIL_64( 42000000 + 2048 * 1024)
#endif

#if (_LANG_STORE_ == _PSTORE_)
#define POOL_SIZE_GFX_STRING    ALIGN_CEIL_64(0x8000)
#else
#define POOL_SIZE_GFX_STRING    ALIGN_CEIL_64(0x20)                // Min Memory Pool size is 32 Bytes
#endif

#if (_JPG_STORE_ == _PSTORE_)
#define POOL_SIZE_GFX_IMAGE     ALIGN_CEIL_64(0x20000)
#else
#define POOL_SIZE_GFX_IMAGE     ALIGN_CEIL_64(0x00000020)
#endif

#define POOL_SIZE_EXIF          ALIGN_CEIL_64(0x10000)

//#NT#2016/07/22#YongChang Qui -begin
//#NT#MovieStamp uses unified memory as IPC & MovieStamp buffer for IPCam with AE_LOG off
#if (THUMB_STAMP_FUNC == ENABLE)
//#define POOL_SIZE_DATEIMPRINT   ALIGN_CEIL_64(0x200000 + 0x57800) // 350 KB for thumbnail stamp
#define POOL_SIZE_DATEIMPRINT_THUMB   ALIGN_CEIL_64(0x4B00) //THUMB_STAMP_WIDTH_MAX*20*3/2=640*20*3/2;//font height=20, YUV420
#else
//#define POOL_SIZE_DATEIMPRINT   ALIGN_CEIL_64(0x200000)
#define POOL_SIZE_DATEIMPRINT_THUMB   0
#endif
#define POOL_SIZE_DATEIMPRINT   ALIGN_CEIL_64(0x200000)
#define POOL_SIZE_DATEIMPRINT_TOTAL    ALIGN_CEIL_64(POOL_SIZE_DATEIMPRINT+POOL_SIZE_DATEIMPRINT_THUMB)

//#NT#2016/07/22#YongChang Qui -end

#if (USE_FILEDB==ENABLE)
#define POOL_SIZE_FILEDB        ALIGN_CEIL_64(0x138000)//0x150000)
#else
#define POOL_SIZE_FILEDB        ALIGN_CEIL_64(0x20)
#endif

#define POOL_SIZE_CPU2          ALIGN_CEIL_64(0) //set it 0 to disable

#define POOL_SIZE_DSP           ALIGN_CEIL_64(0) //set it 0 to disable

#if (HFS_FUNC == ENABLE)
#define POOL_SIZE_HFSIPC        ALIGN_CEIL_64(70*1024)
#else
#define POOL_SIZE_HFSIPC        ALIGN_CEIL_64(0)
#endif

#if (YOUKU_SDK == ENABLE)
#define POOL_SIZE_YOUKUIPC      ALIGN_CEIL_64(512)
#endif
//#NT#2016/05/31#Ben Wang -begin
//#NT#Add UVC multimedia function.
#if(UVC_MULTIMEDIA_FUNC == ENABLE)
#define POOL_SIZE_USBCMD        ALIGN_CEIL_64(64*1024)
#endif
//#NT#2016/05/31#Ben Wang -end
#if (IOT_P2P_FUNC == ENABLE)
//#NT#2016/06/03#Charlie Chang -begin
//#NT#redefine p2pipc size from 1024 to 2048
#define POOL_SIZE_P2PIPC        ALIGN_CEIL_64(2048)
//#NT#2016/06/03#Charlie Chang -end
#endif

#define POOL_SIZE_NVTIPC        ALIGN_CEIL_64(8192)

#if (CALIBRATION_FUNC == ENABLE)

//#NT#2016/07/20#XL_Wei -begin
//#NT#IPCAM(TP_LINK) Calbiration Memory control
#if (IPCAM_FUNC == ENABLE)
#define POOL_SIZE_CAL           ALIGN_CEIL_64(0) ///< here size needs to ask IQ how many should be used
#else
#define POOL_SIZE_CAL           ALIGN_CEIL_64(0x530000) ///< here size needs to ask IQ how many should be used
#endif
//#NT#2016/07/20#XL_Wei -end

#else
#define POOL_SIZE_CAL           ALIGN_CEIL_64(0) ///< here size needs to ask IQ how many should be used
#endif
//#NT#2016/04/21#Lincy Lin -begin
//#NT#Support curl (http client)
#if (CURL_FUNC == ENABLE)
#define POOL_SIZE_CURLNVT       ALIGN_CEIL_64((1024+16384)*4) ///<
#endif
//#NT#2016/04/21#Lincy Lin -end

//#NT#2016/08/31#Lincy Lin -end
//#NT#Adjust IPCAM snapshot mempool size by max image w & h
#if (IPCAM_FUNC == ENABLE)
#define POOL_SIZE_IPCAM_SNAPSHOT    ALIGN_CEIL_64(CROP_SOURCE_W*CROP_SOURCE_H/100*12)
#endif
//#NT#2016/08/31#Lincy Lin -end

//#NT#2016/07/27#Charlie Chang -begin
//#NT# support IQTOOL IPC
#define POOL_SIZE_IQTOOL_IPC  ALIGN_CEIL_64(55*1024)
//#NT#2016/07/27#Charlie Chang -end

//#NT#2016/11/11#Charlie Chang -begin
//#NT# support save face tracking snapshot
#if (FTG_SNAPSHOT_FUN == ENABLE)
#define POOL_SIZE_FTG_SNAPSHOT ALIGN_CEIL_64(FTG_MAX_SNAPSHOT_SIZE)
#endif
//#NT#2016/11/11#Charlie Chang -end

//#NT#2016/08/19#Lincy Lin -begin
//#NT#Support linux cvhost function
#if (LINUX_CVHOST_FUNC == ENABLE)
#define POOL_SIZE_CVHOST      ALIGN_CEIL_64(10*1024+0x200000)   // 10KB for command buffer + 2MB for image buffer FHD Y only
#endif
//#NT#2016/08/19#Lincy Lin -end

#if (UCTRL_FUNC==ENABLE)
#define POOL_SIZE_UCTRL_NVT_STATUS ALIGN_CEIL_64(64*1024) // 64K
#endif

#if (LINUX_MSDC == ENABLE)
#define POOL_SIZE_USBIPC 		ALIGN_CEIL_64(1*1024) // 1K
#endif

#if (MSDCVENDOR_NVT == ENABLE)
#if (USB_MODE == ENABLE)
#define POOL_SIZE_MSDCNVT       ALIGN_CEIL_64(MSDCNVT_REQUIRE_MIN_SIZE)
#else
#define POOL_SIZE_MSDCNVT       ALIGN_CEIL_64(MSDCNVT_REQUIRE_MIN_SIZE_NO_USB)
#endif
#endif

#if (LOGFILE_FUNC == ENABLE)
#define POOL_SIZE_LOGFILE 		ALIGN_CEIL_64(LOGFILE_BUFFER_SIZE)
#endif

#if defined(_ASR_ENABLE_)
#define POOL_SIZE_ASR           ALIGN_CEIL_64(1 * 2 * 1024 * 5)   // 1 ch * 2 byte * 1024 sample * 5 blocks
#endif

#define POOL_SIZE_WAV_PLAY_HEADER				ALIGN_CEIL_32(8*1024)	// 8KB
#define POOL_SIZE_WAV_PLAY_DATA					ALIGN_CEIL_32(380*1024)	// 380KB (300KB for PCM, 80KB for AAC)
#define POOL_SIZE_USER_PARTITION_RW_BUFFER      ALIGN_CEIL_32(0x10000)

#define POOL_SIZE_APP           ((UINT32)OS_GetMempoolSize(POOL_ID_APP)) //for query pool size of POOL_ID_APP after config
#define POOL_SIZE_FREE          (ALIGN_FLOOR_64((UINT32)OS_GetMemFreeSize(MEM_HEAP))) //query current free heap memory size to config pool size of POOL_ID_APP

#if (VIDEOSPRITEIPC != ENABLE)
#define POOL_SIZE_VDS_BK               ALIGN_CEIL_64(15888)
#endif

extern USIZE Calc_VideoSize_LCD(void) _SECTION(".kercfg_text");
extern USIZE Calc_VideoSize_MAX(void) _SECTION(".kercfg_text");


extern void Install_User(void);
extern void Install_UserMEM(void);

extern void Install_SystemMEM(void);

extern void Install_DrvMEM(void);
//Embedded Storage
extern void Install_DevEmbMEM(void);
//Storage
extern void Install_DevStrgMEM(void);
//OSD
extern void Install_DevOsdMEM(void);
//Video
extern void Install_DevVideoMEM(void);
//Imagepipe
extern void Install_DevImageMEM(void);
//Video Codec
extern void Install_DevVCodecMEM(void);
//Network
extern void Install_DevNetMEM(void);

extern void ImageStream_ConfigUserDump(void);
extern void UI_GetOSDBuf(UINT32 *pAddr, UINT32 *pSize);


#endif //_SYSCFG_H

