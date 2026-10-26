int r = 2;
int g = 3;
int b = 4;
int botonr = 10;
int botong = 9;
int botonb = 8;
int valr;
int valg;
int valb;
int valpotr, valpotg, valpotb;
int controlr, controlg, controlb;

void setup() {
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(botonr, INPUT);
  pinMode(botong, INPUT);
  pinMode(botonb, INPUT);
  Serial.begin(9600);
}

void loop() {
  valr = digitalRead(botonr);
  valg = digitalRead(botong);
  valb = digitalRead(botonb);
  valpotr = analogRead(A1);
  valpotg = analogRead(A2);
  valpotb = analogRead(A3);
  controlr = map(valpotr, 0, 1023, 0, 255);
  controlg = map(valpotg, 0, 1023, 0, 255);
  controlb = map(valpotb, 0, 1023, 0, 255);


  if (valr == LOW) {

    digitalWrite(r, LOW);

  } else {

    analogWrite(r, controlr);
  }

  if (valg == LOW) {

    digitalWrite(g, LOW);

  } else {

    analogWrite(g, controlg);
  }

  if (valb == LOW) {

    digitalWrite(b, LOW);

  } else {

    analogWrite(b, controlb);
  }
}