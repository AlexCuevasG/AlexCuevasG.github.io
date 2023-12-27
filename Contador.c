int contador=0;        // Se declara variable con valor en 0
const int tiempo=100;  // Valor de tiempo
void main() {
  ADCON1=0b1111;       // Conversión A/D
  TRISB=0;             // Declara puertos de salida
  TRISD=0;             // Declara puertos de salida
  PORTB=0;             // Se asigna valor de 0
  PORTD=0;             // Se asigna valor de 0
  
  do{ //Ciclo infinito
  if(contador==0) //Seguir condicionante del 1-9 mientras este el valor 0
  {
   PORTB=0b00111111;
  }
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

     contador=contador+1; //Se suma 1 a la variable
     if (contador==1) //Mientras se va sumando 1 a la variable, el puerto b irá incrementando su valor.
     {
      PORTB=0b00000110;   //Uno
      }
      else if (contador==2)
      {
       PORTB=0b01011011;  //Dos
       }
       else if (contador==3)
      {
       PORTB=0b01001111;   //Tres
       }
       else if (contador==4)
      {
       PORTB=0b01100110;   //Cuatro
       }
       else if (contador==5)
      {
       PORTB=0b01101101;   //Cinco
       }
       else if (contador==6)
      {
       PORTB=0b01111101;   //Seis
       }
       else if (contador==7)
      {
       PORTB=0b00000111;   //Siete
       }
       else if (contador==8)
      {
       PORTB=0b01111111;   //Ocho
       }
       else if (contador==9)
      {
       PORTB=0b01101111;   //Nueve
       }
       else if (contador==10)
      {
       contador=0;         //Vuelve a iniciar variable de 0-9
       }
  }while(1);
}
