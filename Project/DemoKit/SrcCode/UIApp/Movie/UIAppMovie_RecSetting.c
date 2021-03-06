#include "SysCommon.h"
#include "UIMovieInfo.h"
#include "UIMovieMapping.h"
//#include "UIPhotoMapping.h"
#include "PrjCfg.h"
//#include "ImageApp_Photo.h"
//#include "ImageApp_Movie.h"
#include "ImageApp_MovieMulti.h"
#include "movieinterface_def.h"
#include "Audio.h"
#include "EthCamSocket.h"
#if FS_MULTI_STRG_FUNC
#include "DxStorage.h"
#include "DxApi.h"
#endif

#include "EthCamAppCmd.h"
#define __MODULE__          UIMovieRecSetting
#define __DBGLVL__          1 // 0=FATAL, 1=ERR, 2=WRN, 3=UNIT, 4=FUNC, 5=IND, 6=MSG, 7=VALUE, 8=USER
#define __DBGFLT__          "*" //*=All, [mark]=CustomClass
#include "DebugModule.h"

#define MOVIE_DUAL_RECORD_TEST          0////1

MOVIE_RECODE_INFO gMovie_Rec_Info[SENSOR_MAX_NUM] = {

	{
		_CFG_REC_ID_1,			//MOVIE_CFG_REC_ID
		_CFG_VID_IN_1,			//MOVIE_CFG_VID_IN
		{1920, 1080},			//MOVIE_CFG_IMG_SIZE
		30,						//MOVIE_CFG_FRAME_RATE
		2 * 1024 * 1024,		//MOVIE_CFG_TARGET_RATE
		#if (defined(_CHIP_96683_) && (defined(_MODEL_WiFiSDV_) || defined(_MODEL_FIREFLY_)|| (defined(_MODEL_B5_))) )
		_CFG_CODEC_H265,		//MOVIE_CFG_CODEC
		#else
		_CFG_CODEC_H264,		//MOVIE_CFG_CODEC
		#endif
		#if (defined(_NVT_ETHREARCAM_RX_))
		ETHCAM_AUDIO_FORMAT,
		#else
		_CFG_AUD_CODEC_AAC,		//MOVIE_CFG_AUD_CODEC
		#endif
		_CFG_REC_TYPE_AV,		//MOVIE_CFG_REC_MODE
		#if (defined(_NVT_ETHREARCAM_TX_))
		_CFG_FILE_FORMAT_TS,	//MOVIE_CFG_FILE_FORMAT
		#elif (defined(_NVT_ETHREARCAM_RX_))
		_CFG_FILE_FORMAT_MOV,
		#else
	_CFG_FILE_FORMAT_MOV,//cj 0526 // 	_CFG_FILE_FORMAT_MP4,	//MOVIE_CFG_FILE_FORMAT
		#endif
		{16, 9},				//MOVIE_CFG_IMG_RATIO
		{1920, 1080},			//MOVIE_CFG_RAWENC_SIZE
		0,						//MOVIE_CFG_IMAGEPIPE_FUNC (IMAGEPIPE_FUNC_SQUARE)
		ENABLE,					//MOVIE_CFG_DISP_ENABLE
		TRUE,					//ipl_set_enable,  FALSE: can not set sensor info, TRUE: can set sensor info
		_CFG_DAR_DEFAULT,		//MOVIE_CFG_DAR
		{0},					//MOVIE_CFG_AQ_INFO
		{0},					//MOVIE_CFG_CBR_INFO
		FALSE,					//Sensor rotate setting
		0,						//MOVIE_CFG_IMAGEPIPE_FUNC2
		{16, 9},				//video display aspect ratio
	},

	{
		_CFG_REC_ID_2,			//MOVIE_CFG_REC_ID
		_CFG_VID_IN_1,			//MOVIE_CFG_VID_IN
		{1920, 1080},			//MOVIE_CFG_IMG_SIZE
		30, 					//MOVIE_CFG_FRAME_RATE
		2 * 1024 * 1024,		//MOVIE_CFG_TARGET_RATE
		#if (defined(_CHIP_96683_) && (defined(_MODEL_WiFiSDV_) || defined(_MODEL_FIREFLY_)|| (defined(_MODEL_B5_))) )
		_CFG_CODEC_H265,		//MOVIE_CFG_CODEC
		#else
		_CFG_CODEC_H264,		//MOVIE_CFG_CODEC
		#endif
		_CFG_AUD_CODEC_AAC, 	//MOVIE_CFG_AUD_CODEC
		_CFG_REC_TYPE_AV,		//MOVIE_CFG_REC_MODE
		#if (defined(_NVT_ETHREARCAM_TX_))
		_CFG_FILE_FORMAT_TS,	//MOVIE_CFG_FILE_FORMAT
		#else
		_CFG_FILE_FORMAT_MOV,//cj 0526 // _CFG_FILE_FORMAT_MP4,	//MOVIE_CFG_FILE_FORMAT
		#endif
		{16, 9},				//MOVIE_CFG_IMG_RATIO
		{1920, 1080},			//MOVIE_CFG_RAWENC_SIZE
		0,						//MOVIE_CFG_IMAGEPIPE_FUNC (IMAGEPIPE_FUNC_SQUARE)
		ENABLE, 				//MOVIE_CFG_DISP_ENABLE
		TRUE,					//ipl_set_enable,  FALSE: can not set sensor info, TRUE: can set sensor info
		_CFG_DAR_DEFAULT,		//MOVIE_CFG_DAR
		{0},					//MOVIE_CFG_AQ_INFO
		{0},					//MOVIE_CFG_CBR_INFO
		FALSE,					//Sensor rotate setting
		0,						//MOVIE_CFG_IMAGEPIPE_FUNC2
		{16, 9},				//video display aspect ratio
	},
};

MOVIE_RECODE_INFO gMovie_Clone_Info[SENSOR_MAX_NUM] = {

	{
		_CFG_CLONE_ID_1,		//MOVIE_CFG_REC_ID
		_CFG_VID_IN_1,			//MOVIE_CFG_VID_IN
		{848, 480},				//MOVIE_CFG_IMG_SIZE
		30,						//MOVIE_CFG_FRAME_RATE
		250 * 1024,				//MOVIE_CFG_TARGET_RATE
		#if (defined(_CHIP_96683_) && (defined(_MODEL_WiFiSDV_) || defined(_MODEL_FIREFLY_)|| (defined(_MODEL_B5_))) )
		_CFG_CODEC_H265,		//MOVIE_CFG_CODEC
		#else
		_CFG_CODEC_H264,		//MOVIE_CFG_CODEC
		#endif
		_CFG_AUD_CODEC_AAC,		//MOVIE_CFG_AUD_CODEC
		_CFG_REC_TYPE_AV,		//MOVIE_CFG_REC_MODE
		#if (defined(_NVT_ETHREARCAM_TX_))
		_CFG_FILE_FORMAT_TS,	//MOVIE_CFG_FILE_FORMAT
		#else
		_CFG_FILE_FORMAT_MOV,//cj 0526 // _CFG_FILE_FORMAT_MP4,	//MOVIE_CFG_FILE_FORMAT
		#endif
		{16, 9},				//MOVIE_CFG_IMG_RATIO
		{848, 480},				//MOVIE_CFG_RAWENC_SIZE
		0,						//MOVIE_CFG_IMAGEPIPE_FUNC (IMAGEPIPE_FUNC_SQUARE)
		ENABLE,					//MOVIE_CFG_DISP_ENABLE
		TRUE,					//ipl_set_enable,  FALSE: can not set sensor info, TRUE: can set sensor info
		_CFG_DAR_DEFAULT,		//MOVIE_CFG_DAR
		{0},					//MOVIE_CFG_AQ_INFO
		{0},					//MOVIE_CFG_CBR_INFO
		FALSE,					//Sensor rotate setting
		0,						//MOVIE_CFG_IMAGEPIPE_FUNC2
		{16, 9},				//video display aspect ratio
	},

	{
		_CFG_CLONE_ID_2,		//MOVIE_CFG_REC_ID
		_CFG_VID_IN_1,			//MOVIE_CFG_VID_IN
		{848, 480},				//MOVIE_CFG_IMG_SIZE
		30, 					//MOVIE_CFG_FRAME_RATE
		250 * 1024, 			//MOVIE_CFG_TARGET_RATE
		#if (defined(_CHIP_96683_) && (defined(_MODEL_WiFiSDV_) || defined(_MODEL_FIREFLY_)|| (defined(_MODEL_B5_))) )
		_CFG_CODEC_H265,		//MOVIE_CFG_CODEC
		#else
		_CFG_CODEC_H264,		//MOVIE_CFG_CODEC
		#endif
		_CFG_AUD_CODEC_AAC, 	//MOVIE_CFG_AUD_CODEC
		_CFG_REC_TYPE_AV,		//MOVIE_CFG_REC_MODE
		#if (defined(_NVT_ETHREARCAM_TX_))
		_CFG_FILE_FORMAT_TS,	//MOVIE_CFG_FILE_FORMAT
		#else
		_CFG_FILE_FORMAT_MOV,//cj 0526 // _CFG_FILE_FORMAT_MP4,	//MOVIE_CFG_FILE_FORMAT
		#endif
		{16, 9},				//MOVIE_CFG_IMG_RATIO
		{848, 480},				//MOVIE_CFG_RAWENC_SIZE
		0,						//MOVIE_CFG_IMAGEPIPE_FUNC (IMAGEPIPE_FUNC_SQUARE)
		ENABLE, 				//MOVIE_CFG_DISP_ENABLE
		TRUE,					//ipl_set_enable,  FALSE: can not set sensor info, TRUE: can set sensor info
		_CFG_DAR_DEFAULT,		//MOVIE_CFG_DAR
		{0},					//MOVIE_CFG_AQ_INFO
		{0},					//MOVIE_CFG_CBR_INFO
		FALSE,					//Sensor rotate setting
		0,						//MOVIE_CFG_IMAGEPIPE_FUNC2
		{16, 9},				//video display aspect ratio
	},
};

//#NT#2018/04/02#IsiahChang -begin
//#NT#To support Wi-Fi command 2025 BRC.
MOVIE_STRM_INFO gMovie_Strm_Info = {
	_CFG_STRM_ID_1,				//MOVIE_CFG_REC_ID
	_CFG_VID_IN_1,				//MOVIE_CFG_VID_IN
	{848,480},					//MOVIE_CFG_IMG_SIZE
	30,							//MOVIE_CFG_FRAME_RATE
	350 * 1024,					//MOVIE_CFG_TARGET_RATE
	_CFG_CODEC_H264,			//MOVIE_CFG_CODEC
	15,							//MOVIE_CFG_GOP_NUM
	_CFG_AUD_CODEC_NONE,//cj 0601 turn off ??????????//_CFG_AUD_CODEC_AAC,			//MOVIE_CFG_AUD_CODEC
	TRUE,						//MOVIE_CFG_RTSP_STRM_OUT
	{0},						//MOVIE_CFG_AQ_INFO, Defined by g_MovieRecSizeTable[].
	{0},						// MOVIE_CFG_CBR_INFO, Defined by g_MovieRecSizeTable[].
	FALSE, 						// ipl_set_enable,  FALSE: can not set sensor info, TRUE: can set sensor info
	{16,9},						//MOVIE_CFG_IMG_RATIO
	#if(MOVIE_STRM_PATH_USERPROC == ENABLE)
	TRUE						//userproc_pull
	#else
	FALSE						//userproc_pull
	#endif
};
//#NT#2018/04/02#IsiahChang -end

MOVIE_RECODE_FILE_OPTION gMovie_Rec_Option = {
	_CFG_REC_ID_1,              //MOVIE_CFG_REC_ID
	180,                        //MOVIE_CFG_FILE_SECOND seamless_sec
	FALSE,                      //MOVIE_CFG_FILE_OPTION emr_on
	3,                          //MOVIE_CFG_FILE_OPTION emr_sec (rollback sec) (main path)
	5,                          //MOVIE_CFG_FILE_SECOND keep_sec (main path)
	0,                          //MOVIE_CFG_FILE_SECOND overlap_sec (only 0 or 1 is valid)
	MOVREC_ENDTYPE_CUTOVERLAP,  //MOVIE_CFG_FILE_ENDTYPE  end_type
	10,                         //MOVIE_CFG_FILE_SECOND rollback_sec (for crash)
	10,                         //MOVIE_CFG_FILE_SECOND forward_sec (for crash)
	3,                          //MOVIE_CFG_FILE_OPTION emr_sec (rollback sec) (clone path)
	5,                          //MOVIE_CFG_FILE_SECOND keep_sec (clone path)
};

MOVIEMULTI_RECODE_FOLDER_NAMING gMovie_Folder_Naming[SENSOR_MAX_NUM] = {
	{
		_CFG_REC_ID_1,			//MOVIE_CFG_REC_ID
		"Movie",				//MOVIE_CFG_FOLDER_NAME   movie
		"RO",//"EMR",			//MOVIE_CFG_FOLDER_NAME   emr
		"Photo",//"Movie",		//MOVIE_CFG_FOLDER_NAME   snapshot  modify for autotest
		TRUE,					//MOVIE_CFG_FILE_NAMING   2018/02/13
	},

	{
		_CFG_REC_ID_2,			//MOVIE_CFG_REC_ID
		"Movie",				//MOVIE_CFG_FOLDER_NAME   movie
		"RO",//"EMR",			//MOVIE_CFG_FOLDER_NAME   emr
		"Photo",//"Movie",		//MOVIE_CFG_FOLDER_NAME   snapshot  modify for autotest
		TRUE,					//MOVIE_CFG_FILE_NAMING   2018/02/13
	},
};

MOVIEMULTI_RECODE_FOLDER_NAMING gMovie_Clone_Folder_Naming[SENSOR_MAX_NUM] = {
	{
		_CFG_CLONE_ID_1,		//MOVIE_CFG_REC_ID
		"Movie_S",				//MOVIE_CFG_FOLDER_NAME   movie
		"EMR_S",				//MOVIE_CFG_FOLDER_NAME   emr
		"Photo_S",				//MOVIE_CFG_FOLDER_NAME   snapshot  modify for autotest
		TRUE,					//MOVIE_CFG_FILE_NAMING   2018/02/13
	},

	{
		_CFG_CLONE_ID_2,		//MOVIE_CFG_REC_ID
		"Movie_S",				//MOVIE_CFG_FOLDER_NAME   movie
		"EMR_S",				//MOVIE_CFG_FOLDER_NAME   emr
		"Photo_S",				//MOVIE_CFG_FOLDER_NAME   snapshot  modify for autotest
		TRUE,					//MOVIE_CFG_FILE_NAMING   2018/02/13
	},
};

MOVIEMULTI_RECODE_FOLDER_NAMING gMovie_EthCam_Folder_Naming[ETHCAM_PATH_ID_MAX] = {
	{
		_CFG_ETHCAM_ID_1,		//MOVIE_CFG_REC_ID
		#if 0
		"Movie_E",				//MOVIE_CFG_FOLDER_NAME   movie
		"EMR_E",				//MOVIE_CFG_FOLDER_NAME   emr
		"Movie_E",				//MOVIE_CFG_FOLDER_NAME   snapshot  modify for autotest
		#else
		"Movie",				//MOVIE_CFG_FOLDER_NAME   movie
		"RO",//"EMR",			//MOVIE_CFG_FOLDER_NAME   emr
		"Photo",
		#endif
		TRUE,					//MOVIE_CFG_FILE_NAMING   2018/02/13
	},
	{
		_CFG_ETHCAM_ID_2,		//MOVIE_CFG_REC_ID
		#if 0
		"Movie_E",				//MOVIE_CFG_FOLDER_NAME   movie
		"EMR_E",				//MOVIE_CFG_FOLDER_NAME   emr
		"Movie_E",				//MOVIE_CFG_FOLDER_NAME   snapshot  modify for autotest
		#else
		"Movie",				//MOVIE_CFG_FOLDER_NAME   movie
		"RO",//"EMR",			//MOVIE_CFG_FOLDER_NAME   emr
		"Photo",
		#endif
		TRUE,					//MOVIE_CFG_FILE_NAMING   2018/02/13
	},
};

MOVIEMULTI_AUDIO_INFO   gMovie_Audio_Info = {
#if ((_BOARD_DRAM_SIZE_ == 0x04000000 && !defined(_NVT_ETHREARCAM_TX_)) || (SENSOR_CAPS_COUNT >= 2) ||  ((defined(_NVT_ETHREARCAM_RX_)) && (ETH_REARCAM_CAPS_COUNT >= 1)) || defined(_ASR_ENABLE_))
	16000,                     //MOVIE_CFG_AUD_RATE
	AUDIO_CH_STEREO,            //MOVIE_CFG_AUD_CH
	2,                         //MOVIE_CFG_AUD_CH_NUM
#else
	16000,                     //MOVIE_CFG_AUD_RATE
	AUDIO_CH_RIGHT,           //MOVIE_CFG_AUD_CH
	1,                         //MOVIE_CFG_AUD_CH_NUM
#endif
};
MOVIEMULTI_CFG_DISP_INFO gMovie_Disp_Info = {
    VDO_ROTATE_DIR,
	#if MOVIE_DUAL_RECORD_TEST
    TRUE,
	#else
    FALSE,
	#endif
};
static UINT32 gSensorRecMask = 0xF; // which sensor is for movie recording; bit [0:3] means sensor 1~4

UINT32 Movie_GetSensorRecMask(void)
{
	return (gSensorRecMask & System_GetEnableSensor());
}

void Movie_SetSensorRecMask(UINT32 mask)
{
	gSensorRecMask = mask & System_GetEnableSensor();
}

// get main movie record mask, bit [0:3] means main movie 1~4
UINT32 Movie_GetMovieRecMask(void)
{
	UINT32 i;
	UINT32 rec_type;
	UINT32 movie_size_idx;
	UINT32 sensor_enable; // sensor enabled
	UINT32 sensor_record; // sensor for recording
	UINT32 movie_rec_mask = 0, mask = 1;
	UINT32 setting_count = 0;

	sensor_enable = System_GetEnableSensor();
	sensor_record = Movie_GetSensorRecMask();
	movie_size_idx = UI_GetData(FL_MOVIE_SIZE);
	rec_type = MovieMapping_GetRecType(movie_size_idx);

	for (i = 0; i < SENSOR_CAPS_COUNT; i++)	{

		if (sensor_enable & mask) {
			if (rec_type == MOVIE_REC_TYPE_FRONT || rec_type == MOVIE_REC_TYPE_CLONE) { // single recording
				if (sensor_record & mask) { // active sensor, for movie recording
					movie_rec_mask = mask;
					break;
				}
			} else if (rec_type == MOVIE_REC_TYPE_DUAL) { // dual recording
				if ((sensor_record & mask) && (setting_count < 2)) { // active sensor, for movie recording
					movie_rec_mask |= mask;
					setting_count++;
#if (SENSOR_CAPS_COUNT >=2)//CID 129672
					if (setting_count == 2)
						break;
#endif
				}

			}
		}

		mask <<= 1;
	}

	return movie_rec_mask;
}

// get clone movie record mask, bit [0:3] means clone movie 1~4
UINT32 Movie_GetCloneRecMask(void)
{
	UINT32 rec_type;
	UINT32 movie_size_idx;
	UINT32 clone_rec_mask = 0;

	movie_size_idx = UI_GetData(FL_MOVIE_SIZE);
	rec_type = MovieMapping_GetRecType(movie_size_idx);

	if (rec_type == MOVIE_REC_TYPE_CLONE) {
		clone_rec_mask = Movie_GetMovieRecMask();
	}

	return clone_rec_mask;
}

void Movie_SetResvSize(void)
{
	// set 10MB reserved size for normal recording
	ImageApp_MovieMulti_SetReservedSize('A', 10*1024*1024, FALSE);

    #if defined(_EMBMEM_EMMC_) && (FS_MULTI_STRG_FUNC==ENABLE)
    {
        UINT32 uiDxState = 0;
        DX_HANDLE pStrgDev = Dx_GetObject(DX_CLASS_STORAGE_EXT | FS_DX_TYPE_DRIVE_A);
        if (Dx_GetState((DX_HANDLE)pStrgDev, STORAGE_STATE_INSERT, &uiDxState) != DX_OK || uiDxState == FALSE) {
        	// set 400MB reserved size for loop recording in eMMC.
        	// according to 4MB/s TBR, 10 sec deleting files time, 10 sec bs buffer, and some tolerance
    	    ImageApp_MovieMulti_SetReservedSize('A', 400*1024*1024, TRUE);
        } else {
        	// set 100MB reserved size for loop recording
        	// according to 4MB/s TBR, 10 sec deleting files time, 10 sec bs buffer, and some tolerance
    	    ImageApp_MovieMulti_SetReservedSize('A', 100*1024*1024, TRUE);
        }
    }
    #else
	// set 100MB reserved size for loop recording
	// according to 4MB/s TBR, 10 sec deleting files time, 10 sec bs buffer, and some tolerance
	//	ImageApp_MovieMulti_SetReservedSize('A', 100*1024*1024, TRUE);
//CHKPNT;
	ImageApp_MovieMulti_SetReservedSize('A', 100*1024*1024, TRUE);
    #endif

    #if defined(_EMBMEM_EMMC_) && (FS_MULTI_STRG_FUNC==ENABLE)
	// set 10MB reserved size for normal recording
	ImageApp_MovieMulti_SetReservedSize('B', 10*1024*1024, FALSE);

	// set 100MB reserved size for loop recording
	// according to 4MB/s TBR, 10 sec deleting files time, 10 sec bs buffer, and some tolerance
	ImageApp_MovieMulti_SetReservedSize('B', 400*1024*1024, TRUE);
    #endif

}

UINT32 Movie_GetFreeSec(void)
{
	UINT32 sec;
	UINT32 i, mask, rec_id;
	UINT32 movie_rec_mask, clone_rec_mask;
	UINT64 remain_size;
	static MOVIEMULTI_CALCSEC_SETTING2 movie_setting;

	memset(&movie_setting, 0, sizeof(MOVIEMULTI_CALCSEC_SETTING2));

	ImageApp_MovieMulti_GetRemainSize('A', &remain_size);
	if (remain_size == 0xFFFFFFFF) // get remaining size failed
		remain_size = 0;

	movie_rec_mask = Movie_GetMovieRecMask();
	clone_rec_mask = Movie_GetCloneRecMask();

	mask = 1;
	rec_id = 0;
	for (i = 0; i < (SENSOR_CAPS_COUNT & SENSOR_ON_MASK); i++) {
		if (movie_rec_mask & mask) {
			movie_setting.info[rec_id].vidfps = gMovie_Rec_Info[i].frame_rate;
			movie_setting.info[rec_id].vidTBR = gMovie_Rec_Info[i].target_bitrate;
			movie_setting.info[rec_id].audSampleRate = gMovie_Audio_Info.aud_rate;
			movie_setting.info[rec_id].audChs = gMovie_Audio_Info.aud_ch;
			movie_setting.info[rec_id].gpson = TRUE;
			movie_setting.info[rec_id].nidxon = TRUE;
			rec_id++;
		}

		if (clone_rec_mask & mask) {
			movie_setting.info[rec_id].vidfps = gMovie_Clone_Info[i].frame_rate;
			movie_setting.info[rec_id].vidTBR = gMovie_Clone_Info[i].target_bitrate;
			movie_setting.info[rec_id].audSampleRate = gMovie_Audio_Info.aud_rate;
			movie_setting.info[rec_id].audChs = gMovie_Audio_Info.aud_ch;
			movie_setting.info[rec_id].gpson = TRUE;
			movie_setting.info[rec_id].nidxon = TRUE;
			rec_id++;
		}

		mask <<= 1;
	}
#if (defined(_NVT_ETHREARCAM_RX_))
	for (i=ETHCAM_PATH_ID_1; i<(ETHCAM_PATH_ID_1+ETH_REARCAM_CAPS_COUNT); i++){
		//DBG_DUMP("[%d]rec_id=%d, vfr=%d, tbr=%d\r\n", i,rec_id,sEthCamTxRecInfo[i].vfr,sEthCamTxRecInfo[i].tbr);
		movie_setting.info[rec_id].vidfps = sEthCamTxRecInfo[i].vfr;
		movie_setting.info[rec_id].vidTBR = sEthCamTxRecInfo[i].tbr;
		movie_setting.info[rec_id].audSampleRate = gMovie_Audio_Info.aud_rate;
		movie_setting.info[rec_id].audChs = gMovie_Audio_Info.aud_ch;
		movie_setting.info[rec_id].gpson = TRUE;
		movie_setting.info[rec_id].nidxon = TRUE;
		rec_id++;
	}
#endif
	movie_setting.givenSpace = remain_size;
	sec = ImageApp_MovieMulti_GetFreeRec2(&movie_setting);

	return sec;
}
