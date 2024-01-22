/* Assignment 6, Make an LED dim to full brightness, then back down to no brightness, then repeat, using for loops.
 * Programmed by Atul R 
 * Oct 18, 2021
 */
 
// Set up a variable for the pin the LED is wired to
int OutputPin = 10; // IMPORTANT: Has to be plugged into a port that has the "~" symbol next to it, as those are the ones that have 
                    // Pulse Width Modulation (PWM) which allows the analog parts to work
void setup() {
  // Initalize pin 10 for output
  pinMode(OutputPin , OUTPUT);
}

void loop(){

   /* This for loop sets a variable "i" to 0, then makes it when it less than or equal to 255 (as 256 is the highest amount of bytes possible),
    * it goes up by one number, and the analogWrite makes it turn on by whatever number i currently is (dimness), with a small delay to make it visible
    */
   for (int i=0; i <= 255; i++){
      analogWrite(OutputPin , i);
      delay(10);
   } 
   
   /* This for loop does the opposite of the one above. It makes "i"  go down in number
    * which makes the light go dimmer (as it is subtracting rather then adding, after it goes to max brightness above
    */
   
   for (int i=255; i >= 0; i--){
      analogWrite(OutputPin , i);
      delay(10);
   }
   // This then repeats over and over again as the for loop is a loop

}
