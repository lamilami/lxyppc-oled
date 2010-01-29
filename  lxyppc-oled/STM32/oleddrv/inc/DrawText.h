#ifndef   DRAWTEXT_H
#define   DRAWTEXT_H
#include "font.h"
typedef unsigned long Pos_t;
typedef unsigned long Size_t;
typedef unsigned long Color_t;


typedef   unsigned long  (*pfnDrawBlock_t)(
  Pos_t x,
  Pos_t y,
  Pos_t cx,
  Pos_t cy,
  const unsigned char* data);
typedef   unsigned long  (*pfnDrawPoint_t)(Pos_t x, Pos_t y, Color_t color);

typedef  struct _DeviceProp
{
  pfnDrawBlock_t    pfnDrawBlok;
  pfnDrawPoint_t    pfnDrawPoint;
  Size_t            xPixel;
  Size_t            yPixel;
}DeviceProp;

typedef  struct  _Device
{
  const DeviceProp*   pDevProp;
  const FontData*     font;
  Pos_t               curX;
  Pos_t               curY;
}Device;




void  InitialDevice(Device* pDev, const DeviceProp* pDevProp, const FontData* pFont);

unsigned long  TextOut(
  Device* pDev,
  Pos_t x,
  Pos_t y,
  const char* text,
  Size_t len);

unsigned long SpecTextOut(
  Device* pDev,
  Pos_t x,
  Pos_t y,
  const FontData* textDot,
  Size_t len);

unsigned long SetPoint(
  Device* pDev,
  Pos_t x,
  Pos_t y);

unsigned long ClearPoint(
  Device* pDev,
  Pos_t x,
  Pos_t y);

#endif