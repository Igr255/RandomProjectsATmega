void main() {
  char buttonState1 = 1;
  char buttonState2 = 1;
  
  DDRA &= ~(1 << 0);
  DDRA &= ~(1 << 7);
  DDRD |= (1 << 0);
  DDRD |= (1 << 7);
  
  PORTA |= (1 << 0);
  PORTA |= (1 << 7);
  
  while (1) {
    if (((PINA & (1 << 0)) == 0) && (buttonState1 == 1)) {
      buttonState1 = 0;
      PORTD |= (1 << 0);
    } else if (((PINA & (1 << 0)) != 0) && (buttonState1 == 0)) {
      buttonState1 = 1;
      PORTD &= ~(1 << 0);
    }
    
    if (((PINA & (1 << 7)) == 0) && (buttonState2 == 1)) {
      buttonState2 = 0;
      PORTD |= (1 << 7);
    } else if (((PINA & (1 << 7)) != 0) && (buttonState2 == 0)) {
      buttonState2 = 1;
      PORTD &= ~(1 << 7);
    }
  }
}