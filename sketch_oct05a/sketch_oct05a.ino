/* Assignment 3, Oct 5, 2021, Turn on a light with a physical button (for school)
   Programmed by Atul R
 */

// Having the delay as 3000 ms does not make it work properly, not sure how to fix it yet.

//Set up constant (unchangeable) variables for each led you want on, then set it to the pin it will be connected to
const int AmberledPin = 10; // Yellow/Amber
const int RedledPin = 8; // Red

// I made variables here to make it more readable, you could just put the numbers as well

// And this variable is for the pin that the button will be connected too
const int buttonPin = 2;
// Set up a variable for the button state (whether it is on or off), this will be used in an if statement to determine whether the button is pressed
int buttonState = 0;

void setup() {  
  // Initalize all the led pins for output
  pinMode(AmberledPin, OUTPUT);
  pinMode(RedledPin, OUTPUT);      
  // But make the the button pin an input, as it needs to know that we are inputting (pressing the button)
  pinMode(buttonPin, INPUT);
   
}

void loop() {
  // Set the previous variable as digitalRead, this is for inputs (in this case for the buttonPin)
  buttonState = digitalRead(buttonPin);

  // Make the red led turn on and off
  digitalWrite(RedledPin, HIGH);
  delay(3000);
  digitalWrite(RedledPin, LOW);
  delay(3000);

// This if statement says that if buttonState (which is above) is 1 (pressed/on) then it will execute the following commands
  if (buttonState == 1) { //Could be HIGH or TRUE
    // This makes the amber led turn on
    digitalWrite(AmberledPin, HIGH); 
  } 
  
  // The else statements means when the conditions of the "if" statement are not satisfied. In this case, it means when the button is not pressed.
  else {
    // When not pressed, it turns off
    digitalWrite(AmberledPin, LOW);
  }
  
// NOTE: The button needs to be pressed the entire time for it to run, one press will not work, so keep it held.

}
