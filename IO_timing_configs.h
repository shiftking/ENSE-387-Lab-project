/* Internal and external interupts  */

/* FILENAME: main.c*/

/*DESCRIPTION: */

/* Dylan rush 200246068 */



#include <stdint.h>
#include "stm32f10x.h"
#include "analog2digital.h"

 #define GREEN_ON	0X00000200 //
 #define GREEN_OFF	0x02000000 //
 #define BLUE_ON	0x00000100 //
 #define BLUE_OFF	0x01000000 //



 void clockInit(void); // Initialize the Cortex M3 clock using the RCC registers

 void IO_init (void);

 void SysTick_Handler(void);
