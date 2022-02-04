#include <SoftwareSerial.h>
#define MovementSensor 3
int Movement;
SoftwareSerial BluetoothComm(10,11);
void setup()
{
pinMode(MovementSensor, INPUT);
Serial.begin(9600);  
BluetoothComm.begin(9600);
}
 

void loop()
{
Movement=digitalRead(MovementSensor); //HAREKET SENSÖRÜ OKUNUYOR VARSA 1 YOKSA 0 DEĞERİ

if (Movement == 1) 
  {
    Serial.println("Movement Available"); //Seri Porta yazıyor bluetooth modül seri porttan okuyacak (1 yazılacak)
    BluetoothComm.println(1);
  delay(1000);
  }
else
  {
  Serial.println("Movement Not Available !"); //Seri Porta yazıyor bluetooth modül seri porttan okuyacak (0 yazılacak)
  BluetoothComm.println(0); //Seri Porta yazıyor bluetooth modül seri porttan okuyacak (0 yazılacak)
  delay(1000);
  }
}
