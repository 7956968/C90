////////////////////////////////////////////////////////////////////////////////
#include "SysCommon.h"
//#include "AppCommon.h"
////////////////////////////////////////////////////////////////////////////////
#include "AppLib.h"
#include "UIMode.h"
#include "UIAppPhoto.h"
#include "UIAppPlay.h"
#include "UIAppMovie.h"
#include "UISetup.h"

#include "UIInfo.h"
#include "UIPhotoInfo.h"
#include "ProjectInfo.h"
#include "DateTimeInfo.h"

#include "PStore.h"

//#include "NVTUserCommand.h"
#include "UIResource.h"

#include "UICfgDefault.h"

#include "DCF.h"

#include "PowerDef.h"

#include "usb.h"

#include "HwClock.h"
#include "rtc.h"

#include "FileDB.h"
#include "NameRule_FileDB.h"

#include "bin_info.h"
#include "Audio.h"

#include "UsbDevDef.h"
#include "UIAppNetwork.h"
#include "DrvExt.h"
#include "wdt.h"

////////////////////////////////////////////////////////////////////////////////
//---------------------UIInfo Debug Definition -----------------------------
#define _UIINFO_ERROR_MSG        1
#define _UIINFO_TRACE_MSG        0

#if (_UIINFO_ERROR_MSG && (PRJ_DBG_LVL>=PRJ_DBG_LVL_ERR))
#define UIInfoErrMsg(...)            debug_msg ("^R UIInfo: "__VA_ARGS__)
#else
#define UIInfoErrMsg(...)
#endif

#if (_UIINFO_TRACE_MSG && (PRJ_DBG_LVL>=PRJ_DBG_LVL_TRC))
#define UIInfoTraceMsg(...)          debug_msg ("^B UIInfo: "__VA_ARGS__)
#else
#define UIInfoTraceMsg(...)
#endif

extern UINT32 System_GetEnableSensor(void);


#define SYSINFO_NAND    ENABLE //DISABLE

//---------------------UIInfo Global Variables -----------------------------

//static UINT32 UIParameter[FL_IndexInfoMAX] = {0}; //#NT#Init the array to zero.

//UISysInfo sysInfo={0}; //#NT#Init the array to zero.

UIMenuStoreInfo  currentInfo = {0}; //#NT#Init the array to zero.


BOOL bSysReady = 0;
BOOL bAutoSystemReset = FALSE;
//static BOOL bAutoReset = FALSE;
static UINT32 guiBatteryLevel       = UIDFT_BATTERY_LVL;

//---------------------UIInfo Prototype Declaration  -----------------------
//---------------------UIInfo Public API  ----------------------------------
//---------------------UIInfo Private API ----------------------------------
void SysSetFixedFlagSysInit(void);

//------------------------------------------------------------

void Load_SysInfo(void)
{
	/*
	    UIInfoTraceMsg("Read SYSINFO\r\n");
	#if (SYSINFO_NAND==ENABLE)
	    PStore_ReadReServedArea((UINT8*)&sysInfo,sizeof(UISysInfo));
	#else
	    //set to default value
	    sysInfo.ubBeepPowerIndex = BEEP_TONE_1;
	    sysInfo.ubBeepVolumnIndex = BEEP_VOL_2;
	    sysInfo.ubWallpaperStartupIndex = WALLPAPER_STARTUP_GE;
	    sysInfo.uhInfoSize = sizeof(sysInfo);
	#endif
	*/
}

void Save_SysInfo(void)
{
	/*
	    UIInfoTraceMsg("Write SYSINFO\r\n");
	#if (SYSINFO_NAND==ENABLE)
	    PStore_WriteReServedArea((UINT8*)&sysInfo,sizeof(UISysInfo));
	#endif
	*/
}

UISysSN SNInfo={0};
void UI_SetSNInfo(char *buff)
{
    UINT32 i;
    UINT32 chksum = 0;
	strncpy(SNInfo.strSN, buff, SERIAL_NUM_LEN-1); // Save serial number.
    for(i = 0; i < strlen(SNInfo.strSN); i ++)
    {
      chksum += SNInfo.strSN[i];
    }
	SNInfo.strSN[SERIAL_NUM_LEN - 1] = '\0';
	SNInfo.uidChksum= chksum;
}
char * UI_GetSNInfo(void)
{
    return SNInfo.strSN;
}
void Load_SysSNInfo(void)
{

#if 0//USER_PACK_UPDATE_ENABLE
	UINT32 i;
	UINT32 chksum = 0;
	UserPartition_Read((UINT8 *)&SNInfo, 0, sizeof(UISysSN), USR_PARTI_SYS_SN);	 
    for(i = 0; i < strlen(SNInfo.strSN); i ++)
    {
       chksum += SNInfo.strSN[i];
    }
	if(chksum != SNInfo.uidChksum)
	{
	   debug_msg("^R SN Info CheckSum Not Match!!\r\n");
	   UI_SetSNInfo(DEFAULT_SN);
	   Save_SysSNInfo();
	}
	else
	{
       debug_msg("^R SN Info!!:%s\r\n",SNInfo.strSN);
	}
#endif
}

void Save_SysSNInfo(void)
{ 
#if 0//USER_PACK_UPDATE_ENABLE
    UserPartition_Write((UINT8 *)&SNInfo, 0, sizeof(UISysSN), USR_PARTI_SYS_SN);
#endif
}


//------------------------------------------------------------
#define PS_SYS_PARAM            "SYSP"
#define BLOCK_UIINFO    0

CHAR previewEVStr[EV_SETTING_MAX][5] = {
	"-2.0",
	"-1.7",
	"-1.3",
	"-1.0",
	"-0.7",
	"-0.3",
	"+0.0",
	"+0.3",
	"+0.7",
	"+1.0",
	"+1.3",
	"+1.7",
	"+2.0"
};

void UI_SetInitVolume(UINT32 volumeIndex)
{
	#if (AUDIO_FUNC == ENABLE)
	const static AUDIO_VOL volume_gain[BEEP_VOL_SETTING_MAX] =
	{AUDIO_GAIN_MUTE, AUDIO_GAIN_3, AUDIO_GAIN_5, AUDIO_GAIN_7};

	if (volumeIndex >= BEEP_VOL_SETTING_MAX) {
		volumeIndex = BEEP_VOL_2;    //set to default
	}

	GxSound_SetVolume(volume_gain[volumeIndex]);
	#endif
}

void UI_SetFileDBFileID(void)
{
#if USE_FILEDB

    struct tm Curr_DateTime;
    Curr_DateTime = HwClock_GetTime(TIME_ID_CURRENT);

	if (((UINT32)Curr_DateTime.tm_year  == currentInfo.cbYear) && ((UINT32)Curr_DateTime.tm_mon== currentInfo.cbMonth) && ((UINT32)Curr_DateTime.tm_mday== currentInfo.cbDay)) {
		NH_FileDB_SetFileID(currentInfo.cbFileID);
	}
#endif
}

void UI_SaveRTCDate(void)
{
#if USE_FILEDB
	FILEDB_HANDLE fileDbHandle = 0;
	FILEDB_FILE_ATTR *pFileAttr;
	RTC_DATE    Date;
	CHAR datetime[10];
	UINT32 uiFileID;

	pFileAttr = FileDB_CurrFile(fileDbHandle);
	if (pFileAttr != NULL) {
		strncpy(datetime, pFileAttr->filename, 4);
		datetime[4] = '\0';
		Date.s.year = atoi(datetime);

		strncpy(datetime, pFileAttr->filename + 5, 2);
		datetime[2] = '\0';
		Date.s.month = atoi(datetime);

		strncpy(datetime, pFileAttr->filename + 7, 2);
		datetime[2] = '\0';
		Date.s.day = atoi(datetime);

		strncpy(datetime, pFileAttr->filename + 17, 3);
		datetime[3] = '\0';
		uiFileID = atoi(datetime);

		currentInfo.cbYear = Date.s.year;
		currentInfo.cbMonth = Date.s.month;
		currentInfo.cbDay = Date.s.day;
		currentInfo.cbFileID = uiFileID;
	}
#endif
}

BOOL Load_MenuInfoForDisp(void)
{
#if (PST_FUNC == ENABLE)
    PPSTORE_SECTION_HANDLE  pSection;
    UINT32  result;
    UINT32  uiFWUpdate = 0;
	extern BOOL bDispInfoOnly;
    UIInfoTraceMsg("Read UIINFO\r\n");
    
    // Read system info from PStore
    if ((pSection = PStore_OpenSection(PS_SYS_PARAM, PS_RDWR)) != E_PS_SECHDLER)
    {
        result = PStore_ReadSection((UINT8 *)&currentInfo, 0, sizeof(UIMenuStoreInfo), pSection);
        if (result != E_PS_OK)
        {
           return FALSE;
        }
        PStore_CloseSection(pSection);
    }
    else
    {
        Reset_MenuInfo();
        UIInfoErrMsg("PStore Read sys param fail\r\n");
    }
    UIInfoTraceMsg("Read UIRES\r\n");
    return TRUE;
#elif USER_PACK_UPDATE_ENABLE
    MODELEXT_HEADER *head = NULL;
    UINT32	result;
    UINT32	uiFWUpdate = 0;
    UINT32	uiTmpBoot = 0;
	
    UIInfoTraceMsg("Read UIINFO\r\n");
	UserPartition_Read((UINT8 *)&currentInfo, 0, sizeof(UIMenuStoreInfo), USR_PARTI_SYS_MENU);	
	if(currentInfo.uhInfoSize != sizeof(currentInfo))	  
	{
		Reset_MenuInfo();
		return TRUE;
	}
#endif
    return TRUE;
}
void Load_MenuInfo(void)
{
#if (PST_FUNC == ENABLE)
	MODELEXT_HEADER *head = NULL;
	BININFO *pBinInfo = (BININFO *)Dx_GetModelExtCfg(MODELEXT_TYPE_BIN_INFO, &head);
	PPSTORE_SECTION_HANDLE  pSection;
	UINT32  result;
	UINT32  uiFWUpdate = 0;
	UINT32  uiTmpBoot = 0;
	UIInfoTraceMsg("Read UIINFO\r\n");

	if (pBinInfo == NULL) {
		UIInfoErrMsg("pBinInfo is NULL\r\n");
		return;
	}

	uiFWUpdate = (pBinInfo->ld.LdCtrl2 & LDCF_UPDATE_FW);
	uiTmpBoot = (pBinInfo->ld.LdCtrl2 & LDCF_BOOT_CARD);

	// Read system info from PStore
	if (uiTmpBoot) {
		SysResetFlag();
		debug_msg("Boot from temp file, use default flags\r\n");
	} else if ((pSection = PStore_OpenSection(PS_SYS_PARAM, PS_RDWR)) != E_PS_SECHDLER) {
		//#NT#2016/06/23#Niven Cho -begin
		//#NT#porting KS's suggestion that PStore reset mechanism
		UINT32 uiPsFreeSpace = PStore_GetInfo(PS_INFO_FREE_SPACE);
		result = PStore_ReadSection((UINT8 *)&currentInfo, 0, sizeof(UIMenuStoreInfo), pSection);
		if ((result != E_PS_OK || currentInfo.uhInfoSize != sizeof(currentInfo) || uiFWUpdate) &&
			uiPsFreeSpace) {
			debug_msg("PStore reset info.\r\n");
			memset(&currentInfo, 0, sizeof(currentInfo));
			currentInfo.uhInfoSize = sizeof(UIMenuStoreInfo);
			SysResetFlag();
			SysSetFlag(FL_IMGDISP_POS_STEP_ID0,  DEFAULT_IMGDISP_POS_ID0);
			SysSetFlag(FL_IMGDISP_POS_STEP_ID1,  DEFAULT_IMGDISP_POS_ID1);

			PStore_WriteSection((UINT8 *)&currentInfo, 0, sizeof(UIMenuStoreInfo), pSection);
			PStore_CloseSection(pSection);
		} else if ((result != E_PS_OK || uiFWUpdate) && (currentInfo.uhInfoSize == sizeof(currentInfo)) &&
				   (uiPsFreeSpace == 0)) {
			//if current size is the same with previous, use PS_UPDATE instead
			//of PS_RDWR to prevent that PStore is no free space
			debug_msg("PStore reset info for uiPsFreeSpace=0.\r\n");
			PStore_CloseSection(pSection);
			memset(&currentInfo, 0, sizeof(currentInfo));
			currentInfo.uhInfoSize = sizeof(UIMenuStoreInfo);
			SysResetFlag();
			SysSetFlag(FL_IMGDISP_POS_STEP_ID0,  DEFAULT_IMGDISP_POS_ID0);
			SysSetFlag(FL_IMGDISP_POS_STEP_ID1,  DEFAULT_IMGDISP_POS_ID1);

			if ((pSection = PStore_OpenSection(PS_SYS_PARAM, PS_UPDATE)) != E_PS_SECHDLER) {
				PStore_WriteSection((UINT8 *)&currentInfo, 0, sizeof(UIMenuStoreInfo), pSection);
				PStore_CloseSection(pSection);
			} else {
				UIInfoErrMsg("Update sys param fail in Load_MenuInfo\r\n");
			}
		} else {
			PStore_CloseSection(pSection);
		}
		//#NT#2016/06/23#Niven Cho -end
		//#NT#2017/03/02#Niven Cho -begin
		//#NT#EMMC_AS_PSTORE, reduce PStore_CloseSection
		//PStore_CloseSection(pSection);
		//#NT#2017/03/02#Niven Cho -end
		bSysReady = 1;
	} else {
		SysResetFlag();
		UIInfoErrMsg("PStore Read sys param fail, use default flags\r\n");
	}

	UIInfoTraceMsg("Read UIRES\r\n");
#else
	SysResetFlag();
#endif
}

void Load_LangString(void)
{
	//load language
	UIRes_InitReadLang(currentInfo.ubLanguageIndex);
}

void Save_MenuInfo()
{
#if (PST_FUNC == ENABLE)
	MODELEXT_HEADER *head = NULL;
	BININFO *pBinInfo = (BININFO *)Dx_GetModelExtCfg(MODELEXT_TYPE_BIN_INFO, &head);
	PPSTORE_SECTION_HANDLE  pSection;
	UINT32 error = 0;
	UINT32  uiTmpBoot;

	if (pBinInfo == NULL) {
		UIInfoErrMsg("pBinInfo is NULL\r\n");
		return;
	}
	uiTmpBoot = (pBinInfo->ld.LdCtrl2 & LDCF_BOOT_CARD);
	// Read system info from PStore
	if (uiTmpBoot) {
		SysResetFlag();
		debug_msg("Boot from temp file, skip Save_MenuInfo\r\n");
		return;
	}

	UIInfoTraceMsg("Write UIINFO\r\n");
	//#NT#2013/3/15#Philex Lin - begin
	/*--- General ---*/
	strncpy(currentInfo.strSoftwareVer, Prj_GetVersionString(), (VER_STR_MAX - 1));
	currentInfo.strSoftwareVer[strlen(currentInfo.strSoftwareVer)] = '\0';
	currentInfo.uhInfoSize = sizeof(UIMenuStoreInfo);
	//#NT#2013/3/15#Philex Lin - end

	//Using PStore to read / sys param
	//#NT#2016/06/23#Niven Cho -begin
	//#NT#porting KS's suggestion that PStore reset mechanism
	UINT32 uiPsFreeSpace = PStore_GetInfo(PS_INFO_FREE_SPACE);
	if (uiPsFreeSpace == 0) {
		if ((pSection = PStore_OpenSection(PS_SYS_PARAM, PS_UPDATE)) != E_PS_SECHDLER) {
			PStore_WriteSection((UINT8 *)&currentInfo, 0, sizeof(UIMenuStoreInfo), pSection);
			PStore_CloseSection(pSection);
		} else {
			UIInfoErrMsg("Update sys param fail\r\n");
		}
	} else {
		if ((pSection = PStore_OpenSection(PS_SYS_PARAM, PS_RDWR | PS_CREATE)) != E_PS_SECHDLER) {
			PStore_WriteSection((UINT8 *)&currentInfo, 0, sizeof(UIMenuStoreInfo), pSection);
			PStore_CloseSection(pSection);
		} else {
			UIInfoErrMsg("Write sys param fail\r\n");
		}
	}
	//#NT#2016/06/23#Niven Cho -end

	if (PStore_CheckSection(PS_SYS_PARAM, &error) != E_PS_OK) {
		UIInfoErrMsg("PStore_CheckSection\r\n");
	}

	if (error != E_PS_OK) {
		UIInfoErrMsg("PStore error msg :%x\r\n", error);
		{
			UINT32 BufSize = 0x1800000;
			UINT8 *pBuf = (UINT8 *)SxCmd_GetTempMem(BufSize);

			if (!pBuf) {
				UIInfoErrMsg("pBuf is NULL\r\n");
				return;
			}
			//open file system for save file
			//Dep_Fs_Init(TRUE,TRUE);
			PStore_Dump(pBuf, BufSize);
            SxCmd_RelTempMem((UINT32)pBuf);
		}
		Ux_DumpEvents();
//        while (1);
	}
#endif
}

void Reset_MenuInfo(void)
{
CHKPNT;
	SysResetFlag();             // reset system flags
	SysExeMenuSettingFuncs();   // execute menu setting related functions

	/* After reset, save to NAND */
	Save_MenuInfo();
}
void Reset_MenuInfo_AfUploadFW(void)
{
	PPSTORE_SECTION_HANDLE  pSection;
	if ((pSection = PStore_OpenSection(PS_SYS_PARAM, PS_RDWR)) != E_PS_SECHDLER) {
		UINT32 uiPsFreeSpace = PStore_GetInfo(PS_INFO_FREE_SPACE);
		PStore_ReadSection((UINT8 *)&currentInfo, 0, sizeof(UIMenuStoreInfo), pSection);
		if (uiPsFreeSpace) {
			debug_msg("PStore reset info.\r\n");
			memset(&currentInfo, 0, sizeof(currentInfo));
			currentInfo.uhInfoSize = sizeof(UIMenuStoreInfo);
			SysResetFlag();
			PStore_WriteSection((UINT8 *)&currentInfo, 0, sizeof(UIMenuStoreInfo), pSection);
			PStore_CloseSection(pSection);
		}
	}
}
void Init_SysInfo(void)
{
	UIInfoTraceMsg("[Init_SysInfo][NAND update state]\r\n");
}

void Init_MenuInfo(void)
{
CHKPNT;
	UIInfoTraceMsg("[Init_MenuInfo][PStore update state]\r\n");
	UIInfoTraceMsg("Version %s  %d\r\n", currentInfo.pVersion, currentInfo.uhInfoSize);

	SysCheckFlag();             // check flag (limit value)
	SysSetFixedFlag();          // set fixed flag
	SysSetFixedFlagSysInit();   // set fixed flag for system init only
	SysExeMenuSettingFuncs();   // execute menu setting related functions
//	debug_msg("FL_LCD_BRIGHTNESS:%d \r\n",SysGetFlag(FL_LCD_BRIGHTNESS));

}

UIMenuStoreInfo *UI_GetMenuInfo(void)
{
	return &currentInfo;
}
#if 0
UINT32 UI_GetData(UINT32 attribute)
{
	UIInfoTraceMsg("get UIParam[%d]\r\n", attribute);
#if (_FPGA_EMULATION_ == ENABLE)
	if (attribute == FL_MOVIE_SIZE) {
		return MOVIE_SIZE_VGA;    // VGA only
	}
#endif
	return currentInfo.UIParameter[attribute];
}
void UI_SetData(UINT32 attribute, UINT32 value)
{
	UIInfoTraceMsg("set UIParam[%d]= %d\r\n", attribute, value);
	currentInfo.UIParameter[attribute] = value;
}
#endif
//-----------------------------------------------------------------------------
// Get USB connect type but naming is backward compatible for NT96220
//-----------------------------------------------------------------------------
/**
  Return AC plug in or unplugged

  Return AC plug in or unplugged.
  TRUE  -> AC plug in.
  FALSE -> AC is unplugged.

  @param void
  @return BOOL: TRUE -> AC plug in, FALSE -> AC is unplugged
*/
BOOL KeyScan_IsACIn(void)
{
	BOOL bACStatus;

	if (GxUSB_GetConnectType() == USB_CONNECT_CHARGER) {
		bACStatus = TRUE;
	} else {
		bACStatus = FALSE;
	}

	return bACStatus;
}

//-----------------------------------------------------------------------------
// Auto Poweroff/USB detect/Enable Key sound scan items
//-----------------------------------------------------------------------------
void KeyScan_EnableMisc(BOOL bEn)
{
	if (bEn == FALSE) {
		// disable auto power off/USB detect timer
		// disable key tone flag
		GxPower_SetControl(GXPWR_CTRL_AUTOPOWEROFF_RESET, 0);
		GxPower_SetControl(GXPWR_CTRL_SLEEP_RESET, 0);
		SxTimer_SetFuncActive(SX_TIMER_DET_AUTOPOWEROFF_ID, FALSE);
#if (USB_MODE == ENABLE)
		SxTimer_SetFuncActive(SX_TIMER_DET_USB_ID, FALSE);
#endif
		//UISound_EnableKey(FALSE); // 660 is full-duplex for audio
	} else {
		// enable auto power off/USB detect timer
		// enable key tone flag
		//#NT#2016/11/21#Adam Su -begin
		//#NT#Fix Mantis Issue 0113246
		SxTimer_SetFuncActive(SX_TIMER_DET_AUTOPOWEROFF_ID, TRUE);
		//#NT#2016/11/21#Adam Su -end
#if (USB_MODE == ENABLE)
		SxTimer_SetFuncActive(SX_TIMER_DET_USB_ID, TRUE);
#endif
		//UISound_EnableKey(TRUE); // 660 is full-duplex for audio
	}
}


//-----------------------------------------------------------------------------
// Battery Level
//-----------------------------------------------------------------------------
UINT32 GetBatteryLevel(void)
{

	if (KeyScan_IsACIn()) {
		guiBatteryLevel = BATTERY_CHARGE;
	} else {
		switch (GxPower_GetControl(GXPWR_CTRL_BATTERY_LEVEL)) {
		case VOLDET_BATTERY_LVL_4:
			guiBatteryLevel = BATTERY_FULL;
			break;
		case VOLDET_BATTERY_LVL_3:
			guiBatteryLevel = BATTERY_MED;
			break;
		case VOLDET_BATTERY_LVL_2:
			guiBatteryLevel = BATTERY_LOW;
			break;
		case VOLDET_BATTERY_LVL_1:
			guiBatteryLevel = BATTERY_EMPTY;
			break;

		case VOLDET_BATTERY_LVL_0:
			guiBatteryLevel = BATTERY_EXHAUSTED;
			break;
		}
	}

	return guiBatteryLevel;
}

//-----------------------------------------------------------------------------
// Set/Get System Flags
//-----------------------------------------------------------------------------
void SysSetFlag(UINT32 uiFlag, UINT32 uiValue)
{
	currentInfo.UIParameter[uiFlag] = uiValue;
}

UINT32 SysGetFlag(UINT32 uiFlag)
{
	return (currentInfo.UIParameter[uiFlag]);
}

static void SysLimitFlag(UINT32 uiFlag, UINT32 uiMinId, UINT32 uiMaxId, UINT32 uiDefaultId)
{
	UINT32  uiValue = SysGetFlag(uiFlag);

	if ((uiValue < uiMinId) || (uiValue > uiMaxId - 1)) {
		uiValue = uiDefaultId;
	}

	SysSetFlag(uiFlag, uiValue);
}

void SysCheckFlag(void)
{
	// Check and limit system flag value
	// Photo
	SysLimitFlag(FL_PHOTO_SIZE,         0,  PHOTO_SIZE_ID_MAX,          DEFAULT_PHOTO_SIZE);
	SysLimitFlag(FL_SCENE,              0,  SCENE_ID_MAX,               DEFAULT_SCENE);
	SysLimitFlag(FL_QUALITY,            0,  QUALITY_ID_MAX,             DEFAULT_PHOTO_QUALITY);
	SysLimitFlag(FL_SELFTIMER,          0,  SELFTIMER_ID_MAX,           DEFAULT_SELFTIMER);
	SysLimitFlag(FL_ANTISHAKE,          0,  ANTISHAKE_ID_MAX,           DEFAULT_ANTISHAKING);
	SysLimitFlag(FL_FD,                 0,  FD_ID_MAX,                  DEFAULT_FD);
	SysLimitFlag(FL_WB,                 0,  WB_ID_MAX,                  DEFAULT_WB);
	SysLimitFlag(FL_COLOR_EFFECT,       0,  COLOR_EFFECT_ID_MAX,        DEFAULT_PHOTO_COLOR);
	SysLimitFlag(FL_CONTINUE_SHOT,      0,  CONTINUE_SHOT_SETTING_MAX,  DEFAULT_CONTINUE_SHOT);
	SysLimitFlag(FL_SHARPNESS,          0,  SHARPNESS_ID_MAX,           DEFAULT_SHARPNESS);
	SysLimitFlag(FL_EV,                 0,  EV_SETTING_MAX,             DEFAULT_EV);
	SysLimitFlag(FL_ISO,                0,  ISO_ID_MAX,                 DEFAULT_ISO);
	SysLimitFlag(FL_METERING,           0,  METERING_ID_MAX,            DEFAULT_METERING);

	// Movie
	SysLimitFlag(FL_MOVIE_PARK,         0,  MOVIE_PARK_ID_MAX,          DEFAULT_MOVIE_PARK);
	SysLimitFlag(FL_MOVIE_BACKADJUST,         0,  MOVIE_BACKADJUST_ID_MAX,          DEFAULT_MOVIE_BACKADJUST);
	SysLimitFlag(FL_MOVIE_BACKADJUST_MENU,         0,  MOVIE_BACKADJUST_ID_MAX,          DEFAULT_MOVIE_BACKADJUST);

	SysLimitFlag(FL_MOVIE_SIZE,         0,  MOVIE_SIZE_ID_MAX,          DEFAULT_MOVIE_SIZE);
	SysLimitFlag(FL_MOVIE_CYCLIC_REC,   0,  MOVIE_CYCLICREC_ID_MAX,     DEFAULT_MOVIE_CYCLICREC);
	SysLimitFlag(FL_MOVIE_MOTION_DET,   0,  MOVIE_MOTIONDET_ID_MAX,     DEFAULT_MOVIE_MOTION_DET);
	SysLimitFlag(FL_MOVIE_AUDIO,        0,  MOVIE_AUDIO_ID_MAX,         DEFAULT_MOVIE_AUDIO);
	SysLimitFlag(FL_MOVIE_DATEIMPRINT,  0,  MOVIE_DATEIMPRINT_ID_MAX,   DEFAULT_MOVIE_DATEIMPRINT);
	SysLimitFlag(FL_MOVIE_HDR,          0,  MOVIE_HDR_ID_MAX,           DEFAULT_MOVIE_HDR);
	SysLimitFlag(FL_MOVIE_WDR,          0,  MOVIE_WDR_ID_MAX,           DEFAULT_MOVIE_WDR);
	SysLimitFlag(FL_MOVIE_DEFOG,          0,  MOVIE_DEFOG_ID_MAX,           DEFAULT_MOVIE_DEFOG);
	SysLimitFlag(FL_MOVIE_SENSOR_ROTATE, 0,  SEN_ROTATE_MAX,             DEFAULT_SENSOR_ROTATE);
	SysLimitFlag(FL_MovieAudioRecIndex, 0,  MOVIE_VOL_MAX,              DEFAULT_MOVIE_REC_VOLUME);
	SysLimitFlag(FL_MovieAudioRec,      0,  MOVIE_AUD_REC_ID_MAX,       DEFAULT_MOVIE_REC_AUD);
	//#NT#2016/06/14#Charlie Chang -begin
	//#NT#support contrast, audio in, audio in sample rate, flip, movie quality set
	SysLimitFlag(FL_MOVIE_CONTRAST,      0,       MOVIE_CONTRAST_ID_MAX,          DEFAULT_MOVIE_CONTRAST);
	SysLimitFlag(FL_MOVIE_AUDIOIN,      0,       MOVIE_AUDIOIN_ID_MAX,           DEFAULT_MOVIE_AUDIOIN);
	SysLimitFlag(FL_MOVIE_AUDIOIN_SR,   0,       MOVIE_AUDIOIN_SR_ID_MAX,        DEFAULT_MOVIE_AUDIOIN_SR);
	SysLimitFlag(FL_MOVIE_FLIP_MIRROR,   0,      MOVIE_FLIP_MIRROR_ID_MAX,       DEFAULT_MOVIE_FLIP_MIRROR);
	SysLimitFlag(FL_MOVIE_QUALITY_SET,   0,  MOVIE_QUALITY_SET_ID_MAX,       DEFAULT_MOVIE_QUALITY_SET);
	//#NT#2016/06/14#Charlie Chang -end
	//#NT#2017/03/03#Jeah Yen -begin
	//#NT# support sbs mode
	SysLimitFlag(FL_MOVIE_SBS_MODE,   0,  MOVIE_SBS_ID_MAX,       DEFAULT_MOVIE_SBS_MODE);
	//#NT#2017/03/03#Jeah Yen -end
	SysLimitFlag(FL_MOVIE_CODEC,   0,  MOVIE_CODEC_ID_MAX,     DEFAULT_MOVIE_CODEC);
	//SysLimitFlag(FL_SENSOR1_DISP_OFFSET,   0,  SEN_DISP_OFFSET_SETTING_MAX,	   DEFAULT_SENSOR_1_DISP_OFFSET);
	//zjf add 210305
	SysLimitFlag(FL_SENSOR1_DISP_OFFSET,   0,  IMG_DISP_POS_MAX,    DEFAULT_SENSOR_1_DISP_OFFSET);
	SysLimitFlag(FL_SENSOR2_DISP_OFFSET,   0,  SEN_DISP_OFFSET_SETTING_MAX,	   DEFAULT_SENSOR_1_DISP_OFFSET);
	// Playback
	SysLimitFlag(FL_PROTECT,            0,  FILE_PROTECT_ID_MAX,    DEFAULT_PROTECT);
	SysLimitFlag(FL_MovieAudioPlayIndex, 0,  MOVIE_AUDIO_VOL_SETTING_MAX,    DEFAULT_MOVIE_PLAY_VOLUME);

	// System
	SysLimitFlag(FL_AudioPlayIndex,     0,  AUDIO_VOL_MAX,          DEFAULT_AUDIO_PLAY_VOLUME);
	SysLimitFlag(FL_LANGUAGE,           0,  LANG_ID_MAX,            DEFAULT_LANGUAGE);
	SysLimitFlag(FL_BEEP,               0,  BEEP_ID_MAX,            DEFAULT_BEEP);
	SysLimitFlag(FL_AUTO_POWER_OFF,     0,  POWEROFF_SETTING_MAX,   DEFAULT_AUTO_POWER_OFF);
	SysLimitFlag(FL_FREQUENCY,          0,  FREQUENCY_ID_MAX,       DEFAULT_FREQUENCY);
	SysLimitFlag(FL_TV_MODE,            0,  TV_MODE_ID_MAX,         DEFAULT_TV_MODE);
	SysLimitFlag(FL_DualDisp,           0,  DUALDISP_SETTING_MAX,   DEFAULT_DUALDISP);

	SysLimitFlag(FL_DATE_FORMAT,        0,  DATE_FORMAT_ID_MAX,     DEFAULT_DATE_FORMAT);
	SysLimitFlag(FL_OPENING_LOGO,       0,  OPENING_LOGO_ID_MAX,    DEFAULT_OPENING_LOGO);
	SysLimitFlag(FL_LCD_DISPLAY,        0,  DISPOUT_ID_MAX,         DEFAULT_LCD_DISPLAY);
	SysLimitFlag(FL_MACRO,              0,  MACRO_ID_MAX,           DEFAULT_MACRO);
	SysLimitFlag(FL_USB_MODE,           0,  USB_MODE_ID_MAX,        DEFAULT_USB_MODE);

	// Sepcial flags
	SysLimitFlag(FL_DCF_DIR_ID,         MIN_DCF_DIR_NUM,    MAX_DCF_DIR_NUM,    MIN_DCF_DIR_NUM);
	SysLimitFlag(FL_DCF_FILE_ID,        MIN_DCF_FILE_NUM,   MAX_DCF_FILE_NUM,   MIN_DCF_FILE_NUM);

	//Wi-Fi
#if (WIFI_FINALCAM_APP_STYLE == ENABLE || UCTRL_APP_MOVIE_FEATURE_SETGET == ENABLE || YOUKU_SDK == ENABLE)
	SysLimitFlag(FL_WIFI_MOVIE_APP_PREVIEW_SIZE, 0,  WIFI_MOVIE_APP_PREVIEW_SIZE_ID_MAX, DEFAULT_MOVIE_WIFI_APP_PREVIEW_SIZE);
#endif
	SysLimitFlag(FL_WIFI_AUTO_RECORDING, 0,  WIFI_AUTO_RECORDING_ID_MAX, DEFAULT_MOVIE_WIFI_AUTO_RECORDING_OPTION);
	SysLimitFlag(FL_NetWorkMode, 0, NET_MODE_SETTING_MAX, DEFAULT_WIFI_MODE);

//#MT#lyb -20200328 -begin
    SysLimitFlag(FL_VOLUME,         0,  VOLUME_ID_MAX,      DEFAULT_VOLUME);
    SysLimitFlag(FL_SCREENLIGHT,    0,  SCREENLIGHT_ID_MAX, DEFAULT_SCREENLIGHT);
    SysLimitFlag(FL_ALARM_LCA,      0,  ALARM_LCA_ID_MAX,   DEFAULT_ALARM_LCA);
//#MT#lyb -20200328 -end
#if(_ANFA_ADAS_MENU_)
    SysLimitFlag(FL_ANFA_ADAS,      0,  ANFA_ADAS_ID_MAX,   DEFAULT_ANFA_ADAS);
#endif
    SysLimitFlag(FL_BeepVolumnIndex,	0,  BEEP_VOL_SETTING_MAX,	DEFAULT_BeepVolumnIndex);

	SysLimitFlag(FL_WIFI,	 0,  WIFI_ID_MAX,			  DEFAULT_AUTO_WIFI);
	SysLimitFlag(FL_LCD_BRIGHTNESS,     0,  LCDBRT_LVL_ID_MAX,      DEFAULT_LCD_BRIGHTNESS);

	SysLimitFlag(FL_IMGDISP_POS_STEP_ID0,     0,  IMG_DISP_POS_MAX,      DEFAULT_IMGDISP_POS_ID0);
	SysLimitFlag(FL_IMGDISP_POS_STEP_ID1,     0,  IMG_DISP_POS_MAX,      DEFAULT_IMGDISP_POS_ID1);

	//SysSetFlag(FL_LCD_BRIGHTNESS,          DEFAULT_LCD_BRIGHTNESS);


}

void SysSetFixedFlag(void)
{
	// Fixed some system flags as system reset

	// Photo
	SysSetFlag(FL_CONTINUE_SHOT,           DEFAULT_CONTINUE_SHOT);
	SysSetFlag(FL_SELFTIMER,               DEFAULT_SELFTIMER);

	// Movie

	// Playback
	SysSetFlag(FL_PROTECT,                 DEFAULT_PROTECT);

	// System
	SysSetFlag(FL_LCD_DISPLAY,             DEFAULT_LCD_DISPLAY);
	SysSetFlag(FL_LCD_BRIGHTNESS,          DEFAULT_LCD_BRIGHTNESS);
	SysSetFlag(FL_MovieDisIndex,           MOVIE_DIS_OFF);

	SysSetFlag(FL_COMMON_LOCAL,            WIFI_OFF);
	SysSetFlag(FL_IsCloneRec,              CLONE_REC_OFF);

//	SysSetFlag(FL_IMGDISP_POS_STEP_ID0,  DEFAULT_IMGDISP_POS_ID0);
//	SysSetFlag(FL_IMGDISP_POS_STEP_ID1,  DEFAULT_IMGDISP_POS_ID1);

#if 0 // unnecessary
	if (System_GetState(SYS_STATE_CARD)  == CARD_REMOVED) {
		SysSetFlag(FL_PHOTO_SIZE, PHOTO_SIZE_5M);
		SysSetFlag(FL_MOVIE_SIZE, MOVIE_SIZE_720P);
	}
#endif
}

void SysSetFixedFlagSysInit(void)
{
	// Set fixed system flags (only on system init)
	SysSetFlag(FL_WIFI_LINK,            WIFI_LINK_NG);
	SysSetFlag(FL_DUAL_CAM,             SysGetFlag(FL_DUAL_CAM_MENU));
	SysSetFlag(FL_MOVIE_SIZE, SysGetFlag(FL_MOVIE_SIZE_MENU));
	SysSetFlag(FL_MOVIE_HDR, SysGetFlag(FL_MOVIE_HDR_MENU));
	SysSetFlag(FL_MOVIE_WDR, SysGetFlag(FL_MOVIE_WDR_MENU));
	SysSetFlag(FL_MOVIE_DEFOG, SysGetFlag(FL_MOVIE_DEFOG_MENU));
	SysSetFlag(FL_MovieRSCIndex, SysGetFlag(FL_MovieRSCIndex_MENU));
	SysSetFlag(FL_NetWorkMode,          DEFAULT_WIFI_MODE);  // Reset Wi-Fi mode to AP mode.
	//#NT#2016/07/12#KCHong#[0104994] -begin
	//#NT#Use FL_MOVIE_LDWS_MENU & FL_MOVIE_FCW_MENU instead of FL_MOVIE_LDWS & FL_MOVIE_FCW
	SysSetFlag(FL_MOVIE_LDWS, SysGetFlag(FL_MOVIE_LDWS_MENU));
	SysSetFlag(FL_MOVIE_FCW, SysGetFlag(FL_MOVIE_FCW_MENU));
	//#NT#2016/07/12#KCHong#[0104994] -end
	//#NT#2016/07/26#KCHong#[0105955] -begin
	//#NT#If ADAS is ON and timelapse changes to OFF, reopen movie mode
	SysSetFlag(FL_MOVIE_TIMELAPSE_REC, SysGetFlag(FL_MOVIE_TIMELAPSE_REC_MENU));
	//#NT#2016/07/26#KCHong#[0105955] -end
	//#NT#2016/08/19#Lincy Lin#[0106935] -begin
	//#NT# Support change WDR, SHDR, RSC setting will change mode after exit menu
	SysSetFlag(FL_RSC,             SysGetFlag(FL_RSC_MENU));
	SysSetFlag(FL_WDR,             SysGetFlag(FL_WDR_MENU));
	SysSetFlag(FL_SHDR,            SysGetFlag(FL_SHDR_MENU));
	//#NT#2016/08/19#Lincy Lin -end
	SysSetFlag(FL_DEFOG,            SysGetFlag(FL_DEFOG_MENU));
	SysSetFlag(FL_MOVIE_CODEC,            SysGetFlag(FL_MOVIE_CODEC_MENU));
	SysSetFlag(FL_LCD_BRIGHTNESS,   SysGetFlag(FL_LCD_BRIGHTNESS));
	
	SysSetFlag(FL_MOVIE_CYCLIC_REC ,  SysGetFlag(FL_MOVIE_CYCLIC_REC_MENU) );

	SysSetFlag(FL_IMGDISP_POS_STEP_ID0,  SysGetFlag(FL_IMGDISP_POS_STEP_ID0));
	SysSetFlag(FL_IMGDISP_POS_STEP_ID1,  SysGetFlag(FL_IMGDISP_POS_STEP_ID1));


}

void SysResetFlag(void)
{
	// Set system flag default value here
	// Photo
	SysSetFlag(FL_PHOTO_SIZE,           DEFAULT_PHOTO_SIZE);
	SysSetFlag(FL_QUALITY,              DEFAULT_PHOTO_QUALITY);
	SysSetFlag(FL_COLOR_EFFECT,         DEFAULT_PHOTO_COLOR);
	SysSetFlag(FL_SCENE,                DEFAULT_SCENE);
	SysSetFlag(FL_EV,                   DEFAULT_EV);
	SysSetFlag(FL_ISO,                  DEFAULT_ISO);
	SysSetFlag(FL_WB,                   DEFAULT_WB);
	SysSetFlag(FL_METERING,             DEFAULT_METERING);
	SysSetFlag(FL_SHARPNESS,            DEFAULT_SHARPNESS);
	SysSetFlag(FL_SATURATION,           DEFAULT_SATURATION);
	SysSetFlag(FL_FD,                   DEFAULT_FD);
	SysSetFlag(FL_ANTISHAKE,            DEFAULT_ANTISHAKING);
	SysSetFlag(FL_RSC,                  DEFAULT_RSC);
	SysSetFlag(FL_WDR,                  DEFAULT_WDR);
	SysSetFlag(FL_DUAL_CAM_MENU,        DEFAULT_DUAL_CAM);
	SysSetFlag(FL_QUICK_REVIEW,         DEFAULT_QUICK_REVIEW);
	SysSetFlag(FL_DATE_STAMP,           DEFAULT_DATE_STAMP);
	SysSetFlag(FL_SELFTIMER,            DEFAULT_SELFTIMER);
	SysSetFlag(FL_FLASH_MODE,           DEFAULT_FLASH_MODE);
	SysSetFlag(FL_CONTINUE_SHOT,       DEFAULT_CONTINUE_SHOT);
	SysSetFlag(FL_SHDR,                 DEFAULT_SHDR);
	//#NT#2016/08/19#Lincy Lin#[0106935] -begin
	//#NT# Support change WDR, SHDR, RSC setting will change mode after exit menu
	SysSetFlag(FL_RSC_MENU,             DEFAULT_RSC);
	SysSetFlag(FL_WDR_MENU,             DEFAULT_WDR);
	SysSetFlag(FL_SHDR_MENU,            DEFAULT_SHDR);
	//#NT#2016/08/19#Lincy Lin -end

	SysSetFlag(FL_DEFOG,            DEFAULT_DEFOG);

	// Movie
	SysSetFlag(FL_MOVIE_PARK,           DEFAULT_MOVIE_PARK);
       SysSetFlag(FL_MOVIE_BACKADJUST,           DEFAULT_MOVIE_BACKADJUST);
       SysSetFlag(FL_MOVIE_BACKADJUST_MENU,           DEFAULT_MOVIE_BACKADJUST);
		SysSetFlag(FL_WIFI,              	DEFAULT_AUTO_WIFI);

	if (System_GetEnableSensor() == (SENSOR_1 | SENSOR_2)) {
		SysSetFlag(FL_MOVIE_SIZE_MENU,           DEFAULT_MOVIE_SIZE_DUAL);
	} else {
		SysSetFlag(FL_MOVIE_SIZE_MENU,           DEFAULT_MOVIE_SIZE);
	}
	SysSetFlag(FL_MOVIE_QUALITY,        DEFAULT_MOVIE_QUALITY);
	SysSetFlag(FL_MOVIE_COLOR,          DEFAULT_MOVIE_COLOR);
	SysSetFlag(FL_MOVIE_CYCLIC_REC,     DEFAULT_MOVIE_CYCLICREC);
	SysSetFlag(FL_MOVIE_CYCLIC_REC_MENU,     DEFAULT_MOVIE_CYCLICREC);

	SysSetFlag(FL_MOVIE_MOTION_DET,     DEFAULT_MOVIE_MOTION_DET);
	SysSetFlag(FL_MOVIE_AUDIO,          DEFAULT_MOVIE_AUDIO);
	SysSetFlag(FL_MOVIE_DATEIMPRINT,    DEFAULT_MOVIE_DATEIMPRINT);
	SysSetFlag(FL_MOVIE_HDR_MENU,            DEFAULT_MOVIE_HDR);
	SysSetFlag(FL_MOVIE_WDR_MENU,            DEFAULT_MOVIE_WDR);
	SysSetFlag(FL_MOVIE_DEFOG_MENU, 		DEFAULT_MOVIE_DEFOG);
	SysSetFlag(FL_MovieRSCIndex_MENU,        DEFAULT_MOVIE_RSC);
	SysSetFlag(FL_MOVIE_SENSOR_ROTATE,  DEFAULT_SENSOR_ROTATE);
	SysSetFlag(FL_MovieMCTFIndex,       DEFAULT_MCTFINDEX);
	SysSetFlag(FL_MOVIE_PTZ,                   DEFAULT_MOVIE_PTZ);
	SysSetFlag(FL_MOVIE_URGENT_PROTECT_AUTO,   DEFAULT_MOVIE_URGENT_PROTECT_AUTO);
	SysSetFlag(FL_MOVIE_URGENT_PROTECT_MANUAL, DEFAULT_MOVIE_URGENT_PROTECT_MANUAL);
	SysSetFlag(FL_MOVIE_IR_CUT,         DEFAULT_IR_CUT);
	//#NT#2016/07/26#KCHong#[0105955] -begin
	//#NT#If ADAS is ON and timelapse changes to OFF, reopen movie mode
	SysSetFlag(FL_MOVIE_TIMELAPSE_REC_MENU,  DEFAULT_MOVIE_TIMELAPSE_REC);
	//#NT#2016/07/26#KCHong#[0105955] -end
	SysSetFlag(FL_MOVIE_PIM,            DEFAULT_MOVIE_PIM);
	//#NT#2016/07/12#KCHong#[0104994] -begin
	//#NT#Use FL_MOVIE_LDWS_MENU & FL_MOVIE_FCW_MENU instead of FL_MOVIE_LDWS & FL_MOVIE_FCW
	SysSetFlag(FL_MOVIE_LDWS_MENU,      DEFAULT_MOVIE_LDWS);
	SysSetFlag(FL_MOVIE_FCW_MENU,       DEFAULT_MOVIE_FCWS);
	//#NT#2016/07/12#KCHong#[0104994] -end
	SysSetFlag(FL_MovieAudioRecIndex,   DEFAULT_MOVIE_REC_VOLUME);
	SysSetFlag(FL_MovieAudioRec,        DEFAULT_MOVIE_REC_AUD);
	SysSetFlag(FL_MOVIE_DDD,                   DEFAULT_MOVIE_DDD);
	SysSetFlag(FL_MOVIE_ADAS_CAL,              DEFAULT_MOVIE_ADAS_CAL);
	SysSetFlag(FL_MOVIE_CODEC,                  DEFAULT_MOVIE_CODEC);
	SysSetFlag(FL_MOVIE_CODEC_MENU,                  DEFAULT_MOVIE_CODEC);
	SysSetFlag(FL_SENSOR1_DISP_OFFSET,          DEFAULT_SENSOR_1_DISP_OFFSET);
	SysSetFlag(FL_SENSOR2_DISP_OFFSET,          DEFAULT_SENSOR_2_DISP_OFFSET);

	// Playback
	SysSetFlag(FL_PROTECT,              DEFAULT_PROTECT);
	SysSetFlag(FL_MovieAudioPlayIndex,  DEFAULT_MOVIE_PLAY_VOLUME);

	// System
	SysSetFlag(FL_AudioPlayIndex,       DEFAULT_AUDIO_PLAY_VOLUME);
	SysSetFlag(FL_AUTO_POWER_OFF,       DEFAULT_AUTO_POWER_OFF);
	SysSetFlag(FL_LCD_OFF,              DEFAULT_LCD_OFF);
	SysSetFlag(FL_BEEP,                 DEFAULT_BEEP);
	SysSetFlag(FL_LANGUAGE,             DEFAULT_LANGUAGE);
	SysSetFlag(FL_FREQUENCY,            DEFAULT_FREQUENCY);
	SysSetFlag(FL_TV_MODE,              DEFAULT_TV_MODE);
	SysSetFlag(FL_HDMI_MODE,            DEFAULT_HDMI_MODE);
	SysSetFlag(FL_DATE_FORMAT,          DEFAULT_DATE_FORMAT);
	SysSetFlag(FL_OPENING_LOGO,         DEFAULT_OPENING_LOGO);
	SysSetFlag(FL_CPU2_DEFAULT,         1);

	SysSetFlag(FL_LCD_DISPLAY,          DEFAULT_LCD_DISPLAY);
	SysSetFlag(FL_LCD_BRIGHTNESS,       DEFAULT_LCD_BRIGHTNESS);
	SysSetFlag(FL_DualDisp,             DEFAULT_DUALDISP);
	SysSetFlag(FL_MACRO,                DEFAULT_MACRO);
	SysSetFlag(FL_USB_MODE,             DEFAULT_USB_MODE);
	SysSetFlag(FL_GSENSOR,              DEFAULT_GSENSOR);
	SysSetFlag(FL_EDGE,                 DEFAULT_EDGE);
	SysSetFlag(FL_NR,                   DEFAULT_NR);

	//#NT#2016/06/14#Charlie Chang -begin
	//#NT#support contrast, two way audio in and sample rate, flip, movie qualiity set
	SysSetFlag(FL_MOVIE_CONTRAST,       DEFAULT_MOVIE_CONTRAST);
	SysSetFlag(FL_MOVIE_AUDIOIN,       DEFAULT_MOVIE_AUDIOIN);
	SysSetFlag(FL_MOVIE_AUDIOIN_SR,       DEFAULT_MOVIE_AUDIOIN_SR);
	SysSetFlag(FL_MOVIE_FLIP_MIRROR,       DEFAULT_MOVIE_FLIP_MIRROR);
	SysSetFlag(FL_MOVIE_QUALITY_SET,       DEFAULT_MOVIE_QUALITY_SET);
	//#NT#2016/06/14#Charlie Chang -end
	//#NT#2017/03/03#Jeah Yen -begin
	//#NT# support sbs mode
	SysSetFlag(FL_MOVIE_SBS_MODE,   DEFAULT_MOVIE_SBS_MODE);
	//#NT#2017/03/03#Jeah Yen -end
	// Wi-Fi
#if (WIFI_FINALCAM_APP_STYLE == ENABLE || UCTRL_APP_MOVIE_FEATURE_SETGET == ENABLE || YOUKU_SDK == ENABLE)
	SysSetFlag(FL_WIFI_MOVIE_APP_PREVIEW_SIZE, DEFAULT_MOVIE_WIFI_APP_PREVIEW_SIZE);
#endif
	SysSetFlag(FL_WIFI_AUTO_RECORDING, DEFAULT_MOVIE_WIFI_AUTO_RECORDING_OPTION);
	SysSetFlag(FL_NetWorkMode, DEFAULT_WIFI_MODE); // Reset To Wi-Fi mode to AP mode.


	SysSetFlag(FL_ETHCAM_TX_IP_ADDR, 		DEFAULT_ETHCAM_TX_IP_ADDR);


//#MT#lyb -20200328 -begin
    SysSetFlag(FL_VOLUME,         DEFAULT_VOLUME);
    SysSetFlag(FL_SCREENLIGHT,    DEFAULT_SCREENLIGHT);
    SysSetFlag(FL_ALARM_LCA,      DEFAULT_ALARM_LCA);
//#MT#lyb -20200328 -end
#if(_ANFA_ADAS_MENU_)
	SysSetFlag(FL_ANFA_ADAS,	  DEFAULT_ANFA_ADAS);
#endif
    SysSetFlag(FL_BeepVolumnIndex,      DEFAULT_BeepVolumnIndex);
//	SysSetFlag(FL_IMGDISP_POS_STEP_ID0,  DEFAULT_IMGDISP_POS_ID0);
//	SysSetFlag(FL_IMGDISP_POS_STEP_ID1,  DEFAULT_IMGDISP_POS_ID1);

	SysSetFixedFlag();

}

void SysExeMenuSettingFuncs(void)
{
//CHKPNT;
#if (PHOTO_MODE==ENABLE)
	/*--- Photo ---*/
	Ux_SendEvent(&CustomPhotoObjCtrl, NVTEVT_EXE_QUALITY,        1,  SysGetFlag(FL_QUALITY));
	Ux_SendEvent(&CustomPhotoObjCtrl, NVTEVT_EXE_ISO,            1,  SysGetFlag(FL_ISO));
	Ux_SendEvent(&CustomPhotoObjCtrl, NVTEVT_EXE_EV,             1,  SysGetFlag(FL_EV));
	Ux_SendEvent(&CustomPhotoObjCtrl, NVTEVT_EXE_WB,             1,  SysGetFlag(FL_WB));
	Ux_SendEvent(&CustomPhotoObjCtrl, NVTEVT_EXE_COLOR,          1,  SysGetFlag(FL_COLOR_EFFECT));
	Ux_SendEvent(&CustomPhotoObjCtrl, NVTEVT_EXE_METERING,       1,  SysGetFlag(FL_METERING));
	Ux_SendEvent(&CustomPhotoObjCtrl, NVTEVT_EXE_FD,             1,  SysGetFlag(FL_FD));
	Ux_SendEvent(&CustomPhotoObjCtrl, NVTEVT_EXE_CAPTURE_SIZE,   1,  SysGetFlag(FL_PHOTO_SIZE));
	Ux_SendEvent(&CustomPhotoObjCtrl, NVTEVT_EXE_SCENEMODE,      1,  SysGetFlag(FL_SCENE));
	Ux_SendEvent(&CustomPhotoObjCtrl, NVTEVT_EXE_SHARPNESS,      1,  SysGetFlag(FL_SHARPNESS));
	Ux_SendEvent(&CustomPhotoObjCtrl, NVTEVT_EXE_SATURATION,     1,  SysGetFlag(FL_SATURATION));
	Ux_SendEvent(&CustomPhotoObjCtrl, NVTEVT_EXE_DUALCAM,        1,  SysGetFlag(FL_DUAL_CAM));
#endif

	/*--- Movie ---*/
	Ux_SendEvent(&CustomMovieObjCtrl, NVTEVT_EXE_MOVIEQUALITY,   1,      SysGetFlag(FL_MOVIE_QUALITY));
	Ux_SendEvent(&CustomMovieObjCtrl, NVTEVT_EXE_MOVIECOLOR,     1,      SysGetFlag(FL_MOVIE_COLOR));
	CHKPNT;
	DBGD(SysGetFlag(FL_DUAL_CAM));
	Ux_SendEvent(&CustomMovieObjCtrl, NVTEVT_EXE_DUALCAM,        1,      SysGetFlag(FL_DUAL_CAM));

	/* Cyclic recording/record with mute or sound/DateImptint/Motion Detect */
	Ux_SendEvent(&CustomMovieObjCtrl,   NVTEVT_EXE_CYCLIC_REC,          1,  SysGetFlag(FL_MOVIE_CYCLIC_REC));
	Ux_SendEvent(&CustomMovieObjCtrl,   NVTEVT_EXE_MOTION_DET,          1,  SysGetFlag(FL_MOVIE_MOTION_DET));
	Ux_SendEvent(&CustomMovieObjCtrl,   NVTEVT_EXE_MOVIE_DATE_IMPRINT,  1,  SysGetFlag(FL_MOVIE_DATEIMPRINT));
	Ux_SendEvent(&CustomMovieObjCtrl,   NVTEVT_EXE_MOVIE_AUDIO,         1,  SysGetFlag(FL_MOVIE_AUDIO));
	Ux_SendEvent(&CustomMovieObjCtrl,   NVTEVT_EXE_MOVIE_MCTF,          1,  SysGetFlag(FL_MovieMCTFIndex));
	Ux_SendEvent(&CustomMovieObjCtrl,   NVTEVT_EXE_GSENSOR,             1,  SysGetFlag(FL_GSENSOR));
	Ux_SendEvent(&CustomMovieObjCtrl,   NVTEVT_EXE_MOVIE_SENSOR_ROTATE, 1,  SysGetFlag(FL_MOVIE_SENSOR_ROTATE));
	Ux_SendEvent(&CustomMovieObjCtrl,   NVTEVT_EXE_MOVIE_IR_CUT,        1,  SysGetFlag(FL_MOVIE_IR_CUT));
	Ux_SendEvent(&CustomMovieObjCtrl,   NVTEVT_EXE_MOVIE_PROTECT_AUTO,  1,  SysGetFlag(FL_MOVIE_URGENT_PROTECT_AUTO));
	Ux_SendEvent(&CustomMovieObjCtrl,   NVTEVT_EXE_MOVIE_PROTECT_MANUAL, 1,  SysGetFlag(FL_MOVIE_URGENT_PROTECT_MANUAL));
	Ux_SendEvent(&CustomMovieObjCtrl,   NVTEVT_EXE_MOVIE_LDWS,          1,  SysGetFlag(FL_MOVIE_LDWS));
	Ux_SendEvent(&CustomMovieObjCtrl,   NVTEVT_EXE_MOVIE_FCW,           1,  SysGetFlag(FL_MOVIE_FCW));
	Ux_SendEvent(&CustomMovieObjCtrl,   NVTEVT_EXE_MOVIE_CODEC,         1,  SysGetFlag(FL_MOVIE_CODEC));

	/*--- Setup ---*/
	Ux_SendEvent(&UISetupObjCtrl, NVTEVT_EXE_LANGUAGE,      1,  SysGetFlag(FL_LANGUAGE));
#if (TV_FUNC == ENABLE)
	Ux_SendEvent(&UISetupObjCtrl, NVTEVT_EXE_TVFORMAT,      1,  SysGetFlag(FL_TV_MODE));
#endif
	Ux_SendEvent(&UISetupObjCtrl, NVTEVT_EXE_POWEROFF,      1,  SysGetFlag(FL_AUTO_POWER_OFF));
	Ux_SendEvent(&UISetupObjCtrl, NVTEVT_EXE_LCDOFF,        1,  SysGetFlag(FL_LCD_OFF));
	Ux_SendEvent(&UISetupObjCtrl, NVTEVT_EXE_BEEPKEY,       1,  SysGetFlag(FL_BEEP));
	Ux_SendEvent(&UISetupObjCtrl, NVTEVT_EXE_DISPLAY,       1,  SysGetFlag(FL_LCD_DISPLAY));
	Ux_SendEvent(&UISetupObjCtrl, NVTEVT_EXE_FREQ,          1,  SysGetFlag(FL_FREQUENCY));
	Ux_SendEvent(&UISetupObjCtrl, NVTEVT_EXE_DATEFORMAT,    1,  SysGetFlag(FL_DATE_FORMAT));


//#MT#lyb -20200328 -begin
    Ux_SendEvent(&UISetupObjCtrl, NVTEVT_EXE_BEEPVOLUME,    1,  SysGetFlag(FL_BeepVolumnIndex));
    Ux_SendEvent(&UISetupObjCtrl, NVTEVT_EXE_SCREENLIGHT,   1,  SysGetFlag(FL_SCREENLIGHT));
    Ux_SendEvent(&CustomMovieObjCtrl, NVTEVT_EXE_MOVIE_PARK,    1,  SysGetFlag(FL_MOVIE_PARK));
    Ux_SendEvent(&UISetupObjCtrl, NVTEVT_EXE_ALARM_LCA,     1,  SysGetFlag(FL_ALARM_LCA));

    Ux_SendEvent(&CustomMovieObjCtrl, NVTEVT_EXE_MOVIE_BACKADJUST,    1, SysGetFlag(FL_MOVIE_BACKADJUST_MENU));
//#MT#lyb -20200328 -end
	//if (currentInfo.strBLLvl == 0) {
	//Ux_SendEvent(&CustomMovieObjCtrl, NVTEVT_EXE_SETLCDBRIGHTLVL,    1,  SysGetFlag(FL_LCD_BRIGHTNESS));
	//}else{
	//	SysSetFlag(FL_LCD_BRIGHTNESS, currentInfo.strBLLvl);
	//	Ux_SendEvent(&CustomMovieObjCtrl, NVTEVT_EXE_SETLCDBRIGHTLVL,    1, currentInfo.strBLLvl);
	//}

#if (WIFI_FUNC==ENABLE)
	/*--- Wi-Fi ---*/
	if (UI_GetData(FL_NetWorkMode) == NET_AP_MODE || UI_GetData(FL_NetWorkMode) == NET_WPS_AP_PBC_MODE) {
		if (currentInfo.strSSID[0] != 0) { // Load SSID if existed.
		CHKPNT;
			debug_msg("--cj uiinfoSSID :%s  %s\r\n ",UINet_GetSSID(), currentInfo.strSSID);
			Ux_SendEvent(&UISetupObjCtrl, NVTEVT_EXE_WIFI_SET_SSID, 1, currentInfo.strSSID);
		}

		if (currentInfo.strPASSPHRASE[0] != 0) { // Load PASSPHARSE if existed.
			Ux_SendEvent(&UISetupObjCtrl, NVTEVT_EXE_WIFI_SET_PASSPHRASE, 1, currentInfo.strPASSPHRASE);
			debug_msg("--cj uiinfoPASSPHRASE :  %s %s\r\n ",UINet_GetSSID(),currentInfo.strPASSPHRASE);

		}
	} else if (UI_GetData(FL_NetWorkMode) == NET_STATION_MODE) {
		CHKPNT;
		char szTemp[NVT_WSC_MAX_SSID_LEN + NVT_MAX_WEP_KEY_LEN] = {0};

		if (currentInfo.strSSID_hotspot_1[0] && currentInfo.strPASSPHRASE_hotspot_1[0]) { // Load SSID and passphrase if existed.
			snprintf(szTemp, NVT_WSC_MAX_SSID_LEN + NVT_MAX_WEP_KEY_LEN, "%s:%s", currentInfo.strSSID_hotspot_1, currentInfo.strPASSPHRASE_hotspot_1);
			Ux_SendEvent(&UISetupObjCtrl, NVTEVT_EXE_WIFI_SEND_SSID_PASSPHRASE, 1, szTemp);
		}
	}
#endif
}

void Photo_SetUserIndex(PHOTO_USR_ITEM_T uiItem, UINT32 uhIndex)
{
	UIInfoTraceMsg("Photo_SetUserIndex: Item %d, index %d\r\n", uiItem, uhIndex);

	if (UI_GetData(FL_IsInitSettingFlag) == FALSE) {
		/* Update Photo Mode user defined settings data while init setting flag is off */
		switch (uiItem) {
		case PHOTO_USR_FLASH:
			currentInfo.ubFlashIndex = uhIndex;
			break;
		case PHOTO_USR_EV:
			currentInfo.ubEVIndex = uhIndex;
			break;
		case PHOTO_USR_AFWINDOW:
			currentInfo.ubAFWindowIndex = uhIndex;
			break;
		case PHOTO_USR_AFBEAM:
			currentInfo.ubAFBeamIndex = uhIndex;
			break;
		case PHOTO_USR_METERING:
			currentInfo.ubAEmode = uhIndex;
			break;
		case PHOTO_USR_TIMELAPSE:
			currentInfo.ubTimelapseIndex = uhIndex;
			break;
		case PHOTO_USR_CONTSHOT:
			currentInfo.ubContshotIndex = uhIndex;
			break;
		case PHOTO_USR_CONTAF:
			currentInfo.ubContAF = uhIndex;
			break;
		case PHOTO_USR_QREVIEW:
			currentInfo.ubQviewIndex = uhIndex;
			break;
		case PHOTO_USR_DZOOMSTATUS:
			currentInfo.ubDzoom      = uhIndex;
			break;
		case PHOTO_USR_SLOWSHUTTER:
			currentInfo.ubSlowShutter = uhIndex;
			break;
		case PHOTO_USR_DATEIMPRINT:
			currentInfo.ubDatePrint = uhIndex;
			break;
		case PHOTO_USR_BLINK:
			currentInfo.ubBlinkDet = uhIndex;
			break;
		case PHOTO_USR_PANDET:
			currentInfo.ubPanModeIndex = uhIndex;
			break;
		case PHOTO_USR_COLOR:
			currentInfo.ubColorIndex = uhIndex;
			break;
		case PHOTO_USR_SIZE:
			currentInfo.ubSizeIndex = uhIndex;
			break;
		case PHOTO_USR_QUALITY:
			currentInfo.ubQualityIndex = uhIndex;
			break;
		case PHOTO_USR_ISO:
			currentInfo.ubISOIndex = uhIndex;
			break;
		case PHOTO_USR_WB:
			currentInfo.ubWBIndex = uhIndex;
			break;
		//#NT#Store FD index after power off
		case PHOTO_USR_FD:
			currentInfo.ubFDIndex = uhIndex;
			break;
		/*
		case PHOTO_USR_SATURATION:
		    currentInfo.ubSaturationIndex = uhIndex;
		    break;
		*/
		case PHOTO_USR_SHARPNESS:
			currentInfo.ubSharpnessIndex = uhIndex;
			break;
		/*
		case PHOTO_USR_CONTRAST:
		    currentInfo.ubContrastIndex = uhIndex;
		    break;
		*/
		case PHOTO_USR_DISPMODE:
			currentInfo.ubPhotoDispMode = uhIndex;
			break;
		default:
			UIInfoErrMsg("Photo_SetUserIndex: Unknown item %d\r\n", uiItem);
			break;
		}
	} else {
		/* While init setting flag is on, do NOT update Photo Mode user defined settings data */
		UIInfoTraceMsg("Photo_SetUserIndex: Init setting flag is ON, no update item %d\r\n", uiItem);
	}
}

UINT32 Photo_GetUserIndex(PHOTO_USR_ITEM_T uiItem)
{
	UINT32 uhUserIndex;

	switch (uiItem) {
	case PHOTO_USR_FLASH:
		uhUserIndex = currentInfo.ubFlashIndex;
		break;
	case PHOTO_USR_EV:
		uhUserIndex = currentInfo.ubEVIndex;
		break;
	case PHOTO_USR_AFWINDOW:
		uhUserIndex = currentInfo.ubAFWindowIndex;
		break;
	case PHOTO_USR_AFBEAM:
		uhUserIndex = currentInfo.ubAFBeamIndex;
		break;
	case PHOTO_USR_METERING:
		uhUserIndex = currentInfo.ubAEmode;
		break;
	case PHOTO_USR_TIMELAPSE:
		uhUserIndex = currentInfo.ubTimelapseIndex;
		break;
	case PHOTO_USR_CONTSHOT:
		uhUserIndex = currentInfo.ubContshotIndex;
		break;
	case PHOTO_USR_CONTAF:
		uhUserIndex = currentInfo.ubContAF;
		break;
	case PHOTO_USR_QREVIEW:
		uhUserIndex = currentInfo.ubQviewIndex;
		break;
	case PHOTO_USR_DZOOMSTATUS:
		uhUserIndex = currentInfo.ubDzoom;
		break;
	case PHOTO_USR_SLOWSHUTTER:
		uhUserIndex = currentInfo.ubSlowShutter;
		break;
	case PHOTO_USR_DATEIMPRINT:
		uhUserIndex = currentInfo.ubDatePrint;
		break;
	case PHOTO_USR_BLINK:
		uhUserIndex = currentInfo.ubBlinkDet;
		break;
	case PHOTO_USR_PANDET:
		uhUserIndex = currentInfo.ubPanModeIndex;
		break;
	case PHOTO_USR_COLOR:
		uhUserIndex = currentInfo.ubColorIndex;
		break;
	case PHOTO_USR_SIZE:
		uhUserIndex = currentInfo.ubSizeIndex;
		break;
	case PHOTO_USR_QUALITY:
		uhUserIndex = currentInfo.ubQualityIndex;
		break;
	case PHOTO_USR_ISO:
		uhUserIndex = currentInfo.ubISOIndex;
		break;
	case PHOTO_USR_WB:
		uhUserIndex = currentInfo.ubWBIndex;
		break;
	//#NT#Store FD index after power off
	case PHOTO_USR_FD:
		uhUserIndex = currentInfo.ubFDIndex;
		break;
	/*
	case PHOTO_USR_SATURATION:
	    uhUserIndex = currentInfo.ubSaturationIndex;
	    break;
	*/
	case PHOTO_USR_SHARPNESS:
		uhUserIndex = currentInfo.ubSharpnessIndex;
		break;
	/*
	case PHOTO_USR_CONTRAST:
	    uhUserIndex = currentInfo.ubContrastIndex;
	    break;
	*/

	case PHOTO_USR_DISPMODE:
		uhUserIndex = currentInfo.ubPhotoDispMode;
		break;

	default:
		uhUserIndex = 0xFFFF;
		UIInfoErrMsg("Photo_GetUserIndex: Unknown item %d\r\n", uiItem);
		break;
	}
	UIInfoTraceMsg("Photo_GetUserIndex: Get item %d user index %d\r\n", uiItem, uhUserIndex);

	return uhUserIndex;
}

#if (TV_FUNC == ENABLE)
extern DX_HANDLE gDevTVObj;
#endif
#if (HDMI_FUNC == ENABLE)
extern DX_HANDLE gDevHDMIObj;
#endif

PLUG_DEV KeyScan_GetPlugDev(void)
{
	UINT32 r = PLUG_OFF;
#if ((TV_FUNC == ENABLE) || (HDMI_FUNC == ENABLE))
	DX_HANDLE uiDevObj1, uiDevObj2;

	uiDevObj1 = (DX_HANDLE)GxVideo_GetDevice(DOUT1);
	uiDevObj2 = (DX_HANDLE)GxVideo_GetDevice(DOUT2);
#endif
#if (TV_FUNC == ENABLE)
	if (uiDevObj1 == gDevTVObj || uiDevObj2 == gDevTVObj) {
		r = PLUG_TV;
	}
#endif
#if (HDMI_FUNC == ENABLE)
	if (uiDevObj1 == gDevHDMIObj || uiDevObj2 == gDevHDMIObj) {
		r = PLUG_HDMI;
	}
#endif
	return r;
}

//-----------------------------------------------------------------------------
// Update DCF Folder/File name Utility
//-----------------------------------------------------------------------------
static BOOL FlowDCF_GetNextDCFFolderID(UINT32 *pDirID)
{
	BOOL ret = FALSE;
	UINT32 uiCurDCFID, uiDirCount;
	SDCFDIRINFO dirinfo;

	uiCurDCFID = DCF_GetDBInfo(DCF_INFO_CUR_DIR_ID);
	uiDirCount = 0;

	do {
		if (uiCurDCFID == MAX_DCF_DIR_NUM) {
			uiCurDCFID = MIN_DCF_DIR_NUM;
		} else {
			uiCurDCFID++;
		}

		uiDirCount++;
		if (!DCF_GetDirInfo(uiCurDCFID, &dirinfo)) {
			*pDirID = uiCurDCFID;
			ret = TRUE;
			break;
		}
	} while (uiDirCount == (MAX_DCF_DIR_NUM - MIN_DCF_DIR_NUM));


	return ret;
}

void FlowDCF_UpdateName(void)
{
	CHAR FolderName[6] = "MEDIA";
	CHAR FileName[5] = "PTDC";
	char DCFpathname[0x20];
	UINT32    uiAddr, uiNextDCFID;
	CHAR filePath[DCF_FULL_FILE_PATH_LEN];
    struct tm Curr_DateTime;
    Curr_DateTime = HwClock_GetTime(TIME_ID_CURRENT);

	snprintf(FolderName, sizeof(FolderName), "%1d%02d%02d", Curr_DateTime.tm_year % 0x0A, Curr_DateTime.tm_mon,Curr_DateTime.tm_mday);
	snprintf(FileName, sizeof(FileName), "%02d%02d", Curr_DateTime.tm_hour,  Curr_DateTime.tm_min);

	uiAddr = DCF_GetDBInfo(DCF_INFO_DIR_FREE_CHARS);
	memcpy((UB *)DCFpathname, (UB *)uiAddr, DCF_DIR_NAME_LEN);
	if (strncmp(DCFpathname, FolderName, 5)) {
		if (FlowDCF_GetNextDCFFolderID(&uiNextDCFID) == TRUE) {
			DCF_SetDirFreeChars(FolderName);
			DCF_MakeDirPath(uiNextDCFID, filePath);
			if (FileSys_MakeDir(filePath) != FST_STA_OK) {
				UIInfoErrMsg("MakeDir %s Fail\r\n", filePath);
			}
			DCF_SetNextID(uiNextDCFID, MIN_DCF_FILE_NUM);
		} else {
			debug_msg("DCF Folder full\r\n");
		}
	}

	// update DCF file name in current RTC time
	DCF_SetFileFreeChars(DCF_FILE_TYPE_ANYFORMAT, FileName);

}

void System_UpdateFWReboot(void)
{
	MODELEXT_HEADER *head = NULL;
	BININFO *pBinInfo = (BININFO *)Dx_GetModelExtCfg(MODELEXT_TYPE_BIN_INFO, &head);
	UINT32  uiFWUpdate = 0;
	INT32 result;
   // CHKPNT;    
	if (pBinInfo == NULL) {
		UIInfoErrMsg("pBinInfo is NULL\r\n");
		 CHKPNT;
		return;
	}
	uiFWUpdate = (pBinInfo->ld.LdCtrl2 & LDCF_UPDATE_FW);
    if(uiFWUpdate)
    {
     //  CHKPNT;
	   System_WaitFS();
       result = FileSys_DeleteFile("A:\\FW96675A.bin");
		if(WavPlay_WriteWavData() == E_OK)
		{
			debug_msg(" WavPlay_WriteWavData ok\r\n");
		}
	   DBGD(result);
	   if(result != FST_STA_OK)
		 	return;
       debug_msg("Updated Done & Reboot!!\r\n");
#if(STARTWDT_FUNCTION)
		SysStopWDT();
#endif
	   GxSystem_HWResetNOW();
       Delay_DelayMs(2000);
    }
}

extern BOOL bflag_EthLinkFinish;
extern BOOL Ethcam_tx_DetFwAutoUpdate(void);
extern BOOL  autoRec;
void System_UpdateTx(void)
{
	#if (ETHCAM_TX_UPDATE_TEST == ENABLE)
    static BOOL bTxUpdateOK = FALSE;
    if(!bTxUpdateOK)
    {
        TESTLOG("EthCamNet_GetEthLinkStatus(0):%d ",EthCamNet_GetEthLinkStatus(0));
        if(EthCamNet_GetEthLinkStatus(0) == ETHCAM_LINK_UP)
        {
            TESTLOG("bflag_EthLinkFinish %d",bflag_EthLinkFinish);
            if(bflag_EthLinkFinish)
            {
             //   TESTLOG("txupdate 2");
                if(Ethcam_tx_DetFwAutoUpdate())
                {
                   TESTLOG("txupdate finish ");
                    bTxUpdateOK = TRUE;
					Ux_OpenWindow(&UIFlowWndWaitMomentCtrl, 1,UIFlowWndWaitMoment_StatusTXT_Msg_STRID_ETHCAM_UDFW_FINISH);
                }else{
					TESTLOG("txupdate no file "); //MT CJ 2020/420
                }
            }
        }else{
		autoRec = FALSE;
		TESTLOG("txupdate no file "); //MT CJ 2020/0615
        }
    }
   
#endif
}

