/* U4.P3 Ultrasonic Sensor & LCD Display Project
 * Use an ultrasonic sensor and a display to show the echoTime of
 * the sensor in microseconds
 * "Coded" by Atul R
 * Dec 14, 2021
 */
// I the library code and variables
#include <LiquidCrystal.h>
#define trigPin 8
#define echoPin 9

// Initialize the library by associating any needed LCD interface pin
// With the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


byte musymbol [8] { //Create a custom symbol for mu (µ)
  B00000,
  B10001,
  B10001,
  B10001,
  B11011,
  B10101,
  B10000,
  B00000,
};

byte smileyface [8] { //Create a custom symbol for a smiley face
  B00000,
  B00000,
  B10001,
  B00000,
  B10001,
  B01110,
  B00000,
  B00000,
  
};

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2); //(16,2)
  lcd.clear();
  // Print an inital message to the LCD.
  lcd.print("Atul R");
  Serial.begin (9600);
  //Initalize the pins for input and output
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Create the custom characters so they can be displayed
  lcd.createChar(0, musymbol);
  lcd.createChar(1, smileyface);
  
}
void loop() {
  
  long echoTime; //Creates a long variable to show the echotime in microseconds

  //Turn the pins on and off so numbers on them can change
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  echoTime = pulseIn(echoPin, HIGH);
  //Sends the value of echoTime to the serial monitor
  Serial.print("echoTime= ");
  Serial.println(echoTime);

  // Prints the echoTime to the display with the custom symbols
  lcd.setCursor(6, 1);
  lcd.print(echoTime);
  lcd.write(byte(0));
  lcd.print("s");
  lcd.print("     ");
  lcd.setCursor(15, 1);
  lcd.write(byte(1));
  delay(800); //100
}
