#include <at89c5131.h>
#include "Stop_watch.h"

int count;
int count_sec;
int count_min;
int count_sec_up;
int	count_sec_low;
int	count_min_up;
int	count_min_low;


void main(void)
{ 
	lcd_init();
	lcd_cmd(0x80);
	TMOD = 0x05;
	P1 = 0x0F;
	TH0 = 0x00;
	TL0 = 0x00;
	while(1){
		if(P1 == 0x01){
			TR0 = 1;
			count_min = (TH0*256 + TL0)/3600;
			count_sec =((TH0*256 + TL0)%3600)/60;
			count_sec_up = (count_sec/10);
			count_sec_low = count_sec%10;
			count_min_up = count_min/10;
			count_min_low = count_min%10;
		}
	  else if(P1 == 0x00){
			TR0 = 0;
		}
	lcd_write_char(count_min_up+48);
	lcd_write_char(count_min_low+48);
	lcd_write_char(':');
	lcd_write_char(count_sec_up+48);
	lcd_write_char(count_sec_low+48);
	lcd_cmd(0x80);
	}
	
}