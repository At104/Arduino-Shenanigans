/* U4.P4 Infrared Remote Control, Display numbers to a LCD Display using IR
   Programmed by: Atul R
   Dec 16, 2021
*/

#include <IRremote.h>
#include <IRremoteInt.h>
#include <LiquidCrystal.h>

// The different codes for the remote, only some are used
/* Vol+ = FF629D
   Func/Stop = FFE21D
   Left Arrow Seek (|<<) = FF22DD
   To End (>||) = FF02FD
   Right Arrow Seek (>>|) = FFC23D
   Down = FFE01F
   Vol- = FFA857
   Up = FF906F
   0 = FF6897
   Eq = FF9867
   St/Rept = FFB04F
   1 = FF30CF
   2 = FF18E7
   3 = FF7A85
   4 = FF10EF
   5 = FF38C7
   6 = FF5AA5
   7 = FF42BD
   8 = FF4AB5
   9 = FF52AD
   Is being held down/Error = FFFFFFFF
*/
// Initalize the IR sensor to recieve values from the remote
int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;


// Initalize the LCD Display to display characters
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Extra variables that will be used in the code to account for button press and what number wil be displayed and the final number
int buttonPress;
String displayInt;
String myInts[2];

void setup() {

  Serial.begin(9600); // Start the serial monitor for debugging
  irrecv.enableIRIn(); // Start the receiver
  lcd.begin(16, 2); //Amount of Columns, Rows
  lcd.clear();
  // Print an inital message to the LCD.
  lcd.print("Input:");
 

}


void loop() {
  
  lcd.setCursor(6, 0); //Sets where the inputted values will be displayed

  // Reads what button is pressed on the IR Sensor, and adds the amount of times the button is pressed
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
    if (buttonPress < 4) {
      buttonPress++;
    }
    else if (buttonPress > 4) {
      buttonPress = 0;
    }
  }

  // Checks how many times the button has been pressed, and adds the inputted values to an array
  if (buttonPress == 1) {
    myInts[0] = displayInt;
    Serial.println(myInts[0]);
  }
  else if (buttonPress == 2) {
    myInts[1] = displayInt;
    Serial.println(myInts[1]);
  }
  else if (buttonPress == 3) {
    myInts[2] = displayInt;
    Serial.println(myInts[2]);
  }
  // On the fourth press, if the Func/Stop key has been pressed, it displays all of the numbers together on the second line
  else if (buttonPress == 4 && results.value == 0xFFE21D) {
    lcd.setCursor(0, 1);
    for (int i = 0; i < 3; i++) {
      lcd.print(myInts[i]);
    }
   buttonPress = 0;
  }

  // These make it so if Func/Stop is pressed before the 4th button press, it resets it
  if (results.value == 0xFFE21D && buttonPress == 1) {
    buttonPress = 0;
    myInts[0] = "";
    myInts[1] = "";
    myInts[2] = "";
    lcd.print("Reset");
    lcd.setCursor(0, 1);
    lcd.print("               ");
  }
  else if (results.value == 0xFFE21D && buttonPress == 2) {
    buttonPress = 0;
    myInts[0] = "";
    myInts[1] = "";
    myInts[2] = "";
    lcd.print("Reset");
    lcd.setCursor(0, 1);
    lcd.print("               ");
  }
  
  else if (results.value == 0xFFE21D && buttonPress == 3) {
    buttonPress = 0;
    myInts[0] = "";
    myInts[1] = "";
    myInts[2] = "";
    lcd.print("Reset");
    lcd.setCursor(0, 1);
    lcd.print("               ");
  
  }
  else if (results.value != 0xFFE21D && buttonPress > 3) {
    buttonPress = 0;
    
  }

  // Checks the value of the input from the remote, and changes it to a number that will be added to the array to display
  switch (results.value) {
    case 0xFF6897:
      displayInt = "0";
      lcd.print(displayInt);
      break;
    case 0xFF30CF:
      displayInt = "1";
      lcd.print(displayInt);
      break;
    case 0xFF18E7:
      displayInt = "2";
      lcd.print(displayInt);
      break;
    case 0xFF7A85:
      displayInt = "3";
      lcd.print(displayInt);
      break;
    case 0xFF10EF:
      displayInt = "4";
      lcd.print(displayInt);
      break;
    case 0xFF38C7:
      displayInt = "5";
      lcd.print(displayInt);
      break;
    case 0xFF5AA5:
      displayInt = "6";
      lcd.print(displayInt);
      break;
    case 0xFF42BD:
      displayInt = "7";
      lcd.print(displayInt);
      break;
    case 0xFF4AB5:
      displayInt = "8";
      lcd.print(displayInt);
      break;
    case 0xFF52AD:
      displayInt = "9";
      lcd.print(displayInt);
      break;
    case 0xFFE21D: // Func/Stop
      break;
  }
  lcd.print("             ");
  delay(200);
  
}
