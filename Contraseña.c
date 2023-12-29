char  keypadPort at PORTD;

sbit LCD_RS at LATB4_bit;
sbit LCD_EN at LATB5_bit;
sbit LCD_D7 at LATB3_bit;
sbit LCD_D6 at LATB2_bit;
sbit LCD_D5 at LATB1_bit;
sbit LCD_D4 at LATB0_bit;

sbit LCD_RS_Direction at TRISB4_bit;
sbit LCD_EN_Direction at TRISB5_bit;
sbit LCD_D7_Direction at TRISB3_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D4_Direction at TRISB0_bit;

//Password: B563
int cont;                          
int kp;                            
const int t=200;
char contra[]={"B563"};             
char password[5]={" "};

void main() {
ADCON1=0b1101;         
TRISA=0;
TRISB=0;
TRISD=1;
PORTA=0;
PORTB=0;
PORTD=0;

Keypad_Init();         
Lcd_Init();            

while(1){
LCD_Cmd(_LCD_CLEAR);
Lcd_Cmd(_LCD_CURSOR_OFF);
Lcd_Out(1,1,"Password: ");
cont=0;

 do{
  kp = 0;                                
      do
        kp = Keypad_Key_Click();           
      while (!kp);
    
      switch (kp) {
        case  1: kp = 49; break; // 1        
        case  2: kp = 50; break; // 2
        case  3: kp = 51; break; // 3
        case  4: kp = 65; break; // A
        case  5: kp = 52; break; // 4
        case  6: kp = 53; break; // 5
        case  7: kp = 54; break; // 6
        case  8: kp = 66; break; // B
        case  9: kp = 55; break; // 7
        case 10: kp = 56; break; // 8
        case 11: kp = 57; break; // 9
        case 12: kp = 67; break; // C
        case 13: kp = 42; break; // *
        case 14: kp = 48; break; // 0
        case 15: kp = 35; break; // #
        case 16: kp = 68; break; // D
      }
   if (kp){
   password[cont]=kp;
   cont++;
   Lcd_Chr(2,1+cont, kp);
   }
     if (cont==4){
      if (strcmp(contra,password)==0){
       Lcd_Cmd(_LCD_CLEAR);
       Lcd_Out(1, 1, "Abriendo...");
       PORTA.F0=1;
       delay_ms(t);
       PORTA.F0=0;
       }
       else{
       Lcd_Cmd(_LCD_CLEAR);
       Lcd_Out(2, 1, "Error contra");
       PORTA.F2=1;
       delay_ms(t);
       PORTA.F2=0;
       }
       break;
     }
    }while(1);
 }
}
