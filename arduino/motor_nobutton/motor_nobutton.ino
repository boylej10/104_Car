//L293D
//Motor A
const int motorPin1  = 5;  // Pin 14 of L293
const int motorPin2  = 6;  // Pin 10 of L293
//Motor B
const int motorPin3  = 10; // Pin  7 of L293
const int motorPin4  = 9;  // Pin  2 of L293

String readString; 

//This will run only one time.
void setup(){
 
    //Set pins as outputs
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);

    Serial.begin(9600); //Serial read rate
    
    //Motor Control - Motor A: motorPin1,motorpin2 & Motor B: motorpin3,motorpin4

    
}


void loop(){

  while (!Serial.available()) {}

  while (Serial.available()){
    if (Serial.available() >0){
      char c = Serial.read();
      readString = c;
    }
    if (readString.length() >0){
      Serial.println("Message from Arduino: "+ readString);
      if (readString == "1"){
        //This code  will turn Motor A clockwise for 2 sec.
        digitalWrite(motorPin1, LOW);
        digitalWrite(motorPin2, HIGH);
        digitalWrite(motorPin3, LOW);
        digitalWrite(motorPin4, HIGH);
        delay(1000); 
            
        //And this code will stop motors
        digitalWrite(motorPin1, LOW);
        digitalWrite(motorPin2, LOW);
        digitalWrite(motorPin3, LOW);
        digitalWrite(motorPin4, LOW);
        
        Serial.println("Arduino: Moving forward!");

        break;
      }
      else if (readString == "2"){
        //This code will turn Motor A counter-clockwise for 2 sec.
        digitalWrite(motorPin1, HIGH);
        digitalWrite(motorPin2, LOW);
        digitalWrite(motorPin3, HIGH);
        digitalWrite(motorPin4, LOW);
        delay(1000);
        //And this code will stop motors
        digitalWrite(motorPin1, LOW);
        digitalWrite(motorPin2, LOW);
        digitalWrite(motorPin3, LOW);
        digitalWrite(motorPin4, LOW);
        
        Serial.println("Arduino: Moving backward!");

        break;
      }
      else if (readString == "3"){
        //This code will turn Motor B clockwise for 2 sec.
        digitalWrite(motorPin1, LOW);
        digitalWrite(motorPin2, HIGH);
        digitalWrite(motorPin3, LOW);
        digitalWrite(motorPin4, LOW);
        delay(500);
        //And this code will stop motors
        digitalWrite(motorPin1, LOW);
        digitalWrite(motorPin2, LOW);
        digitalWrite(motorPin3, LOW);
        digitalWrite(motorPin4, LOW);
        
        Serial.println("Arduino: Moving left!");

        break;
      }
      else if (readString == "4"){
        //This code will turn Motor B counter-clockwise for 2 sec.
        digitalWrite(motorPin1, LOW);
        digitalWrite(motorPin2, LOW);
        digitalWrite(motorPin3, LOW);
        digitalWrite(motorPin4, HIGH);
        delay(500);
        //And this code will stop motors
        digitalWrite(motorPin1, LOW);
        digitalWrite(motorPin2, LOW);
        digitalWrite(motorPin3, LOW);
        digitalWrite(motorPin4, LOW);
        
        Serial.println("Arduino: Moving right!");    

        break;
      }
      else{}
    }
  }
  
//    //This code  will turn Motor A clockwise for 2 sec.
//    digitalWrite(motorPin1, HIGH);
//    digitalWrite(motorPin2, LOW);
//    digitalWrite(motorPin3, LOW);
//    digitalWrite(motorPin4, LOW);
//    delay(2000); 
//    //This code will turn Motor A counter-clockwise for 2 sec.
//    digitalWrite(motorPin1, LOW);
//    digitalWrite(motorPin2, HIGH);
//    digitalWrite(motorPin3, LOW);
//    digitalWrite(motorPin4, LOW);
//    delay(2000);
//    
//    //This code will turn Motor B clockwise for 2 sec.
//    digitalWrite(motorPin1, LOW);
//    digitalWrite(motorPin2, LOW);
//    digitalWrite(motorPin3, HIGH);
//    digitalWrite(motorPin4, LOW);
//    delay(2000); 
//    //This code will turn Motor B counter-clockwise for 2 sec.
//    digitalWrite(motorPin1, LOW);
//    digitalWrite(motorPin2, LOW);
//    digitalWrite(motorPin3, LOW);
//    digitalWrite(motorPin4, HIGH);
//    delay(2000);    
//    
//    //And this code will stop motors
//    digitalWrite(motorPin1, LOW);
//    digitalWrite(motorPin2, LOW);
//    digitalWrite(motorPin3, LOW);
//    digitalWrite(motorPin4, LOW);
//  

}

