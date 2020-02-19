/*  
 MIlani Francesco
 3AI
 19.04.18
  
 Half-duplex station, with serial communication between two arduino.

 Send a number m and if receive number n, resend number m
  
 */

const int ledPin= 13;

int n = 0;   // for incoming serial data

int m = 4;  // for random number

void setup() {

  pinMode(ledPin,OUTPUT);

  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
  
}

void loop() {
   
  // send data only when you receive data:
  if (Serial.available() > 0) {
    
    // read the incoming byte:
     n= Serial.read();
  
}
  
    n-=48;

    delay(500);         

    if(n==8){
        
      while(n>0){            //Blink led

      digitalWrite(ledPin, HIGH);
      delay(500);
      digitalWrite(ledPin, LOW);
      delay(100);

      n--;
      
   }
      
    Serial.println("Returns m: ");
    Serial.println(m);
    Serial.write(m);
    
    }
  
  else
  {
    Serial.print("Insert n=8");
  }
  
  
}


