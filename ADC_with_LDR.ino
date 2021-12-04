#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <math.h>

void init_ports(){
  //set output for LEDS
  DDRD |= 0xE0;
  PORTD &= ~(1<<PORTD5) & ~(1<<PORTD6) & ~(1<<PORTD7);

  //set input for LDR
  DDRC &= 0xDF;
  PORTC |= (1<<PORTC5);
}

void init_ADC(){
  //enable ADC module and set prescaler as 128
  ADCSRA |= (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);

  //set voltage reference to AVcc and input channel to A5
  ADMUX |= (1<<REFS0) | (1<<MUX2) | (1<<MUX0);

  //set ADC input to analog
  DIDR0 |= (1<<ADC5D);
}

uint16_t getRegistercontent(){
  //wait for channel to get selected
  _delay_ms(10);
  
  //activate start conversion
  ADCSRA |= (1<<ADSC);
  //wait for conversion to finish
  while(ADCSRA&(1<<ADSC));
 
  _delay_ms(10);

  return(ADC);
}

int DigitalOut(int x){
    //formula for calculating digital output is x*(Vref/no.of steps)
    //no.of steps is 1024 as resolution is 10 and Vref is 5v
    return(round(x*(5.0/1024.0)));  
}

int main(void){
  //initialize ports
  init_ports();
  //initialize ADC
  init_ADC();

  while(1){
    switch(DigitalOut(getRegistercontent())){
      case 0:
        //all LEDS off
        PORTD &= ~(1<<PORTD5) & ~(1<<PORTD6) & ~(1<<PORTD7);
      break;
      case 1:
        //LED5 on while 6 & 7 off
        PORTD |= (1<<PORTD5); 
        PORTD &= ~(1<<PORTD6) & ~(1<<PORTD7);
      break;
      case 2:
        //LED6 on while 5 & 7 off
        PORTD |= (1<<PORTD6);
        PORTD &= ~(1<<PORTD5) & ~(1<<PORTD7);
      break;
      case 3:
        //LED7 on while 5 & 6 off
        PORTD |= (1<<PORTD7);
        PORTD &= ~(1<<PORTD5) & ~(1<<PORTD6);
      break;
      case 4:
        //LED 5 & 6 on while LED 7 off
        PORTD |= (1<<PORTD5) | (1<<PORTD6);
        PORTD &= ~(1<<PORTD7);
      break;
      case 5:
        //all LEDS on
        PORTD |= (1<<PORTD5) | (1<<PORTD6) | (1<<PORTD7);
      break;
    }
  }
}
