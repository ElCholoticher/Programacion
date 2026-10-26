
int fotopin = 1; //fotoresistencia
int ledpin = 9; //led
int val = 0; //valoracion

void setup() {

  pinMode(ledpin, OUTPUT);
  pinMode(fotopin, INPUT);
  Serial.begin(9600);
}
void loop() {
  val = map(analogRead(fotopin), 0, 1023, 0, 255);
  Serial.print(val);
  if (fotopin<30) {
  digitalWrite(ledpin,  val);
  }
  else if (fotopin>31) {
  digitalWrite(ledpin, LOW);
  }

}

 fullstack= backend + frontend;  
