/*
Library to interface with WS2812b ICs
Dylan Rush
200246068
March 11 2016:  first addition

*/

#include "IO_timing_configs.h"

  void WS2812b_Init(void); //Initialize the clock and the pins used for the Neopixles WS2812b
  void setPixelColor(int color,int pixel,int channel); //sets the bit pattern for a specific pixel and channel
  void showDisplay(int channel); //sets the current virtual display to the neo pixels to be displayed
  void ZeroOut(void);
  void delay_wait(uint32_t time);
