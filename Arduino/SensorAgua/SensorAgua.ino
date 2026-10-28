//declaraciones 
int Sensor;

//configuracion
void setup() {
  Serial.begin (9600);

}
//loop
void loop() {
  Sensor= analogRead(A0);
  Serial.println(Sensor);
  delay(1000);

}
