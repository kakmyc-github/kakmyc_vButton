#include <kakmyc_vButton.h>

#define BTN_1_PIN 5
#define BTN_2_PIN A3
boolean btn_1_state=0, btn_2_state=0;
kakmyc_vButton btn1(btn_1_state,HIGHLEVEL_ACTIVE,2);
kakmyc_vButton btn2(btn_2_state,LOWLEVEL_ACTIVE,3);

void setup(){
  pinMode(BTN_1_PIN,INPUT_PULLUP);
    pinMode(BTN_2_PIN,INPUT);
    Serial.begin(9600);    
}

void loop(){
    btn_1_state=digitalRead(BTN_1_PIN);
    btn_2_state=digitalRead(BTN_2_PIN);
    
    int val1=btn1.read();
    int val2=btn2.read();
    if(val1){
     Serial.print("btn1 state= ")  ; 
    Serial.println(val1);}
    if(val2){
     Serial.print("btn2 state= ")  ; 
   Serial.println(val2);}
}