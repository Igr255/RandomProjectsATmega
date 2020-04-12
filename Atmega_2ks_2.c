// Lcd pinout settings
sbit LCD_RS at PORTC0_bit;
sbit LCD_EN at PORTC1_bit;
sbit LCD_D7 at PORTC7_bit;
sbit LCD_D6 at PORTC6_bit;
sbit LCD_D5 at PORTC5_bit;
sbit LCD_D4 at PORTC4_bit;

// Pin direction
sbit LCD_RS_Direction at DDC0_bit;
sbit LCD_EN_Direction at DDC1_bit;
sbit LCD_D7_Direction at DDC7_bit;
sbit LCD_D6_Direction at DDC6_bit;
sbit LCD_D5_Direction at DDC5_bit;
sbit LCD_D4_Direction at DDC4_bit;

void main() {
  char buttonState1 = 1;
  char buttonState2 = 1;
  
  char number = 0;
  
  char strNumber[8];
  
  Lcd_Init();
  Lcd_Cmd(_LCD_CLEAR);
  Lcd_Cmd(_LCD_CURSOR_OFF);
    Lcd_Out(1, 1, "Cislo:");

  DDRA &= ~(1 << 4);
  DDRB &= ~(1 << 2);

  while (1) {
    if (((PINA & (1 << 4)) != 0) && (buttonState1 == 1)) {
      buttonState1 = 0;
      if (number != 255) {
        number += 1;
      }
    } else if (((PINA & (1 << 4)) == 0) && (buttonState1 == 0)) {
      buttonState1 = 1;
    }

    if (((PINB & (1 << 2)) != 0) && (buttonState2 == 1)) {
      buttonState2 = 0;
      if (number != 0) {
        number -= 1;
      }
    } else if (((PINB & (1 << 2)) == 0) && (buttonState2 == 0)) {
      buttonState2 = 1;
    }
    intToStr(number, strNumber);
    Lcd_Out(2, 1, strNumber);

  }
}