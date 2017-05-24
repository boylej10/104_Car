const int controlPin1 = 2;
const int controlPin2 = 3;
const int enablePin = 9;
const int directionSwitchPin = 4;
const int onOffSwitchStatePin = 5;
const int potPin = A0;

int onOffSwitchState = 0;
int previousOnOffSwitchState = 0;
int directionSwitchState = 0;
int previousDirectionSwitchState = 0;

int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;

String readString;

void setup() {
  pinMode(directionSwitchPin, INPUT);
  pinMode(onOffSwitchStatePin, INPUT);
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);

  digitalWrite(enablePin, LOW);
  
  Serial.begin(9600);
  
}

void loop() {
  onOffSwitchState = digitalRead(onOffSwitchStatePin);
  delay(1);
  directionSwitchState = digitalRead(directionSwitchPin);
  motorSpeed = analogRead(potPin)/4;
  
  if(onOffSwitchState != previousDirectionSwitchState){
    if(onOffSwitchState == HIGH){
      motorEnabled = !motorEnabled;
    }
  }

  if(directionSwitchState != previousDirectionSwitchState){
    if(directionSwitchState == HIGH){
      motorDirection = !motorDirection;
    }
  }

  if(motorDirection == 1){
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  }

  else{
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  }

  if(motorEnabled == 1){
    analogWrite(enablePin, motorSpeed);
  }

  else{
    analogWrite(enablePin, 0);
  }

  while (!Serial.available()) {}

  while (Serial.available()){
    if (Serial.available() >0){
      char c = Serial.read();
      readString = c;
    }
    if (readString.length() >0){
      Serial.println("Message from Arduino: "+ readString);
      if (readString == "1"){
        digitalWrite(controlPin1, LOW);
        digitalWrite(controlPin2, HIGH);
        Serial.println("Arduino: Someone sent a tweet; motor on!");
      }
    }
  }

  previousDirectionSwitchState = directionSwitchState;
  previousOnOffSwitchState = onOffSwitchState;
  
}
