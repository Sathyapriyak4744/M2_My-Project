#include <mega328.h>
#include <delay.h>
#include <alcd.h>
#include <stdio.h>

#define ADC_VREF_TYPE 0xC0
  int T1,T2,T3;
void adc_init(void)
{ 
   ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);  

   ADMUX |= (1 << REFS0);  
 
   ADCSRA |= (1 << ADEN);  
   ADCSRA |= (1 << ADSC);   
}
unsigned int read_adc(unsigned char adc_input)
{

ADMUX=adc_input | (ADC_VREF_TYPE & 0xff);
 
delay_us(10);
 
ADCSRA|=0x40;
 
while ((ADCSRA & 0x10)==0);
ADCSRA|=0x10;
return ADCW;
}

void sendtext(char *text) 
{
  char i=0;
  while (text[i]!=0)
 {
  putchar(text[i]);
  i++;
  delay_ms(100);
  }
}

 void num(unsigned int s)
{
 unsigned int a;
 unsigned char b,c,d,e,f;
 a=s/10;
 b=s%10;
 c=a%10;
 d=a/10;
 e=d%10;
 f=d/10;
 lcd_putchar(f+0x30);
 lcd_putchar(e+0x30);
 lcd_putchar(c+0x30);
 lcd_putchar(b+0x30); 
 }

void main(void)
{

#pragma optsize-
CLKPR=(1<<CLKPCE);
CLKPR=(0<<CLKPCE) | (0<<CLKPS3) | (0<<CLKPS2) | (0<<CLKPS1) | (0<<CLKPS0);
#ifdef _OPTIMIZE_SIZE_
#pragma optsize+
#endif

 
DDRB=(0<<DDB7) | (0<<DDB6) | (0<<DDB5) | (0<<DDB4) | (0<<DDB3) | (0<<DDB2) | (1<<DDB1) | (0<<DDB0);
 PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (1<<PORTB1) | (0<<PORTB0);

 
DDRC=(0<<DDC6) | (0<<DDC5) | (0<<DDC4) | (0<<DDC3) | (0<<DDC2) | (0<<DDC1) | (0<<DDC0);
 
 PORTC=(0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);

DDRD=(0<<DDD7) | (0<<DDD6) | (0<<DDD5) | (0<<DDD4) | (0<<DDD3) | (1<<DDD2) | (0<<DDD1) | (0<<DDD0);
 PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (1<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (1<<PORTD1) | (0<<PORTD0);

TCCR0A=(0<<COM0A1) | (0<<COM0A0) | (0<<COM0B1) | (0<<COM0B0) | (0<<WGM01) | (0<<WGM00);
TCCR0B=(0<<WGM02) | (0<<CS02) | (0<<CS01) | (0<<CS00);
TCNT0=0x00;
OCR0A=0x00;
OCR0B=0x00;


TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (0<<CS11) | (0<<CS10);
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

 
ASSR=(0<<EXCLK) | (0<<AS2);
TCCR2A=(0<<COM2A1) | (0<<COM2A0) | (0<<COM2B1) | (0<<COM2B0) | (0<<WGM21) | (0<<WGM20);
TCCR2B=(0<<WGM22) | (0<<CS22) | (0<<CS21) | (0<<CS20);
TCNT2=0x00;
OCR2A=0x00;
OCR2B=0x00;

 TIMSK0=(0<<OCIE0B) | (0<<OCIE0A) | (0<<TOIE0);

 TIMSK1=(0<<ICIE1) | (0<<OCIE1B) | (0<<OCIE1A) | (0<<TOIE1);

 TIMSK2=(0<<OCIE2B) | (0<<OCIE2A) | (0<<TOIE2);

EICRA=(0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
EIMSK=(0<<INT1) | (0<<INT0);
PCICR=(0<<PCIE2) | (0<<PCIE1) | (0<<PCIE0);

UCSR0A=(0<<RXC0) | (0<<TXC0) | (0<<UDRE0) | (0<<FE0) | (0<<DOR0) | (0<<UPE0) | (0<<U2X0) | (0<<MPCM0);
UCSR0B=(0<<RXCIE0) | (0<<TXCIE0) | (0<<UDRIE0) | (1<<RXEN0) | (1<<TXEN0) | (0<<UCSZ02) | (0<<RXB80) | (0<<TXB80);
UCSR0C=(0<<UMSEL01) | (0<<UMSEL00) | (0<<UPM01) | (0<<UPM00) | (0<<USBS0) | (1<<UCSZ01) | (1<<UCSZ00) | (0<<UCPOL0);
UBRR0H=0x00;
UBRR0L=0x33;

ACSR=(1<<ACD) | (0<<ACBG) | (0<<ACO) | (0<<ACI) | (0<<ACIE) | (0<<ACIC) | (0<<ACIS1) | (0<<ACIS0);
 
DIDR1=(0<<AIN0D) | (0<<AIN1D);

 
DIDR0=(0<<ADC5D) | (0<<ADC4D) | (0<<ADC3D) | (0<<ADC2D) | (0<<ADC1D) | (0<<ADC0D);
ADMUX=ADC_VREF_TYPE;
ADCSRA=(1<<ADEN) | (0<<ADSC) | (0<<ADATE) | (0<<ADIF) | (0<<ADIE) | (0<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
ADCSRB=(0<<ADTS2) | (0<<ADTS1) | (0<<ADTS0);

SPCR=(0<<SPIE) | (0<<SPE) | (0<<DORD) | (0<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);

 
TWCR=(0<<TWEA) | (0<<TWSTA) | (0<<TWSTO) | (0<<TWEN) | (0<<TWIE);
 
PORTD.2=0;
lcd_init(16);
  lcd_gotoxy(0,0);
   lcd_puts("PATIENT"); 
    lcd_gotoxy(0,1);
   lcd_puts("MONITORING");
   delay_ms(2000);
   lcd_clear();

while (1)
      {
          T1=read_adc(5)/5;
        lcd_gotoxy(0,1);
        lcd_puts("GAS:");
        num(T1);
           PORTD.2=0; 
           PORTB.1=0; 
         
              T2=read_adc(3);
        lcd_gotoxy(0,0);
        lcd_puts("PRESSURE:");
        num(T2);
           PORTD.2=0;
            PORTB.1=0; 
         
           if(T1>150)
               {       
                 PORTB.1=1;
                  lcd_gotoxy(0,0);
                  lcd_puts("GAS ALERT");
                 delay_ms(2000);  
                 lcd_clear(); 
               
               }   
               
                 if(T2>750)
               {       
                 PORTB.1=1;
                  lcd_gotoxy(0,0);
                  lcd_puts("PRESSURE ALERT");
                 delay_ms(2000);  
                 lcd_clear(); 
               
               } 
        
           if(PIND.4==0)
               {       
               
                  PORTB.1=1;
                  lcd_gotoxy(0,0);
                  lcd_puts("HIGH VOLT ALERT");
                 delay_ms(2000);  
                 lcd_clear(); 
               
               }  
       
      }
}
