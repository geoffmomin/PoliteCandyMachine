/*
Cognitive Candy Dispenser
*/
 
 
int motorPin = 3;
 
void setup() 
{ 
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Welcome To The Polite Candy Machine!");
} 
 
 
void loop() 
{ 
//    int speed = 255;
//    if (speed >= 0 && speed <= 255)
//    {
//      analogWrite(motorPin, speed);
//    }
  String data;
  if (Serial.available()) {
    // read all the available characters
    while (Serial.available() > 0) {
      data = Serial.readString();
      data = data[0];
      // display each character to the LCD
      if (data == "p") {
        Serial.println("Aww you're too sweet!");
        analogWrite(motorPin, 255);
        delay(1000);
        analogWrite(motorPin, 0);
      } else {
        Serial.println("Why so sad T_T Try again");
      }
    }
  }
}   
