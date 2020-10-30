#include <LiquidCrystal.h>
LiquidCrystal lcd( 8, 9, 4, 5, 6, 7);
const int inPin =A1;//pin senzor de temperatura
int h=12;
int m=59;
int s=55;
int flag=1; //PM
void setup()
{
lcd.begin(16,2);
lcd.setCursor(3,0);
lcd.print(" PROIECT ");
lcd.setCursor(1,1);
lcd.print("SINCRETIC 2020");
delay(2000);
lcd.clear();
}
void loop()
{
float reading=analogRead(inPin);
float temperature=(reading*(5.0/1023.0)*100);//conversia in grade celsius
delay(10);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Temp= ");
lcd.print(temperature);
lcd.print("'C");
lcd.setCursor(0,1);
if(h<10)lcd.print("0");
lcd.print(h);
lcd.print(":");
if(m<10)lcd.print("0");
lcd.print(m);
lcd.print(":");
if(s<10)lcd.print("0");
lcd.print(s);
if(flag==0) lcd.print(" AM");
if(flag==1) lcd.print(" PM");
s=s+1;
delay(1000);
if(s==60){
  s=0;
  m=m+1;
 }
if(m==60)
 {
  m=0;
  h=h+1;
 }
if(h==13)
 {
  h=1;
  flag=flag+1;
if(flag==2)flag=0;//trecerea de la PM la AM
 }
}
