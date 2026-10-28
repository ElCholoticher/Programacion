//DECLARACIONES
const int DIP[3]={2, 3, 4};
const int LEDS[7]={5,6,7,8,9,10,11};
int anterior = 0;

//CONFIGURACIÓN
void setup() {
  for(int i=0; i<3; i++){
    pinMode(DIP[i], INPUT);
  }
  for(int i=0; i<7; i++){
    pinMode(LEDS[i], OUTPUT);
  }
}

//FUNCIONES
int toDecimal(int estado[3]){
  return (estado[0]*4 + estado[1]*2 + estado[2]);
}

//FUNCIÓN LOOP
void loop() {
  int estado[3]={LOW, LOW, LOW};
  for(int i=0; i<3; i++){
    estado[i]=digitalRead(DIP[i]);
  }
  int decimal = toDecimal(estado);
  digitalWrite(LEDS[anterior], LOW);
  if(decimal>0){
    decimal--;
    digitalWrite(LEDS[decimal], HIGH);
  }
  anterior = decimal;
}