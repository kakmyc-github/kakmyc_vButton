#include "Arduino.h"
#include "kakmyc_vButton.h"
#define _long_press 1500
#define _bounce_time 50
#define _wait_multiclick 300

kakmyc_vButton::kakmyc_vButton(boolean &value,byte state,byte multiclick)
{
    _value = &value;
_multiclick=multiclick;
    state?_state=1:_state=0;
    }

byte kakmyc_vButton::read(){ 
	uint16_t _millis=millis();
 _state?button=!*_value:button=*_value;
	if(!button){num=0;}
	if(button&&!pressFlag)
	{pressTime=_millis-start_press;
		if(pressTime>=_long_press){
			pressFlag=1;
num=255;
pressTime=0;
		}		}
	if(!button){
 start_press=_millis;
pressFlag=0;
}

	if(!button&&!pressFlag){
		if(pressTime>_bounce_time&&pressTime<_long_press)
		{press_one++;
 if(press_one>_multiclick)press_one=_multiclick;
 pressTime=0;
 double_press=_millis;
    }}
if(press_one){
if(millis()-double_press>=_wait_multiclick){
pressTime=0;
num=press_one;
press_one=0;
  }}
_num=num;
num=0;
	return _num;
}