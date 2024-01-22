// U4P1, Make a single digit display go up and down in number count from respective buttons
// Coded by: Atul R
// Programmed on: Nov, 17, 2021

// Creating variable names for the various the various input and output pins
int dp = 4;
int a = 3;
int b = 2;
int c = 5;
int d = 6;
int e = 7;
int f = 8;
int g = 9;
int button1 = 11;
int button2 = 10;

// Creating the pressCount variable to check how many times the button has been pressed
static int pressCount = 0;

// These variables are for button debounce, to ensure the button does not input hundreds of times a second
unsigned long buttonDebounce = 0;
int debounceSens = 40;

// These integers are to check if the buttons are pressed or not
int buttonStateUP;
int lastButtonStateUP;
int buttonStateDOWN;
int lastButtonStateDOWN;

void setup() {
  // Initalizing the pins on the display for output, and the buttons for input
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(dp, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);

  // Set up the serial monitor to see the button inputs and debug
  Serial.begin(9600);

}

void loop() {
  // Set buttonstate to read the state of the button
  buttonStateUP = digitalRead(button1);

  /* These if statements check if the buttonstate is not the previous time it was pressed, and uses millis along with debounce to add a
  / 30 ms delay so the button only registers an input once. It then ups the pressCount variable when the button is pressed,
   and turns the indicator light on/off when needed */
  if (buttonStateUP != lastButtonStateUP && millis() > buttonDebounce) {
    buttonDebounce = millis() + debounceSens;
    if (buttonStateUP == HIGH) {
      pressCount++;
      digitalWrite(dp, HIGH);
      Serial.println(pressCount); // Prints the value of pressCount to the serial monitor
      if (pressCount == 10) {
        pressCount = 0; // If the pressCount variables goes out of bounds, then reset it back to 0
      }
    }
    else if (buttonStateUP == LOW) {
      digitalWrite(dp, LOW); // If the button is not pressed, turn the indicator light off
    }
  }
  lastButtonStateUP = buttonStateUP;

  
  // These nested if statements do the same thing as the previous ones, but instead lowers the pressCount variable as this is buttonDown
  buttonStateDOWN = digitalRead(button2);
  if (buttonStateDOWN != lastButtonStateDOWN && millis() > buttonDebounce) {
    buttonDebounce = millis() + debounceSens;
    if (buttonStateDOWN == HIGH) {
      pressCount--;
      digitalWrite(dp, HIGH);
      Serial.println(pressCount);
      if (pressCount == -1) {
        pressCount = 0;
      }
    }
    else if (buttonStateUP == LOW) {
      digitalWrite(dp, LOW);
    }
  }
  lastButtonStateDOWN = buttonStateDOWN;

  // This switch-case statement checks the value of the pressCount variable, and displays that number on the display when it corresponds 
  switch (pressCount) {
    case 0:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, LOW);
      break;
    case 1:
      digitalWrite(a, LOW);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
      break;
    case 2:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, LOW);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, LOW);
      digitalWrite(g, HIGH);
      break;
    case 3:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, HIGH);
      break;
    case 4:
      digitalWrite(a, LOW);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      break;
    case 5:
      digitalWrite(a, HIGH);
      digitalWrite(b, LOW);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, LOW);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      break;
    case 6:
      digitalWrite(a, HIGH);
      digitalWrite(b, LOW);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      break;
    case 7:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
      break;
    case 8:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      break;
    case 9:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      break;
  }

}
