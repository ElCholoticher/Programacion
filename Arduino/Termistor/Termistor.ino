//Declaraciones
int tempPin = A0; //declaramos nuestro pin analogico

//Configuracion
void setup() {
  Serial.begin(9600); 

}

//Funcion loop
void loop() {
  int tempReading = analogRead(tempPin);
  double tempSen= tempReading;
  tempSen = 1/ 0.001129148 + 0.00234125 * log(10000) + 0.0000000876741 * log(tempSen * tempSen * tempSen);
  double TempCorr= tempSen - (125/0.001 * 10000);
  //tempK = 1 / (0.001129148 + (0.00234125 + (0.0000000876741 * tempK * tempK )) * tempK ); 
  //float tempC = tempK - 273.15; Convertir Kelvin a Celsius
  //float tempF = (tempC * 9.0)/ 5.0 + 32.0; //convertir a Fahrenheit
  Serial.print("Temperatura:");
  Serial.print(TempCorr);
  Serial.println("C");
  delay(500);

}
