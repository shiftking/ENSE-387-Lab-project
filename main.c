/*
Library to interface with WS2812b ICs
Dylan Rush
200246068
March 11 2016:  first addition

*/
//char display[3][105];
//green , red, blue
char color[3][8] = {
  {0,255,0}, //red
  {128,255,0}, //orange
  {255,255,51}, //yellow
  {225,128,0}, //green
  {0,0,255}, //blue
  {0,127,255}, //purple
  {255,255,255}, //White
  {0,0,0}// clear
};

int main(void){
  int i,j,pixel;
  IO_init();
  MSGEQ7_init();
  showDisplay();
  WS2812b_Init();
  int volumes[7][2];
  while(1){
    readValues();
    for(i = 0;i<7;i++){
      volumes[i][0] = (8192 / getAmplitude(i,0)) * 15;
      volumes[i][1] = (8192 /getAmplitude(i,1)) * 15;
    }
    pixel = 0 ;
    for(i = 7;i>=0;i--){
      for(j = 0 ;j < 15;j++){
        if(j < volumes[i][0]){
          setPixelColor(color[i][0],pixel ,0);
          pixel++;
        }else{
          setPixelColor(color[7][0],pixel,0);
          pixel++;
        }
      }


    }
    pixel = 0;
    for(i = 0;i>=7;i--){
      for(j = 15 ;j >= 0 ;j--){
        if( j > volumes[i][0]){
          setPixelColor(color[i][0],pixel,0);
          pixel++;
        }else{
          setPixelColor(color[7][0],pixel ,0);
          pixel++;
        }
      }


    }
    showDisplay();
  }




}
