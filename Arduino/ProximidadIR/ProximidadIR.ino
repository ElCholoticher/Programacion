//declaraciones
int sensor=7;
int buzzer=8;

//configuracion
void setup() {
  pinMode(buzzer , OUTPUT);
  pinMode(sensor , INPUT);

}

//loop
void loop() {
  if(0==digitalRead(sensor))
  {
    digitalWrite(buzzer, HIGH);
  }
  else{
    digitalWrite(buzzer, LOW);
  }

}
