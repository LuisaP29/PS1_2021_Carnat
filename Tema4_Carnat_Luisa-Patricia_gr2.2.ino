#include <LiquidCrystal.h>
#define temperatura A1  
double kp = 1, ki = 0.1, kd = 0.1; // exemplu valori

double eroare= 0;

double suma_erori= 0;

double eroare_anterioara = 0;

double derivativa = 0;

double dt=1; // timp esantionare

double setpoint = 30;

double output;

LiquidCrystal lcd( 8, 9, 4, 5, 6, 7);


void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  
}
void loop()
{
  int  temperatura_citita_senzor=(analogRead(temperatura)*(5.0/1023.0)*100);
  eroare = setpoint - temperatura_citita_senzor;

  suma_erori= suma_erori + eroare * dt;

  derivativa = (eroare - eroare_anterioara) / dt;

  output = (kp * eroare) + (ki * suma_erori ) + (kd * derivativa);

  eroare_anterioara = eroare;
  lcd.setCursor(0,0);
  lcd.print("Temp actuala:");
  lcd.print(temperatura_citita_senzor);
  lcd.setCursor(0,1);
  lcd.print("Timp: ");
  lcd.print(output);
  delay(1000);
  lcd.clear();
  
}
