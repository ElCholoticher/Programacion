int potpin=0;
int ledpin=8;
int val=0;
int brillo;


void setup() {
  pinMode(ledpin , OUTPUT);
  pinMode(potpin , INPUT);
  Serial.begin(9600);

}

void loop() {
  val=analogRead(potpin);
  brillo=map(val , 0 , 1023 , 0 , 255);
  analogWrite(ledpin , brillo);
  Serial.println(val);

}
