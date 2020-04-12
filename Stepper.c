void main() {
   char buttonStateLeft = 1;
   char buttonStateRight = 1;
   char pos = 0;

   DDRC = 0b00001111;

   DDRD &= ~(1 << 2);
   DDRD &= ~(1 << 7);

   PORTD |= (1 << 2);
   PORTD |= (1 << 7);

   PORTC |= (1 << pos);
   while (1) {
      if (((PIND & (1 << 2)) == 0) && (buttonStateLeft == 1)) {
        buttonStateLeft = 0;
        PORTC &= ~(1 << pos);
        if (pos != 3 ) {
           pos++;
        } else {
           pos = 0;
        }
         PORTC |= (1 << pos);
      } else if (((PIND & (1 << 2)) != 0) && (buttonStateLeft == 0)) {
         buttonStateLeft = 1;
      }
      if (((PIND & (1 << 7)) == 0) && (buttonStateRight == 1)) {
         buttonStateRight = 0;
         PORTC &= ~(1 << pos);
         if (pos != 0 ) {
         pos--;
        } else {
            pos = 3;
         }
         PORTC |= (1 << pos);
      } else if (((PIND & (1 << 7)) != 0) && (buttonStateRight == 0)) {
         buttonStateRight = 1;
      }
   }
}
