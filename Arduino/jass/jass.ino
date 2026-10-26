// ------------------ Biblioteca(s) ------------------
#include <SoftwareSerial.h> // Permite comunicación serial por software

// ------------------ Pines ------------------
#define MOTOR_CABINA_IN1 2     // Pin para controlar sentido del motor de cabina
#define MOTOR_CABINA_IN2 3     // Pin para controlar sentido del motor de cabina
#define MOTOR_CABINA_PWM 9     // Pin para controlar velocidad del motor de cabina (PWM)

#define MOTOR_PUERTA_IN3 4     // Pin para controlar sentido del motor de puerta
#define MOTOR_PUERTA_IN4 5     // Pin para controlar sentido del motor de puerta
#define MOTOR_PUERTA_PWM 10    // Pin para controlar velocidad del motor de puerta (PWM)

#define FC_PISO1 6             // Pin para sensor final de carrera piso 1
#define FC_PISO2 7             // Pin para sensor final de carrera piso 2
#define FC_PUERTA_ABIERTA 8    // Pin para sensor puerta abierta
#define FC_PUERTA_CERRADA 11   // Pin para sensor puerta cerrada

#define BTN_ABRIR_PUERTA 12    // Pin para botón abrir puerta
#define BTN_MOVER 13           // Pin para botón mover cabina

#define DISPLAY_DATA 14        // Pin para enviar datos al display
#define DISPLAY_LATCH 15       // Pin para latch del display
#define DISPLAY_CLK 16         // Pin para clock del display

SoftwareSerial BT(17, 18); // RX, TX // Objeto BT declarado aquí (línea 22), usado para comunicación Bluetooth

// 7 segmentos: 0=en movimiento, 1=piso1, 2=piso2
byte numeros[3] = {
  0b00111111, // 0
  0b00000110, // 1
  0b01011011  // 2
}; // Arreglo 'numeros' declarado aquí (línea 25), usado para mostrar números en el display

// ------------------ Variables ------------------
enum EstadoCabina { MOVIMIENTO, PISO1, PISO2 }; // Enumeración de estados de cabina (línea 33)
enum EstadoPuerta { ABIERTA, CERRADA, MOVIENDO }; // Enumeración de estados de puerta (línea 34)

EstadoCabina estadoCabina = PISO1; // Variable 'estadoCabina' declarada aquí (línea 36), indica el estado actual de la cabina
EstadoPuerta estadoPuerta = CERRADA; // Variable 'estadoPuerta' declarada aquí (línea 37), indica el estado actual de la puerta

int pisoDestino = 1; // Variable 'pisoDestino' declarada aquí (línea 39), indica el piso al que se moverá la cabina


// ------------------ Funciones ------------------
void setup() {
  // Configura los pines de los motores como salida
  pinMode(MOTOR_CABINA_IN1, OUTPUT);      // Motor cabina IN1 (línea 5)
  pinMode(MOTOR_CABINA_IN2, OUTPUT);      // Motor cabina IN2 (línea 6)
  pinMode(MOTOR_CABINA_PWM, OUTPUT);      // Motor cabina PWM (línea 7)
  
  pinMode(MOTOR_PUERTA_IN3, OUTPUT);      // Motor puerta IN3 (línea 9)
  pinMode(MOTOR_PUERTA_IN4, OUTPUT);      // Motor puerta IN4 (línea 10)
  pinMode(MOTOR_PUERTA_PWM, OUTPUT);      // Motor puerta PWM (línea 11)

  // Configura los pines de los sensores como entrada con pullup
  pinMode(FC_PISO1, INPUT_PULLUP);        // Sensor piso 1 (línea 13)
  pinMode(FC_PISO2, INPUT_PULLUP);        // Sensor piso 2 (línea 14)
  pinMode(FC_PUERTA_ABIERTA, INPUT_PULLUP);// Sensor puerta abierta (línea 15)
  pinMode(FC_PUERTA_CERRADA, INPUT_PULLUP);// Sensor puerta cerrada (línea 16)

  // Configura los pines de los botones como entrada con pullup
  pinMode(BTN_ABRIR_PUERTA, INPUT_PULLUP);// Botón abrir puerta (línea 18)
  pinMode(BTN_MOVER, INPUT_PULLUP);       // Botón mover cabina (línea 19)

  // Configura los pines del display como salida
  pinMode(DISPLAY_DATA, OUTPUT);          // Pin data display (línea 21)
  pinMode(DISPLAY_LATCH, OUTPUT);         // Pin latch display (línea 22)
  pinMode(DISPLAY_CLK, OUTPUT);           // Pin clock display (línea 23)

  // Inicia la comunicación Bluetooth
  BT.begin(9600);                         // Objeto BT (línea 22)

  // Estado inicial del display mostrando piso 1
  mostrarDisplay(1);                      // Función mostrarDisplay (línea 68), usa el arreglo 'numeros' (línea 25)
}

void loop() {
  leerBluetooth(); // Revisa si hay comandos Bluetooth por ejecutar (función línea 138)
  leerBotones();   // Revisa si hay botones presionados por el usuario (función línea 121)
}

// ----------- Motores -----------

// Mueve la cabina hacia arriba
void moverCabinaArriba() {
  digitalWrite(MOTOR_CABINA_IN1, HIGH); // Motor cabina IN1 (línea 5)
  digitalWrite(MOTOR_CABINA_IN2, LOW);  // Motor cabina IN2 (línea 6)
  analogWrite(MOTOR_CABINA_PWM, 200);   // Motor cabina PWM (línea 7), velocidad fija
}

// Mueve la cabina hacia abajo
void moverCabinaAbajo() {
  digitalWrite(MOTOR_CABINA_IN1, LOW);  // Motor cabina IN1 (línea 5)
  digitalWrite(MOTOR_CABINA_IN2, HIGH); // Motor cabina IN2 (línea 6)
  analogWrite(MOTOR_CABINA_PWM, 200);   // Motor cabina PWM (línea 7)
}

// Detiene la cabina
void detenerCabina() {
  digitalWrite(MOTOR_CABINA_IN1, LOW);  // Motor cabina IN1 (línea 5)
  digitalWrite(MOTOR_CABINA_IN2, LOW);  // Motor cabina IN2 (línea 6)
  analogWrite(MOTOR_CABINA_PWM, 0);     // Motor cabina PWM (línea 7)
}

// Motor puerta: sentido y velocidad
// Abre la puerta
void abrirPuerta() {
  digitalWrite(MOTOR_PUERTA_IN3, HIGH); // Motor puerta IN3 (línea 9)
  digitalWrite(MOTOR_PUERTA_IN4, LOW);  // Motor puerta IN4 (línea 10)
  analogWrite(MOTOR_PUERTA_PWM, 150);   // Motor puerta PWM (línea 11), velocidad suave
}

// Cierra la puerta
void cerrarPuerta() {
  digitalWrite(MOTOR_PUERTA_IN3, LOW);  // Motor puerta IN3 (línea 9)
  digitalWrite(MOTOR_PUERTA_IN4, HIGH); // Motor puerta IN4 (línea 10)
  analogWrite(MOTOR_PUERTA_PWM, 150);   // Motor puerta PWM (línea 11)
}

// Detiene el motor de la puerta
void detenerPuerta() {
  digitalWrite(MOTOR_PUERTA_IN3, LOW);  // Motor puerta IN3 (línea 9)
  digitalWrite(MOTOR_PUERTA_IN4, LOW);  // Motor puerta IN4 (línea 10)
  analogWrite(MOTOR_PUERTA_PWM, 0);     // Motor puerta PWM (línea 11)
}

// ----------- Display 7 segmentos con 74HC595 -----------
// Muestra el número correspondiente en el display de 7 segmentos
void mostrarDisplay(uint8_t num) {
  digitalWrite(DISPLAY_LATCH, LOW);              // Pin latch display (línea 22)
  shiftOut(DISPLAY_DATA, DISPLAY_CLK, MSBFIRST, numeros[num]); // Pin data (línea 21), clock (línea 23), arreglo 'numeros' (línea 25)
  digitalWrite(DISPLAY_LATCH, HIGH);             // Pin latch display (línea 22)
}

// ----------- Acciones principales -----------
// Mueve la cabina al piso solicitado
void moverAlPiso(int piso) {
  // Si la puerta está abierta, la cierra antes de mover la cabina
  if (digitalRead(FC_PUERTA_ABIERTA) == LOW) {     // Sensor puerta abierta (línea 15)
    cerrarPuerta();                                // Función cerrarPuerta (línea 89)
    while (digitalRead(FC_PUERTA_CERRADA) != LOW); // Espera hasta que el sensor puerta cerrada (línea 16) esté activado
    detenerPuerta();                               // Función detenerPuerta (línea 95)
    estadoPuerta = CERRADA;                        // Variable estadoPuerta (línea 37)
  }

  // Mueve la cabina al piso solicitado
  if (piso == 1) {
    moverCabinaAbajo();     // Función moverCabinaAbajo (línea 75)
    mostrarDisplay(0);      // Función mostrarDisplay (línea 68), muestra "en movimiento"
    while (digitalRead(FC_PISO1) != LOW); // Espera hasta llegar a piso 1 (sensor línea 13)
    detenerCabina();        // Función detenerCabina (línea 81)
    estadoCabina = PISO1;   // Variable estadoCabina (línea 36)
    mostrarDisplay(1);      // Función mostrarDisplay (línea 68), muestra "piso 1"
  } else if (piso == 2) {
    moverCabinaArriba();    // Función moverCabinaArriba (línea 69)
    mostrarDisplay(0);      // Función mostrarDisplay (línea 68)
    while (digitalRead(FC_PISO2) != LOW); // Espera hasta llegar a piso 2 (sensor línea 14)
    detenerCabina();        // Función detenerCabina (línea 81)
    estadoCabina = PISO2;   // Variable estadoCabina (línea 36)
    mostrarDisplay(2);      // Función mostrarDisplay (línea 68), muestra "piso 2"
  }
}

// Abre la puerta
void abrirLaPuerta() {
  abrirPuerta();                              // Función abrirPuerta (línea 86)
  while (digitalRead(FC_PUERTA_ABIERTA) != LOW); // Espera hasta que el sensor puerta abierta (línea 15) esté activado
  detenerPuerta();                            // Función detenerPuerta (línea 95)
  estadoPuerta = ABIERTA;                     // Variable estadoPuerta (línea 37)
}

// ----------- Botones -----------
// Lee el estado de los botones y ejecuta la acción correspondiente
void leerBotones() {
  if (digitalRead(BTN_ABRIR_PUERTA) == LOW) { // Botón abrir puerta (línea 18)
    abrirLaPuerta();                          // Función abrirLaPuerta (línea 113)
    delay(300);                               // Antirebote
  }

  if (digitalRead(BTN_MOVER) == LOW) {        // Botón mover cabina (línea 19)
    // Cambia el destino de la cabina dependiendo de su lugar actual
    if (estadoCabina == PISO1) pisoDestino = 2; // Variable estadoCabina (línea 36), pisoDestino (línea 39)
    else pisoDestino = 1;                       // Variable pisoDestino (línea 39)
    moverAlPiso(pisoDestino);                   // Función moverAlPiso (línea 101)
    delay(300);                                 // Antirebote
  }
}

// ----------- Bluetooth -----------
// Lee comandos recibidos por Bluetooth y ejecuta acciones
void leerBluetooth() {
  if (BT.available()) {            // Objeto BT (línea 22)
    char comando = BT.read();      // Lee el comando recibido
    if (comando == 'A') abrirLaPuerta(); // Si recibe 'A', abre la puerta (función línea 113)
    if (comando == '1') moverAlPiso(1);  // Si recibe '1', mueve la cabina al piso 1 (función línea 101)
    if (comando == '2') moverAlPiso(2);  // Si recibe '2', mueve la cabina al piso 2 (función línea 101)
  }
}