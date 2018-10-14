/* 
 * RFID Sample - Simple control using RFID 
 * RIF module: Mifare RFID Mfrc522 
 * Autor : Pedro R. Zamora
*/

/*  RFID Pins (UNO):
3.3 - Pino 3.3V
RST - Pino 9
GND - Pino GND
IRQ - Não Conectado
MISO - Pino 12
MOSI - Pino 11
SCK - Pino 13
SDA - Pino 10

Pins (software): 
#define SS_PIN 10
#define RST_PIN 9
*/

/*  RFID Pins (MEGA):
3.3 - Pin 3.3V
RST - Pin 5
GND - Pin GND
IRQ - Not Connected
MISO - Pin 50
MOSI - Pin 51
SCK - Pin 52
SDA - Pin 53

Pins (software): 
#define SS_PIN 53
#define RST_PIN 5

*/

#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h> 
 
Servo servo1;

#define SS_PIN 53
#define RST_PIN 5

MFRC522 mfrc522(SS_PIN, RST_PIN); 


int LED_Cleared = 5;
int LED_Denied = 6;

char st[20];

void setup() 
{
  pinMode(LED_Cleared, OUTPUT);
  pinMode(LED_Denied, OUTPUT);
  
  servo1.attach(3);  
  servo1.write(90);

  Serial.begin(9600);

  SPI.begin();
  mfrc522.PCD_Init(); 

  Serial.println("Bring your Tag till the Sensor...");
  Serial.println();
}

void loop() 
{

  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  

  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  
  // Shows ID on serial. Use it to know your ID, then correct ir later in the code.
  Serial.print("Tag ID :");
  String content= "";
  byte character;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  
  // Test reading of first tag. Change the ID here.
  if (content.substring(1) == "9D A0 0F BB")
  {
    // Move the servo to enable access, then turn on green led.
    servo1.write(-90);
    digitalWrite(LED_Cleared, HIGH);
    Serial.println("Tag1 - Access Cleared !");
    Serial.println();
    delay(3000);
    servo1.write(90);
    digitalWrite(LED_Cleared, LOW);
    }
    
  // Test reading of another tag. Change the ID here, also.
  if (content.substring(1) == "86 14 57 8E")
  {
    Serial.println("Tag 2 - Access Denied !!");
    Serial.println();
    // Blinks red Led
    for (int i= 1; i<5 ; i++)
    {
      digitalWrite(LED_Denied, HIGH);
      delay(200);
      digitalWrite(LED_Denied, LOW);
      delay(200);
    }
  }
  delay(1000);
}
