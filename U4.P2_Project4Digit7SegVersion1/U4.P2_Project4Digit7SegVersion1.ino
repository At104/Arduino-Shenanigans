/*    Project 4 Digit 7 Segment Timer
      Jan 2021
      Author: Atul R
      *******************       Version 1       **********************
*/ 
int ASeg = 9;
int BSeg = 13;
int CSeg = 4;
int DSeg = 6;
int ESeg = 7;
int FSeg = 10;
int GSeg = 3;
int a1 = 8;
int a2 = 11;
int a3 = 12;
int a4 = 2;
long n = 0; //0 //determines the amount of cycles, every 100 is 1 digit in the ones, so 9999 is 999900
int x = 100; //100
int del = 54; //54   // These 2 determine the timer thing, x is more powerful. X actually is the number that is used in the...
//... equation to determine the what number will be displayed, where as del is the delay between each seperate digit turning on. So if x is higher it takes...
//... longer as the remainder of that / 10 takes longer to become 1-9 (whole number). 100 and 54 are just the "sweet spots" where they both work together as..
//... the coders intended, where it goes fast but not too fast.
void setup()
{
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(a3, OUTPUT);
  pinMode(a4, OUTPUT);
  pinMode(ASeg, OUTPUT);
  pinMode(BSeg, OUTPUT);
  pinMode(CSeg, OUTPUT);
  pinMode(DSeg, OUTPUT);
  pinMode(ESeg, OUTPUT);
  pinMode(FSeg, OUTPUT);
  pinMode(GSeg, OUTPUT);
}
void loop()
{
  clearLEDS();
  pickDigit(1);
  pickNumber((n / x / 1000) % 10); ///1000 as it is the 4th digit (first one to show up)
  delayMicroseconds(del);
  clearLEDS();
  pickDigit(2);
  pickNumber((n / x / 100) % 10); // 100 as it is the third (second to show up)
  delayMicroseconds(del);
  clearLEDS();
  pickDigit(3);
  pickNumber((n / x / 10) % 10); //10 as it is the second (third to show up)
  delayMicroseconds(del);
  clearLEDS();
  pickDigit(4);
  pickNumber(n / x % 10); // nothing as it is the first (last to show up)
  delayMicroseconds(del);
  n++;
}
void pickDigit(int x)
{
  digitalWrite(a1, LOW);
  digitalWrite(a2, LOW);
  digitalWrite(a3, LOW);
  digitalWrite(a4, LOW);
  switch (x)
  {
    case 1:
      digitalWrite(a1, HIGH);
      break;
    case 2:
      digitalWrite(a2, HIGH);
      break;
    case 3:
      digitalWrite(a3, HIGH);
      break;
    case 4:
      digitalWrite(a4, HIGH);
      break;
  }
}
void pickNumber(int x)
{
  switch (x) {
    case 1: one(); break;
    case 2: two(); break;
    case 3: three(); break;
    case 4: four(); break;
    case 5: five(); break;
    case 6: six(); break;
    case 7: seven(); break;
    case 8: eight(); break;
    case 9: nine(); break;
    default: zero(); break;
  }
}
void clearLEDS()
{
  digitalWrite(ASeg, HIGH);
  digitalWrite(BSeg, HIGH);
  digitalWrite(CSeg, HIGH);
  digitalWrite(DSeg, HIGH);
  digitalWrite(ESeg, HIGH);
  digitalWrite(FSeg, HIGH);
  digitalWrite(GSeg, HIGH);
}
void zero() {
  digitalWrite(ASeg, LOW);
  digitalWrite(BSeg, LOW);
  digitalWrite(CSeg, LOW);
  digitalWrite(DSeg, LOW);
  digitalWrite(ESeg, LOW);
  digitalWrite(FSeg, LOW);
  digitalWrite(GSeg, HIGH);
}
void one() {
  digitalWrite(ASeg, HIGH);
  digitalWrite(BSeg, LOW);
  digitalWrite(CSeg, LOW);
  digitalWrite(DSeg, HIGH);
  digitalWrite(ESeg, HIGH);
  digitalWrite(FSeg, HIGH);
  digitalWrite(GSeg, HIGH);
}
void two() {
  digitalWrite(ASeg, LOW);
  digitalWrite(BSeg, LOW);
  digitalWrite(CSeg, HIGH);
  digitalWrite(DSeg, LOW);
  digitalWrite(ESeg, LOW);
  digitalWrite(FSeg, HIGH);
  digitalWrite(GSeg, LOW);
}
void three() {
  digitalWrite(ASeg, LOW);
  digitalWrite(BSeg, LOW);
  digitalWrite(CSeg, LOW);
  digitalWrite(DSeg, LOW);
  digitalWrite(ESeg, HIGH);
  digitalWrite(FSeg, HIGH);
  digitalWrite(GSeg, LOW);
}
void four() {
  digitalWrite(ASeg, HIGH);
  digitalWrite(BSeg, LOW);
  digitalWrite(CSeg, LOW);
  digitalWrite(DSeg, HIGH);
  digitalWrite(ESeg, HIGH);
  digitalWrite(FSeg, LOW);
  digitalWrite(GSeg, LOW);
}
void five() {
  digitalWrite(ASeg, LOW);
  digitalWrite(BSeg, HIGH);
  digitalWrite(CSeg, LOW);
  digitalWrite(DSeg, LOW);
  digitalWrite(ESeg, HIGH);
  digitalWrite(FSeg, LOW);
  digitalWrite(GSeg, LOW);
}
void six() {
  digitalWrite(ASeg, LOW);
  digitalWrite(BSeg, HIGH);
  digitalWrite(CSeg, LOW);
  digitalWrite(DSeg, LOW);
  digitalWrite(ESeg, LOW);
  digitalWrite(FSeg, LOW);
  digitalWrite(GSeg, LOW);
}
void seven() {
  digitalWrite(ASeg, LOW);
  digitalWrite(BSeg, LOW);
  digitalWrite(CSeg, LOW);
  digitalWrite(DSeg, HIGH);
  digitalWrite(ESeg, HIGH);
  digitalWrite(FSeg, HIGH);
  digitalWrite(GSeg, HIGH);
}
void eight() {
  digitalWrite(ASeg, LOW);
  digitalWrite(BSeg, LOW);
  digitalWrite(CSeg, LOW);
  digitalWrite(DSeg, LOW);
  digitalWrite(ESeg, LOW);
  digitalWrite(FSeg, LOW);
  digitalWrite(GSeg, LOW);
}
void nine() {
  digitalWrite(ASeg, LOW);
  digitalWrite(BSeg, LOW);
  digitalWrite(CSeg, LOW);
  digitalWrite(DSeg, LOW);
  digitalWrite(ESeg, HIGH);
  digitalWrite(FSeg, LOW);
  digitalWrite(GSeg, LOW);
}
