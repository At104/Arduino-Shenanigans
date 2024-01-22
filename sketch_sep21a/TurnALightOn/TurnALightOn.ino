 // put your setup code here, to run once:
void setup() {
 pinMode(13, OUTPUT);
}

// put your main code here, to run repeatedly:
void loop() {
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
}
