/* Analog to Digital Conversion */

/* FILENAME: lab_3.h*/

/*DESCRIPTION: clock, delay and I/O functions*/

/* Author – Nicholas LaPlante 200297217, Feb 2,2015 */
 #include "stm32f10x.h"
#include "main.h"
 
 #define GREEN_ON	0X00000200 //
 #define GREEN_OFF	0x02000000 //
 #define BLUE_ON	0x00000100 //
 #define BLUE_OFF	0x01000000 //


void clockInit()
{
	uint32_t temp = 0x00;
	//If you hover over the RCC you can go to the definition and then see it is a structure 
	//of all the RCC registers.  Then you can simply assign a value.
	RCC->CFGR = 0x00050002;		// Output PLL/2 as MCO,
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

/*
* Name:					void delay()
* Paramaters: 	32 bit delay value, ( a value of 6000 gives approximately 1 mS of delay)
* Description: 	This function creates a delay
*/


void IO_init (void)
{
	//Enable peripheral clocks for various ports and subsystems
  //Bit 4: Port C Bit3: Port B Bit 2: Port A
		
		RCC->APB2ENR |=  RCC_APB2ENR_IOPCEN | RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPAEN ; 

	//Set the config and mode bits for Port C bit 9 and 8 so they will
	// be push-pull outputs (up to 50 MHz)
	
			GPIOC->CRL |= GPIO_CRL_MODE0 | GPIO_CRL_MODE1 | GPIO_CRL_MODE2 | GPIO_CRL_MODE6 ;
		GPIOC->CRL &= ~GPIO_CRL_CNF0 & ~GPIO_CRL_CNF1 & ~GPIO_CRL_CNF2 & ~GPIO_CRL_CNF6;
	
}

void PWM_init(void)
{
	
	
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN | RCC_APB2ENR_AFIOEN;
	
	GPIOA->CRH = 0xB; //configure Port A pin 0 to alternative output-push-pull at 50mhz
	
	TIM1->CR1 = TIM_CR1_CEN; //enables counter for Timer 1
	
	TIM1->CR2 |= TIM_CR2_OIS1;
	
	TIM1->EGR |= TIM_EGR_UG;
								 //PWM Mode 1 Active As long as TIM_CNT<TIM_CCR
	TIM1->CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1PE | TIM_CCMR1_OC1FE;
	
	TIM1->CCER |= TIM_CCER_CC1E;
	
	TIM1->PSC = 0; //40khz
	
	TIM1->ARR = 600;  //10ms pw
	
	TIM1->CCR1 = 42; // 50/1000
	
	TIM1->BDTR |= TIM_BDTR_MOE;
	
	TIM1->CR1 = TIM_CR1_CEN;
	
	
	
}

void PWM_change(void)
{

	//TIM1->CCR1 = 42; 
	
	//GPIOC->BSRR = GREEN_ON;
	
	//delay(200000);
	
	//GPIOC->BSRR = GREEN_OFF;
	
	//TIM1->CCR1 = 50;
	
}
