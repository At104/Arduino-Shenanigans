//Atul R, change LED light that turns on with sequential button presses

// NEED TO ADD DEBOUNCE EVENTUALLY TO MAKE IT WORK BETTER, also add comments

const int ledPin = 12; //Originally 6
const int ledPin2 = 10; //Originally 4
const int ledPin3 = 8; //Originally 2
const int buttonPin = 2; //Originally 13 
static int pressCount = 0;
int buttonState;
int lastButtonState;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600); 

  digitalWrite(ledPin, LOW);    
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState){
    if (buttonState == HIGH){
      pressCount++;
      Serial.println(pressCount);
        if (pressCount == 4) {
          pressCount = 1;
        }
      }
    } 
  lastButtonState = buttonState;

  //probably should make it else and elseif statements but it wasnt working idk
  if (pressCount == 1) {
      digitalWrite(ledPin, HIGH);    
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
    }

  if (pressCount == 2) {
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin, LOW);
      digitalWrite(ledPin3, LOW);
    }

  
  if (pressCount == 3) {
      digitalWrite(ledPin3, HIGH);
      digitalWrite(ledPin, LOW);
      digitalWrite(ledPin2, LOW);
    }    

  
 }

  
  

    
    

    
    
    
   
  

  
  
  
  
  
