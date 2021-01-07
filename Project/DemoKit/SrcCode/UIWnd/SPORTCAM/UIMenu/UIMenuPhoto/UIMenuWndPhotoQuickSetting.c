//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UISetup.h"
#include "UIMenuWndPhotoQuickSettingRes.c"
#include "UIMenuWndPhotoQuickSetting.h"
#include "UIFlow.h"

static INT32 EV_item_num[] = {
	ICON_EV_M2P0,
	ICON_EV_M1P6,
	ICON_EV_M1P3,
	ICON_EV_M1P0,
	ICON_EV_M0P6,
	ICON_EV_M0P3,
	ICON_EV_P0P0,
	ICON_EV_P0P3,
	ICON_EV_P0P6,
	ICON_EV_P1P0,
	ICON_EV_P1P3,
	ICON_EV_P1P6,
	ICON_EV_P2P0
};
static INT32 AWB_item_num[] = {
	ICON_WB_AUTO,
	ICON_WB_CLOUDY,
	ICON_WB_DAYLIGHT,
	ICON_WB_FLUORESCENT,
	ICON_WB_TUNGSTEN
};
//---------------------UIMenuWndPhotoQuickSetting Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndPhotoQuickSetting)
CTRL_LIST_ITEM(UIMenuWndPhotoQS_Title_Panel)
CTRL_LIST_ITEM(UIMenuWndPhotoQS_End_Panel)
CTRL_LIST_ITEM(UIMenuWndPhotoQS_Left_Panel)
CTRL_LIST_ITEM(UIMenuWndPhotoQS_Help_Status)
CTRL_LIST_END

//----------------------UIMenuWndPhotoQuickSetting Event---------------------------
INT32 UIMenuWndPhotoQuickSetting_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPhotoQuickSetting_OnClose(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPhotoQuickSetting_OnChildClose(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPhotoQuickSetting_OnKeyEnter(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPhotoQuickSetting_OnKeyShutter2(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndPhotoQuickSetting)
EVENT_ITEM(NVTEVT_OPEN_WINDOW, UIMenuWndPhotoQuickSetting_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW, UIMenuWndPhotoQuickSetting_OnClose)
EVENT_ITEM(NVTEVT_CHILD_CLOSE, UIMenuWndPhotoQuickSetting_OnChildClose)
EVENT_ITEM(NVTEVT_KEY_ENTER, UIMenuWndPhotoQuickSetting_OnKeyEnter)
EVENT_ITEM(NVTEVT_KEY_SHUTTER2, UIMenuWndPhotoQuickSetting_OnKeyShutter2)
EVENT_END

INT32 UIMenuWndPhotoQuickSetting_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
	INT32   ev_icon_index = 0, wb_icon_index = 0, wb_menu_index = 0, wb_str_index = 0;
	INT32   downmenu_ev_index = 0;

	if (UI_GetData(FL_NextMode) == PRIMARY_MODE_PHOTO) {
		UxState_SetData(&UIMenuWndPhotoQS_Tile_IconCtrl, STATE_CURITEM, UIMenuWndPhotoQS_Tile_Icon_ICON_QM_STILL);
	} else if (UI_GetData(FL_NextMode) == UI_GetData(FL_NextMode) == PRIMARY_MODE_PHOTO) {
		UxState_SetData(&UIMenuWndPhotoQS_Tile_IconCtrl, STATE_CURITEM, UIMenuWndPhotoQS_Tile_Icon_ICON_QM_VIDEO);
	} else {
		UxState_SetData(&UIMenuWndPhotoQS_Tile_IconCtrl, STATE_CURITEM, UIMenuWndPhotoQS_Tile_Icon_ICON_QM_STILL);
	}

	switch (SysGetFlag(FL_EV)) {
	case EV_N20:
		ev_icon_index = ICON_EV_M2P0;
		downmenu_ev_index = UIMenuWndPhotoQS_EV_Menu_ICON_EV_M2P0;
		break;
	case EV_N16:
		ev_icon_index = ICON_EV_M1P6;
		downmenu_ev_index = UIMenuWndPhotoQS_EV_Menu_ICON_EV_M1P6;
		break;
	case EV_N13:
		ev_icon_index = ICON_EV_M1P3;
		downmenu_ev_index = UIMenuWndPhotoQS_EV_Menu_ICON_EV_M1P3;
		break;
	case EV_N10:
		ev_icon_index = ICON_EV_M1P0;
		downmenu_ev_index = UIMenuWndPhotoQS_EV_Menu_ICON_EV_M1P0;
		break;
	case EV_N06:
		ev_icon_index = ICON_EV_M0P6;
		downmenu_ev_index = UIMenuWndPhotoQS_EV_Menu_ICON_EV_M0P6;
		break;
	case EV_N03:
		ev_icon_index = ICON_EV_M0P3;
		downmenu_ev_index = UIMenuWndPhotoQS_EV_Menu_ICON_EV_M0P3;
		break;
	case EV_00:
		ev_icon_index = ICON_EV_P0P0;
		downmenu_ev_index = UIMenuWndPhotoQS_EV_Menu_ICON_EV_P0P0;
		break;
	case EV_P03:
		ev_icon_index = ICON_EV_P0P3;
		downmenu_ev_index = UIMenuWndPhotoQS_EV_Menu_ICON_EV_P0P3;
		break;
	case EV_P06:
		ev_icon_index = ICON_EV_P0P6;
		downmenu_ev_index = UIMenuWndPhotoQS_EV_Menu_ICON_EV_P0P6;
		break;
	case EV_P10:
		ev_icon_index = ICON_EV_P1P0;
		downmenu_ev_index = UIMenuWndPhotoQS_EV_Menu_ICON_EV_P1P0;
		break;
	case EV_P13:
		ev_icon_index = ICON_EV_P1P3;
		downmenu_ev_index = UIMenuWndPhotoQS_EV_Menu_ICON_EV_P1P3;
		break;
	case EV_P16:
		ev_icon_index = ICON_EV_P1P6;
		downmenu_ev_index = UIMenuWndPhotoQS_EV_Menu_ICON_EV_P1P6;
		break;
	case EV_P20:
		ev_icon_index = ICON_EV_P2P0;
		downmenu_ev_index = UIMenuWndPhotoQS_EV_Menu_ICON_EV_P2P0;
		break;
	}
	switch (SysGetFlag(FL_WB)) {
	case WB_AUTO:
		wb_icon_index = ICON_WB_AUTO;
		wb_menu_index = UIMenuWndPhotoQS_AWB_Menu_ICON_WB_AUTO;
		wb_str_index = UIMenuWndPhotoQS_Help_Status_STRID_AUTO;
		break;
	case WB_TUNGSTEN:
		wb_icon_index = ICON_WB_TUNGSTEN;
		wb_menu_index = UIMenuWndPhotoQS_AWB_Menu_ICON_WB_TUNGSTEN;
		wb_str_index = UIMenuWndPhotoQS_Help_Status_STRID_WB_TUNGSTEN;
		break;
	case WB_FLUORESCENT:
		wb_icon_index = ICON_WB_FLUORESCENT;
		wb_menu_index = UIMenuWndPhotoQS_AWB_Menu_ICON_WB_FLUORESCENT;
		wb_str_index = UIMenuWndPhotoQS_Help_Status_STRID_WB_FLUORESCENT;
		break;
	case WB_DAYLIGHT:
		wb_icon_index = ICON_WB_DAYLIGHT;
		wb_menu_index = UIMenuWndPhotoQS_AWB_Menu_ICON_WB_DAYLIGHT;
		wb_str_index = UIMenuWndPhotoQS_Help_Status_STRID_WB_DAY;
		break;
	case WB_CLOUDY:
		wb_icon_index = ICON_WB_CLOUDY;
		wb_menu_index = UIMenuWndPhotoQS_AWB_Menu_ICON_WB_CLOUDY;
		wb_str_index = UIMenuWndPhotoQS_Help_Status_STRID_WB_CLOUDY;
		break;
	}
//    sprintf((char *)menu_Buf,"Exposure");
//    UxStatic_SetData(&UIMenuWndMovieTurn_Title_Mode_StaticCtrl,STATIC_VALUE,Txt_Pointer(menu_Buf));
	UxState_SetData(&UIMenuWndPhotoQS_Title_Mode_StatusCtrl, STATE_CURITEM, UIMenuWndPhotoQS_Title_Mode_Status_STRID_EXPOSURE);

	UxCtrl_SetShow(&UIMenuWndPhotoQS_EV_MenuCtrl, TRUE);
	UxCtrl_SetShow(&UIMenuWndPhotoQS_AWB_MenuCtrl, FALSE);



	UxMenu_SetData(&UIMenuWndPhotoQS_EV_MenuCtrl, MNU_CURITM, downmenu_ev_index);
	UxMenu_SetData(&UIMenuWndPhotoQS_AWB_MenuCtrl, MNU_CURITM, wb_menu_index);

	UxMenu_SetData(&UIMenuWndPhotoQS_Left_MenuCtrl, MNU_CURITM, UIMenuWndPhotoQS_Left_Menu_ICON_EV_P0P0);
	//debug_msg("%d %d\n\r",ev_icon_index,wb_icon_index);
	UxMenu_SetItemData(&UIMenuWndPhotoQS_Left_MenuCtrl, UIMenuWndPhotoQS_Left_Menu_ICON_EV_P0P0, MNUITM_ICONID, ev_icon_index);
	UxMenu_SetItemData(&UIMenuWndPhotoQS_Left_MenuCtrl, UIMenuWndPhotoQS_Left_Menu_ICON_WB_AUTO, MNUITM_ICONID, wb_icon_index);
	//UxMenu_SetItemData(&UIMenuWndMovieTurn_EV_MenuCtrl,UIMenuWndMovieTurn_EV_Menu_ICON_EV_P0P0,UINT32 attribute,UINT32 value);
	//UxMenu_SetItemData(VControl *pCtrl,UINT32 index,UINT32 attribute,UINT32 value)

	UxCtrl_SetShow(&UIMenuWndPhotoQS_Help_StatusCtrl, FALSE);
	UxState_SetData(&UIMenuWndPhotoQS_Help_StatusCtrl, STATE_CURITEM, wb_str_index);
	Ux_DefaultEvent(pCtrl, NVTEVT_OPEN_WINDOW, paramNum, paramArray);
	return NVTEVT_CONSUME;
}
INT32 UIMenuWndPhotoQuickSetting_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
	Ux_DefaultEvent(pCtrl, NVTEVT_CLOSE_WINDOW, paramNum, paramArray);
	return NVTEVT_CONSUME;
}
INT32 UIMenuWndPhotoQuickSetting_OnChildClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
	Ux_DefaultEvent(pCtrl, NVTEVT_CHILD_CLOSE, paramNum, paramArray);
	return NVTEVT_CONSUME;
}
INT32 UIMenuWndPhotoQuickSetting_OnKeyEnter(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
	Ux_DefaultEvent(pCtrl, NVTEVT_KEY_ENTER, paramNum, paramArray);
	Ux_CloseWindow(pCtrl, 0);
	return NVTEVT_CONSUME;
}
INT32 UIMenuWndPhotoQuickSetting_OnKeyShutter2(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
	Ux_SendEvent(&UISetupObjCtrl, NVTEVT_FORCETO_LIVEVIEW_MODE, 0);
	return NVTEVT_CONSUME;
}
//---------------------UIMenuWndPhotoQS_Title_Panel Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndPhotoQS_Title_Panel)
CTRL_LIST_ITEM(UIMenuWndPhotoQS_Tile_Icon)
CTRL_LIST_ITEM(UIMenuWndPhotoQS_Title_Mode_Status)
CTRL_LIST_END

//----------------------UIMenuWndPhotoQS_Title_Panel Event---------------------------
EVENT_BEGIN(UIMenuWndPhotoQS_Title_Panel)
EVENT_END

//----------------------UIMenuWndPhotoQS_Tile_Icon Event---------------------------
EVENT_BEGIN(UIMenuWndPhotoQS_Tile_Icon)
EVENT_END

//----------------------UIMenuWndPhotoQS_Title_Mode_Status Event---------------------------
EVENT_BEGIN(UIMenuWndPhotoQS_Title_Mode_Status)
EVENT_END

//---------------------UIMenuWndPhotoQS_End_Panel Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndPhotoQS_End_Panel)
CTRL_LIST_ITEM(UIMenuWndPhotoQS_EV_Menu)
CTRL_LIST_ITEM(UIMenuWndPhotoQS_AWB_Menu)
CTRL_LIST_END

//----------------------UIMenuWndPhotoQS_End_Panel Event---------------------------
EVENT_BEGIN(UIMenuWndPhotoQS_End_Panel)
EVENT_END

//----------------------UIMenuWndPhotoQS_EV_Menu Event---------------------------
INT32 UIMenuWndPhotoQS_EV_Menu_OnKeyLeft(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPhotoQS_EV_Menu_OnKeyRight(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndPhotoQS_EV_Menu)
EVENT_ITEM(NVTEVT_KEY_LEFT, UIMenuWndPhotoQS_EV_Menu_OnKeyLeft)
EVENT_ITEM(NVTEVT_KEY_RIGHT, UIMenuWndPhotoQS_EV_Menu_OnKeyRight)
EVENT_END

INT32 UIMenuWndPhotoQS_EV_Menu_OnKeyLeft(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
	INT32   item, ae_index;
	if (UxCtrl_IsShow(pCtrl)) {
		item = UxMenu_GetData(pCtrl, MNU_CURITM);
		if (item > 0) {
			item = (item - 1) % UIMenuWndPhotoQS_EV_Menu_MAX;
		} else {
			item = UxMenu_GetData(pCtrl, MNU_TOTITM) - 1;
		}
		UxMenu_SetItemData(&UIMenuWndPhotoQS_Left_MenuCtrl, UIMenuWndPhotoQS_Left_Menu_ICON_EV_P0P0, MNUITM_ICONID, EV_item_num[item]);
		//Set_EVIndex(item);
		Ux_SendEvent(pCtrl, NVTEVT_PREVIOUS_ITEM, 0);
		switch (UxMenu_GetData(pCtrl, MNU_CURITM)) {
		case UIMenuWndPhotoQS_EV_Menu_ICON_EV_M2P0:
			ae_index = EV_N20;
			break;
		case UIMenuWndPhotoQS_EV_Menu_ICON_EV_M1P6:
			ae_index = EV_N16;
			break;
		case UIMenuWndPhotoQS_EV_Menu_ICON_EV_M1P3:
			ae_index = EV_N13;
			break;
		case UIMenuWndPhotoQS_EV_Menu_ICON_EV_M1P0:
			ae_index = EV_N10;
			break;
		case UIMenuWndPhotoQS_EV_Menu_ICON_EV_M0P6:
			ae_index = EV_N06;
			break;
		case UIMenuWndPhotoQS_EV_Menu_ICON_EV_M0P3:
			ae_index = EV_N03;
			break;
		case UIMenuWndPhotoQS_EV_Menu_ICON_EV_P0P0:
			ae_index = EV_00;
			break;
		case UIMenuWndPhotoQS_EV_Menu_ICON_EV_P0P3:
			ae_index = EV_P03;
			break;
		case UIMenuWndPhotoQS_EV_Menu_ICON_EV_P0P6:
			ae_index = EV_P06;
			break;
		case UIMenuWndPhotoQS_EV_Menu_ICON_EV_P1P0:
			ae_index = EV_P10;
			break;
		case UIMenuWndPhotoQS_EV_Menu_ICON_EV_P1P3:
			ae_index = EV_P13;
			break;
		case UIMenuWndPhotoQS_EV_Menu_ICON_EV_P1P6:
			ae_index = EV_P16;
			break;
		case UIMenuWndPhotoQS_EV_Menu_ICON_EV_P2P0:
			ae_index = EV_P20;
			break;
		default:
			ae_index = EV_00;
			break;
		}
		Ux_SendEvent(&CustomPhotoObjCtrl, NVTEVT_EXE_EV, 2, ae_index, TRUE);
	}
	return NVTEVT_CONSUME;
}
INT32 UIMenuWndPhotoQS_EV_Menu_OnKeyRight(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
	INT32   item, ae_index;
	if (UxCtrl_IsShow(pCtrl)) {
		item = UxMenu_GetData(pCtrl, MNU_CURITM);
		item = (item + 1) % UIMenuWndPhotoQS_EV_Menu_MAX;
		UxMenu_SetItemData(&UIMenuWndPhotoQS_Left_MenuCtrl, UIMenuWndPhotoQS_Left_Menu_ICON_EV_P0P0, MNUITM_ICONID, EV_item_num[item]);
		//Set_EVIndex(item);

		Ux_SendEvent(pCtrl, NVTEVT_NEXT_ITEM, 0);
		switch (UxMenu_GetData(pCtrl, MNU_CURITM)) {
		case UIMenuWndPhotoQS_EV_Menu_ICON_EV_M2P0:
			ae_index = EV_N20;
			break;
		case UIMenuWndPhotoQS_EV_Menu_ICON_EV_M1P6:
			ae_index = EV_N16;
			break;
		case UIMenuWndPhotoQS_EV_Menu_ICON_EV_M1P3:
			ae_index = EV_N13;
			break;
		case UIMenuWndPhotoQS_EV_Menu_ICON_EV_M1P0:
			ae_index = EV_N10;
			break;
		case UIMenuWndPhotoQS_EV_Menu_ICON_EV_M0P6:
			ae_index = EV_N06;
			break;
		case UIMenuWndPhotoQS_EV_Menu_ICON_EV_M0P3:
			ae_index = EV_N03;
			break;
		case UIMenuWndPhotoQS_EV_Menu_ICON_EV_P0P0:
			ae_index = EV_00;
			break;
		case UIMenuWndPhotoQS_EV_Menu_ICON_EV_P0P3:
			ae_index = EV_P03;
			break;
		case UIMenuWndPhotoQS_EV_Menu_ICON_EV_P0P6:
			ae_index = EV_P06;
			break;
		case UIMenuWndPhotoQS_EV_Menu_ICON_EV_P1P0:
			ae_index = EV_P10;
			break;
		case UIMenuWndPhotoQS_EV_Menu_ICON_EV_P1P3:
			ae_index = EV_P13;
			break;
		case UIMenuWndPhotoQS_EV_Menu_ICON_EV_P1P6:
			ae_index = EV_P16;
			break;
		case UIMenuWndPhotoQS_EV_Menu_ICON_EV_P2P0:
			ae_index = EV_P20;
			break;
		default:
			ae_index = EV_00;
			break;
		}
		Ux_SendEvent(&CustomPhotoObjCtrl, NVTEVT_EXE_EV, 2, ae_index, TRUE);
	}
	return NVTEVT_CONSUME;
}
//----------------------UIMenuWndPhotoQS_AWB_Menu Event---------------------------
INT32 UIMenuWndPhotoQS_AWB_Menu_OnKeyLeft(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPhotoQS_AWB_Menu_OnKeyRight(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndPhotoQS_AWB_Menu)
EVENT_ITEM(NVTEVT_KEY_LEFT, UIMenuWndPhotoQS_AWB_Menu_OnKeyLeft)
EVENT_ITEM(NVTEVT_KEY_RIGHT, UIMenuWndPhotoQS_AWB_Menu_OnKeyRight)
EVENT_END

INT32 UIMenuWndPhotoQS_AWB_Menu_OnKeyLeft(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
	INT32   item, wb_index;
	if (UxCtrl_IsShow(pCtrl)) {
		item = UxMenu_GetData(pCtrl, MNU_CURITM);
		if (item > 0) {
			item = (item - 1) % UIMenuWndPhotoQS_AWB_Menu_MAX;
		} else {
			item = UxMenu_GetData(pCtrl, MNU_TOTITM) - 1;
		}
		UxMenu_SetItemData(&UIMenuWndPhotoQS_Left_MenuCtrl, UIMenuWndPhotoQS_Left_Menu_ICON_WB_AUTO, MNUITM_ICONID, AWB_item_num[item]);
		UxState_SetData(&UIMenuWndPhotoQS_Help_StatusCtrl, STATE_CURITEM, (item % UIMenuWndPhotoQS_Help_Status_MAX));
		Ux_SendEvent(pCtrl, NVTEVT_PREVIOUS_ITEM, 0);
		switch (UxMenu_GetData(pCtrl, MNU_CURITM)) {
		case UIMenuWndPhotoQS_AWB_Menu_ICON_WB_AUTO:
			wb_index = WB_AUTO;
			break;
		case UIMenuWndPhotoQS_AWB_Menu_ICON_WB_CLOUDY:
			wb_index = WB_CLOUDY;
			break;
		case UIMenuWndPhotoQS_AWB_Menu_ICON_WB_DAYLIGHT:
			wb_index = WB_DAYLIGHT;
			break;
		case UIMenuWndPhotoQS_AWB_Menu_ICON_WB_FLUORESCENT:
			wb_index = WB_FLUORESCENT;
			break;
		case UIMenuWndPhotoQS_AWB_Menu_ICON_WB_TUNGSTEN:
			wb_index = WB_TUNGSTEN;
			break;
		default:
			wb_index = WB_AUTO;
			break;
		}
		//Set_WBIndex(wb_index);
		Ux_SendEvent(&CustomPhotoObjCtrl, NVTEVT_EXE_WB, 2, wb_index, TRUE);
	}
	return NVTEVT_CONSUME;
}
INT32 UIMenuWndPhotoQS_AWB_Menu_OnKeyRight(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
	INT32   item, wb_index;
	if (UxCtrl_IsShow(pCtrl)) {
		item = UxMenu_GetData(pCtrl, MNU_CURITM);
		item = (item + 1) % UIMenuWndPhotoQS_AWB_Menu_MAX;
		UxMenu_SetItemData(&UIMenuWndPhotoQS_Left_MenuCtrl, UIMenuWndPhotoQS_Left_Menu_ICON_WB_AUTO, MNUITM_ICONID, AWB_item_num[item]);
		//Set_WBIndex(wb_index);
		UxState_SetData(&UIMenuWndPhotoQS_Help_StatusCtrl, STATE_CURITEM, (item % UIMenuWndPhotoQS_Help_Status_MAX));
		Ux_SendEvent(pCtrl, NVTEVT_NEXT_ITEM, 0);
		switch (UxMenu_GetData(pCtrl, MNU_CURITM)) {
		case UIMenuWndPhotoQS_AWB_Menu_ICON_WB_AUTO:
			wb_index = WB_AUTO;
			break;
		case UIMenuWndPhotoQS_AWB_Menu_ICON_WB_CLOUDY:
			wb_index = WB_CLOUDY;
			break;
		case UIMenuWndPhotoQS_AWB_Menu_ICON_WB_DAYLIGHT:
			wb_index = WB_DAYLIGHT;
			break;
		case UIMenuWndPhotoQS_AWB_Menu_ICON_WB_FLUORESCENT:
			wb_index = WB_FLUORESCENT;
			break;
		case UIMenuWndPhotoQS_AWB_Menu_ICON_WB_TUNGSTEN:
			wb_index = WB_TUNGSTEN;
			break;
		default:
			wb_index = WB_AUTO;
			break;
		}
		//Set_WBIndex(wb_index);
		Ux_SendEvent(&CustomPhotoObjCtrl, NVTEVT_EXE_WB, 2, wb_index, TRUE);
	}
	return NVTEVT_CONSUME;
}
//---------------------UIMenuWndPhotoQS_Left_Panel Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndPhotoQS_Left_Panel)
CTRL_LIST_ITEM(UIMenuWndPhotoQS_Left_Menu)
CTRL_LIST_END

//----------------------UIMenuWndPhotoQS_Left_Panel Event---------------------------
EVENT_BEGIN(UIMenuWndPhotoQS_Left_Panel)
EVENT_END

//----------------------UIMenuWndPhotoQS_Left_Menu Event---------------------------
INT32 UIMenuWndPhotoQS_Left_Menu_OnKeyUp(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPhotoQS_Left_Menu_OnKeyDown(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndPhotoQS_Left_Menu)
EVENT_ITEM(NVTEVT_KEY_UP, UIMenuWndPhotoQS_Left_Menu_OnKeyUp)
EVENT_ITEM(NVTEVT_KEY_DOWN, UIMenuWndPhotoQS_Left_Menu_OnKeyDown)
EVENT_END

INT32 UIMenuWndPhotoQS_Left_Menu_OnKeyUp(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
	INT32   item;
	item = UxMenu_GetData(pCtrl, MNU_CURITM);
	item = (item + 1) % UIMenuWndPhotoQS_Left_Menu_MAX;
	switch (item) {
	case UIMenuWndPhotoQS_Left_Menu_ICON_EV_P0P0:
		UxState_SetData(&UIMenuWndPhotoQS_Title_Mode_StatusCtrl, STATE_CURITEM, UIMenuWndPhotoQS_Title_Mode_Status_STRID_EXPOSURE);
		UxCtrl_SetShow(&UIMenuWndPhotoQS_EV_MenuCtrl, TRUE);
		UxCtrl_SetShow(&UIMenuWndPhotoQS_AWB_MenuCtrl, FALSE);
		UxCtrl_SetShow(&UIMenuWndPhotoQS_Help_StatusCtrl, FALSE);
		break;
	case UIMenuWndPhotoQS_Left_Menu_ICON_WB_AUTO:
		UxState_SetData(&UIMenuWndPhotoQS_Title_Mode_StatusCtrl, STATE_CURITEM, UIMenuWndPhotoQS_Title_Mode_Status_STRID_WB);
		UxCtrl_SetShow(&UIMenuWndPhotoQS_EV_MenuCtrl, FALSE);
		UxCtrl_SetShow(&UIMenuWndPhotoQS_AWB_MenuCtrl, TRUE);
		UxCtrl_SetShow(&UIMenuWndPhotoQS_Help_StatusCtrl, TRUE);
		break;
	}
	Ux_SendEvent(pCtrl, NVTEVT_PREVIOUS_ITEM, 0);
	return NVTEVT_CONSUME;
}
INT32 UIMenuWndPhotoQS_Left_Menu_OnKeyDown(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
	INT32   item;
	item = UxMenu_GetData(pCtrl, MNU_CURITM);
	item = (item + 1) % UIMenuWndPhotoQS_Left_Menu_MAX;
	switch (item) {
	case UIMenuWndPhotoQS_Left_Menu_ICON_EV_P0P0:
		UxState_SetData(&UIMenuWndPhotoQS_Title_Mode_StatusCtrl, STATE_CURITEM, UIMenuWndPhotoQS_Title_Mode_Status_STRID_EXPOSURE);
		UxCtrl_SetShow(&UIMenuWndPhotoQS_EV_MenuCtrl, TRUE);
		UxCtrl_SetShow(&UIMenuWndPhotoQS_AWB_MenuCtrl, FALSE);
		UxCtrl_SetShow(&UIMenuWndPhotoQS_Help_StatusCtrl, FALSE);
		break;
	case UIMenuWndPhotoQS_Left_Menu_ICON_WB_AUTO:
		UxState_SetData(&UIMenuWndPhotoQS_Title_Mode_StatusCtrl, STATE_CURITEM, UIMenuWndPhotoQS_Title_Mode_Status_STRID_WB);
		UxCtrl_SetShow(&UIMenuWndPhotoQS_EV_MenuCtrl, FALSE);
		UxCtrl_SetShow(&UIMenuWndPhotoQS_AWB_MenuCtrl, TRUE);
		UxCtrl_SetShow(&UIMenuWndPhotoQS_Help_StatusCtrl, TRUE);
		break;
	}
	Ux_SendEvent(pCtrl, NVTEVT_NEXT_ITEM, 0);
	return NVTEVT_CONSUME;
}
//----------------------UIMenuWndPhotoQS_Help_Status Event---------------------------
EVENT_BEGIN(UIMenuWndPhotoQS_Help_Status)
EVENT_END

