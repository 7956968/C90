//This source code is generated by UI Designer Studio.

#ifndef LEDTESTWNDRES_H
#define LEDTESTWNDRES_H

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIDisplayUtil.h"
//------------------------------------------------------------

SHOW_ITEM_RECT(CMD_Rectangle,Skin1Rect,0,0,319,239,0,0,14,14,0,0,0)
SHOW_MAP_BEGIN(Skin1)
SHOW_MAP_BODY(Skin1Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin1,0,0,319,239)

SHOW_MAP_BEGIN(LEDTestWnd)
SHOW_MAP_BODY(Skin1)
SHOW_MAP_END

DECLARE_EVENT(LEDTestWnd)
DECLARE_CTRL_LIST(LEDTestWnd)
CREATE_CTRL(LEDTestWnd,LEDTestWnd,CTRL_WND,NULL,0 ,0,0,319,239)
#endif
