//Atul R, Turn on a light with a physical button (I also did multiple in sequence for fun)

//Set up constant (unchangeable) variables for each led you want on, then set it to the pin it will be connected to
const int ledPin = 12;
const int ledPin2 = 11;
const int ledPin3 = 10;
const int ledPin4 = 9;
const int ledPin5 = 8;

// And this variable is for the pin that the button will be connected too
const int buttonPin = 3;
// Set up a variable for the button state (whether it is on or off), this will be used in an if statement to determine whether the button is pressed
int buttonState = 0;

void setup() {  
  // Initalize all the led pins for output
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);      
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  // But make the the button pin an input, as it needs to know that we are inputting (pressing the button)
  pinMode(buttonPin, INPUT);
   
}

void loop() {
  // Set the previous variable as digitalRead, this is for inputs (in this case for the buttonPin)
  buttonState = digitalRead(buttonPin);

// This if statement says that if buttonState (which is above) is HIGH (pressed/on) then it will execute the following commands
  if (buttonState == HIGH) {
    // This makes each led turn on, with some delay in between
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin2, HIGH);
    delay(100);
    digitalWrite(ledPin3, HIGH);
    delay(100);
    digitalWrite(ledPin4, HIGH);
    delay(100);
    digitalWrite(ledPin5, HIGH);
  } 
  // The else statements means when the conditions of the "if" statement are not satisfied. In this case, it means when the button is not pressed.
  else {
    // When not pressed, they all turn off, with some delay.
    digitalWrite(ledPin5, LOW);
    delay(100);
    digitalWrite(ledPin4, LOW);
    delay(100);
    digitalWrite(ledPin3, LOW);
    delay(100);
    digitalWrite(ledPin2, LOW);
    delay(100);
    digitalWrite(ledPin, LOW);
// NOTE: The button needs to be pressed the entire time for it to run, one press will not work, so keep it held.
  }

}
