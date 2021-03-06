//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIMenuWndSetupFormatConfirmRes.c"
#include "UIMenuWndSetupFormatConfirm.h"
#include "UIMenuWndSetupFormat.h"
#include "MenuCommonItem.h"
//#include "UIFlowWndWaitMoment.h"
#include "UIFlow.h"

UINT32 g_u32FormatIndex = 0;

//---------------------UIMenuWndSetupFormatConfirmCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndSetupFormatConfirm)
CTRL_LIST_ITEM(UIMenuWndSetupFormatConfirm_Static_TxtTop)
CTRL_LIST_ITEM(UIMenuWndSetupFormatConfirm_Panel)
CTRL_LIST_END

//----------------------UIMenuWndSetupFormatConfirmCtrl Event---------------------------
INT32 UIMenuWndSetupFormatConfirm_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndSetupFormatConfirm_OnClose(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndSetupFormatConfirm_OnChildClose(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndSetupFormatConfirm_OnKeyLeft(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndSetupFormatConfirm_OnKeyMenu(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndSetupFormatConfirm_OnKeyMode(VControl *, UINT32, UINT32 *);
//INT32 UIMenuWndSetupFormatConfirm_OnKeyShutter2(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndSetupFormatConfirm)
EVENT_ITEM(NVTEVT_OPEN_WINDOW, UIMenuWndSetupFormatConfirm_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW, UIMenuWndSetupFormatConfirm_OnClose)
EVENT_ITEM(NVTEVT_CHILD_CLOSE, UIMenuWndSetupFormatConfirm_OnChildClose)
EVENT_ITEM(NVTEVT_KEY_LEFT, UIMenuWndSetupFormatConfirm_OnKeyLeft)
EVENT_ITEM(NVTEVT_KEY_MENU, UIMenuWndSetupFormatConfirm_OnKeyMenu)
EVENT_ITEM(NVTEVT_KEY_MODE, UIMenuWndSetupFormatConfirm_OnKeyMode)
//EVENT_ITEM(NVTEVT_KEY_SHUTTER2,UIMenuWndSetupFormatConfirm_OnKeyShutter2)
EVENT_END

INT32 UIMenuWndSetupFormatConfirm_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
	//#NT#2009/07/28#Chris Chung -begin
	#if 0
	if (paramNum > 0) {
		g_u32FormatIndex = paramArray[0];
	}
    #else //lyb ----20200319
    g_u32FormatIndex = 1;   //only SD
    #endif
    
    //FlowMovie_StopRec();//lyb,for the display delay bug
    
	//#NT#2009/07/28#Chris Chung -end
	Ux_DefaultEvent(pCtrl, NVTEVT_OPEN_WINDOW, paramNum, paramArray);
	return NVTEVT_CONSUME;
}
INT32 UIMenuWndSetupFormatConfirm_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
	Ux_DefaultEvent(pCtrl, NVTEVT_CLOSE_WINDOW, paramNum, paramArray);
	return NVTEVT_CONSUME;
}
BOOL g_closeformatwnd=FALSE;
INT32 UIMenuWndSetupFormatConfirm_OnChildClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
	//#NT#2009/08/12#Chris Chung -begin
	if (paramNum > 0) {
		if (paramArray[0] == NVTRET_WAITMOMENT && paramArray[1] == NVTRET_FORMAT) {
			//Ux_CloseWindow(&UIMenuWndSetupFormatCtrl, 0);
		} else if (paramArray[0] == NVTRET_ENTER_MENU) {
			Ux_RedrawAllWind();
		}
	} else {
		Ux_RedrawAllWind();
	}
	//#NT#2009/08/12#Chris Chung -end
	if(g_closeformatwnd==TRUE)
	{
		CHKPNT;
		g_closeformatwnd=FALSE;
		//Ux_PostEvent(NVTEVT_SYSTEM_MODE, 1, PRIMARY_MODE_MOVIE);
	}
	return NVTEVT_CONSUME;
}
INT32 UIMenuWndSetupFormatConfirm_OnKeyLeft(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
	//Ux_CloseWindow(&UIMenuWndSetupFormatCtrl, 0);
	return NVTEVT_CONSUME;
}
INT32 UIMenuWndSetupFormatConfirm_OnKeyMenu(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
	Ux_CloseWindow(&MenuCommonItemCtrl, 0); // close whole tab menu
	return NVTEVT_CONSUME;
}
INT32 UIMenuWndSetupFormatConfirm_OnKeyMode(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
	Ux_SendEvent(&UISetupObjCtrl, NVTEVT_EXE_CHANGEDSCMODE, 1, DSCMODE_CHGTO_NEXT);
	return NVTEVT_CONSUME;
}
INT32 UIMenuWndSetupFormatConfirm_OnKeyShutter2(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
	Ux_SendEvent(&UISetupObjCtrl, NVTEVT_FORCETO_LIVEVIEW_MODE, 0);
	return NVTEVT_CONSUME;
}

//#MT#lyb -20200319 -begin
#if 0
//----------------------UIMenuWndSetupFormatConfirm_List_TextCtrl Event---------------------------
INT32 UIMenuWndSetupFormatConfirm_List_Text_OnKeyUp(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndSetupFormatConfirm_List_Text_OnKeyDown(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndSetupFormatConfirm_List_Text_OnKeyEnter(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndSetupFormatConfirm_List_Text_OnKeyShutter2(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndSetupFormatConfirm_List_Text)
EVENT_ITEM(NVTEVT_KEY_UP, UIMenuWndSetupFormatConfirm_List_Text_OnKeyUp)
EVENT_ITEM(NVTEVT_KEY_DOWN, UIMenuWndSetupFormatConfirm_List_Text_OnKeyDown)
EVENT_ITEM(NVTEVT_KEY_ENTER, UIMenuWndSetupFormatConfirm_List_Text_OnKeyEnter)
EVENT_ITEM(NVTEVT_KEY_SHUTTER2, UIMenuWndSetupFormatConfirm_List_Text_OnKeyShutter2)
EVENT_END

INT32 UIMenuWndSetupFormatConfirm_List_Text_OnKeyUp(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
	Ux_SendEvent(pCtrl, NVTEVT_PREVIOUS_ITEM, 0);
	return NVTEVT_CONSUME;
}
INT32 UIMenuWndSetupFormatConfirm_List_Text_OnKeyDown(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
	Ux_SendEvent(pCtrl, NVTEVT_NEXT_ITEM, 0);
	return NVTEVT_CONSUME;
}
INT32 UIMenuWndSetupFormatConfirm_List_Text_OnKeyEnter(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
	if (UxList_GetData(pCtrl, LST_CURITM) == UIMenuWndSetupFormatConfirm_List_Text_STRID_OK) {
		if (g_u32FormatIndex == 0) {
			Ux_OpenWindow(&UIFlowWndWaitMomentCtrl, 1, UIFlowWndWaitMoment_StatusTXT_Msg_STRID_PLEASE_WAIT);
			BKG_PostEvent(NVTEVT_BKW_FORMAT_NAND);
		} else if (g_u32FormatIndex == 1) {
			if (System_GetState(SYS_STATE_CARD)  == CARD_REMOVED) {
				Ux_OpenWindow(&UIFlowWndWrnMsgCtrl, 2, FLOWWRNMSG_ISSUE_NO_CARD, FLOWWRNMSG_TIMER_2SEC);
				return NVTEVT_CONSUME;
			} else {
				if (UIStorageCheck(STORAGE_CHECK_LOCKED, NULL) == TRUE) {
					Ux_OpenWindow(&UIFlowWndWrnMsgCtrl, 2, FLOWWRNMSG_ISSUE_CARD_LOCKED, FLOWWRNMSG_TIMER_2SEC);
					return NVTEVT_CONSUME;
				}
			}

			Ux_OpenWindow(&UIFlowWndWaitMomentCtrl, 1, UIFlowWndWaitMoment_StatusTXT_Msg_STRID_PLEASE_WAIT);
			BKG_PostEvent(NVTEVT_BKW_FORMAT_CARD);
			// reset file ID
#if USE_FILEDB
			if (UI_GetData(FL_IsUseFileDB)) {
				Ux_SendEvent(&UISetupObjCtrl, NVTEVT_FILEID_RESET, 0);
			}
#endif
		} else {
			Ux_CloseWindow(&UIMenuWndSetupFormatCtrl, 0);
		}
	} else {
		Ux_CloseWindow(&UIMenuWndSetupFormatCtrl, 0);
	}
	return NVTEVT_CONSUME;
}
INT32 UIMenuWndSetupFormatConfirm_List_Text_OnKeyShutter2(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
	// the same behavior as ENTER key!
	return UIMenuWndSetupFormatConfirm_List_Text_OnKeyEnter(pCtrl, paramNum, paramArray);
}
#endif
//#MT#lyb -20200319 -end



//----------------------UIMenuWndSetupFormatConfirm_Static_TxtTopCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndSetupFormatConfirm_Static_TxtTop)
EVENT_END

//---------------------UIMenuWndSetupFormatConfirm_PanelCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndSetupFormatConfirm_Panel)
CTRL_LIST_ITEM(UIMenuWndSetupFormatConfirm_Static_TxtTip)
CTRL_LIST_ITEM(UIMenuWndSetupFormatConfirm_Static_TxtReset)
CTRL_LIST_ITEM(UIMenuWndSetupFormatConfirm_BTN_OK)
CTRL_LIST_ITEM(UIMenuWndSetupFormatConfirm_BTN_Cancle)
CTRL_LIST_END

//----------------------UIMenuWndSetupFormatConfirm_PanelCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndSetupFormatConfirm_Panel)
EVENT_END

//----------------------UIMenuWndSetupFormatConfirm_Static_TxtTipCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndSetupFormatConfirm_Static_TxtTip)
EVENT_END

//----------------------UIMenuWndSetupFormatConfirm_Static_TxtResetCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndSetupFormatConfirm_Static_TxtReset)
EVENT_END

//----------------------UIMenuWndSetupFormatConfirm_BTN_OKCtrl Event---------------------------
INT32 UIMenuWndSetupFormatConfirm_BTN_OK_OnTouchPanelClick(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndSetupFormatConfirm_BTN_OK)
EVENT_ITEM(NVTEVT_CLICK,UIMenuWndSetupFormatConfirm_BTN_OK_OnTouchPanelClick)
EVENT_END

INT32 UIMenuWndSetupFormatConfirm_BTN_OK_OnTouchPanelClick(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    if (g_u32FormatIndex == 0) 
    {
        Ux_OpenWindow(&UIFlowWndWaitMomentCtrl, 1, UIFlowWndWaitMoment_StatusTXT_Msg_STRID_PLEASE_WAIT, FLOWWRNMSG_TIMER_5SEC);
        BKG_PostEvent(NVTEVT_BKW_FORMAT_NAND);
    } 
    else if (g_u32FormatIndex == 1) 
    {
        if (System_GetState(SYS_STATE_CARD)  == CARD_REMOVED) {
            Ux_OpenWindow(&UIFlowWndWrnMsgCtrl, 2, FLOWWRNMSG_ISSUE_NO_CARD, FLOWWRNMSG_TIMER_2SEC);
            return NVTEVT_CONSUME;
        } else {
            if (UIStorageCheck(STORAGE_CHECK_LOCKED, NULL) == TRUE) {
                Ux_OpenWindow(&UIFlowWndWrnMsgCtrl, 2, FLOWWRNMSG_ISSUE_CARD_LOCKED, FLOWWRNMSG_TIMER_2SEC);
            return NVTEVT_CONSUME;
            }
        }

	  if(gMovData.State == MOV_ST_REC ||
            gMovData.State == (MOV_ST_REC|MOV_ST_ZOOM))
	{
            debug_msg(" If is recording,must stop Rec !!!!  \r\n");
            FlowMovie_StopRec();
            Delay_DelayMs(100);
        }
        Ux_OpenWindow(&UIFlowWndWaitMomentCtrl, 2, UIFlowWndWaitMoment_StatusTXT_Msg_STRID_PLEASE_WAIT, FLOWWRNMSG_TIMER_5SEC);
   
        BKG_PostEvent(NVTEVT_BKW_FORMAT_CARD);
        // reset file ID
        #if USE_FILEDB//----lyb mask, FORMAT_CARD      has done it. // 20200430 cj open 
        if (UI_GetData(FL_IsUseFileDB)) {
     //   Ux_SendEvent(&UISetupObjCtrl, NVTEVT_FILEID_RESET, 0);
        }
        #endif
    } 
    else 
    {
        Ux_CloseWindow(&UIMenuWndSetupFormatConfirmCtrl, 0);
    }

    return NVTEVT_CONSUME;
}
//----------------------UIMenuWndSetupFormatConfirm_BTN_CancleCtrl Event---------------------------
INT32 UIMenuWndSetupFormatConfirm_BTN_Cancle_OnTouchPanelClick(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndSetupFormatConfirm_BTN_Cancle)
EVENT_ITEM(NVTEVT_CLICK,UIMenuWndSetupFormatConfirm_BTN_Cancle_OnTouchPanelClick)
EVENT_END

INT32 UIMenuWndSetupFormatConfirm_BTN_Cancle_OnTouchPanelClick(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_CloseWindow(&UIMenuWndSetupFormatConfirmCtrl, 0);
    return NVTEVT_CONSUME;
}


