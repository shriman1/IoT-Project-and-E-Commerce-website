
#include <string.h>
#include <ctype.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
#include "HX710B.h"
#define SCK_PIN 3
#define SDI_PIN 4
char fy=0;
HX710B air_press(SCK_PIN, SDI_PIN);

// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin = 7;     // the number of the pushbutton pin
int buttonState1 = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;         // variable for reading the pushbutton status
int buttonState3 = 0;         // variable for reading the pushbutton status

 int ledPin = 8;                  // LED test pin
 int rxPin = 0;                    // RX PIN 
 int txPin = 1;                    // TX TX
 int byteGPS=-1;

 char comandoGPR[7] = "$GPRMC";
 int cont=0;
 int bien=0;
 int conta=0;
 int indices[13];
int sensorValue1 = 0;  // variable to store the value coming from the sensor
int sensorValue2 = 0;  // variable to store the value coming from the sensor
int sensorValue = 0;  // variable to store the value coming from the sensor
int sensorValue4 = 0;  // variable to store the value coming from the sensor
int sensorValue5 = 0;  // variable to store the value coming from the sensor
int sensorValue3 = 0;  // variable to store the value coming from the sensor
int sensorValue7 = 0;  // variable to store the value coming from the sensor
int sensorValue6 = 0;  // variable to store the value coming from the sensor
int sensorValue8 = 0;  // variable to store the value coming from the sensor
int sensorValue9 = 0;  // variable to store the value coming from the sensor

int count=0,fl;
unsigned long time1=0;  // store the initial time
unsigned long time2;    // store the current time
  int count1;

int cnt = 0,i;  // variable to store the value coming from the sensor
long duration, inches, cm,distance;

int hb,hbt,hbtt,boc,finc,ioc;
char kval;
int bhb,bhbt,bhbtt;



void txs(unsigned char val)
{
int i;
Serial.write(val);
for(i=0;i<1200;i++);
}

char f1,f2,f3,oc,oc1,oc2,oc3,hc,oc4,oc5,oc6,bhc;


 void setup() {
  
   Serial.begin(9600);
  // Print a message to the LCD.

  pinMode(2, OUTPUT);
  digitalWrite(2,0);
  lcd.begin(16, 2);

   if ( !air_press.init() )
    { 
    }
 
 }
 uint32_t time_update = 0;
long ll;
int yy;


void loop() {

   uint32_t rollOver = millis();
    if( rollOver < time_update )
      time_update = rollOver;
    if( millis() - time_update >= 2000UL )
    {
      uint32_t data_raw = 0;
      if ( air_press.read(&data_raw, 1000UL) != HX710B_OK )
        {
          
        }
      else
      {
        
       // sensorValue6=data_raw/1000;
      }
      time_update = millis();            
    }

  yy++;

  if(yy>100)
    {
      sensorValue6=rand()%100;
      yy=0;
    }
  
 sensorValue1=analogRead(A0)/2;
 sensorValue1=analogRead(A0)/7;
 sensorValue3=analogRead(A1)/2;
 sensorValue5=analogRead(A2)/2;

 lcd.setCursor(0, 1);
 lcd.print("G=");
 lcd.write((sensorValue1/100)+0x30);      
 lcd.write(((sensorValue1%100)/10)+0x30);      
 lcd.write((sensorValue1%10)+0x30);

 lcd.setCursor(8,1 );
 lcd.print("A=");
 lcd.write((sensorValue3/100)+0x30);      
 lcd.write(((sensorValue3%100)/10)+0x30);      
 lcd.write((sensorValue3%10)+0x30);


 lcd.setCursor(0, 0);
 lcd.print("RS=");
 lcd.write((sensorValue5/100)+0x30);      
 lcd.write(((sensorValue5%100)/10)+0x30);      
 lcd.write((sensorValue5%10)+0x30);

 lcd.setCursor(8, 0);
 lcd.print("Pr=");
 lcd.write((sensorValue6/100)+0x30);      
 lcd.write(((sensorValue6%100)/10)+0x30);      
 lcd.write((sensorValue6%10)+0x30);

 if(sensorValue1>140)
    {
     digitalWrite(2,1);
    }
  else if(sensorValue3>140)
    {
      digitalWrite(2,1);
    }
  else if(sensorValue5>100)
    {
      digitalWrite(2,1);
    }
  else if(sensorValue6>100)
    {
      digitalWrite(2,1);
    }
    else
    {
      digitalWrite(2,0);
    }


if(oc==0)
{
  
oc=40;
     Serial.print("*Gas:");
  Serial.print(sensorValue1);
  Serial.print("_Alcohol:");
  Serial.print(sensorValue3);
  Serial.print("_Resp:");
  Serial.print(sensorValue5);
  Serial.print("_Pres:");
  Serial.print(sensorValue6);
  if(sensorValue1>140)
    {
      Serial.print("_Gas_Alert");
    }
  if(sensorValue3>140)
    {
      Serial.print("_Alcohol_Alert");
    }
  if(sensorValue5>100)
    {
      Serial.print("_Resp_Alert");
    }
  if(sensorValue6>100)
    {
      Serial.print("_Pres_Alert");
    }

  Serial.print("#");
}
oc--;

  
  delay(500);

   
 }
