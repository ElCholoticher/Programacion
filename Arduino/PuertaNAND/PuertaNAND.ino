int led = 10;
int boton1=5;
int boton2=3;
int val1;
int val2;

void setup() {
  pinMode(led , OUTPUT);
  pinMode(boton1 , INPUT);
  pinMode(boton2 , INPUT);

}

void loop() {
  val1=digitalRead(boton1);
  val2=digitalRead(boton2);

  if(val1== LOW && val2== LOW)
  
  {

    digitalWrite(led , HIGH);

  }

  else if(val1== HIGH && val2== HIGH){

      digitalWrite(led , LOW);

  }



}
