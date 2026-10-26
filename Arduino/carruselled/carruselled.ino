int potpin=0;
int ledpina=8;
int ledpinb=9;
int ledpinc=10;
int val;
int valled;

void setup() {
  pinMode(ledpina , OUTPUT);
  pinMode(ledpinb , OUTPUT);
  pinMode(ledpinc , OUTPUT);
  pinMode(potpin , INPUT);
  Serial.begin(9600);

}

void loop() {
  val=analogRead(potpin);
  Serial.println(val);

  if (val<=100){
    digitalWrite(ledpina , HIGH)
  }

}