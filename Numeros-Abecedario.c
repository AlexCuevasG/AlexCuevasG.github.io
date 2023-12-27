const int tiempo=1000;  //Valor de tiempo
void main() {
  ADCON1=0b1111;  // Comversión A/D
  TRISB=0;        // Declarara puertos de salida
  TRISD=0;        // Declarara puertos de salida
  PORTB=0;        // Se asigna valor de 0
  PORTD=0;        // Se asigna valor de 0
  
  do{ // Ciclo infinito
  if(PORTC.F0==0) //Si Bit 0 es 0 seguir condicionante
  {
   PORTB=0;  //Puerto B se queda con valor de 0
   PORTD=0b00111111;   //Cero
   delay_ms(tiempo);
   PORTD=0b00000110;   //Uno
   delay_ms(tiempo);
   PORTD=0b01011011;   //Dos
   delay_ms(tiempo);
   PORTD=0b01001111;   //Tres
   delay_ms(tiempo);
   PORTD=0b01100110;   //Cuatro
   delay_ms(tiempo);
   PORTD=0b01101101;   //Cinco
   delay_ms(tiempo);
   PORTD=0b01111101;   //Seis
   delay_ms(tiempo);
   PORTD=0b00000111;   //Siete
   delay_ms(tiempo);
   PORTD=0b01111111;   //Ocho
   delay_ms(tiempo);
   PORTD=0b01101111;   //Nueve
   delay_ms(tiempo);
   }
   else if (PORTC.F1==0)
   {
    PORTD=0;  //Puerto D se queda con valor de 0
    PORTB=0b01110111;   //A
    delay_ms(tiempo);
    PORTB=0b01111100;   //B
    delay_ms(tiempo);
    PORTB=0b00111001;   //C
    delay_ms(tiempo);
    PORTB=0b01011110;   //D
    delay_ms(tiempo);
    PORTB=0b01111001;   //E
    delay_ms(tiempo);
    PORTB=0b01110001;   //F
    delay_ms(tiempo);
    }
   PORTD=0;
   PORTB=0;

  }while(1);
}
