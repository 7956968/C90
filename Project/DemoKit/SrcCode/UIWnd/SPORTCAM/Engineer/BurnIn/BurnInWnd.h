//This source code is generated by UI Designer Studio.

#ifndef BURNINWND_H
#define BURNINWND_H

#include "UIFramework.h"

extern VControl BurnInWndCtrl;//Panel type

//---------------------BurnInWndCtrl User Export---------------------------
extern void BurnIn_DrawLoopCount(BOOL bClear);
extern void BurnIn_DrawStatus(CHAR *pStr, UINT32 uiColor, BOOL bClear);
extern void BurnIn_DrawTime(UINT32 uiTime);
extern void BurnIn_DrawTips(CHAR *pStr);

#endif