//Declaraciones
int Sensor= 2;
int led= 10;

//Configuracion
void setup() {2
  Serial.begin(9600);
  pinMode(led , OUTPUT);
  pinMode(Sensor , INPUT);

}

//Ejecutable
void loop() {
  int lectura = digitalRead(Sensor);
  Serial.println(Sensor);
  if(Sensor=HIGH)
  {
    digitalWrite(led , HIGH);
    delay(1000);
    digitalWrite(led , LOW);
    delay(1000);
  }

  else
  {
    digitalWrite(led , LOW);
  }
}
