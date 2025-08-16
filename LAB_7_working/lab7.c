#include <at89c5131.h>
#include "lcd.h"

code unsigned char display_msg1[] = " Enter Password ";
code unsigned char display_msg2[] = "Correct Password";
code unsigned char display_msg3[] = " Access Granted ";
code unsigned char display_msg4[] = " Wrong Password ";
code unsigned char display_msg5[] = " Access  Denied ";
unsigned char z[8];
unsigned char a;
unsigned int i = 0;

void main(void)
{
	lcd_init();
	lcd_cmd(0x80);
	msdelay(4);
	lcd_write_string(display_msg1); 
	
	for(i=0;i<8;i++)
	{
		P3 = 0x0f;
		K1: a = P3;
		a = a&0x0f;
		if(a != 0x0f)
		{goto K1;}
		
		K2: msdelay(20);
		a = P3;
		a = a&0x0f;
		if(a != 0x0f)
		{goto over;}
		else {goto K2;}
		
		over: msdelay(20);
		a = P3;
		a = a&0x0f;
		if(a != 0x0f)
		{goto over1;}
		else {goto K2;}
		
		over1: P3 = 0xef;
		a = P3&0x0f;
		if(a != 0x0f)
		{goto row0;}
		
		P3 = 0xdf;
		a = P3&0x0f;
		if(a != 0x0f)
		{goto row1;}
		
		P3 = 0xbf;
		a = P3&0x0f;
		if(a != 0x0f)
		{goto row2;}
		
		P3 = 0x7f;
		a = P3&0x0f;
		if(a != 0x0f)
		{goto row3;}
		
		goto K2;
		
		row0: if(P3_3 == 0)
		{z[i] = '1';
			lcd_cmd(0xC0);
			msdelay(4);
			lcd_write_string(z);
			continue;}
		
		else if(P3_2 == 0)
		{z[i] = '2';
		lcd_cmd(0xC0);
		msdelay(4);
		lcd_write_string(z);
		continue;}
		
		else if(P3_1 == 0)
		{z[i] = '3';
		lcd_cmd(0xC0);
		msdelay(4);
		lcd_write_string(z);
		continue;}
		
		else if(P3_0 == 0)
		{z[i] = 'A';
		lcd_cmd(0xC0);
		msdelay(4);
		lcd_write_string(z);
		continue;}

		row1: if(P3_3 == 0)
		{z[i] = '4';
			lcd_cmd(0xC0);
			msdelay(4);
			lcd_write_string(z);
		continue;}
		
		else if(P3_2 == 0)
		{z[i] = '5';
		lcd_cmd(0xC0);
		msdelay(4);
		lcd_write_string(z);
		continue;}
		
		else if(P3_1 == 0)
		{z[i] = '6';
		lcd_cmd(0xC0);
		msdelay(4);
		lcd_write_string(z);
		continue;}
		
		else if(P3_0 == 0)
		{z[i] = 'B';
		lcd_cmd(0xC0);
		msdelay(4);
		lcd_write_string(z);
		continue;}
		
		row2: if(P3_3 == 0)
		{z[i] = '7';
			lcd_cmd(0xC0);
			msdelay(4);
			lcd_write_string(z);
		continue;}
		
		else if(P3_2 == 0)
		{z[i] = '8';
		lcd_cmd(0xC0);
		msdelay(4);
		lcd_write_string(z);
		continue;}
		
		else if(P3_1 == 0)
		{z[i] = '9';
		lcd_cmd(0xC0);
		msdelay(4);
		lcd_write_string(z);
		continue;}
		
		else if(P3_0 == 0)
		{z[i] = 'C';
		lcd_cmd(0xC0);
		msdelay(4);
		lcd_write_string(z);
		continue;}
		
		row3: if(P3_3 == 0)
		{z[i] = '*';
			lcd_cmd(0xC0);
			msdelay(4);
			lcd_write_string(z);
		continue;}
		
		else if(P3_2 == 0)
		{z[i] = '0';
		lcd_cmd(0xC0);
		msdelay(4);
		lcd_write_string(z);
		continue;}
		
		else if(P3_1 == 0)
		{z[i] = '#';
		lcd_cmd(0xC0);
		msdelay(4);
		lcd_write_string(z);
		continue;}
		
		else if(P3_0 == 0)
		{z[i] = 'D';
		lcd_cmd(0xC0);
		msdelay(4);
		lcd_write_string(z);
		continue;}
	}
		msdelay(1000);
		if((z[0] == '1') & (z[1] == '5') & (z[2] == 'A') & (z[3] == '8') & (z[4] == '*') & (z[5] == 'D') & (z[6] == '6') & (z[7] == '#'))
		{
			lcd_cmd(0x80);
			msdelay(4);
			lcd_write_string(display_msg2);
			lcd_cmd(0xC0);
			msdelay(4);
			lcd_write_string(display_msg3);
			while(1);
		}
		
		else
		{
			lcd_cmd(0x80);
			msdelay(4);
			lcd_write_string(display_msg4);
			lcd_cmd(0xC0);
			msdelay(4);
			lcd_write_string(display_msg5);
			while(1);
		}
}