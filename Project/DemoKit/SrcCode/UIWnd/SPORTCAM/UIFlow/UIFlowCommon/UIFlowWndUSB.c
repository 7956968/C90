//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "NVTToolCommand.h"
#include "UIFlowWndUSBRes.c"
#include "UIFlow.h"
//---------------------UIFlowWndUSBCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIFlowWndUSB)
CTRL_LIST_ITEM(UIFlowWndMSDC_StaticTxt_MassStorage)
CTRL_LIST_END

//----------------------UIFlowWndUSBCtrl Event---------------------------
INT32 UIFlowWndUSB_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndUSB_OnClose(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndUSB_OnTimer(VControl *, UINT32, UINT32 *);
#if (SDHOTPLUG_FUNCTION == ENABLE)
INT32 UIFlowWndUSB_OnStorageChange(VControl *, UINT32, UINT32 *);
#endif
EVENT_BEGIN(UIFlowWndUSB)
EVENT_ITEM(NVTEVT_OPEN_WINDOW, UIFlowWndUSB_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW, UIFlowWndUSB_OnClose)
EVENT_ITEM(NVTEVT_TIMER, UIFlowWndUSB_OnTimer)
#if (SDHOTPLUG_FUNCTION == ENABLE)
EVENT_ITEM(NVTEVT_STORAGE_INIT, UIFlowWndUSB_OnStorageChange)
EVENT_ITEM(NVTEVT_STORAGE_CHANGE, UIFlowWndUSB_OnStorageChange)
#endif
EVENT_END

INT32 UIFlowWndUSB_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
	if (paramNum == 1) {
		if (paramArray[0] == UIFlowWndUSB_PCC_MODE) {
			// show pcc string
			UxStatic_SetData(&UIFlowWndMSDC_StaticTxt_MassStorageCtrl,
							 STATIC_VALUE, STRID_PCC);
		} else {
#if (SDHOTPLUG_FUNCTION == ENABLE)
			if (UIStorageCheck(STORAGE_CHECK_ERROR, NULL) == TRUE) {
				Ux_OpenWindow(&UIFlowWndWrnMsgCtrl, 2, UIFlowWndWrnMsg_StatusTXT_Msg_STRID_PLEASE_INSERT_SD, FLOWWRNMSG_TIMER_KEEP);
				return NVTEVT_CONSUME;
			}
#endif
			// show msdc string
			UxStatic_SetData(&UIFlowWndMSDC_StaticTxt_MassStorageCtrl,
							 STATIC_VALUE, STRID_MSDC);
		}
	}
	Ux_DefaultEvent(pCtrl, NVTEVT_OPEN_WINDOW, paramNum, paramArray);
	return NVTEVT_CONSUME;
}
INT32 UIFlowWndUSB_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
	Ux_DefaultEvent(pCtrl, NVTEVT_CLOSE_WINDOW, paramNum, paramArray);
	return NVTEVT_CONSUME;
}
INT32 UIFlowWndUSB_OnTimer(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
	return NVTEVT_CONSUME;
}
#if (SDHOTPLUG_FUNCTION == ENABLE)
INT32 UIFlowWndUSB_OnStorageChange(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
	if (STRID_MSDC == UxStatic_GetData(&UIFlowWndMSDC_StaticTxt_MassStorageCtrl, STATIC_VALUE)) {
		Ux_PostEvent(NVTEVT_SYSTEM_MODE, 1, System_GetState(SYS_STATE_CURRMODE));
	}
	return NVTEVT_CONSUME;
}
#endif
//----------------------UIFlowWndMSDC_StaticTxt_MassStorageCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMSDC_StaticTxt_MassStorage)
EVENT_END
