int potpin=0;// inicializa el pin analógico 0 (A0)
int ledpin=13;// inicializa el pin digital 13
int val=0;// define val, asigna valor inicial 0


void setup(){

pinMode(ledpin , OUTPUT);// establece el pin digital como “salida”
Serial.begin(9600);// establece la tasa de baudios en 9600

}

void loop(){

digitalWrite(ledpin,HIGH);// enciende el LED en el pin 13
delay(50);// espera 0,05 segundos
digitalWrite(ledpin,LOW);// apaga el LED en el pin 13
delay(50);// espera 0,05 segundos
val=analogRead(potpin);// lee el valor analógico del pin analógico 0 y lo asigna a val
Serial.println(val);// muestra el valor de val

}