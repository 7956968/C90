//This source code is generated by UI Designer Studio.
#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIFlowPhotoFuncs.h"
#include "SysCommon.h"
#include "AppCommon.h"
#include "PrjCfg.h"
#include "WifiAppCmd.h"
#include "UIAppPhoto.h"
#include "UIFlow.h"
#include "UIAppWiFiCmd.h"

///////////////////////////////////////////////////////////////////////////////
#define __MODULE__          UIAppWiFiCmdPhoto
#define __DBGLVL__          2 // 0=FATAL, 1=ERR, 2=WRN, 3=UNIT, 4=FUNC, 5=IND, 6=MSG, 7=VALUE, 8=USER
#define __DBGFLT__          "*" //*=All, [mark]=CustomClass
#include "DebugModule.h"

#if (WIFI_AP_FUNC==ENABLE)
INT32 WiFiCmd_OnExePhotoCapture(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
#if(PHOTO_MODE==ENABLE)
	if (System_GetState(SYS_STATE_CURRMODE) != PRIMARY_MODE_PHOTO) {

		WifiCmd_Done(WIFIFLAG_CAPTURE_DONE, WIFIAPP_RET_FAIL);

		return NVTEVT_CONSUME;
	}
	FlowPhoto_DoCapture();
#endif
	return NVTEVT_CONSUME;
}
INT32 WiFiCmd_OnUpdateInfo(UINT32 callBackEvent)
{
#if(PHOTO_MODE==ENABLE)
	DBG_IND("callBackEvent %d\r\n", callBackEvent);
	switch (callBackEvent) {
	case UIAPPPHOTO_CB_QVSTART:
		//UIFlowWndPhoto_OnQVStart();
		break;

	case UIAPPPHOTO_CB_JPGOK:
		break;

	case UIAPPPHOTO_CB_FSTOK: {
#if(WIFI_AP_FUNC==ENABLE)
			WifiCmd_Done(WIFIFLAG_CAPTURE_DONE, E_OK);
			// Notify Photo capture OK
			SysCmdWifi_CmdSend(WIFI_CMDSEND_NOTIFY_STATUS, WIFI_DV_STA_OK);

			// Notify Free Picutre Number
			UI_SetData(FL_WIFI_PHOTO_FREEPICNUM, PhotoExe_GetFreePicNum());
			SysCmdWifi_CmdSend(WIFI_CMDSEND_NOTIFY_FREPICNUM, UI_GetData(FL_WIFI_PHOTO_FREEPICNUM));
#endif
		}
		break;

	case UIAPPPHOTO_CB_CAPTUREEND:
		// Enable preview after capture ending.
		{
			/* set FD/SD feature */
			FlowPhoto_SetFdSdProc(FALSE);

			/* Set to preview mode */
			UI_Show(UI_SHOW_PREVIEW, TRUE);

			/* close quick view image */
			UI_Show(UI_SHOW_QUICKVIEW, FALSE);

			Ux_FlushEventByRange(NVTEVT_KEY_EVT_START, NVTEVT_KEY_EVT_END);
		}

		// unlock AE/AWB
		Ux_SendEvent(&CustomPhotoObjCtrl, NVTEVT_EXE_START_FUNC, 2, UIAPP_PHOTO_AE | UIAPP_PHOTO_AWB, UIAPP_PHOTO_NOWAITIDLE);
		break;

	case UIAPPPHOTO_CB_FDEND:
		break;

	case UIAPPPHOTO_CB_SDEND:
		break;
	}
#endif
	return NVTEVT_CONSUME;
}
INT32 WiFiCmd_OnExeSetPhotoSize(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
#if(PHOTO_MODE==ENABLE)
	UINT32 Data;

	Data = paramNum ? paramArray[0] : 0;

	if (System_GetState(SYS_STATE_CURRMODE) != PRIMARY_MODE_PHOTO) {
		//only set photo size
		Ux_SendEvent(&CustomPhotoObjCtrl, NVTEVT_EXE_CAPTURE_SIZE, 1, Data);
		return NVTEVT_CONSUME;
	}
#if(HTTP_LIVEVIEW_FUNC==ENABLE)
	Ux_SendEvent(0, NVTEVT_EXE_CAPTURE_SIZE, 1, Data);
	Ux_SendEvent(0, NVTEVT_EXE_IMAGE_RATIO, 1, GetPhotoSizeRatio(UI_GetData(FL_PHOTO_SIZE)));
#endif
#if(WIFI_AP_FUNC==ENABLE)
	SysCmdWifi_CmdSend(WIFI_CMDSEND_NOTIFY_STATUS, WIFI_DV_STA_OK);
#endif
#endif
	return NVTEVT_CONSUME;
}

#endif
