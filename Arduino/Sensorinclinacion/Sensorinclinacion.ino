//Declaraciones
int LED = 8;
int i;

//Configuracion
void setup() {
  pinMode(LED, OUTPUT);

}

//Ejecucion
void loop() {
  while(1){
    i=analogRead(A5);

    if(i>512){
      digitalWrite(LED, HIGH);
      
    }

    else{
      
      digitalWrite(LED, LOW);
    }

  }

}
