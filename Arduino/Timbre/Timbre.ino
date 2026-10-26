int buzzer=3;
int in_boton_pin = 6;
int val; 


void setup() {
 pinMode(in_boton_pin, INPUT);
 pinMode(buzzer , OUTPUT);
}

void loop() {
  
  val=digitalRead(in_boton_pin);

  if(val==HIGH){


    for(int i=0; i<3; i++)
    {
      
      digitalWrite(buzzer, HIGH);
      delay(500);
      digitalWrite(buzzer, LOW);
    }




  }

  if else (){


        digitalWrite(buzzer , LOW);


  }


}
