/*
Library to interface with WS2812b ICs
Dylan Rush
200246068
March 11 2016:  first addition

*/
//char display[3][105];
//green , red, blue
#include "WS2812b.h"
#include "MSGEQ7.h"


int main(void){
  int i,j,bands;
	int volumes[7][2];
  //clockInit();
	ZeroOut();


	MSGEQ7_init();
	WS2812b_Init();
  showDisplay(0);
	showDisplay(1);
	delay_wait(940000);
  while(1){

    readValues();


		for(i = 0;i<7;i++){

      volumes[i][0] = getAmplitude(i,0);
      volumes[i][1] = getAmplitude(i,1);
    }
		bands = 0;
    for(i = 0;i < 105;i+=15){
      for(j = 15 ;j >= 0 ;j--){
        if(j >= (15 - volumes[bands][1])){
          setPixelColor(bands,i + j,0);

        }else{
          setPixelColor(7,i+j,1);

        }
      }
			bands++;

    }

    for(i = 0;i< 105;i+=15){

      for(j = 0 ;j <15 ;j++){
        if( j <  volumes[bands][1]){
          setPixelColor(bands,i + j,1);

        }else{
          setPixelColor(7,i+j ,0);

        }
      }
			bands++;

    }



    showDisplay(0);
    showDisplay(1);
		//ZeroOut();
  }




}
