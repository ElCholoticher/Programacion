int luzr=8;
int luzg=7;
int luzb=6;
int val;

void setup() {
  
  pinMode(luzr , OUTPUT);
  pinMode(luzg , OUTPUT);
  pinMode(luzb , OUTPUT);
  Serial.begin(9600);

}

void loop() {
  
  for(val=225; val>0; val++){

      analogWrite(8 , val);
      analogWrite(7 , val);
      analogWrite(6 , val);
      delay(1);

  }

}
