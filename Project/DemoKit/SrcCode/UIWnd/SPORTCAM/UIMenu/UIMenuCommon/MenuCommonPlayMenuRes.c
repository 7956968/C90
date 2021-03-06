//This source code is generated by UI Designer Studio.

#ifndef MENUCOMMONPLAYMENURES_H
#define MENUCOMMONPLAYMENURES_H

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIDisplayUtil.h"
//------------------------------------------------------------

SHOW_ITEM_RECT(CMD_Rectangle,Skin1Rect,0,0,1279,319,0,0,1,1,0,0,0)
SHOW_MAP_BEGIN(Skin1)
SHOW_MAP_BODY(Skin1Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin1,0,0,1279,319)

SHOW_ITEM_ROUNDRECT(CMD_RoundRect,RoundRect4,46,23,705,72,16,2,19,255,0,0,0,50,48)
SHOW_MAP_BEGIN(Skin2)
SHOW_MAP_BODY(RoundRect4)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin2,0,0,755,72)

SHOW_MAP_BEGIN(Skin6)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin6,0,0,110,79)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon7, 0, 0, 109,78, ICONID_NULL,83886080,0,0,0,0,0,33,0)
SHOW_MAP_BEGIN(Normal5)
SHOW_MAP_BODY(Skin6)
SHOW_MAP_BODY(Icon7)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal5,486,240,596,319)

SHOW_MAP_BEGIN(Skin9)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin9,0,0,110,79)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon10, 0, 0, 109,78, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Focused8)
SHOW_MAP_BODY(Skin9)
SHOW_MAP_BODY(Icon10)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused8,486,240,596,319)

SHOW_MAP_BEGIN(Skin12)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin12,0,0,110,79)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon13, 0, 0, 109,78, ICONID_NULL,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal_Disable11)
SHOW_MAP_BODY(Skin12)
SHOW_MAP_BODY(Icon13)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal_Disable11,486,240,596,319)

SHOW_MAP_BEGIN(Skin15)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin15,0,0,110,79)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon16, 0, 0, 109,78, ICONID_NULL,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Focused_Disable14)
SHOW_MAP_BODY(Skin15)
SHOW_MAP_BODY(Icon16)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused_Disable14,486,240,596,319)

SHOW_MAP_BEGIN(Skin18)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin18,0,0,110,79)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon19, 0, 0, 109,78, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Pressed17)
SHOW_MAP_BODY(Skin18)
SHOW_MAP_BODY(Icon19)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Pressed17,486,240,596,319)

CREATE_BUTTON_ITEM_DATA(ICON_OPERATE_RETURN20,STRID_NULL,ICON_OPERATE_RETURN,STATUS_ENABLE,NULL) 
SHOW_MAP_BEGIN(MenuCommonPlayMenu_BTN_Return)
SHOW_MAP_BODY(Normal5)
SHOW_MAP_BODY(Focused8)
SHOW_MAP_BODY(Normal_Disable11)
SHOW_MAP_BODY(Focused_Disable14)
SHOW_MAP_BODY(Pressed17)
SHOW_MAP_END

DECLARE_EVENT(MenuCommonPlayMenu_BTN_Return)
BUTTON_LIST_BEGIN(MenuCommonPlayMenu_BTN_Return)
BUTTON_LIST_ITEM(ICON_OPERATE_RETURN20)
BUTTON_LIST_END

CREATE_BUTTON_DATA(MenuCommonPlayMenu_BTN_Return,BTN_DRAW_IMAGE)

CREATE_BUTTON_CTRL(MenuCommonPlayMenu_BTN_Return,MenuCommonPlayMenu_BTN_Return,0,222,-7,332,72)
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin22)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin22,0,0,100,76)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon23, 0, 0, 101,76, ICONID_NULL,83886080,0,0,0,0,0,33,0)
SHOW_MAP_BEGIN(Normal21)
SHOW_MAP_BODY(Skin22)
SHOW_MAP_BODY(Icon23)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal21,695,243,795,319)

SHOW_MAP_BEGIN(Skin25)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin25,0,0,100,76)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon26, 0, 0, 101,76, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Focused24)
SHOW_MAP_BODY(Skin25)
SHOW_MAP_BODY(Icon26)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused24,695,243,795,319)

SHOW_MAP_BEGIN(Skin28)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin28,0,0,100,76)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon29, 0, 0, 101,76, ICONID_NULL,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal_Disable27)
SHOW_MAP_BODY(Skin28)
SHOW_MAP_BODY(Icon29)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal_Disable27,695,243,795,319)

SHOW_MAP_BEGIN(Skin31)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin31,0,0,100,76)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon32, 0, 0, 101,76, ICONID_NULL,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Focused_Disable30)
SHOW_MAP_BODY(Skin31)
SHOW_MAP_BODY(Icon32)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused_Disable30,695,243,795,319)

SHOW_MAP_BEGIN(Skin34)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin34,0,0,100,76)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon35, 0, 0, 101,76, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Pressed33)
SHOW_MAP_BODY(Skin34)
SHOW_MAP_BODY(Icon35)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Pressed33,695,243,795,319)

CREATE_BUTTON_ITEM_DATA(ICON_OPERATE_EXIT36,STRID_NULL,ICON_OPERATE_EXIT,STATUS_ENABLE,NULL) 
SHOW_MAP_BEGIN(MenuCommonPlayMenu_BTN_Exit)
SHOW_MAP_BODY(Normal21)
SHOW_MAP_BODY(Focused24)
SHOW_MAP_BODY(Normal_Disable27)
SHOW_MAP_BODY(Focused_Disable30)
SHOW_MAP_BODY(Pressed33)
SHOW_MAP_END

DECLARE_EVENT(MenuCommonPlayMenu_BTN_Exit)
BUTTON_LIST_BEGIN(MenuCommonPlayMenu_BTN_Exit)
BUTTON_LIST_ITEM(ICON_OPERATE_EXIT36)
BUTTON_LIST_END

CREATE_BUTTON_DATA(MenuCommonPlayMenu_BTN_Exit,BTN_DRAW_IMAGE)

CREATE_BUTTON_CTRL(MenuCommonPlayMenu_BTN_Exit,MenuCommonPlayMenu_BTN_Exit,0,431,-4,531,72)
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(MenuCommonPlayMenu_Panel_Operate)
SHOW_MAP_BODY(Skin2)
SHOW_MAP_END

DECLARE_EVENT(MenuCommonPlayMenu_Panel_Operate)
DECLARE_CTRL_LIST(MenuCommonPlayMenu_Panel_Operate)
CREATE_CTRL(MenuCommonPlayMenu_Panel_Operate,MenuCommonPlayMenu_Panel_Operate,CTRL_WND,NULL,0 ,264,247,1019,319)
SHOW_ITEM_RECT(CMD_Rectangle,Skin37Rect,0,0,426,139,0,0,1,1,0,0,0)
SHOW_MAP_BEGIN(Skin37)
SHOW_MAP_BODY(Skin37Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin37,0,0,426,139)

SHOW_ITEM_RECT(CMD_Rectangle,Skin39Rect,0,0,117,138,0,0,1,1,0,0,0)
SHOW_MAP_BEGIN(Skin39)
SHOW_MAP_BODY(Skin39Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin39,0,0,117,138)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon40, 0, 0, 121,138, ICONID_NULL,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal38)
SHOW_MAP_BODY(Skin39)
SHOW_MAP_BODY(Icon40)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal38,457,67,574,205)

CREATE_STATE_ITEM_DATA(ICON_PBMENU_LOOP41,STRID_NULL,ICON_PBMENU_LOOP,NULL) 
CREATE_STATE_ITEM_DATA(ICON_PBMENU_LOOP_F42,STRID_NULL,ICON_PBMENU_LOOP_F,NULL) 
SHOW_MAP_BEGIN(Status_loopC)
SHOW_MAP_BODY(Normal38)
SHOW_MAP_END

DECLARE_EVENT(Status_loopC)
STATE_LIST_BEGIN(Status_loopC)
STATE_LIST_ITEM(ICON_PBMENU_LOOP41)
STATE_LIST_ITEM(ICON_PBMENU_LOOP_F42)
STATE_LIST_END

CREATE_STATE_DATA(Status_loopC,0)
CREATE_STATE_CTRL(Status_loopC,0,23,0,140,138)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin44Rect,0,0,119,138,0,0,1,1,0,0,0)
SHOW_MAP_BEGIN(Skin44)
SHOW_MAP_BODY(Skin44Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin44,0,0,119,138)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon45, 0, 0, 119,138, ICONID_NULL,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal43)
SHOW_MAP_BODY(Skin44)
SHOW_MAP_BODY(Icon45)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal43,700,67,819,205)

CREATE_STATE_ITEM_DATA(ICON_PBMENU_URG46,STRID_NULL,ICON_PBMENU_URG,NULL) 
CREATE_STATE_ITEM_DATA(ICON_PBMENU_URG_F47,STRID_NULL,ICON_PBMENU_URG_F,NULL) 
SHOW_MAP_BEGIN(Status_EMRC)
SHOW_MAP_BODY(Normal43)
SHOW_MAP_END

DECLARE_EVENT(Status_EMRC)
STATE_LIST_BEGIN(Status_EMRC)
STATE_LIST_ITEM(ICON_PBMENU_URG46)
STATE_LIST_ITEM(ICON_PBMENU_URG_F47)
STATE_LIST_END

CREATE_STATE_DATA(Status_EMRC,0)
CREATE_STATE_CTRL(Status_EMRC,0,266,0,385,138)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin49Rect,0,0,119,138,0,0,1,1,0,0,0)
SHOW_MAP_BEGIN(Skin49)
SHOW_MAP_BODY(Skin49Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin49,0,0,119,138)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon50, 0, 0, 119,138, ICONID_NULL,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal48)
SHOW_MAP_BODY(Skin49)
SHOW_MAP_BODY(Icon50)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal48,741,67,860,205)

CREATE_STATE_ITEM_DATA(ICON_PBMENU_PHOTO51,STRID_NULL,ICON_PBMENU_PHOTO,NULL) 
CREATE_STATE_ITEM_DATA(ICON_PBMENU_PHOTO_F52,STRID_NULL,ICON_PBMENU_PHOTO_F,NULL) 
SHOW_MAP_BEGIN(Status_PHOTO)
SHOW_MAP_BODY(Normal48)
SHOW_MAP_END

DECLARE_EVENT(Status_PHOTO)
STATE_LIST_BEGIN(Status_PHOTO)
STATE_LIST_ITEM(ICON_PBMENU_PHOTO51)
STATE_LIST_ITEM(ICON_PBMENU_PHOTO_F52)
STATE_LIST_END

CREATE_STATE_DATA(Status_PHOTO,0)
CREATE_STATE_CTRL(Status_PHOTO,0,307,0,426,138)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(MenuCommonPlayMenu_List)
SHOW_MAP_BODY(Skin37)
SHOW_MAP_END

DECLARE_EVENT(MenuCommonPlayMenu_List)
DECLARE_CTRL_LIST(MenuCommonPlayMenu_List)
CREATE_CTRL(MenuCommonPlayMenu_List,MenuCommonPlayMenu_List,CTRL_WND,NULL,0 ,434,67,860,206)
SHOW_MAP_BEGIN(Skin54)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin54,0,0,149,49)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text56,0,0,149,49,STRID_NULL,0,0,0,0,129,1,1,0,0,16,0,2,0,0)
SHOW_MAP_BEGIN(Normal53)
SHOW_MAP_BODY(Skin54)
SHOW_MAP_BODY(Text56)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal53,115,0,264,49)

SHOW_MAP_BEGIN(MenuCommonPlayMenu_StaticTXT_Title)
SHOW_MAP_BODY(Normal53)
SHOW_MAP_END

DECLARE_EVENT(MenuCommonPlayMenu_StaticTXT_Title)
CREATE_STATIC_DATA(MenuCommonPlayMenu_StaticTXT_Title,STRID_A0)
CREATE_STATIC_CTRL(MenuCommonPlayMenu_StaticTXT_Title,0,115,0,264,49)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(MenuCommonPlayMenu)
SHOW_MAP_BODY(Skin1)
SHOW_MAP_END

DECLARE_EVENT(MenuCommonPlayMenu)
DECLARE_CTRL_LIST(MenuCommonPlayMenu)
CREATE_CTRL(MenuCommonPlayMenu,MenuCommonPlayMenu,CTRL_WND,NULL,0 ,0,0,1279,319)
#endif
