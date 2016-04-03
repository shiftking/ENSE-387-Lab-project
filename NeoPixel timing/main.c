#include "main.h"
char display[3][105];

int main(void){
	int i,j,k;
	int hight = 15;
	clockInit();
	IO_init ();
	//PWM_init();
	//400 rset
	//GPIOC->ODR = GPIO_ODR_ODR1;
	//delay(4000);
	//GPIOC->ODR ^= GPIO_ODR_ODR1;
	//delay(400000);
	for(i = 0;i <105;i++){
		//set green
		display[0][i] = 0x00;
		//set red
		display[1][i] =0x0;
		//set blue
		display[2][i] =0xFF;
	}
	while(1){
		if((GPIOA->IDR & GPIO_IDR_IDR0) == 1){
		for(j = 0;j<105;j++){
		//for(j = 0; j<3;j++){
			/*for(i = 0;i<8;i++){
				GPIOC->ODR ^= GPIO_ODR_ODR1;
				GPIOC->ODR = GPIO_ODR_ODR1;
				GPIOC->ODR ^= GPIO_ODR_ODR1;
			}

			for(i = 0;i<8;i++){
				GPIOC->ODR ^= GPIO_ODR_ODR1;
				GPIOC->ODR = GPIO_ODR_ODR1;
		  	GPIOC->ODR ^= GPIO_ODR_ODR1;
			}*/
			//if((GPIOA->IDR & GPIO_IDR_IDR0) == 1){
			//if(j % 3){
				for(i = 0;i<3;i++){

					char buffer;
					buffer = display[i][j];
					for(k = 0;k<8;k++){

						if(buffer & 0xFE){
							GPIOC->ODR = GPIO_ODR_ODR0;
							delay(5);
							GPIOC->ODR ^= GPIO_ODR_ODR0;
							//counting = 4000;
							delay(2);
						}else{
							GPIOC->ODR = GPIO_ODR_ODR0;
							//delay(5);
							GPIOC->ODR ^= GPIO_ODR_ODR0;
							//counting = 4000;
							delay(2);
						}
						buffer = buffer >> 1;
					}

				}
			//}else{
				//	for(i = 0;i<24;i++){

					//GPIOC->ODR = GPIO_ODR_ODR1;

					//GPIOC->ODR ^= GPIO_ODR_ODR1;

					//delay(2);

				//}

				//}
			//}else{

				/*for(i = 0;i<24;i++){

					GPIOC->ODR = GPIO_ODR_ODR1;
					//delay(5);
					GPIOC->ODR ^= GPIO_ODR_ODR1;
					//counting = 4000;
					delay(7);

				//}
			}*/
		//}
		//GPIOC->ODR = GPIO_ODR_ODR1;
		//delay(40);
		}


		for(i = 0;i <105;i+=15){
			for(k = 0;k<15;k++){
				//set green
				if(k < hight){
					display[0][i + k] = 0x00;
					//set red
					display[1][i + k] =0x0;
					//set green
					display[2][i + k] =0xFF;

				}else{
					display[0][i + k] = 0x0;
					//set red
					display[1][i + k] =0x0;
					//set green
					display[2][i + k] =0x0;

				}

			}
		}
		hight--;
		if(hight < 0){
					hight = 15;
		}
		GPIOC->ODR ^= GPIO_ODR_ODR0;
		delay(900000);


		GPIOC->ODR = GPIO_ODR_ODR0;
		delay(9000);
		GPIOC->ODR ^= GPIO_ODR_ODR0;
		//GPIOC->ODR ^= GPIO_ODR_ODR1;
		delay(6000000);
	}else{
		for(j = 0;j<105;j++){
		//for(j = 0; j<3;j++){
			/*for(i = 0;i<8;i++){
				GPIOC->ODR ^= GPIO_ODR_ODR1;
				GPIOC->ODR = GPIO_ODR_ODR1;
				GPIOC->ODR ^= GPIO_ODR_ODR1;
			}

			for(i = 0;i<8;i++){
				GPIOC->ODR ^= GPIO_ODR_ODR1;
				GPIOC->ODR = GPIO_ODR_ODR1;
		  	GPIOC->ODR ^= GPIO_ODR_ODR1;
			}*/
			//if((GPIOA->IDR & GPIO_IDR_IDR0) == 1){

				for(i = 0;i<24;i++){

					GPIOC->ODR = GPIO_ODR_ODR0;
					//delay(5);
					GPIOC->ODR ^= GPIO_ODR_ODR0;
					//counting = 4000;
					delay(2);

				}

			//}else{

				/*for(i = 0;i<24;i++){

					GPIOC->ODR = GPIO_ODR_ODR1;
					//delay(5);
					GPIOC->ODR ^= GPIO_ODR_ODR1;
					//counting = 4000;
					delay(7);

				//}
			}*/
		//}
		//GPIOC->ODR = GPIO_ODR_ODR1;
		//delay(40);
		}
		GPIOC->ODR ^= GPIO_ODR_ODR0;
		delay(9000);

		GPIOC->ODR = GPIO_ODR_ODR0;
		delay(9000);
		GPIOC->ODR ^= GPIO_ODR_ODR0;
	}
	}

}
void delay(uint32_t val){
	while(val != 0){
		val--;
	}
}
