/* Analog to Digital Conversion */
 
/* FILENAME: adc.h*/
 
/*DESCRIPTION: Function prototypes for analog to digital conversion*/
 
/* Author Dylan Rush 200246068 */
#include <stdint.h>


void a2d_init(void);
void a2d_start(uint16_t);
uint16_t a2d_read(void);

