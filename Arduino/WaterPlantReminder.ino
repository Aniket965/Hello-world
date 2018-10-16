#include <dht.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address
dht DHT; 
#define DHT11_PIN 7
int value;          //Store watersensor data

void setup()
{
  //Begin serial communication
  Serial.begin(9600);  
  pinMode(DHT11_PIN, INPUT);
  lcd.begin(16,2);
  //Analog 0-1023
}

void loop()
{
  waterManager(A0);
  //cicalinoManager(13);
  humidityManager(DHT11_PIN);
  screenManager();
  delay(2000);
}


void waterManager(int port){
  value = analogRead(port); //Read data from analog pin and store it to value variable
  Serial.print(value);
  if (value<=480){ 
    Serial.println("Water level: 0mm - Empty!"); 
  }
  else if (value>480 && value<=530){ 
    Serial.println("Water level: 0mm to 5mm"); 
  }
  else if (value>530 && value<=615){ 
    Serial.println("Water level: 5mm to 10mm"); 
  }
  else if (value>615 && value<=660){ 
    Serial.println("Water level: 10mm to 15mm"); 
  } 
  else if (value>660 && value<=680){ 
    Serial.println("Water level: 15mm to 20mm"); 
  }
  else if (value>680 && value<=690){ 
    Serial.println("Water level: 20mm to 25mm"); 
  }
  else if (value>690 && value<=700){ 
    Serial.println("Water level: 25mm to 30mm"); 
  }
  else if (value>700 && value<=705){ 
    Serial.println("Water level: 30mm to 35mm"); 
  }
  else if (value>705){ 
    Serial.println("Water level: 35mm to 40mm"); 
  }
}

void humidityManager(int port){
  int chk = DHT.read11(port);
  int valTemp = DHT.temperature;
  int valHum = DHT.humidity;
  Serial.print("Temperatura = ");
  Serial.println(DHT.temperature);
  Serial.print("Umidità = ");
  Serial.println(DHT.humidity);
}

bool change = false;
void screenManager(){
  int chk = DHT.read11(7);
  int valTemp = DHT.temperature;
  int valHum = DHT.humidity;

  lcd.setCursor(0,0); //Start at character 4 on line 0
  
  
  String allTemp = "";
  if(change == false){
    lcd.clear();
    String allTemp = "Air: ";
    allTemp += valTemp;
    lcd.print(allTemp);
    change = true;
  }
  else{
    value = analogRead(A0); //Read data from analog pin and store it to value variable
   
    if (value<=480){ 
      lcd.print("Water: 0mm-Empty!"); 
    }
    else if (value>480 && value<=530){ 
      lcd.print("Water: 0mm-5mm"); 
    }
    else if (value>530 && value<=615){ 
      lcd.print("Water: 5mm-10mm"); 
    }
    else if (value>615 && value<=660){ 
      lcd.print("Water: 10mm-15mm"); 
    } 
    else if (value>660 && value<=680){ 
      lcd.print("Water: 15mm-20mm"); 
    }
    else if (value>680 && value<=690){ 
      lcd.print("Water: 20mm-25mm"); 
    }
    else if (value>690 && value<=700){ 
      lcd.print("Water: 25mm-30mm"); 
    }
    else if (value>700 && value<=705){ 
      lcd.print("Water: 30mm-35mm"); 
    }
    else if (value>705){ 
      lcd.print("Water: 35mm-40mm"); 
    }

    change = false;
  }
  
  //change != change;
  String allHum = "Humidity: ";
  allHum += valHum;

  if(change == false){
    lcd.print(allTemp);
  }
  //delay(1000);
  lcd.setCursor(0,1);
  lcd.print(allHum);
}







