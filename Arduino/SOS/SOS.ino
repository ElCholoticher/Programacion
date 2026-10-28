int ledr1 =10; 
int ledp =4; 

void setup() 

{

pinMode(ledr1, OUTPUT); 
pinMode(ledr1, OUTPUT); 

}

void loop() 

{

digitalWrite(ledr1, HIGH);
digitalWrite(ledr1, LOW); 
  for(int i=0; i<3; i++)
    {
      delay(500);
      digitalWrite(ledr1, HIGH);
      delay(500);
      digitalWrite(ledr1, LOW);
    }

    
digitalWrite(ledp, HIGH);
digitalWrite(ledp, LOW); 
  for(int i=0; i<3; i++)
    {
      delay(500);
      digitalWrite(ledp, HIGH);
      delay(500);
      digitalWrite(ledp, LOW);
    }

}
