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

void Lcd_Out_Int(char row, char column, int cislo) { 
   char pole[14]; 
   IntToStr(cislo, pole); 
   Lcd_Out(row, column, pole); 
} 

void main() { 
   char buttonState1 = 1; 
   char buttonState2 = 1; 
   int cislo = 0; 

   Lcd_Init(); 
   Lcd_Cmd(_LCD_CURSOR_OFF); 

   DDRD &= ~(1 << 2); 
   DDRD &= ~(1 << 7); 
   PORTD |= (1 << 2); 
   PORTD |= (1 << 7); 

   Lcd_Out(1, 1, "Cislo:"); 
   Lcd_Out_Int(2, 4, cislo); 

   while (1) { 
      if (((PIND & (1 << 2)) == 0) && (buttonState1 == 1)) { 
         buttonState1 = 0; 
         cislo++; 
      } else if (((PIND & (1 << 2)) != 0) && (buttonState1 == 0)) { 
         buttonState1 = 1; 
      } 

      if (((PIND & (1 << 7)) == 0) && (buttonState2 == 1)) { 
         buttonState2 = 0; 
         cislo--; 
      } else if (((PIND & (1 << 7)) != 0) && (buttonState2 == 0)) { 
         buttonState2 = 1; 
      } 
      Lcd_Out_Int(2, 4, cislo); 
   } 
}
