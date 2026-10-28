//DECLARACIONES
const int DIP[3] = {2,3,4}; // declaramos un arreglo para el DIP Switch
int estados[3] = {LOW, LOW, LOW}; // declaramos un segundo arreglo para manejar estados, esto lo hacemos como enteros (int) 
int LED = 7; // Declaramos el pin de nuesto Led

//CONFIGURACIÓN
void setup() {
  Serial.begin(9600); // Inicializamos los badios en 9600
  for(int i=0; i<3; i++){ // Recorremos el arreglo DIP con un for haciendo que cada "entrada" sea un INPUT
    pinMode(DIP[i], INPUT);
  }
}

//FUNCIÓN LOOP
void loop() {
  for(int i=0; i<3; i++){ //Ahora unimos los arreglos mediante un for 
    estados[i]=digitalRead(DIP[i]); 
    Serial.print(i+1); //imprimos los resultados de los arreglos
    Serial.print(": "); 
    Serial.println(estados[i]); //se usa pintln en vez de print
  }
  Serial.println("");
  delay(1000);

}