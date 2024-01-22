// put your setup code here, to run once:

// Atul Rao, Objective: Make 3 seperate lights blink in a loop, first for 5 seconds, second for 1 second, third for 3 seconds, and repeat.

void setup() {
//Set up each individual pin for output (so the light turns on)
pinMode(10-12,OUTPUT);

}

// put your main code here, to run repeatedly:
void loop() {
  
  //Turn the first light (Green) on , then put a delay for 5000 ms (5 seconds) then turn it off
  //digitalWrite(pin, HIGH/LOW); selects whatever pin you put (in this case no.12) and then turn it ON or OFF (HIGH = ON, LOW = OFF)
  digitalWrite(12, HIGH);
  delay(5000);
  digitalWrite(12, LOW);

  //Turn the second light (Yellow) on, then put a delay for 1000 ms (1 seconds) then turn it off
  digitalWrite(11, HIGH);
  delay(1000);
  digitalWrite(11, LOW);

  //Turn the third light (Red) on, then put a delay for 3000 ms (3 seconds) then turn it off
  digitalWrite(10, HIGH);
  delay(3000);
  digitalWrite(10, LOW);

}
