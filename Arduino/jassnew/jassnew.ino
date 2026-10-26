// ------------------ Bibliotecas ------------------
#include <ShiftOut.h>

// ------------------ Definición de Pines ------------------
// Motor cabina (Subir/Bajar) - L298N
#define MOTOR_CABINA_IN1 8   // IN1 L298N - línea 7, Digital
#define MOTOR_CABINA_IN2 9   // IN2 L298N - línea 8, Digital
#define MOTOR_CABINA_PWM 10  // ENA L298N (PWM) - línea 9, Digital (PWM)

// Motor puerta (Abrir/Cerrar) - L298N
#define MOTOR_PUERTA_IN3 6   // IN3 L298N - línea 11, Digital
#define MOTOR_PUERTA_IN4 7   // IN4 L298N - línea 12, Digital
#define MOTOR_PUERTA_PWM 5   // ENB L298N (PWM) - línea 13, Digital (PWM)

// Finales de carrera de piso
#define FC_PISO1 22     // línea 15, Digital
#define FC_PISO2 23     // línea 16, Digital
#define FC_PISO3 24     // línea 17, Digital
#define FC_PISO4 25     // línea 18, Digital

// Finales de carrera de puerta
#define FC_PUERTA_ABIERTA 26 // línea 20, Digital
#define FC_PUERTA_CERRADA 27 // línea 21, Digital

// Botones (Pulsadores)
#define BTN_ABRIR 2     // línea 23, Digital
#define BTN_CERRAR 3    // línea 24, Digital
#define BTN_PISO1 4     // línea 25, Digital
#define BTN_PISO2 11    // línea 26, Digital
#define BTN_PISO3 12    // línea 27, Digital
#define BTN_PISO4 13    // línea 28, Digital

// Display 7 segmentos por 74LS595
#define DISPLAY_DATA 14    // línea 30, Digital (A0 si usas Arduino UNO)
#define DISPLAY_CLK 15     // línea 31, Digital (A1 si usas Arduino UNO)
#define DISPLAY_LATCH 12   // línea 32, Digital

// ------------------ Variables ------------------
// Estados de cabina y puerta
enum EstadoCabina { MOVIMIENTO, PISO1, PISO2, PISO3, PISO4 };
enum EstadoPuerta { ABIERTA, CERRADA, MOVIENDO };

EstadoCabina estadoCabina = PISO1; // Estado inicial de cabina
EstadoPuerta estadoPuerta = CERRADA; // Estado inicial de puerta

int pisoDestino = 1; // Piso destino solicitado

// Segmentos para display: 0=movimiento, 1=piso1, 2=piso2, 3=piso3, 4=piso4
byte numeros[5] = {
  0b00111111, // 0 (En movimiento)
  0b00000110, // 1 (Piso 1)
  0b01011011, // 2 (Piso 2)
  0b01001111, // 3 (Piso 3)
  0b01100110  // 4 (Piso 4)
};

// ------------------ Setup ------------------
void setup() {
  // Configuración de pines de motores (líneas 7-13)
  pinMode(MOTOR_CABINA_IN1, OUTPUT);      // línea 7, Digital
  pinMode(MOTOR_CABINA_IN2, OUTPUT);      // línea 8, Digital
  pinMode(MOTOR_CABINA_PWM, OUTPUT);      // línea 9, Digital (PWM)
  
  pinMode(MOTOR_PUERTA_IN3, OUTPUT);      // línea 11, Digital
  pinMode(MOTOR_PUERTA_IN4, OUTPUT);      // línea 12, Digital
  pinMode(MOTOR_PUERTA_PWM, OUTPUT);      // línea 13, Digital (PWM)

  // Configuración finales de carrera de piso (líneas 15-18)
  pinMode(FC_PISO1, INPUT_PULLUP);        // línea 15, Digital
  pinMode(FC_PISO2, INPUT_PULLUP);        // línea 16, Digital
  pinMode(FC_PISO3, INPUT_PULLUP);        // línea 17, Digital
  pinMode(FC_PISO4, INPUT_PULLUP);        // línea 18, Digital

  // Configuración finales de carrera de puerta (líneas 20-21)
  pinMode(FC_PUERTA_ABIERTA, INPUT_PULLUP);// línea 20, Digital
  pinMode(FC_PUERTA_CERRADA, INPUT_PULLUP);// línea 21, Digital

  // Configuración de botones (líneas 23-28)
  pinMode(BTN_ABRIR, INPUT_PULLUP);       // línea 23, Digital
  pinMode(BTN_CERRAR, INPUT_PULLUP);      // línea 24, Digital
  pinMode(BTN_PISO1, INPUT_PULLUP);       // línea 25, Digital
  pinMode(BTN_PISO2, INPUT_PULLUP);       // línea 26, Digital
  pinMode(BTN_PISO3, INPUT_PULLUP);       // línea 27, Digital
  pinMode(BTN_PISO4, INPUT_PULLUP);       // línea 28, Digital

  // Configuración de pines del display (líneas 30-32)
  pinMode(DISPLAY_DATA, OUTPUT);          // línea 30, Digital
  pinMode(DISPLAY_CLK, OUTPUT);           // línea 31, Digital
  pinMode(DISPLAY_LATCH, OUTPUT);         // línea 32, Digital

  // Muestra piso inicial en el display
  mostrarDisplay(1); // Piso 1
}

// ------------------ Loop ------------------
void loop() {
  leerBotones(); // Función principal que revisa el estado de los botones
}

// ------------------ Motores ------------------
/*
  Función: moverCabinaArriba
  Descripción: Activa el motor para subir la cabina del elevador
  Pines usados: MOTOR_CABINA_IN1 (línea 7, Digital), MOTOR_CABINA_IN2 (línea 8, Digital), MOTOR_CABINA_PWM (línea 9, Digital PWM)
*/
void moverCabinaArriba() {
  digitalWrite(MOTOR_CABINA_IN1, HIGH);
  digitalWrite(MOTOR_CABINA_IN2, LOW);
  analogWrite(MOTOR_CABINA_PWM, 200);
}

/*
  Función: moverCabinaAbajo
  Descripción: Activa el motor para bajar la cabina del elevador
  Pines usados: MOTOR_CABINA_IN1 (línea 7, Digital), MOTOR_CABINA_IN2 (línea 8, Digital), MOTOR_CABINA_PWM (línea 9, Digital PWM)
*/
void moverCabinaAbajo() {
  digitalWrite(MOTOR_CABINA_IN1, LOW);
  digitalWrite(MOTOR_CABINA_IN2, HIGH);
  analogWrite(MOTOR_CABINA_PWM, 200);
}

/*
  Función: detenerCabina
  Descripción: Detiene el motor de la cabina
  Pines usados: MOTOR_CABINA_IN1 (línea 7, Digital), MOTOR_CABINA_IN2 (línea 8, Digital), MOTOR_CABINA_PWM (línea 9, Digital PWM)
*/
void detenerCabina() {
  digitalWrite(MOTOR_CABINA_IN1, LOW);
  digitalWrite(MOTOR_CABINA_IN2, LOW);
  analogWrite(MOTOR_CABINA_PWM, 0);
}

// Puerta: abrir/cerrar
/*
  Función: abrirPuerta
  Descripción: Activa el motor para abrir la puerta del elevador
  Pines usados: MOTOR_PUERTA_IN3 (línea 11, Digital), MOTOR_PUERTA_IN4 (línea 12, Digital), MOTOR_PUERTA_PWM (línea 13, Digital PWM)
*/
void abrirPuerta() {
  digitalWrite(MOTOR_PUERTA_IN3, HIGH);
  digitalWrite(MOTOR_PUERTA_IN4, LOW);
  analogWrite(MOTOR_PUERTA_PWM, 150);
}

/*
  Función: cerrarPuerta
  Descripción: Activa el motor para cerrar la puerta del elevador
  Pines usados: MOTOR_PUERTA_IN3 (línea 11, Digital), MOTOR_PUERTA_IN4 (línea 12, Digital), MOTOR_PUERTA_PWM (línea 13, Digital PWM)
*/
void cerrarPuerta() {
  digitalWrite(MOTOR_PUERTA_IN3, LOW);
  digitalWrite(MOTOR_PUERTA_IN4, HIGH);
  analogWrite(MOTOR_PUERTA_PWM, 150);
}

/*
  Función: detenerPuerta
  Descripción: Detiene el motor de la puerta
  Pines usados: MOTOR_PUERTA_IN3 (línea 11, Digital), MOTOR_PUERTA_IN4 (línea 12, Digital), MOTOR_PUERTA_PWM (línea 13, Digital PWM)
*/
void detenerPuerta() {
  digitalWrite(MOTOR_PUERTA_IN3, LOW);
  digitalWrite(MOTOR_PUERTA_IN4, LOW);
  analogWrite(MOTOR_PUERTA_PWM, 0);
}

// ------------------ Display ------------------
/*
  Función: mostrarDisplay
  Descripción: Muestra el número correspondiente en el display de 7 segmentos usando el 74LS595
  Pines usados: DISPLAY_DATA (línea 30, Digital), DISPLAY_CLK (línea 31, Digital), DISPLAY_LATCH (línea 32, Digital)
*/
void mostrarDisplay(uint8_t num) {
  digitalWrite(DISPLAY_LATCH, LOW);
  shiftOut(DISPLAY_DATA, DISPLAY_CLK, MSBFIRST, numeros[num]);
  digitalWrite(DISPLAY_LATCH, HIGH);
}

// ------------------ Acciones principales ------------------
/*
  Función: moverAlPiso
  Descripción: Mueve la cabina al piso solicitado y actualiza el display
  Pines usados:
    - FC_PUERTA_ABIERTA (línea 20, Digital)
    - FC_PUERTA_CERRADA (línea 21, Digital)
    - FC_PISO1 (línea 15, Digital)
    - FC_PISO2 (línea 16, Digital)
    - FC_PISO3 (línea 17, Digital)
    - FC_PISO4 (línea 18, Digital)
    - Motores de cabina y puerta (líneas 7-13, Digital)
    - Display 7 segmentos (líneas 30-32, Digital)
*/
void moverAlPiso(int piso) {
  // Cierra puerta si está abierta
  if (digitalRead(FC_PUERTA_ABIERTA) == LOW) {
    cerrarPuerta();
    while (digitalRead(FC_PUERTA_CERRADA) != LOW);
    detenerPuerta();
    estadoPuerta = CERRADA;
  }

  // Mueve cabina al piso solicitado
  mostrarDisplay(0); // Movimiento
  switch (piso) {
    case 1:
      moverCabinaAbajo();
      while (digitalRead(FC_PISO1) != LOW);
      detenerCabina();
      estadoCabina = PISO1;
      mostrarDisplay(1);
      break;
    case 2:
      if (estadoCabina == PISO1 || estadoCabina == PISO2) moverCabinaArriba();
      else moverCabinaAbajo();
      while (digitalRead(FC_PISO2) != LOW);
      detenerCabina();
      estadoCabina = PISO2;
      mostrarDisplay(2);
      break;
    case 3:
      moverCabinaArriba();
      while (digitalRead(FC_PISO3) != LOW);
      detenerCabina();
      estadoCabina = PISO3;
      mostrarDisplay(3);
      break;
    case 4:
      moverCabinaArriba();
      while (digitalRead(FC_PISO4) != LOW);
      detenerCabina();
      estadoCabina = PISO4;
      mostrarDisplay(4);
      break;
    default:
      break;
  }
}

/*
  Función: abrirLaPuerta
  Descripción: Abre la puerta del elevador
  Pines usados: FC_PUERTA_ABIERTA (línea 20, Digital), MOTOR_PUERTA_IN3/IN4/PWM (líneas 11-13, Digital)
*/
void abrirLaPuerta() {
  abrirPuerta();
  while (digitalRead(FC_PUERTA_ABIERTA) != LOW);
  detenerPuerta();
  estadoPuerta = ABIERTA;
}

/*
  Función: cerrarLaPuerta
  Descripción: Cierra la puerta del elevador
  Pines usados: FC_PUERTA_CERRADA (línea 21, Digital), MOTOR_PUERTA_IN3/IN4/PWM (líneas 11-13, Digital)
*/
void cerrarLaPuerta() {
  cerrarPuerta();
  while (digitalRead(FC_PUERTA_CERRADA) != LOW);
  detenerPuerta();
  estadoPuerta = CERRADA;
}

// ------------------ Botones ------------------
/*
  Función: leerBotones
  Descripción: Lee el estado de los botones y ejecuta la acción correspondiente
  Pines usados:
    - BTN_ABRIR (línea 23, Digital)
    - BTN_CERRAR (línea 24, Digital)
    - BTN_PISO1 (línea 25, Digital)
    - BTN_PISO2 (línea 26, Digital)
    - BTN_PISO3 (línea 27, Digital)
    - BTN_PISO4 (línea 28, Digital)
*/
void leerBotones() {
  if (digitalRead(BTN_ABRIR) == LOW) {
    abrirLaPuerta();
    delay(300); // Antirebote
  }
  if (digitalRead(BTN_CERRAR) == LOW) {
    cerrarLaPuerta();
    delay(300); // Antirebote
  }
  if (digitalRead(BTN_PISO1) == LOW) {
    moverAlPiso(1);
    delay(300); // Antirebote
  }
  if (digitalRead(BTN_PISO2) == LOW) {
    moverAlPiso(2);
    delay(300); // Antirebote
  }
  if (digitalRead(BTN_PISO3) == LOW) {
    moverAlPiso(3);
    delay(300); // Antirebote
  }
  if (digitalRead(BTN_PISO4) == LOW) {
    moverAlPiso(4);
    delay(300); // Antirebote
  }
}