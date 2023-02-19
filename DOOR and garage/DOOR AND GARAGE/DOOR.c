/*
 * DOOR.c
 *
* Created: 2/18/2023 8:43:57 AM
*  Author: Ismail
 */
#include <avr/io.h>
#include "LCD.h"
#include "STMR.h"
#define F_CPU 1000000UL
#include <util/delay.h>
int main(void)
{
	LCD_vInit();
	LCD_vSend_string("  welcome home  ");
	LCD_movecursor(2,1);
	LCD_vSend_string("  ****sir****  ");
	signed char flag1=0,flag2=0,IR1,IR2,counter=0;
    while(1)
    {
         IR1=DIO_u8read('D',0);
		 if(IR1==1 && flag1==0)
		 {
			 LCD_movecursor(1,11);
			 flag1=1;
			  {
				 LCD_clearscreen();
				 LCD_vSend_string("the door is");
				 LCD_movecursor(2,1);
				 LCD_vSend_string("open sir");
			  }
			  timer1_wave_fastPWM_B(0.999999);
			  
			  
		 }
		 else if(IR1==0 && flag1==1)
		 {
			 flag1=0;
			 LCD_clearscreen();
			 LCD_vSend_string("the door is");
			 LCD_movecursor(2,1);
			 LCD_vSend_string("closed sir");
			 timer1_wave_fastPWM_B(1.499999);
		 }
	}
}