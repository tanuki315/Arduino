#include <Arduino.h>
int score;
void number_print(int num){
  switch(num){
    case 0: PORTB = 0b00000011; PORTD = 0b11110000; break;
    case 1: PORTB = 0b00000000; PORTD = 0b01100000; break;
    case 2: PORTB = 0b00000101; PORTD = 0b10110000; break;
    case 3: PORTB = 0b00000100; PORTD = 0b11110000; break;
    case 4: PORTB = 0b00000110; PORTD = 0b01100000; break;
    case 5: PORTB = 0b00000110; PORTD = 0b11010000; break;
    case 6: PORTB = 0b00000111; PORTD = 0b11010000; break;
    case 7: PORTB = 0b00000010; PORTD = 0b01110000; break;
    case 8: PORTB = 0b00000111; PORTD = 0b11110000; break;
    case 9: PORTB = 0b00000110; PORTD = 0b11110000; break;
  }
}
void display_score(int score){
  number_print(score%10);
  PORTB |= (1<<PORTB4);
  PORTB &= ~(1<<PORTB5);
  delay(10);
  number_print(score/10);
  PORTB |= (1<<PORTB5);
  PORTB &= ~(1<<PORTB4);
  delay(10);
}