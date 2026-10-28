
const int LED = 7; 

void setup()
{
 
  pinMode (LED , OUTPUT);

}

void loop() 
{

  digitalWrite(LED,HIGH);
  delay(5000);
  digitalWrite(LED,LOW);
  delay(5000);

}
