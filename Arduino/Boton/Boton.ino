int ledpin = 10;
int in_boton_pin = 7;
int val; 


void setup()

{

 pinMode(ledpin, OUTPUT);
 pinMode(in_boton_pin, INPUT);

}

void loop() 

{

  val=digitalRead(in_boton_pin);
  
if(val==LOW)
  { 
  
    digitalWrite(ledpin,LOW);
  
  }
    else
      { 
        
        digitalWrite(ledpin,HIGH);
  
      }

}
