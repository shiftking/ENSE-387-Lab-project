/*
Library to interface with more than one msgeq7 frequency analyser
Dylan Rush
200246068
March 11 2016:  first addition

*/
#include "IO_timing_configs.h"
     //int RESET,STROBE,DATA; //hard code pin interface
     //int devices;
     void MSGEQ7_init(void);
     void readValues(void);
     int getAmplitude(int frequency,int channel); //hard code for one device
     void SysTick_config(uint32_t timing);
     void delay_tick(uint32_t time); //delay for a specific time
		 long map(long x, long in_min, long in_max, long out_min, long out_max);
