/*
Library to interface with more than one msgeq7 frequency analyser
Dylan Rush
200246068
March 11 2016:  first addition

*/
#include "MSGEQ7.h"
int done = 0;


void MSGEQ7_init(){
  //set up pins for output
	//clockInit();
  //IO_init();

  //setup ADC pins for one controller
  a2d_init();
	//RCC->APB2ENR |=  RCC_APB2ENR_IOPBEN;
	//turn on pins 0 and 1 for reset and strobe
	GPIOB->CRL |= GPIO_CRL_MODE0 | GPIO_CRL_MODE1 ;
	GPIOB->CRL &= ~GPIO_CRL_CNF0 & ~GPIO_CRL_CNF1 ;



}
int getAmplitude(int frequency,int channel){
  if (frequency > 6 || channel > 1) { return 0;}
  return amplitudes[frequency][channel];


}
//1000  =  20us
void readValues(){
	int i;
  //grab the first frequency aplitude
  //set the reset to high and hold for a few secconds
	GPIOB->ODR = GPIO_ODR_ODR0; //set reset high
	delay_tick(500); //wait for .100ns
	GPIOB->ODR ^= GPIO_ODR_ODR0;// set reset low

	GPIOB->ODR = GPIO_ODR_ODR1; //set pulse high
	delay_tick(20000); //wait for output to setle
	GPIOB->ODR ^= GPIO_ODR_ODR1; //set pulse high
	delay_tick(35000);
	a2d_start(0);
	amplitudes[0][0] = a2d_read();
	a2d_start(1);
	amplitudes[0][1] = a2d_read();

	for(i = 1;i<7;i++){
		GPIOB->ODR = GPIO_ODR_ODR1; //set pulse high
		delay_tick(20000);  //wait the allowed time for a high pulse
		GPIOB->ODR ^= GPIO_ODR_ODR1; //set pulse low
		delay_tick(35000);
		//
		a2d_start(0);
		amplitudes[i][0] = a2d_read(); //get the  value of the aplitude for that channel
		a2d_start(1);
		amplitudes[i][1] = a2d_read(); //get the  value of the aplitude for that channel
		delay_tick(1000); //waith the strobe to strobe time
	}


}

void SysTick_config(uint32_t timing)
{
	SysTick->CTRL = 0x0;
	SysTick->VAL = 0x0;
	SysTick->LOAD = timing;

	SysTick->CTRL = 0x7;
}

void SysTick_Handler(void)
{

	done = 1;

}
/*
* Name:					void delay()
* Paramaters: 	32 bit delay value, ( a value of 6000 gives approximately 1 mS of delay)
* Description: 	This function creates a delay
*/
void delay_tick(uint32_t delay)
{
	int i;
	//for(i = 0;i < delay;i++){

	//}
	//convert the value from ms to clock ticks using the 3mhz counter
	float ratio = delay / 1000000000.0; //converts to what scalar of the clock tick total
	int ticks = ratio * 80000000; //calcuate the number of clock ticks for the delay
	SysTick_config(ticks);
	done = 0;
	while(!done);
  //initalize system tick*/

}
