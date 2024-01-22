//Assignment 4, Oct 6, 2021: Program it so yesterdays code (with the red led blinking and the amber led programmed by a button works when the delay is higher)
//Programmed by Atul R

//Set up constant variables for the various LED pins and the button to make it more readable
const int AmberledPin = 10; // Yellow/Amber
const int RedledPin = 8; // Red
const int buttonPin = 2; //For the button

//Set up a variable for if the button is pressed (also makes it more readable)
int buttonState;

// Set up a variable for the "delay" (flashRate) in order to use in an "if" statement to determine how fast the Red led turns on and off
int flashRate = 2000; //(2000 ms = 2 seconds)

// Set up a long variable (can have a lot of numbers) to determine the lastTime of when the LED was on.
unsigned long lastTime;

void setup() {
  // Initalize the LED's and button for input and output
  pinMode(AmberledPin, OUTPUT);
  pinMode(RedledPin, OUTPUT);      
  pinMode(buttonPin, INPUT);

  //Start the serial monitor in order to see the delay between the red led turning on and off
  Serial.begin(9600);
  
  /* Make lastTime = millis() which is how long the program has been running in ms 
    (has a limit of 50 days but it would never be on for that long) and a single reset resets the timer */
  lastTime = millis();
}

void loop() {
  // Set the buttonState to determine the status of the button
  buttonState = digitalRead(buttonPin);
  

  // This statement checks buttonState(which is digitalRead(buttonPin) so if it is pressed (HIGH/TRUE/1) it makes it so the Amber Led turns on
  // as the buttonState becomes a 1 or 0 which affects the digitalWrite.
  digitalWrite(AmberledPin, buttonState);
 


  /* The if statement means if millis() (current time) minus lastTime (which is millis() but a bit behind) is greater than the flashRate,
   (which it always will be as the flashTime is set by the coder which denotes the delay between lastTime and millis as well) which happens every
   2000 ms (2 seconds), the light will turn on*/
  
  if ((millis() - lastTime) > flashRate) {
    lastTime = millis(); // Will first set lastTime to the current millis() so the loop can keep running
    Serial.println(lastTime); //Then prints the lastTime to the serial monitor to visibly see the delay numbers
    
    /* ! means "if not", so if the Redledpin is off (which is found by digital read), 
       it will make the digitalwrite NOT be that, making it turn on, and vice versa */
    digitalWrite(RedledPin, !(digitalRead(RedledPin)));
  }


}
