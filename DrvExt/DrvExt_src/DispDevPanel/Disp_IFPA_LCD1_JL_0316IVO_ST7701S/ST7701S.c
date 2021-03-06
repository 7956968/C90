/*
    Display object object panel configuration parameters for T30P105

    @file       T30P106.c
    @ingroup
    @note       Nothing

    Copyright   Novatek Microelectronics Corp. 2011.  All rights reserved.
*/

#include "kernel.h"
#include "Debug.h"
#include "display.h"
#include "dispdev_IFParal.h"
#include "dispdev_panlcomn.h"

#define IFCMD_CMD		0x01000000
#define IFCMD_DATA		0x02000000

#define PANEL_WIDTH     320
#define PANEL_HEIGHT    820
/*
#define HSYNCT      30
#define VSYNCT      4
*/

/*
    Panel Parameters for T30P105
*/
const tPANEL_CMD tCmdStandby[] =
{
  //  {0x2B, 0x00}
};


const tPANEL_CMD tCmdModeRgbd320[] =
{
    {IFCMD_CMD , 0xFF},     
    {IFCMD_DATA , 0x77},   
    {IFCMD_DATA , 0x01},   
    {IFCMD_DATA , 0x00},   
    {IFCMD_DATA , 0x00},   
    {IFCMD_DATA , 0x13},   

    {IFCMD_CMD , 0xEF},     
    {IFCMD_DATA , 0x08},   

    {IFCMD_CMD , 0xFF},     
    {IFCMD_DATA , 0x77},   
    {IFCMD_DATA , 0x01},   
    {IFCMD_DATA , 0x00},   
    {IFCMD_DATA , 0x00},   
    {IFCMD_DATA , 0x10},   

    {IFCMD_CMD , 0xC0},     
    {IFCMD_DATA , 0xE5},   
    {IFCMD_DATA , 0x02},   

    {IFCMD_CMD , 0xC1},     
    {IFCMD_DATA , 0x0C},   
    {IFCMD_DATA , 0x0A},   

    {IFCMD_CMD , 0xC2},     
    {IFCMD_DATA , 0x07},   
    {IFCMD_DATA , 0x0F},   
/*
    {IFCMD_CMD , 0xC3},     
    {IFCMD_DATA , 0x00},   
*/
    {IFCMD_CMD , 0xCC},     
    {IFCMD_DATA , 0x18},   

    {IFCMD_CMD , 0xB0},//Positive Voltage Gamma Control     
    {IFCMD_DATA , 0x00},   
    {IFCMD_DATA , 0x08},   
    {IFCMD_DATA , 0x51},   
    {IFCMD_DATA , 0x0D},   
    {IFCMD_DATA , 0xCE},   
    {IFCMD_DATA , 0x06},   
    {IFCMD_DATA , 0x00},   
    {IFCMD_DATA , 0x08},   
    {IFCMD_DATA , 0x08},   
    {IFCMD_DATA , 0x1D},   
    {IFCMD_DATA , 0x02},   
    {IFCMD_DATA , 0xD0},   
    {IFCMD_DATA , 0x0F},   
    {IFCMD_DATA , 0x6F},   
    {IFCMD_DATA , 0x36},   
    {IFCMD_DATA , 0x3F},   

    {IFCMD_CMD , 0xB1},//Negative Voltage Gamma Control     
    {IFCMD_DATA , 0x00},   
    {IFCMD_DATA , 0x10},   
    {IFCMD_DATA , 0x4F},   
    {IFCMD_DATA , 0x0C},   
    {IFCMD_DATA , 0x11},   
    {IFCMD_DATA , 0x05},   
    {IFCMD_DATA , 0x00},   
    {IFCMD_DATA , 0x07},   
    {IFCMD_DATA , 0x07},   
    {IFCMD_DATA , 0x1F},   
    {IFCMD_DATA , 0x05},   
    {IFCMD_DATA , 0xD3},   
    {IFCMD_DATA , 0x11},   
    {IFCMD_DATA , 0x6E},   
    {IFCMD_DATA , 0x34},   
    {IFCMD_DATA , 0x3F},   

    {IFCMD_CMD , 0xFF},     
    {IFCMD_DATA , 0x77},   
    {IFCMD_DATA , 0x01},   
    {IFCMD_DATA , 0x00},   
    {IFCMD_DATA , 0x00},   
    {IFCMD_DATA , 0x11},   

    {IFCMD_CMD , 0xB0},//Vop Amplitude setting     
    {IFCMD_DATA , 0x4D},   

    {IFCMD_CMD , 0xB1},//VCOM amplitude setting     
    {IFCMD_DATA , 0x68},   

    {IFCMD_CMD , 0xB2},     
    {IFCMD_DATA , 0x87},   

    {IFCMD_CMD , 0xB3},     
    {IFCMD_DATA , 0x80},   

    {IFCMD_CMD , 0xB5},     
    {IFCMD_DATA , 0x47},   

    {IFCMD_CMD , 0xB7},     
    {IFCMD_DATA , 0x85},   

    {IFCMD_CMD , 0xB8},     
    {IFCMD_DATA , 0x21},   

    {IFCMD_CMD , 0xB9},     
    {IFCMD_DATA , 0x10},   

    {IFCMD_CMD , 0xC1},     
    {IFCMD_DATA , 0x78},   

    {IFCMD_CMD , 0xC2},     
    {IFCMD_DATA , 0x78},   

    {IFCMD_CMD , 0xD0},     
    {IFCMD_DATA , 0x88},   

    {CMDDELAY_MS,   100},

    {IFCMD_CMD , 0xE0},     
    {IFCMD_DATA , 0x80},   
    {IFCMD_DATA , 0x00},   
    {IFCMD_DATA , 0x02},   

    {IFCMD_CMD , 0xE1},     
    {IFCMD_DATA , 0x04},   
    {IFCMD_DATA , 0xA0},   
    {IFCMD_DATA , 0x00},   
    {IFCMD_DATA , 0x00},   
    {IFCMD_DATA , 0x05},   
    {IFCMD_DATA , 0xA0},   
    {IFCMD_DATA , 0x00},   
    {IFCMD_DATA , 0x00},   
    {IFCMD_DATA , 0x00},   
    {IFCMD_DATA , 0x60},   
    {IFCMD_DATA , 0x60},   

    {IFCMD_CMD , 0xE2},     
    {IFCMD_DATA , 0x30},   
    {IFCMD_DATA , 0x30},   
    {IFCMD_DATA , 0x60},   
    {IFCMD_DATA , 0x60},   
    {IFCMD_DATA , 0x3C},   
    {IFCMD_DATA , 0xA0},   
    {IFCMD_DATA , 0x00},   
    {IFCMD_DATA , 0x00},   
    {IFCMD_DATA , 0x3D},   
    {IFCMD_DATA , 0xA0},   
    {IFCMD_DATA , 0x00},   
    {IFCMD_DATA , 0x00},   
    {IFCMD_DATA , 0x00},   

    {IFCMD_CMD , 0xE3},     
    {IFCMD_DATA , 0x00},   
    {IFCMD_DATA , 0x00},   
    {IFCMD_DATA , 0x33},   
    {IFCMD_DATA , 0x33},   

    {IFCMD_CMD , 0xE4},     
    {IFCMD_DATA , 0x44},   
    {IFCMD_DATA , 0x44},   

    {IFCMD_CMD , 0xE5},     
    {IFCMD_DATA , 0x06},   
    {IFCMD_DATA , 0x3E},   
    {IFCMD_DATA , 0xA0},   
    {IFCMD_DATA , 0xA0},   
    {IFCMD_DATA , 0x08},   
    {IFCMD_DATA , 0x40},   
    {IFCMD_DATA , 0xA0},   
    {IFCMD_DATA , 0xA0},   
    {IFCMD_DATA , 0x0A},   
    {IFCMD_DATA , 0x42},   
    {IFCMD_DATA , 0xA0},   
    {IFCMD_DATA , 0xA0},   
    {IFCMD_DATA , 0x0C},   
    {IFCMD_DATA , 0x44},   
    {IFCMD_DATA , 0xA0},   
    {IFCMD_DATA , 0xA0},   

    {IFCMD_CMD , 0xE6},     
    {IFCMD_DATA , 0x00},   
    {IFCMD_DATA , 0x00},   
    {IFCMD_DATA , 0x33},   
    {IFCMD_DATA , 0x33},   

    {IFCMD_CMD , 0xE7},     
    {IFCMD_DATA , 0x44},   
    {IFCMD_DATA , 0x44},   

    {IFCMD_CMD , 0xE8},     
    {IFCMD_DATA , 0x07},   
    {IFCMD_DATA , 0x3F},   
    {IFCMD_DATA , 0xA0},   
    {IFCMD_DATA , 0xA0},   
    {IFCMD_DATA , 0x09},   
    {IFCMD_DATA , 0x41},   
    {IFCMD_DATA , 0xA0},   
    {IFCMD_DATA , 0xA0},   
    {IFCMD_DATA , 0x0B},   
    {IFCMD_DATA , 0x43},   
    {IFCMD_DATA , 0xA0},   
    {IFCMD_DATA , 0xA0},   
    {IFCMD_DATA , 0x0D},   
    {IFCMD_DATA , 0x45},   
    {IFCMD_DATA , 0xA0},   
    {IFCMD_DATA , 0xA0},   

    {IFCMD_CMD , 0xEB},     
    {IFCMD_DATA , 0x00},   
    {IFCMD_DATA , 0x01},   
    {IFCMD_DATA , 0x4E},   
    {IFCMD_DATA , 0x4E},   
    {IFCMD_DATA , 0xEE},   
    {IFCMD_DATA , 0x44},   
    {IFCMD_DATA , 0x00},   

    {IFCMD_CMD , 0xED},     
    {IFCMD_DATA , 0xFF},   
    {IFCMD_DATA , 0xFF},   
    {IFCMD_DATA , 0x04},   
    {IFCMD_DATA , 0x56},   
    {IFCMD_DATA , 0x72},   
    {IFCMD_DATA , 0xFF},   
    {IFCMD_DATA , 0xFF},   
    {IFCMD_DATA , 0xFF},   
    {IFCMD_DATA , 0xFF},   
    {IFCMD_DATA , 0xFF},   
    {IFCMD_DATA , 0xFF},   
    {IFCMD_DATA , 0x27},   
    {IFCMD_DATA , 0x65},   
    {IFCMD_DATA , 0x40},   
    {IFCMD_DATA , 0xFF},   
    {IFCMD_DATA , 0xFF},   

    {IFCMD_CMD , 0xEF},     
    {IFCMD_DATA , 0x10},   
    {IFCMD_DATA , 0x0D},   
    {IFCMD_DATA , 0x04},   
    {IFCMD_DATA , 0x08},   
    {IFCMD_DATA , 0x3F},   
    {IFCMD_DATA , 0x1F},   

    {IFCMD_CMD , 0xFF},     
    {IFCMD_DATA , 0x77},   
    {IFCMD_DATA , 0x01},   
    {IFCMD_DATA , 0x00},   
    {IFCMD_DATA , 0x00},   
    {IFCMD_DATA , 0x13},   

    {IFCMD_CMD , 0xE8},     
    {IFCMD_DATA , 0x00},   
    {IFCMD_DATA , 0x0E},   

    {IFCMD_CMD , 0xFF},     
    {IFCMD_DATA , 0x77},   
    {IFCMD_DATA , 0x01},   
    {IFCMD_DATA , 0x00},   
    {IFCMD_DATA , 0x00},   
    {IFCMD_DATA , 0x00},   

    {IFCMD_CMD , 0x11},     

    {CMDDELAY_MS,   120},

    {IFCMD_CMD , 0xFF},     
    {IFCMD_DATA , 0x77},   
    {IFCMD_DATA , 0x01},   
    {IFCMD_DATA , 0x00},   
    {IFCMD_DATA , 0x00},   
    {IFCMD_DATA , 0x13},   

    {IFCMD_CMD , 0xE8},     
    {IFCMD_DATA , 0x00},   
    {IFCMD_DATA , 0x0C},   

    {CMDDELAY_MS,   10},

    {IFCMD_CMD , 0xE8},     
    {IFCMD_DATA , 0x00},   
    {IFCMD_DATA , 0x00},   

    {IFCMD_CMD , 0xFF},     
    {IFCMD_DATA , 0x77},   
    {IFCMD_DATA , 0x01},   
    {IFCMD_DATA , 0x00},   
    {IFCMD_DATA , 0x00},   
    {IFCMD_DATA , 0x00},   

    {IFCMD_CMD , 0x3A},     
    {IFCMD_DATA , 0x55},   

    {IFCMD_CMD , 0x36},     
    {IFCMD_DATA , 0x00},   

    {IFCMD_CMD , 0x35},     
    {IFCMD_DATA , 0x00},   

    {IFCMD_CMD , 0x29},     
};

//VBP>=12, VFP>=12, to fit IVO VSW=2, VBP=15, VFP=15
const tLCD_PARAM tMode[] =
{
    /***********       RGB Dummy-320 MODE         *************/
    {
        // tPANEL_PARAM
        {
            /* Old prototype */
            PINMUX_LCDMODE_RGB_PARALL565,//PINMUX_LCDMODE_RGB_THROUGH,         //!< LCDMode
            24.0f,// max is 1/33                 //!< fDCLK 24.54f,
            (10+480),//1048,                           //!< uiHSyncTotalPeriod
            480,//960,                           //!< uiHSyncActivePeriod
            4,//36,                            //!< uiHSyncBackPorch
            (25+820),                            //!< uiVSyncTotalPeriod
            820,                            //!< uiVSyncActivePeriod
            12,//20, //27                            //!< uiVSyncBackPorchOdd  29
            12,//20,//27.5                             //!< uiVSyncBackPorchEven 29.5
            PANEL_WIDTH,                            //!< uiBufferWidth
            PANEL_HEIGHT,                            //!< uiWindowHeight
            PANEL_WIDTH,                            //!< uiWindowWidth
            PANEL_HEIGHT,                            //!< uiWindowHeight
            FALSE,                          //!< bYCbCrFormat

            /* New added parameters */
            0x01,                           //!< uiHSyncSYNCwidth
            0x01,                           //!< uiVSyncSYNCwidth
        },

        // tIDE_PARAM
        {
            /* Old prototype */
            PINMUX_LCD_SEL_PARALLE_RGB565|PINMUX_LCD_SEL_DE_ENABLE,//PINMUX_LCD_SEL_SERIAL_RGB_8BITS,//!< pinmux_select_lcd;
            ICST_CCIR601,                   //!< icst;
            {TRUE,TRUE},                  //!< dithering[2];
            DISPLAY_DEVICE_AU,              //!< **DONT-CARE**
            IDE_PDIR_RGB,                   //!< pdir;
            IDE_LCD_B,                      //!< odd;
            IDE_LCD_G,                      //!< even;
            TRUE,                           //!< hsinv;
            TRUE,                           //!< vsinv;
            FALSE,                          //!< hvldinv;
            FALSE,                          //!< vvldinv;
            TRUE,                           //!< clkinv;
            FALSE,                          //!< fieldinv;
            FALSE,                          //!< **DONT-CARE**
            FALSE,                          //!< interlace;
            FALSE,                          //!< **DONT-CARE**
            0x40,                           //!< ctrst;
            0x00,                           //!< brt;
            0x58,                           //!< cmults;
            FALSE,                          //!< cex;
            FALSE,                          //!< **DONT-CARE**
            TRUE,                           //!< **DONT-CARE**
            TRUE,                           //!< tv_powerdown;
            {0x00,0x00},                    //!< **DONT-CARE**

            /* New added parameters */
            FALSE,                          //!< YCex
            FALSE,                          //!< HLPF
            {FALSE,FALSE,FALSE},            //!< subpixOdd[3]
            {FALSE,FALSE,FALSE},            //!< subpixEven[3]
            {IDE_DITHER_5BITS,IDE_DITHER_6BITS,IDE_DITHER_5BITS}//!< DitherBits[3]
        },

        (tPANEL_CMD*)tCmdModeRgbd320,                  //!< pCmdQueue
        sizeof(tCmdModeRgbd320)/sizeof(tPANEL_CMD),    //!< nCmd
    }
};
const tPANEL_CMD tCmdRotate_None[] =
{
    //{0x04,0x1b}
    //{0x0B,0x00},
};
const tPANEL_CMD tCmdRotate_180[] =
{
    //{0x04,0x1B}
    //{0x0B,0x03},

};
const tLCD_ROT tRotate[] =
{
    {DISPDEV_LCD_ROTATE_NONE,(tPANEL_CMD*)tCmdRotate_None,1},
    {DISPDEV_LCD_ROTATE_180,(tPANEL_CMD*)tCmdRotate_180,1}
};
//@}

tLCD_ROT* dispdev_getLcdRotateCmdParal(UINT32 *ModeNumber)
{
    if(tRotate != NULL)
    {
        *ModeNumber = sizeof(tRotate)/sizeof(tLCD_ROT);
    }
    else
    {
        *ModeNumber = 0;
    }
    return (tLCD_ROT*)tRotate;
}

tLCD_PARAM* dispdev_getConfigModeParal(UINT32 *ModeNumber)
{
    *ModeNumber = sizeof(tMode)/sizeof(tLCD_PARAM);
    return (tLCD_PARAM*)tMode;
}

tPANEL_CMD* dispdev_getStandbyCmdParal(UINT32 *CmdNumber)
{
    *CmdNumber = sizeof(tCmdStandby)/sizeof(tPANEL_CMD);
    return (tPANEL_CMD*)tCmdStandby;
}

#if 1
void dispdev_writeToLcdSifParal(DISPDEV_IOCTRL pDispDevControl, UINT32 addr, UINT32 value)
{
    UINT32                  uiSIFData;
    DISPDEV_IOCTRL_PARAM    DevIOCtrl;

    uiSIFData = ((((UINT32)addr << 8)|((UINT32)value)) << 16);

    pDispDevControl(DISPDEV_IOCTRL_GET_REG_IF, &DevIOCtrl);
    sif_send(DevIOCtrl.SEL.GET_REG_IF.uiSifCh, uiSIFData, 0, 0);
}

void dispdev_writeToLcdGpioParal(DISPDEV_IOCTRL pDispDevControl, UINT32 addr, UINT32 value)
{
    //UINT32                  uiSIFData,j,i;
    UINT32                  j;
    UINT32                  SifClk,SifSen,SifData;
    DISPDEV_IOCTRL_PARAM    DevIOCtrl;

    pDispDevControl(DISPDEV_IOCTRL_GET_REG_IF, &DevIOCtrl);
    SifClk  = DevIOCtrl.SEL.GET_REG_IF.uiGpioClk;
    SifSen  = DevIOCtrl.SEL.GET_REG_IF.uiGpioSen;
    SifData = DevIOCtrl.SEL.GET_REG_IF.uiGpioData;

    gpio_setDir(SifSen, GPIO_DIR_OUTPUT);
    gpio_setDir(SifClk, GPIO_DIR_OUTPUT);
    gpio_setDir(SifData, GPIO_DIR_OUTPUT);

    gpio_setPin(SifSen);
    gpio_setPin(SifData);
    gpio_setPin(SifClk);

    //uiSIFData = (UINT32)addr << 8 | (UINT32)value;
    //debug_msg("Has not implement dispdev_readFromLcdGpio%x %x  %x\r\n",uiSIFData,addr,value);
    Delay_DelayUs(500);

    gpio_clearPin(SifSen);

	if (addr == IFCMD_CMD) {
        value = (value & 0x00ff);
		for (j = 9; j > 0; j--) {
			if (((value >> (j - 1)) & 0x01)) {
				gpio_setPin(SifData);
			} else {
				gpio_clearPin(SifData);
			}

			Delay_DelayUs(100);
			gpio_clearPin(SifClk);
			Delay_DelayUs(200);
			gpio_setPin(SifClk);
			Delay_DelayUs(100);
		}
	} else if (addr == IFCMD_DATA) {
		value = ((value & 0x00ff) | 0x100);
		for (j = 9; j > 0; j--) {
			if (((value >> (j - 1)) & 0x01)) {
				gpio_setPin(SifData);
			} else {
				gpio_clearPin(SifData);
			}

			Delay_DelayUs(100);
			gpio_clearPin(SifClk);
			Delay_DelayUs(200);
			gpio_setPin(SifClk);
			Delay_DelayUs(100);
		}
	}

    Delay_DelayUs(500);
    gpio_setPin(SifSen);

}


void dispdev_readFromLcdGpioParal(DISPDEV_IOCTRL pDispDevControl, UINT32 addr, UINT32* p_value)
{
    //debug_err(("Has not implement dispdev_readFromLcdGpio \r\n"));
}
#endif
