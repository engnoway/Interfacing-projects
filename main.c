/*
 * main.c

 *
 *  Created on: ???/???/????
 *      Author: Ismailia Laptop
 */

#include"types.h"
#include "TACTILE_config.h"
#include "TACTILE_interface.h"
#include "DIO_utils.h"
#include "DIO_private.h"
#include "DIO_config.h"
#include "DIO_interface.h"
#include "TACTILE_private.h"
#include"delay.h"

static u8 x = 0;
int main(void) {
	u8 y = 0;

	u8 flag2 = 0;
	DIO_voidInit();
	TACTILE_voidInit();

	while (1) {

		TACTILE_u8GetState(TACTILE_u8Switch1Pin, &y);
		if (y == TACTILE_u8PRESSED && flag2 == 0) //released
				{
			x++;
			flag2 = 1;
			//DIO_u8WritePinVal( DIO_u8PIN31,!x);

			//Delay_ms(50);
			//y=1;
		}

		if (x == 3) {
			DIO_u8WritePinVal( DIO_u8PIN31, 1);
			x = 0;
		}
		/*if(y==1) //pressed
		 {
		 //flag2=!flag2;
		 DIO_u8WritePinVal( DIO_u8PIN31,0);
		 //Delay_ms(50);
		 //	y=1;
		 }
		 */
		if (y == TACTILE_u8RELEASED) {

			//DIO_u8WritePinVal( DIO_u8PIN31,0);
			flag2 = 0;
		}
	}

	return 0;
}
