#include<at89c5131.h>
#include<stdio.h>
#include<stdlib.h>
#include "que2.h"
code unsigned char display_msg1[]=" START PROGRAM  ";
code unsigned char display_msg2[]="  FIRST INPUT   ";
code unsigned char display_msg3[]="   NEXT INPUT   ";
code unsigned char display_msg4[]="    SORTING     ";
code unsigned char display_msg5[]="   COMPLETED    ";
code unsigned char display_msg6[]="  NUMBER TO BE  ";
code unsigned char display_msg7[]="   SEARCHED     ";
code unsigned char display_msg8[]="     NUMBER     ";
 code unsigned char display_msg9[]="   NOT FOUND    ";
code unsigned char display_msg10[]="  THE INDEX IS  ";


///code unsigned char array_inputs;
///code unsigned char input_data;
unsigned char a[4];	
unsigned char input_data;
int i;
int   m , k ;
int last;
int display_on_led;
unsigned char temp;
unsigned char key;
int n = 5;
void main()
{
	 
	
   	P1 = 0x0F;
	
	lcd_init();       //display on
	lcd_cmd(0x80);    //move cursor to first line
	msdelay(4);       //4ms delay
	
	lcd_write_string(display_msg1);  //"START PROGRAM" command on display
	msdelay(5000);        //delay of 5 sec
	
	lcd_cmd(0x80);       // move cursor to first row first column
	
	lcd_write_string(display_msg2);  //"first input" command on display
 
	msdelay(5000);        //delay of 5 sec
	input_data = P1; 	// TAKE INPUT first
	a[0] = P1;
	input_data = input_data << 4;
  P1 = input_data;        // displaying the first input on led
	
  lcd_cmd(0x80);													//Move cursor to 1st line of LCD
	lcd_write_string(display_msg3);	// display "NEXT INPUT " ON SECOND ROW
	msdelay(5000);
	for(i = 1 ; i<5 ; i++)
	{
		P1 = 0x0F;
	input_data = P1;       // storing P1 input in input_data
		a[i] = P1;               // storing it in an array
		input_data = input_data << 4;   // shifting by 4 bits 
		P1 = input_data;                  // displaying on leds
		lcd_cmd(0x80);													//Move cursor to 1st line of LCD
	  lcd_write_string(display_msg3);	// display "NEXT INPUT " ON SECOND ROW
	  msdelay(5000);
	}
	P1 = 0x0F;
	input_data = P1 ;   //storing last input in input_data
	a[4] = P1 ;           // storing last input in a[4]
	input_data = input_data << 4;
	P1 = input_data;
	lcd_cmd(0x80);
	lcd_write_string(display_msg4);
	msdelay(5000);
	P1 = 0x00;
	lcd_cmd(0xC0);													//Move cursor to 2nd line of LCD
	lcd_write_string(display_msg5);
	msdelay(1000);
	
   //implementing bubble sort
	 for(m = 0 ; m < 4 ; m++)
	{
		for(k = 0 ; k < 4 ; k++)
		{
			if(a[k] >a[k+1])
			{
				temp = a[k];
				a[k] = a[k+1];
				a[k+1] = temp;
			}
			
		}
		
	}
	//bubble sort finish here
	
	//code to display sorted array on leds
	P1 = 0x00;
	input_data = P1;
	for(display_on_led=0 ; display_on_led<5 ; display_on_led++)
	{
	   input_data = a[display_on_led];
		 input_data = input_data << 4 ;
		P1 = input_data;
		msdelay(5000);
		P1 = 0x00;
		msdelay(1000);
	}
	//displaying on leds finished
	// Now take input
	P1 = 0xFF;
	lcd_cmd(0x80);													//Move cursor to first line
	msdelay(4);
	lcd_write_string(display_msg6);  	// display "NUMBER TO BE SEARCHED"
	msdelay(4);
	lcd_cmd(0xC0);													//Move cursor to 2nd line of LCD
	msdelay(4);
	lcd_write_string(display_msg7);
	msdelay(5000);
	P1 = 0x0F;   //take input
	key = P1;    // store input in variable, key
	msdelay(1000);
	
	for(last = 0 ; last < 5 ; last++)
	{
	  if(a[last] == key )
		{
		   key = last;
       break;			
		}
		if(last == 4)
		{
		key = 8;
		}
		
		
	}
	if(key == 8)
	{
		lcd_cmd(0x01);     ///clear screen
	lcd_cmd(0x80);
		msdelay(4);
		
		lcd_write_string(display_msg8);
		msdelay(4);
		lcd_cmd(0xC0);													//Move cursor to 2nd line of LCD
	msdelay(4);
	lcd_write_string(display_msg9);
		msdelay(4);
		while(1);
	}
	else
	{
		lcd_cmd(0x01);        // clear screen
		lcd_cmd(0x80);
		msdelay(4);
		lcd_write_string(display_msg10);
		msdelay(4);
		key = key + 1;
	   key = key << 4;
		P1 = key;
		while(1);
	}
	
	
	
	
	}

	
	
	