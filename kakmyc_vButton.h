/* myBtn_constructor.h by kakmyc 2022©
Library for processing signal from virtual button 
Types of signal: once/double/multiple/long */
 /*constructor parameters:
    variable reference (boolean)
    active level (high/low)
    max multiclick value (1-254)
    */


#ifndef kakmyc_vButton_h
#define kakmyc_vButton_h
#include <Arduino.h>


#define LOWLEVEL_ACTIVE 0
#define HIGHLEVEL_ACTIVE 1

class kakmyc_vButton{
    public:
   
    kakmyc_vButton(boolean &value,const byte state,byte multiclick);
    byte read();    
    private:
    boolean *_value;
    byte _state,_multiclick;
    uint16_t start_press;
 uint16_t pressTime;
 uint16_t double_press;
 boolean pressFlag;
 byte press_one;
 byte num,_num,button; 
};

#endif