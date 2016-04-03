/* Internal and external interupts  */

/* FILENAME: main.c*/

/*DESCRIPTION: */

/* Dylan rush 200246068 */
 #include "stm32f10x.h"
 #include "IO_timing_configs.h"

void clockInit()
{
	uint32_t temp = 0x00;
	//If you hover over the RCC you can go to the definition and then see it is a structure
	//of all the RCC registers.  Then you can simply assign a value.
	RCC->CFGR = 0x07050002;		// Output PLL/2 as MCO,
														// PLLMUL X3, PREDIV1 is PLL input

	RCC->CR =  0x01010081;	    // Turn on PLL, HSE, HSI

	while (temp != 0x02000000)  // Wait for the PLL to stabilize

	{
				temp = RCC->CR & 0x02000000; //Check to see if the PLL lock bit is set
	}


	//Enable peripheral clocks for various ports and subsystems
  //Bit 4: Port C Bit3: Port B Bit 2: Port A

		RCC->APB2ENR |=  RCC_APB2ENR_IOPAEN ;

	// Write a 0xB ( 1011b ) into the configuration and mode bits for PA8 (AFIO)

		GPIOB->CRH |= GPIO_CRH_CNF8_1 | GPIO_CRH_MODE8_1 | GPIO_CRH_MODE8_0 ;
		GPIOA->CRH &= ~GPIO_CRH_CNF8_0 ;
}


void IO_init (void)
{
	//Enable peripheral clocks for various ports and subsystems
  //Bit 4: Port C Bit3: Port B Bit 2: Port A

		RCC->APB2ENR |=  RCC_APB2ENR_IOPCEN | RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPAEN ;

	//Set the config and mode bits for Port C bit 0 and 1 so they will
	// be push-pull outputs (up to 50 MHz) for reset and strobe



}
