/*
Library to interface with WS2812b ICs
Dylan Rush
200246068
March 11 2016:  first addition

*/
char display_left[3][105];
char display_right[3][105];
void WS2812b_Init(){


  //RCC->APB2ENR |=  RCC_APB2ENR_IOPCEN;

  //Set the config and mode bits for Port C bit 0 and 1 so they will
  // be push-pull outputs (up to 50 MHz)

  GPIOC->CRL |= GPIO_CRL_MODE0 | GPIO_CRL_MODE1;
  GPIOC->CRL &= ~GPIO_CRL_CNF0 & ~GPIO_CRL_CNF1;
  ZeroOut();

}

void showDisplay(int channel){

  int i,j,k;
  char buffer;
  if(channel){
    for(j = 0;j<105;j++){
      for(i = 0;i<3;i++){


        buffer= display_right[i][j];

        for(k = 0;k<8;k++){

          if(buffer & 0xFE){
            GPIOC->ODR = GPIO_ODR_ODR0;
            delay_wait(5);
            GPIOC->ODR ^= GPIO_ODR_ODR0;

            delay_wait(2);
          }else{
            GPIOC->ODR = GPIO_ODR_ODR0;

            GPIOC->ODR ^= GPIO_ODR_ODR0;

            delay_wait(2);
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
    delay_wait(9000);
  }else{
    for(j = 0;j<105;j++){
      for(i = 0;i<3;i++){


        buffer= display_left[i][j];

        for(k = 0;k<8;k++){

          if(buffer & 0xFE){
            GPIOC->ODR = GPIO_ODR_ODR1;
            delay_wait(5);
            GPIOC->ODR ^= GPIO_ODR_ODR1;

            delay_wait(2);
          }else{
            GPIOC->ODR = GPIO_ODR_ODR1;

            GPIOC->ODR ^= GPIO_ODR_ODR1;

            delay_wait(2);
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
    delay_wait(9000);
  }

  //GPIOC->ODR ^= GPIO_ODR_ODR1;
  ///delay_wait(6000000);

}
void setPixelColor(char pixel_color[],int col,int row,int channel){
  int i;
  if(channel){
    for(i =0 ;i<3;i++){
      display_left[i][pixel] = pixel_color[i];
    }
  }else{
    for(i =0 ;i<3;i++){
      display_right[i][pixel] = pixel_color[i];
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
