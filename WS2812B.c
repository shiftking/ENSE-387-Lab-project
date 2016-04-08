/*
Library to interface with WS2812b ICs
Dylan Rush
200246068
March 11 2016:  first addition

*/
#include "WS2812b.h"
char display_left[3][105];
char display_right[3][105];
char color[8][3] = {
  {0,15,0}, //red
  {15,10,0}, //orange
  {15,15,0}, //yellow
  {12,0,0}, //green
  {0,0,15}, //blue
  {0,5,15}, //purple
  {10,10,10}, //White
  {0,0,0}// clear
};
void WS2812b_Init(){


  RCC->APB2ENR |=  RCC_APB2ENR_IOPCEN;

  //Set the config and mode bits for Port C bit 0 and 1 so they will
  // be push-pull outputs (up to 50 MHz)

  GPIOC->CRL |= GPIO_CRL_MODE0 | GPIO_CRL_MODE1;
  GPIOC->CRL &= ~GPIO_CRL_CNF0 & ~GPIO_CRL_CNF1;
  ZeroOut();

}

void showDisplay(int channel){

  int i,j,k;
  //ZeroOut();

  if(channel){
    for(j = 0;j<105;j++){
      for(i = 0;i<3;i++){

				char buffer;
        buffer= display_right[i][j];

        for(k = 0;k<8;k++){

          if(buffer & 0xFE){
            GPIOC->ODR = GPIO_ODR_ODR0;
            delay_wait(5);  //wait ~800ns
            GPIOC->ODR ^= GPIO_ODR_ODR0;

            //delay_wait(2);//wait ~200ns
          }else{
            GPIOC->ODR = GPIO_ODR_ODR0;
              //wait ~400ns
						GPIOC->ODR =  ^= GPIO_ODR_ODR0;

            delay_wait(5);  //wait ~800ns
          }
          buffer = buffer >> 1;
        }

      }
    }
    GPIOC->ODR ^= GPIO_ODR_ODR0;
    delay_wait(9000);
    GPIOC->ODR = GPIO_ODR_ODR0;
    delay_wait(9000);
    GPIOC->ODR ^= GPIO_ODR_ODR0;
    delay_wait(70000);
		GPIOC->ODR ^= GPIO_ODR_ODR0;
  }else{
    for(j = 0;j<105;j++){
      for(i = 0;i<3;i++){
				char buffer;
        //color buffer
        buffer = display_left[i][j];

        for(k = 0;k<8;k++){

          if(buffer & 0xFE){
            GPIOC->ODR = GPIO_ODR_ODR1;
            delay_wait(5);  //wait ~800ns
            GPIOC->ODR ^= GPIO_ODR_ODR1;
              //wait ~400ns
            
          }else{
            GPIOC->ODR = GPIO_ODR_ODR1;
						//delay_wait(0); //wait ~400ns

            GPIOC->ODR  ^= GPIO_ODR_ODR1;
            delay_wait(5); //wait ~800ns
          }
          buffer = buffer >> 1;
        }

      }
    }
    GPIOC->ODR ^= GPIO_ODR_ODR1;
    delay_wait(9000);
    GPIOC->ODR = GPIO_ODR_ODR1;
    delay_wait(9000);
    GPIOC->ODR ^= GPIO_ODR_ODR1;
    delay_wait(70000);
		GPIOC->ODR ^= GPIO_ODR_ODR0;
  }

  //GPIOC->ODR ^= GPIO_ODR_ODR1;
  ///delay_wait(6000000);

}
void setPixelColor(int color_val,int pixel,int channel){
  int i;
	//int pixel = col * 15 + row;
  if(channel == 0){
    for(i =0 ;i<3;i++){

      display_right[i][pixel] = color[color_val][i];
    }
  }else if(channel == 1){
    for(i =0 ;i<3;i++){
      display_left[i][pixel] = color[color_val][i];
    }
  }
}
//Zero Out function
//Sets all the pixels to zero to clear them
void ZeroOut(){
int i,j;
  for(j = 0; j< 105;j++){
    for(i=0;i<3;i++){
      display_left[i][j] = 0x0;
      display_right[i][j] = 0x0;
    }
  }
}
void delay_wait(uint32_t val){
	while(val != 0){
		val--;
	}
}
