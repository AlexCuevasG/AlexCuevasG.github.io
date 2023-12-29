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

int raw_temp;                  
int pot=0;                      
int pot1=0;                     
const int t=500;              
char tempe[] = "Temperatura:";   
char valor[]=" ";
char porcen[]= "V/V(%): " ;
char valor1[]=" ";
char porcen1[]="Agitacion(RPM):" ;
float porcentaje=0.0;          
int pwm2=0.0;                  
int pwm1=0.0;                  

void main() {
  ADCON1=0b00001101;         
  TRISA=0;                    
  TRISA.F0=1;               
  TRISA.F1=1;                 
  PORTA=0;                  
  TRISB=0;
  PORTB=0;                  
  PORTB.F6=1;
  TRISC=0;
  PORTC=0;                  
  TRISD=1;                    
  PORTD=0;                   

  Lcd_Init();                 
  LCD_Cmd(_LCD_CLEAR);      
  LCD_Cmd(_LCD_CURSOR_OFF);  
  ADC_Init();               

  while(1){                  
    if (PORTD.F0==1){
      Ow_Reset(&PORTA, 2);                        
      Ow_Write(&PORTA, 2, 0xCC);               
      Ow_Write(&PORTA, 2, 0x44);                   
    
      while(Ow_Read(&PORTA, 2) == 0) ;
      Ow_Reset(&PORTA, 2);                       
      Ow_Write(&PORTA, 2, 0xCC);                   
      Ow_Write(&PORTA, 2, 0xBE);                   
    
      raw_temp  = Ow_Read(&PORTA, 2);             
      raw_temp |= (Ow_Read(&PORTA, 2) << 8);      
    
      if(raw_temp & 0x8000) {                     
        temp[0] = '-';                              
        raw_temp = ~raw_temp + 1;                  
      }
        else {
          if((raw_temp >> 4) >= 100)               
            temp[0] = '1';                           
          else                                     
            temp[0] = ' ';                       
        }
    
      temp[1] = ( (raw_temp >> 4) / 10 ) % 10 + 48;      
      temp[2] =   (raw_temp >> 4)        % 10  + 48;     
    
      temp[4] = ( (raw_temp & 0x0F) * 625) / 1000 + 48;          
      temp[5] = (((raw_temp & 0x0F) * 625) / 100 ) % 10 + 48;    
      temp[6] = (((raw_temp & 0x0F) * 625) / 10 )  % 10 + 48;   
      temp[7] = ( (raw_temp & 0x0F) * 625) % 10 + 48;           
      temp[8] = 223;
      Lcd_Out(1,1,tempe);           
      Lcd_out(2,1, temp);           
      delay_ms(t);                   
    } 
    else if (PORTD.F1==1){
      PWM2_Init(5000);               
      PWM2_Start();
      pot1=ADC_READ(0);
      porcentaje=pot1*0.58;
      pwm2=(pot1*2250)/1023;
      PWM2_SET_DUTY(pwm2);
      IntToStr(porcentaje, valor1);
      LCD_Cmd(_LCD_CLEAR);
      Lcd_Out(1,1,porcen1);
      Lcd_Out(2,1,valor1);
      delay_ms(t); 
    }
    else if (PORTD.F2==1){
      PWM1_Init(5000);            
      PWM1_Start();
      pot=ADC_READ(1);
      porcentaje=pot/51.15;
      pwm1=(pot*225)/1023;
      PWM1_SET_DUTY(pwm1);
      IntToStr(porcentaje, valor);
      LCD_Cmd(_LCD_CLEAR);
      Lcd_Out(1,1,porcen);
      Lcd_Out(2,1,valor);
      delay_ms(t);
    }
    else if (PORTD.F0==0 || PORTD.F1==0 ||PORTD.F2==0){
      LCD_Cmd(_LCD_CLEAR);
      delay_ms(t);
    }
  }
}
