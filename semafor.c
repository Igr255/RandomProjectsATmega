#include <stdbool.h>
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

int cislo = 5;
bool run = false;
bool ye = false;
void omen(char stlpec, char riadok, int cislo) {
  char pole[20];
  intToStr(cislo, pole);
  Lcd_Out(stlpec, riadok, pole);

}
void klik() org IVT_ADDR_INT2 {
  if (ye == false) {
    ye = true;
    run = true;
    cislo++;
  }
}
void kluk() org IVT_ADDR_INT1 {
  ye = false;
  run = false;
}

void main() {
  Lcd_Init();
  Lcd_Cmd(_LCD_CURSOR_OFF);
  DDRB &= ~(1 << 2);
  PORTB |= (1 << 2);
  DDRD &= ~(1 << 3);
  PORTD |= (1 << 3);
  MCUCSR &= ~(1 << ISC2);
  MCUCR &= ~(1 << ISC10);
  MCUCR |= (1 << ISC11);
  GICR |= (1 << INT1);
  GICR |= (1 << INT2);
  SREG |= (1 << 7);
  DDRA |= 1 << 0;
  DDRA |= 1 << 1;
  DDRA |= 1 << 2;
  DDRA |= 1 << 3;

  while (1) {

    if (ye == true) {
      cislo++;
    }

    Lcd_Out(1, 1, "Cislo:");
    Omen(2, 1, cislo);

    if (run == true) {
      PORTA |= (1 << 0);
      delay_ms(200);
      PORTA &= ~(1 << 0);
      PORTA |= (1 << 1);
      delay_ms(200);
      PORTA &= ~(1 << 1);
      PORTA |= (1 << 2);
      delay_ms(200);
      PORTA &= ~(1 << 2);
      PORTA |= (1 << 3);
      delay_ms(200);
      PORTA &= ~(1 << 3);
    }

  }

}