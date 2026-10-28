int ledr =10; 
int leda =7;
int ledv =4; 
int in_boton_pin = 5;
int val; 

void setup() {
pinMode(ledr, OUTPUT);
pinMode(leda, OUTPUT); 
pinMode(ledv, OUTPUT); 
pinMode(in_boton_pin, INPUT);

}

void loop() {
digitalWrite(ledv, HIGH);
delay(3000);
digitalWrite(ledv, LOW); 
  for(int i=0; i<3; i++)
    {
      delay(500);
      digitalWrite(ledv, HIGH);
      delay(500);
      digitalWrite(ledv, LOW);
    }
    
digitalWrite(leda, HIGH);
delay(3000);
digitalWrite(leda, LOW); 
  for(int i=0; i<3; i++)
    {
      delay(500);
      digitalWrite(leda, HIGH);
      delay(500);
      digitalWrite(leda, LOW);
    }
    
digitalWrite(ledr, HIGH);
delay(3000);
digitalWrite(ledr, LOW);
  for(int i=0; i<3; i++)
    {
      delay(500);
      digitalWrite(ledr, HIGH);
      delay(500);
      digitalWrite(ledr, LOW);
    }
val=digitalRead(in_boton_pin);
if(val==LOW)
  { 
  
    digitalWrite(ledr,LOW);
  
  }
    else
      { 
        
        digitalWrite(ledr,LOW);
        digitalWrite(leda, HIGH);
        delay(3000);
        digitalWrite(leda, LOW); 
        for(int i=0; i<3; i++)
        {
          delay(500);
          digitalWrite(leda, HIGH);
          delay(500);
          digitalWrite(leda, LOW);
        }
          digitalWrite(ledv, HIGH);
  
      }

}