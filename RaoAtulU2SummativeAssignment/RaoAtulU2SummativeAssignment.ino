/* Unit 2 Summative Assignment, Create 2 stoplight systems, that run on a rotation and have a pedestrian button to make the green light come faster
    Coded by: Atul R
    Nov, 2, 2021
*/

// Variables for first set of lights and button (Northbound)
int Buttonpin1 = 13;
int IndicatorLight1 = 12;
int red1 = 11;
int amb1 = 10;
int grn1 = 9;



// Variables for second set of lights and button (Eastbound)
int Buttonpin2 = 2;
int IndicatorLight2 = 3;
int red2 = 6;
int amb2 = 5;
int grn2 = 4;

// Variables for stoplight time
unsigned long lastTime; // This will be used along with millis to allow the if statements to work for the stoplights
int grnTime = 6000;
int redTime = 800;
int ambTime = 1000;
int redLightswitch = 0; //Allows the stoplights to run independently of each other, acts as another check


unsigned long buttonTime; // This variable will be used with millis to determine when the button is pressed
int buttonPress = 0; // And this is for if it has been pressed

void setup() {

  //Initializing the buttons and lights for input and output respectively
  pinMode(Buttonpin1, INPUT);
  pinMode(IndicatorLight1, OUTPUT);
  pinMode(red1, OUTPUT);
  pinMode(amb1, OUTPUT);
  pinMode(grn1, OUTPUT);

  pinMode(Buttonpin2, INPUT);
  pinMode(IndicatorLight2, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(amb2, OUTPUT);
  pinMode(grn2, OUTPUT);


  // Turn on the red lights and make the other lights turn off, to show the stoplight system starting
  digitalWrite(red1, HIGH);
  digitalWrite(red2, HIGH);
  digitalWrite(amb1, LOW);
  digitalWrite(amb2, LOW);
  digitalWrite(grn1, LOW);
  digitalWrite(grn2, LOW);

  // Set the lastTime variable to be millis, as millis() counts time independently & indefinitely
  lastTime = millis();
}

void loop() {

  // Step 1, make it so if 800 milliseconds have passed, turn of the first red light and turn on the first green light.
  // The conditions are specific so each command only runs when it is supposed to.
  if (millis() - lastTime > redTime && (digitalRead(red1) == HIGH) && (digitalRead(red2) == HIGH) && redLightswitch == 0) {
    digitalWrite(red1, LOW);
    digitalWrite(grn1, HIGH);
    lastTime = millis();
    redLightswitch = 1; // This makes it so the second set of lights can function, as they work separately
  }

  // Step 2, make it so if 6 seconds (6000 ms) have passed, turn of the green light and turn on the yellow (amber) light.
  if (millis() - lastTime > grnTime && (digitalRead(grn1)) == HIGH && (digitalRead(amb1))  == LOW) {
    digitalWrite(grn1, LOW);
    digitalWrite(amb1, HIGH);
    lastTime = millis();
  }

  //Step 3, once 1 second (1000 ms) has passed, turn of the first amber light and turn on the red light
  if (millis() - lastTime > ambTime && (digitalRead(amb1)) == HIGH && (digitalRead(red1)) == LOW) {
    digitalWrite(amb1, LOW);
    digitalWrite(red1, HIGH);
    lastTime = millis();
  }

  //Step 4, after 800 milliseconds have passed, turn of the second red light, and start the second green light on
  if (millis() - lastTime > redTime && (digitalRead(red2) == HIGH) && (digitalRead(red1) == HIGH) && redLightswitch == 1) {
    digitalWrite(red2, LOW);
    digitalWrite(grn2, HIGH);
    lastTime = millis();
    redLightswitch = 0; //Switch it back so the first set of lights can run
  }

  //Step 5, if 6 seconds have passed, turn of the second green light and turn on the amber light
  if (millis() - lastTime > grnTime && (digitalRead(grn2) == HIGH) && (digitalRead(amb2) == LOW)) {
    digitalWrite(grn2, LOW);
    digitalWrite(amb2, HIGH);
    lastTime = millis();
  }

  //Step 6, if 1 second has passed, turn of the second amber light and turn on the second red light
  if (millis() - lastTime > ambTime && (digitalRead(amb2) == HIGH) && (digitalRead(red2) == LOW)) {
    digitalWrite(amb2, LOW);
    digitalWrite(red2, HIGH);
    lastTime = millis();
  }

  //Step 7, set up the pedestrian crossing button. If 2 seconds have passed since the green light is on, and the button is pressed,
  //set the buttonPress to 1 (so it recognizes that the first button was pressed, turn on the indicator (white) light and reset millis()
  if (millis() - lastTime > 2000 && (digitalRead(Buttonpin1) == HIGH) && (digitalRead(grn1) == HIGH)) {
    digitalWrite(IndicatorLight1, HIGH);
    buttonPress = 1;
    buttonTime = millis();
  }
  /* This adds a 1 second delay after the button is pressed so the transition does not happen instantly, makes it more realistic
     Confirming if buttonPress == 1, then set the first green light to low and the amber light to high, so the if statements above can work again.
     Then turn of the indicator light and reset millis() and buttonPress */
  if (millis() - buttonTime > 1000 && (buttonPress == 1)) {
    digitalWrite(grn1, LOW);
    digitalWrite(amb1, HIGH);
    digitalWrite(IndicatorLight1, LOW);
    lastTime = millis();
    buttonPress = 0;
  }
  //Step8, This is the same code as the previous two if statements, except it sets buttonPress to 2, so the second button works independently
  if (millis() - lastTime > 2000 && (digitalRead(Buttonpin2) == HIGH) && (digitalRead(grn2) == HIGH)) {
    digitalWrite(IndicatorLight2, HIGH);
    buttonPress = 2;
    buttonTime = millis();
  }
  // Once again does the same thing, but changes the second lights and checks if buttonPress is 2
  // These are split into 2 if statements so the separation is clear, and it makes it more understandable
  if (millis() - buttonTime > 1000 && (buttonPress == 2)) {
    digitalWrite(grn2, LOW);
    digitalWrite(amb2, HIGH);
    digitalWrite(IndicatorLight2, LOW);
    lastTime = millis();
    buttonPress = 0;
  }

}
