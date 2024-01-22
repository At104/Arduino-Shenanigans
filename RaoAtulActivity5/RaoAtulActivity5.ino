
int potValue = 0;
int pbValue = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  potValue = analogRead(A0);
  pbValue = analogRead(A1);
  Serial.print("Potentiometer = ");
  Serial.print(potValue);
  Serial.print("\t Push Button = ");
  Serial.println(pbValue);
  delay(0.5);
}
