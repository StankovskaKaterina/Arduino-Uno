// C++ code
//
int numBlinks;
String msg="How many blinks do you want?";
int j; // counter
int blinkTime=500;
int redPin=12; 
void setup()
{
 Serial.begin(9600);
  pinMode(redPin,OUTPUT);
}

void loop()
{
  Serial.println(msg);
  while (Serial.available()==0){
  }
  numBlinks = Serial.parseInt();
  // blink the LED 
  
  for (j=1; j<=numBlinks;j=j+1){
digitalWrite (redPin, HIGH);
    delay(blinkTime);
    digitalWrite(redPin, LOW);
    delay(blinkTime);
  }
  
  
}