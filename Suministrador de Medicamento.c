char  keypadPort at PORTD;

sbit LCD_RS at RB4_bit;
sbit LCD_EN at RB5_bit;
sbit LCD_D7 at RB3_bit;
sbit LCD_D6 at RB2_bit;
sbit LCD_D5 at RB1_bit;
sbit LCD_D4 at RB0_bit;

sbit LCD_RS_Direction at TRISB4_bit;
sbit LCD_EN_Direction at TRISB5_bit;
sbit LCD_D7_Direction at TRISB3_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D4_Direction at TRISB0_bit;

int cont;
int kp;
char meda1[]={"AC"};
char meda2[]={"AD"};
char meda3[]={"A5"};
char medb1[]={"BC"};
char medb2[]={"BD"};
char medb3[]={"B5"};
char password[3]={" "};
float pwm=0.0;

void main() {
    ADCON1 = 0b1111;
    TRISA = 0;
    TRISB = 0;
    TRISC = 0;
    TRISD = 1;
    PORTA = 0;
    PORTB = 0;
    PORTC = 0;
    PORTD = 0;

    Keypad_Init();
    Lcd_Init();
    PWM1_Init(1222);
    PWM2_Init(1222);
    PWM1_Start();
    PWM2_Start();

    while(1){
     LCD_Cmd(_LCD_CLEAR);
     Lcd_Cmd(_LCD_CURSOR_OFF);
     Lcd_Out(1,1,"Acereros: ");
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
       Lcd_Chr(1,9+cont, kp);
      }
      if (cont==2){
       if (strcmp(meda1,password)==0){
         Lcd_Cmd(_LCD_CLEAR);
         Lcd_Out(2, 1, "Med:A  Duty:1%");
         pwm=(1*225)/1023;
         PWM1_SET_DUTY(pwm);
         PORTA.F0=1;
         delay_ms(2000);
         PORTA.F0=0;
       }
        else if (strcmp(meda2,password)==0){
         Lcd_Cmd(_LCD_CLEAR);
         Lcd_Out(2, 1, "Med:A  Duty:25%");
         pwm=(25*225)/1023;
         PWM1_SET_DUTY(pwm);
         PORTA.F0=1;
         delay_ms(2000);
         PORTA.F0=0;
        }
        else if (strcmp(meda3,password)==0){
         Lcd_Cmd(_LCD_CLEAR);
         Lcd_Out(2, 1, "Med:A  Duty:75%");
         pwm=(75*225)/1023;
         PWM1_SET_DUTY(pwm);
         PORTA.F0=1;
         delay_ms(2000);
         PORTA.F0=0;
        }
        else if (strcmp(medb1,password)==0){
         Lcd_Cmd(_LCD_CLEAR);
         Lcd_Out(2, 1, "Med:B  Duty:1%");
         pwm=(1*225)/1023;
         PWM2_SET_DUTY(pwm);
         PORTA.F1=1;
         delay_ms(2000);
         PORTA.F1=0;
        }
        else if (strcmp(medb2,password)==0){
         Lcd_Cmd(_LCD_CLEAR);
         Lcd_Out(2, 1, "Med:B  Duty:25%");
         pwm=(25*225)/1023;
         PWM2_SET_DUTY(pwm);
         PORTA.F1=1;
         delay_ms(2000);
         PORTA.F1=0;
        }
        else if (strcmp(medb3,password)==0){
         Lcd_Cmd(_LCD_CLEAR);
         Lcd_Out(2, 1, "Med:B  Duty:75%");
         pwm=(75*225)/1023;
         PWM2_SET_DUTY(pwm);
         PORTA.F1=1;
         delay_ms(2000);
         PORTA.F1=0;
        }
      }
    }while(1);
  }
}
