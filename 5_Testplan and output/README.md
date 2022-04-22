# Test case 1 : Gas Alert
(T1>150)    {       
                 PORTB.2=1;
                  lcd_gotoxy(0,0);
                  lcd_puts("GAS ALERT");
                 delay_ms(2000);  
                 lcd_clear(); 
               
               }   

# Test case 2 : Pressure Alert
(T2<850)
               {       
                 PORTB.2=1;
                  lcd_gotoxy(0,0);
                  lcd_puts("PRESSURE ALERT");
                 delay_ms(2000);  
                 lcd_clear(); 
               
               } 
        
# Test case 3 : High Volt Alert
(PIND.4==0)
               {       
               
                  PORTB.1=1;
                  lcd_gotoxy(0,0);
                  lcd_puts("HIGH VOLT ALERT");
                 delay_ms(2000);  
                 lcd_clear(); 
               
               }  
