/*
 *   ________  ________  ________  ___  ___  ___  ___  ___  ___  ________     
 *  |\   ____\|\   __  \|\   ____\|\  \|\  \|\  \|\  \|\  \|\  \|\   ____\    
 *  \ \  \___|\ \  \|\  \ \  \___|\ \  \\\  \ \  \\\  \ \  \\\  \ \  \___|    
 *   \ \_____  \ \   __  \ \_____  \ \   __  \ \  \\\  \ \  \\\  \ \  \____   
 *    \|____|\  \ \  \ \  \|____|\  \ \  \ \  \ \  \\\  \ \  \\\  \ \  ___  \ 
 *      ____\_\  \ \__\ \__\____\_\  \ \__\ \__\ \_______\ \_______\ \_______\
 *     |\_________\|__|\|__|\_________\|__|\|__|\|_______|\|_______|\|_______|
 *     \|_________|        \|_________|                                              
 *     
 *     Program name: Hello World!!
 *     Author: Sashwat K
 *     Created on 11 Oct 2018
 *     Revision: 1
 *     Device: Arduino UNO
 */


#include <SPI.h>  // adafruit display driver header file
#include <Wire.h> // adafruit display driver header file
#include <Adafruit_GFX.h> // adafruit display driver header file
#include <Adafruit_SSD1306.h> // adafruit display model header file

#define OLED_RESET 4 //OLED
Adafruit_SSD1306 display(OLED_RESET); //OLED 

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //OLED 
  display.display(); //initialize display
  delay(2000);
  display.clearDisplay(); //clear display
}

void loop() {
  display.clearDisplay();
  display.display();
  display.setTextSize(1); // setting text size
  display.setTextColor(WHITE); // setting text color
  display.setCursor(0,0); // setting position for OLED display
  display.println("Hello World!!!"); //Hello world message
}
