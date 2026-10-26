int buzzer=8;


void setup() {
  
  pinMode(buzzer,OUTPUT);

}

void loop() {
  
  char i;

  
    for(i=0;i<80;i++)
    {

      digitalWrite(buzzer,HIGH);
      delay(1);
      digitalWrite(buzzer,LOW);
      delay(1);

    }

    for(i=0;i<100;i++)
    { 
      digitalWrite(buzzer,HIGH);
      delay(1);
      digitalWrite(buzzer,LOW);
      delay(2);
    }


}