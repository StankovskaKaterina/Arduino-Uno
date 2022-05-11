// C++ code
//

const int sensorPin = A0; // voltazata sto ja cita temp senzorot
const float baseTemp =24.0; // granicna temp
int pinNumber = 2;
int switchState=0;

void setup()
{
  Serial.begin(9600); 
  pinMode (pinNumber,OUTPUT); 
// go setirame pinot 2 na kojsto e povrzana led diodata
// da bide output pin i inicijalno sijalickata da bide izgasnata
  digitalWrite (pinNumber, LOW);
  pinMode(3, INPUT); // pushbutton-ot
}
void loop()
{
  int sensorVal= analogRead(sensorPin);
  Serial.print("Sensor value: ");
  Serial.print(sensorVal);
  // go pretvorame citanjeto vo voltage
  float voltage = (sensorVal/1024.0)*5.0;
  Serial. print ("Volts: ");
  Serial.print (voltage);
  Serial.println (", C: ");
// voltazata ja pretvorame vo temp vo stepeni
  float temp = (voltage-.5) *100;
  Serial.print(temp);
// ako se nadmine granicnata temperatura
  if (temp > baseTemp){ 
  digitalWrite(pinNumber,HIGH); // trepka led sijalickata
   delay(250);
   digitalWrite(pinNumber, LOW);
   delay(250);
   switchState = digitalRead(3); // sostojba na pushbutton-ot
    if (switchState == HIGH)
    {
      // kje se otvori vratata/servo motorot
      temp = 19.0;
      digitalWrite(pinNumber, LOW);
    }
  }
  
    
}