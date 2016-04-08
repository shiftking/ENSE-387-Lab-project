/* Internal and external interupts  */

/* FILENAME: main.c*/

/*DESCRIPTION: */

/* Dylan rush 200246068 */
 #include "stm32f10x.h"
 #include "IO_timing_configs.h"

void clockInit()
{
	


	//Enable peripheral clocks for various ports and subsystems
  //Bit 4: Port C Bit3: Port B Bit 2: Port A

		RCC->APB2ENR |=  RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPCEN | RCC_APB2ENR_IOPBEN;

	// Write a 0xB ( 1011b ) into the configuration and mode bits for PA8 (AFIO)

		//GPIOB->CRH |= GPIO_CRH_CNF8_1 | GPIO_CRH_MODE8_1 | GPIO_CRH_MODE8_0 ;
		//GPIOA->CRH &= ~GPIO_CRH_CNF8_0 ;
}



