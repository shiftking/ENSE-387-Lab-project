 
/* Analog to Digital Conversion */
 
/* FILENAME: adc.c*/
 
/*DESCRIPTION: Functions for analog to digital conversion*/
 
/* Author ? Dylan Rush 200246068 */
 
 #include "stm32f10x.h"

 #include "analog2digital.h"

 int out;
 //start conversion
void a2d_start(uint16_t channel)
{
    if (channel == 1)
    {
        ADC1->SQR3 |= ADC_SQR3_SQ1; 
     
        ADC1->CR2 |= 0x00000001; 
    }
    if (channel == 0)
    {
        ADC1->SQR3 |= ADC_SQR3_SQ2; 
     
        ADC1->CR2 |= 0x00000001; 
    }
     
}
 
//read the data from analog to digital
uint16_t a2d_read()
{
     
    
    while (!(ADC1->SR & ADC_SR_EOC))
    {
         
    }
     
    out = ADC1->DR & 0xF0;
     
    return out;
     
}
 

 
 void a2d_init()
{
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_ADC1EN;
 
    GPIOA->CRL &=  ~GPIO_CRL_CNF0 & ~GPIO_CRL_MODE0; 
     
    ADC1->CR2 |= 0x005;  //turn reset calibration on, and wake up the ADC
     
    ADC1->SMPR2 |= 0xFFF; 
     
    ADC1->SQR3 |= 0x000; 
     
}

