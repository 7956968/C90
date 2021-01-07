#ifndef  _DCS_H
#define  _DCS_H

#include "Type.h"

#define  LPDT_LPK  0x29
#define  LPDT_SPK  0x15

/////////////////////////////////////////////////////
//#define  CMDNUM (129)
//const  u8  dcs0[]  = {0x00,0x00};
//const  u8  dcs1[]  = {0xFF,0x12,0x84,0x01};
//const  u8  dcs2[]  = {0x00,0x80};
//const  u8  dcs3[]  = {0xFF,0x12,0x84};
//const  u8  dcs4[]  = {0x00,0x92};
//const  u8  dcs5[]  = {0xff,0x30,0x02};
//const  u8  dcs6[]  = {0x00,0x80};
//const  u8  dcs7[]  = {0xc0,0x00,0x64,0x00,0x15,0x15,0x00,0x64,0x15,0x15};
//const  u8  dcs8[]  = {0x00,0x90};
//const  u8  dcs9[]  = {0xC0,0x00,0x5C,0x00,0x01,0x00,0x04};
//const  u8  dcs10[] = {0x00,0x81};
//const  u8  dcs11[] = {0xC1,0x66};
//const  u8  dcs12[] = {0x00,0xA6};
//const  u8  dcs13[] = {0xB3,0x0F,0x01};
//const  u8  dcs14[] = {0x00,0x92};
//const  u8  dcs15[] = {0xC4,0x00};
//const  u8  dcs16[] = {0x00,0xA0};
//const  u8  dcs17[] = {0xC4,0x05,0x10,0x06,0x02,0x05,0x15,0x10,0x05,0x10,0x07,0x02,0x05,0x15,0x10};
//const  u8  dcs18[] = {0x00,0xB0};
//const  u8  dcs19[] = {0xC4,0x22,0x00};
//const  u8  dcs20[] = {0x00,0x91};
//const  u8  dcs21[] = {0xC5,0x46,0x42};
//const  u8  dcs22[] = {0x00,0x00};
//const  u8  dcs23[] = {0xD8,0xC7,0xC7};
//const  u8  dcs24[] = {0x00,0x00};
//const  u8  dcs25[] = {0xD9,0x65,0x65};
//const  u8  dcs26[] = {0x00,0x87};
//const  u8  dcs27[] = {0xC4,0x18};
//const  u8  dcs28[] = {0x00,0xB3};
//const  u8  dcs29[] = {0xC5,0x84};
//const  u8  dcs30[] = {0x00,0xBB};
//const  u8  dcs31[] = {0xC5,0x8a};
//const  u8  dcs32[] = {0x00,0x82};
//const  u8  dcs33[] = {0xC4,0x0a};
//const  u8  dcs34[] = {0x00,0xC6};
//const  u8  dcs35[] = {0xB0,0x03};
//const  u8  dcs36[] = {0x00,0xC2};
//const  u8  dcs37[] = {0xF5,0x40};
//const  u8  dcs38[] = {0x00,0xC3};
//const  u8  dcs39[] = {0xF5,0x85};
//const  u8  dcs40[] = {0x00,0x00};
//const  u8  dcs41[] = {0xD0,0x40};
//const  u8  dcs42[] = {0x00,0x00};
//const  u8  dcs43[] = {0xD1,0x00,0x00};
//const  u8  dcs44[] = {0x00,0x90};
//const  u8  dcs45[] = {0xF5,0x02,0x11,0x02,0x15};
//const  u8  dcs46[] = {0x00,0x90};
//const  u8  dcs47[] = {0xC5,0x50};
//const  u8  dcs48[] = {0x00,0x94};
//const  u8  dcs49[] = {0xC5,0x66,0x66,0x63};
//const  u8  dcs50[] = {0x00,0xB2};
//const  u8  dcs51[] = {0xF5,0x00,0x00};
//const  u8  dcs52[] = {0x00,0xB4};
//const  u8  dcs53[] = {0xF5,0x00,0x00};
//const  u8  dcs54[] = {0x00,0xB6};
//const  u8  dcs55[] = {0xF5,0x00,0x00};
//const  u8  dcs56[] = {0x00,0xB8};
//const  u8  dcs57[] = {0xF5,0x00,0x00};
//const  u8  dcs58[] = {0x00,0x94};
//const  u8  dcs59[] = {0xF5,0x00,0x00};
//const  u8  dcs60[] = {0x00,0xD2};
//const  u8  dcs61[] = {0xF5,0x06,0x15};
//const  u8  dcs62[] = {0x00,0xB4};
//const  u8  dcs63[] = {0xC5,0xCC};
//const  u8  dcs64[] = {0x00,0xB4};
//const  u8  dcs65[] = {0xC5,0xCC};
//const  u8  dcs66[] = {0x00,0xC0};
//const  u8  dcs67[] = {0xCB,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x00,0x15,0x15,0x00,0x00,0x00};
//const  u8  dcs68[] = {0x00,0xD0};
//const  u8  dcs69[] = {0xCB,0x15,0x15,0x00,0x15,0x15,0x15,0x00,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15};
//const  u8  dcs70[] = {0x00,0xE0};
//const  u8  dcs71[] = {0xCB,0x15,0x00,0x15,0x15,0x00,0x00,0x00,0x15,0x15,0x00,0x15,0x15,0x15,0x00};
//const  u8  dcs72[] = {0x00,0xF0};
//const  u8  dcs73[] = {0xCB,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
//const  u8  dcs74[] = {0x00,0x80};
//const  u8  dcs75[] = {0xCC,0x14,0x0c,0x12,0x0a,0x0e,0x16,0x10,0x18,0x02,0x00,0x2f,0x2f,0x00,0x00,0x00};
//const  u8  dcs76[] = {0x00,0x90};
//const  u8  dcs77[] = {0xCC,0x29,0x2a,0x00,0x2d,0x2e,0x06,0x00,0x13,0x0b,0x11,0x09,0x0d,0x15,0x0f,0x17};
//const  u8  dcs78[] = {0x00,0xA0};
//const  u8  dcs79[] = {0xCC,0x01,0x00,0x2f,0x2f,0x00,0x00,0x00,0x29,0x2a,0x00,0x2d,0x2e,0x05,0x00};
//const  u8  dcs80[] = {0x00,0xB0};
//const  u8  dcs81[] = {0xCC,0x0d,0x15,0x0f,0x17,0x13,0x0b,0x11,0x09,0x05,0x00,0x2f,0x2f,0x00,0x00,0x00};
//const  u8  dcs82[] = {0x00,0xC0};
//const  u8  dcs83[] = {0xCC,0x29,0x2a,0x00,0x2e,0x2d,0x01,0x00,0x0e,0x16,0x10,0x18,0x14,0x0c,0x12,0x0a};
//const  u8  dcs84[] = {0x00,0xD0};
//const  u8  dcs85[] = {0xCC,0x06,0x00,0x2f,0x2f,0x00,0x00,0x00,0x29,0x2a,0x00,0x2e,0x2d,0x02,0x00};
//const  u8  dcs86[] = {0x00,0x80};
//const  u8  dcs87[] = {0xCE,0x8F,0x0D,0x1A,0x8E,0x0D,0x1A,0x00,0x00,0x00,0x00,0x00,0x00};
//const  u8  dcs88[] = {0x00,0x90};
//const  u8  dcs89[] = {0xCE,0x75,0x00,0x1A,0x75,0x01,0x1A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
//const  u8  dcs90[] = {0x00,0xA0};
//const  u8  dcs91[] = {0xCE,0x78,0x07,0x84,0xF0,0x90,0x1A,0x00,0x78,0x06,0x84,0xF1,0x91,0x1A,0x00};
//const  u8  dcs92[] = {0x00,0xB0};
//const  u8  dcs93[] = {0xCE,0x78,0x05,0x84,0xF2,0x90,0x1A,0x00,0x78,0x04,0x84,0xF3,0x91,0x1A,0x00};
//const  u8  dcs94[] = {0x00,0xC0};
//const  u8  dcs95[] = {0xCE,0x78,0x03,0x84,0xF4,0x90,0x1A,0x00,0x78,0x02,0x84,0xF5,0x91,0x1A,0x00};
//const  u8  dcs96[] = {0x00,0xD0};
//const  u8  dcs97[] = {0xCE,0x78,0x01,0x84,0xF6,0x90,0x1A,0x00,0x78,0x00,0x84,0xF7,0x91,0x1A,0x00};
//const  u8  dcs98[] = {0x00,0x80};
//const  u8  dcs99[] = {0xCF,0x70,0x00,0x84,0xF8,0x90,0x1A,0x00,0x70,0x01,0x84,0xF9,0x91,0x1A,0x00};
//const  u8  dcs100[]= {0x00,0x90};
//const  u8  dcs101[]= {0xCF,0x70,0x02,0x84,0xFA,0x90,0x1A,0x00,0x70,0x03,0x84,0xFB,0x91,0x1A,0x00};
//const  u8  dcs102[]= {0x00,0xA0};
//const  u8  dcs103[]= {0xCF,0x70,0x04,0x84,0xFC,0x90,0x1A,0x00,0x70,0x05,0x84,0xFD,0x91,0x1A,0x00};
//const  u8  dcs104[]= {0x00,0xB0};
//const  u8  dcs105[]= {0xCF,0x70,0x06,0x84,0xFE,0x90,0x1A,0x00,0x70,0x07,0x84,0xFF,0x91,0x1A,0x00};
//const  u8  dcs106[]= {0x00,0xC0};
//const  u8  dcs107[]= {0xCF,0x01,0x01,0x64,0x64,0x00,0x00,0x01,0x00,0x00,0x00,0x00};
//const  u8  dcs108[]= {0x00,0xB5};
//const  u8  dcs109[]= {0xC5,0x3f,0xff,0xff,0x3f,0xff,0xff};
//const  u8  dcs110[]= {0x00,0x00};
//const  u8  dcs111[]= {0xE1,0x00,0x19,0x29,0x3A,0x4C,0x5C,0x5D,0x8B,0x7D,0x98,0x67,0x53,0x63,0x40,0x3E,0x32,0X26,0X1A,0X0B,0X00};
//const  u8  dcs112[]= {0x00,0x00};
//const  u8  dcs113[]= {0xE2,0x00,0x19,0x29,0x3A,0x4C,0x5C,0x5D,0x8B,0x7D,0x98,0x67,0x53,0x63,0x40,0x3E,0x32,0X26,0X1A,0X0B,0X00};
//const  u8  dcs114[]= {0x00,0xA4};
//const  u8  dcs115[]= {0xC1,0xF0};
//const  u8  dcs116[]= {0x00,0x92};
//const  u8  dcs117[]= {0xC4,0x00};
//const  u8  dcs118[]= {0x00,0xB4};
//const  u8  dcs119[]= {0xC5,0xCC};
//const  u8  dcs120[]= {0x00,0x90};
//const  u8  dcs121[]= {0xB6,0xB6};
//const  u8  dcs122[]= {0x00,0x92};
//const  u8  dcs123[]= {0xB3,0x06};
//const  u8  dcs124[]= {0x00,0xC2};
//const  u8  dcs125[]= {0xF5,0x40};
//const  u8  dcs126[]= {0x00,0x80};
//const  u8  dcs127[]= {0xFF,0xFF,0xFF};
//const  u8  dcs128[]= {0x51,0x00};
//const  u8  dcs129[]= {0x53,0x24};
/////////////////////////////////////////////////////

//const u8 *cmdlist[]={
//dcs0,dcs1,dcs2,dcs3,dcs4,dcs5,dcs6,dcs7,dcs8,dcs9,
//dcs10,dcs11,dcs12,dcs13,dcs14,dcs15,dcs16,dcs17,dcs18,dcs19,
//dcs20,dcs21,dcs22,dcs23,dcs24,dcs25,dcs26,dcs27,dcs28,dcs29,
//dcs30,dcs31,dcs32,dcs33,dcs34,dcs35,dcs36,dcs37,dcs38,dcs39,
//dcs40,dcs41,dcs42,dcs43,dcs44,dcs45,dcs46,dcs47,dcs48,dcs49,
//dcs50,dcs51,dcs52,dcs53,dcs54,dcs55,dcs56,dcs57,dcs58,dcs59,
//dcs60,dcs61,dcs62,dcs63,dcs64,dcs65,dcs66,dcs67,dcs68,dcs69,
//dcs70,dcs71,dcs72,dcs73,dcs74,dcs75,dcs76,dcs77,dcs78,dcs79,
//dcs80,dcs81,dcs82,dcs83,dcs84,dcs85,dcs86,dcs87,dcs88,dcs89,
//dcs90,dcs91,dcs92,dcs93,dcs94,dcs95,dcs96,dcs97,dcs98,dcs99,
//dcs100,dcs101,dcs102,dcs103,dcs104,dcs105,dcs106,dcs107,dcs108,dcs109,
//dcs110,dcs111,dcs112,dcs113,dcs114,dcs115,dcs116,dcs117,dcs118,dcs119,
//dcs120,dcs121,dcs122,dcs123,dcs124,dcs125,dcs126,dcs127,dcs128,dcs129};

//const u8 cmdlen[]={
//sizeof(dcs0),sizeof(dcs1),sizeof(dcs2),sizeof(dcs3),sizeof(dcs4),sizeof(dcs5),sizeof(dcs6),sizeof(dcs7),sizeof(dcs8),sizeof(dcs9),
//sizeof(dcs10),sizeof(dcs11),sizeof(dcs12),sizeof(dcs13),sizeof(dcs14),sizeof(dcs15),sizeof(dcs16),sizeof(dcs17),sizeof(dcs18),sizeof(dcs19),
//sizeof(dcs20),sizeof(dcs21),sizeof(dcs22),sizeof(dcs23),sizeof(dcs24),sizeof(dcs25),sizeof(dcs26),sizeof(dcs27),sizeof(dcs28),sizeof(dcs29),
//sizeof(dcs30),sizeof(dcs31),sizeof(dcs32),sizeof(dcs33),sizeof(dcs34),sizeof(dcs35),sizeof(dcs36),sizeof(dcs37),sizeof(dcs38),sizeof(dcs39),
//sizeof(dcs40),sizeof(dcs41),sizeof(dcs42),sizeof(dcs43),sizeof(dcs44),sizeof(dcs45),sizeof(dcs46),sizeof(dcs47),sizeof(dcs48),sizeof(dcs49),
//sizeof(dcs50),sizeof(dcs51),sizeof(dcs52),sizeof(dcs53),sizeof(dcs54),sizeof(dcs55),sizeof(dcs56),sizeof(dcs57),sizeof(dcs58),sizeof(dcs59),
//sizeof(dcs60),sizeof(dcs61),sizeof(dcs62),sizeof(dcs63),sizeof(dcs64),sizeof(dcs65),sizeof(dcs66),sizeof(dcs67),sizeof(dcs68),sizeof(dcs69),
//sizeof(dcs70),sizeof(dcs71),sizeof(dcs72),sizeof(dcs73),sizeof(dcs74),sizeof(dcs75),sizeof(dcs76),sizeof(dcs77),sizeof(dcs78),sizeof(dcs79),
//sizeof(dcs80),sizeof(dcs81),sizeof(dcs82),sizeof(dcs83),sizeof(dcs84),sizeof(dcs85),sizeof(dcs86),sizeof(dcs87),sizeof(dcs88),sizeof(dcs89),
//sizeof(dcs90),sizeof(dcs91),sizeof(dcs92),sizeof(dcs93),sizeof(dcs94),sizeof(dcs95),sizeof(dcs96),sizeof(dcs97),sizeof(dcs98),sizeof(dcs99),
//sizeof(dcs100),sizeof(dcs101),sizeof(dcs102),sizeof(dcs103),sizeof(dcs104),sizeof(dcs105),sizeof(dcs106),sizeof(dcs107),sizeof(dcs108),sizeof(dcs109),
//sizeof(dcs110),sizeof(dcs111),sizeof(dcs112),sizeof(dcs113),sizeof(dcs114),sizeof(dcs115),sizeof(dcs116),sizeof(dcs117),sizeof(dcs118),sizeof(dcs119),
//sizeof(dcs120),sizeof(dcs121),sizeof(dcs122),sizeof(dcs123),sizeof(dcs124),sizeof(dcs125),sizeof(dcs126),sizeof(dcs127),sizeof(dcs128),sizeof(dcs129)};

void Panel_Init(void);

#endif
