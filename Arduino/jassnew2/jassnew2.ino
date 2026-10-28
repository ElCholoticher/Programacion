// ------------------ Biblioteca(s) ------------------
#include <SoftwareSerial.h> // Permite comunicación Bluetooth

// ------------------ Pines ------------------
// Motor cabina
#define MOTOR_CABINA_IN1 2     // Motor cabina IN1, línea 6, Digital
#define MOTOR_CABINA_IN2 3     // Motor cabina IN2, línea 7, Digital
#define MOTOR_CABINA_PWM 9     // Motor cabina PWM, línea 8, Digital (PWM)

// Motor puerta
#define MOTOR_PUERTA_IN3 4     // Motor puerta IN3, línea 10, Digital
#define MOTOR_PUERTA_IN4 5     // Motor puerta IN4, línea 11, Digital
#define MOTOR_PUERTA_PWM 10    // Motor puerta PWM, línea 12, Digital (PWM)

// Finales de carrera
#define FC_PISO1 6             // Final de carrera piso 1, línea 14, Digital
#define FC_PISO2 7             // Final de carrera piso 2, línea 15, Digital
#define FC_PUERTA_ABIERTA 8    // Final de carrera puerta abierta, línea 16, Digital
#define FC_PUERTA_CERRADA 11   // Final de carrera puerta cerrada, línea 17, Digital

// Display 7 segmentos por 74HC595
#define DISPLAY_DATA 14        // Data display, línea 19, Analógico (A0) usado como Digital
#define DISPLAY_LATCH 15       // Latch display, línea 20, Analógico (A1) usado como Digital
#define DISPLAY_CLK 16         // Clock display, línea 21, Analógico (A2) usado como Digital

// ------------------ Botones EXTERNOS ------------------
// Piso 1
#define BTN_LLAMAR_P1 A0       // Botón llamar piso 1, línea 23, Analógico usado como Digital
#define BTN_ABRIR_P1 A1        // Botón abrir piso 1, línea 24, Analógico usado como Digital
#define BTN_CERRAR_P1 A2       // Botón cerrar piso 1, línea 25, Analógico usado como Digital
// Piso 2
#define BTN_LLAMAR_P2 A3       // Botón llamar piso 2, línea 26, Analógico usado como Digital
#define BTN_ABRIR_P2 A4        // Botón abrir piso 2, línea 27, Analógico usado como Digital
#define BTN_CERRAR_P2 A5       // Botón cerrar piso 2, línea 28, Analógico usado como Digital

// ------------------ Botones INTERNOS ------------------
#define BTN_SUBIR 12           // Botón subir (cabina), línea 30, Digital
#define BTN_BAJAR 13           // Botón bajar (cabina), línea 31, Digital

// Bluetooth por SoftwareSerial
SoftwareSerial BT(17, 18);     // RX(17), TX(18), línea 33, Analógico (A3, A4) usados como Digital

// 7 segmentos: 0=en movimiento, 1=piso1, 2=piso2
byte numeros[3] = {
  0b00111111, // 0 (En movimiento)
  0b00000110, // 1 (Piso 1)
  0b01011011  // 2 (Piso 2)
};

// ------------------ Variables ------------------
enum EstadoCabina { MOVIMIENTO, PISO1, PISO2 }; // línea 39
enum EstadoPuerta { ABIERTA, CERRADA, MOVIENDO }; // línea 40

EstadoCabina estadoCabina = PISO1; // Estado inicial cabina, línea 42
EstadoPuerta estadoPuerta = CERRADA; // Estado inicial puerta, línea 43

int pisoDestino = 1; // Destino inicial, línea 45

// ------------------ Setup ------------------
/* Configura todos los pines como entrada/salida según su función y muestra el piso inicial en el display */
void setup() {
  // Motores cabina y puerta
  pinMode(MOTOR_CABINA_IN1, OUTPUT);   // línea 6, Digital
  pinMode(MOTOR_CABINA_IN2, OUTPUT);   // línea 7, Digital
  pinMode(MOTOR_CABINA_PWM, OUTPUT);   // línea 8, Digital (PWM)
  pinMode(MOTOR_PUERTA_IN3, OUTPUT);   // línea 10, Digital
  pinMode(MOTOR_PUERTA_IN4, OUTPUT);   // línea 11, Digital
  pinMode(MOTOR_PUERTA_PWM, OUTPUT);   // línea 12, Digital (PWM)

  // Finales de carrera
  pinMode(FC_PISO1, INPUT_PULLUP);     // línea 14, Digital
  pinMode(FC_PISO2, INPUT_PULLUP);     // línea 15, Digital
  pinMode(FC_PUERTA_ABIERTA, INPUT_PULLUP); // línea 16, Digital
  pinMode(FC_PUERTA_CERRADA, INPUT_PULLUP); // línea 17, Digital

  // Display
  pinMode(DISPLAY_DATA, OUTPUT);       // línea 19, Analógico (A0) como Digital
  pinMode(DISPLAY_LATCH, OUTPUT);      // línea 20, Analógico (A1) como Digital
  pinMode(DISPLAY_CLK, OUTPUT);        // línea 21, Analógico (A2) como Digital

  // Botones externos
  pinMode(BTN_LLAMAR_P1, INPUT_PULLUP);   // línea 23, Analógico como Digital
  pinMode(BTN_ABRIR_P1, INPUT_PULLUP);    // línea 24, Analógico como Digital
  pinMode(BTN_CERRAR_P1, INPUT_PULLUP);   // línea 25, Analógico como Digital
  pinMode(BTN_LLAMAR_P2, INPUT_PULLUP);   // línea 26, Analógico como Digital
  pinMode(BTN_ABRIR_P2, INPUT_PULLUP);    // línea 27, Analógico como Digital
  pinMode(BTN_CERRAR_P2, INPUT_PULLUP);   // línea 28, Analógico como Digital

  // Botones internos
  pinMode(BTN_SUBIR, INPUT_PULLUP);       // línea 30, Digital
  pinMode(BTN_BAJAR, INPUT_PULLUP);       // línea 31, Digital

  // Bluetooth
  BT.begin(9600);                         // línea 33, Analógico (A3/A4) como Digital

  // Estado inicial del display
  //mostrarDisplay(1); // Muestra "Piso 1"

  //Estado inicial del mecanismo
  detenerCabina();   // Asegura que la cabina esté detenida al arrancar
  detenerPuerta();   // Asegura que la puerta esté detenida al arrancar
  delay(500); // Espera a que los pines se estabilicen

  mostrarDisplay(1); // Muestra "Piso 1"
}

// ------------------ Loop ------------------
/* Ciclo principal: revisa Bluetooth, botones externos e internos */
void loop() {
  leerBluetooth();         // función línea 153
  leerBotonesExternos();   // función línea 115
  leerBotonesInternos();   // función línea 133
}

// ----------- Motores -----------

/* Mueve la cabina hacia el segundo piso
   Usa MOTOR_CABINA_IN1 (línea 6, Digital), MOTOR_CABINA_IN2 (línea 7, Digital), MOTOR_CABINA_PWM (línea 8, PWM) */
void moverCabinaArriba() {
  digitalWrite(MOTOR_CABINA_IN1, HIGH);
  digitalWrite(MOTOR_CABINA_IN2, LOW);
  analogWrite(MOTOR_CABINA_PWM, 200);
}

/* Mueve la cabina hacia el primer piso
   Usa MOTOR_CABINA_IN1 (línea 6, Digital), MOTOR_CABINA_IN2 (línea 7, Digital), MOTOR_CABINA_PWM (línea 8, PWM) */
void moverCabinaAbajo() {
  digitalWrite(MOTOR_CABINA_IN1, LOW);
  digitalWrite(MOTOR_CABINA_IN2, HIGH);
  analogWrite(MOTOR_CABINA_PWM, 200);
}

/* Detiene la cabina
   Usa MOTOR_CABINA_IN1 (línea 6, Digital), MOTOR_CABINA_IN2 (línea 7, Digital), MOTOR_CABINA_PWM (línea 8, PWM) */
void detenerCabina() {
  digitalWrite(MOTOR_CABINA_IN1, LOW);
  digitalWrite(MOTOR_CABINA_IN2, LOW);
  analogWrite(MOTOR_CABINA_PWM, 0);
}

/* Abre la puerta de cabina
   Usa MOTOR_PUERTA_IN3 (línea 10, Digital), MOTOR_PUERTA_IN4 (línea 11, Digital), MOTOR_PUERTA_PWM (línea 12, PWM) */
void abrirPuerta() {
  digitalWrite(MOTOR_PUERTA_IN3, HIGH);
  digitalWrite(MOTOR_PUERTA_IN4, LOW);
  analogWrite(MOTOR_PUERTA_PWM, 150);
}

/* Cierra la puerta de cabina
   Usa MOTOR_PUERTA_IN3 (línea 10, Digital), MOTOR_PUERTA_IN4 (línea 11, Digital), MOTOR_PUERTA_PWM (línea 12, PWM) */
void cerrarPuerta() {
  digitalWrite(MOTOR_PUERTA_IN3, LOW);
  digitalWrite(MOTOR_PUERTA_IN4, HIGH);
  analogWrite(MOTOR_PUERTA_PWM, 150);
}

/* Detiene el motor de la puerta
   Usa MOTOR_PUERTA_IN3 (línea 10, Digital), MOTOR_PUERTA_IN4 (línea 11, Digital), MOTOR_PUERTA_PWM (línea 12, PWM) */
void detenerPuerta() {
  digitalWrite(MOTOR_PUERTA_IN3, LOW);
  digitalWrite(MOTOR_PUERTA_IN4, LOW);
  analogWrite(MOTOR_PUERTA_PWM, 0);
}

// ----------- Display 7 segmentos -----------

/* Muestra el número correspondiente en el display de 7 segmentos
   Usa DISPLAY_DATA (línea 19, Analógico/Digital), DISPLAY_CLK (línea 21, Analógico/Digital), DISPLAY_LATCH (línea 20, Analógico/Digital) */
void mostrarDisplay(uint8_t num) {
  digitalWrite(DISPLAY_LATCH, LOW);
  shiftOut(DISPLAY_DATA, DISPLAY_CLK, MSBFIRST, numeros[num]);
  digitalWrite(DISPLAY_LATCH, HIGH);
}

// ----------- Acciones principales -----------

/* Mueve la cabina al piso solicitado, cerrando y abriendo puertas automáticamente
   Usa finales de carrera FC_PUERTA_ABIERTA (línea 16, Digital), FC_PUERTA_CERRADA (línea 17, Digital),
   FC_PISO1 (línea 14, Digital), FC_PISO2 (línea 15, Digital) */
void moverAlPiso(int piso) {
  // Si puerta está abierta, ciérrala antes de moverse
  if (digitalRead(FC_PUERTA_ABIERTA) == LOW) {
    cerrarPuerta();
    while (digitalRead(FC_PUERTA_CERRADA) != LOW);
    detenerPuerta();
    estadoPuerta = CERRADA;
  }
  mostrarDisplay(0); // En movimiento

  if (piso == 1) {
    moverCabinaAbajo();
    while (digitalRead(FC_PISO1) != LOW); // Espera final de carrera piso 1
    detenerCabina();
    estadoCabina = PISO1;
    mostrarDisplay(1);
    abrirLaPuerta(); // Abre puerta al llegar
  } else if (piso == 2) {
    moverCabinaArriba();
    while (digitalRead(FC_PISO2) != LOW); // Espera final de carrera piso 2
    detenerCabina();
    estadoCabina = PISO2;
    mostrarDisplay(2);
    abrirLaPuerta(); // Abre puerta al llegar
  }
}

/* Abre la puerta y espera a que el final de carrera indique puerta abierta
   Usa FC_PUERTA_ABIERTA (línea 16, Digital), MOTOR_PUERTA_IN3/IN4/PWM (líneas 10,11,12) */
void abrirLaPuerta() {
  abrirPuerta();
  while (digitalRead(FC_PUERTA_ABIERTA) != LOW);
  detenerPuerta();
  estadoPuerta = ABIERTA;
}

/* Cierra la puerta y espera a que el final de carrera indique puerta cerrada
   Usa FC_PUERTA_CERRADA (línea 17, Digital), MOTOR_PUERTA_IN3/IN4/PWM (líneas 10,11,12) */
void cerrarLaPuerta() {
  cerrarPuerta();
  while (digitalRead(FC_PUERTA_CERRADA) != LOW);
  detenerPuerta();
  estadoPuerta = CERRADA;
}

// ----------- Botones EXTERNOS -----------

/* Lee los botones externos de ambos pisos y ejecuta acciones
   Usa:
   BTN_LLAMAR_P1 (línea 23, Analógico/Digital), BTN_ABRIR_P1 (línea 24, Analógico/Digital), BTN_CERRAR_P1 (línea 25, Analógico/Digital)
   BTN_LLAMAR_P2 (línea 26, Analógico/Digital), BTN_ABRIR_P2 (línea 27, Analógico/Digital), BTN_CERRAR_P2 (línea 28, Analógico/Digital)
*/
void leerBotonesExternos() {
  // Piso 1
  if (digitalRead(BTN_LLAMAR_P1) == LOW) {
    if (estadoCabina != PISO1) moverAlPiso(1);
    delay(300);
  }
  if (digitalRead(BTN_ABRIR_P1) == LOW) {
    abrirLaPuerta();
    delay(300);
  }
  if (digitalRead(BTN_CERRAR_P1) == LOW) {
    cerrarLaPuerta();
    delay(300);
  }
  // Piso 2
  if (digitalRead(BTN_LLAMAR_P2) == LOW) {
    if (estadoCabina != PISO2) moverAlPiso(2);
    delay(300);
  }
  if (digitalRead(BTN_ABRIR_P2) == LOW) {
    abrirLaPuerta();
    delay(300);
  }
  if (digitalRead(BTN_CERRAR_P2) == LOW) {
    cerrarLaPuerta();
    delay(300);
  }
}

// ----------- Botones INTERNOS -----------

/* Lee los botones internos de la cabina y mueve al piso correspondiente
   Usa BTN_BAJAR (línea 31, Digital), BTN_SUBIR (línea 30, Digital) */
void leerBotonesInternos() {
  if (digitalRead(BTN_BAJAR) == LOW && estadoCabina != PISO1) {
    moverAlPiso(1);
    delay(300);
  }
  if (digitalRead(BTN_SUBIR) == LOW && estadoCabina != PISO2) {
    moverAlPiso(2);
    delay(300);
  }
}

// ----------- Bluetooth -----------

/* Lee comandos por Bluetooth y ejecuta acción correspondiente
   Usa objeto BT (línea 33, Analógico/Digital) */
void leerBluetooth() {
  if (BT.available()) {
    char comando = BT.read();
    if (comando == 'A') abrirLaPuerta();
    if (comando == 'C') cerrarLaPuerta();
    if (comando == '1') moverAlPiso(1);
    if (comando == '2') moverAlPiso(2);
  }
}