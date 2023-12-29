int contador=0;        
const int tiempo=100; 
void main() {
  ADCON1=0b1111;       
  TRISB=0;            
  TRISD=0;             
  PORTB=0;            
  PORTD=0;             
  
  do{ 
  if(contador==0) 
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

     contador=contador+1; 
     if (contador==1) 
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
