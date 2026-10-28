//Declaraciones
int a = 1;
int b = 2;
int c = 3;
int d = 4;
int e = 5;
int f = 6;
int g = 7;
int dp = 8;

//Funciones

void cero (){
  digitalWrite(a , HIGH);
  digitalWrite(b , HIGH);
  digitalWrite(c , HIGH);
  digitalWrite(d , HIGH);
  digitalWrite(e , HIGH);
  digitalWrite(f , HIGH);
  digitalWrite(g , LOW);
  digitalWrite(dp , LOW);
}

void uno (){
  digitalWrite(a , LOW);
  digitalWrite(b , HIGH);
  digitalWrite(c , HIGH);
  digitalWrite(d , LOW);
  digitalWrite(e , LOW);
  digitalWrite(f , LOW);
  digitalWrite(g , LOW);
  digitalWrite(dp , LOW);
}

void dos (){
  digitalWrite(a , HIGH);
  digitalWrite(b , HIGH);
  digitalWrite(c , LOW);
  digitalWrite(d , HIGH);
  digitalWrite(e , HIGH);
  digitalWrite(f , LOW);
  digitalWrite(g , HIGH);
  digitalWrite(dp , LOW);
}

void tres (){
  digitalWrite(a , HIGH);
  digitalWrite(b , HIGH);
  digitalWrite(c , HIGH);
  digitalWrite(d , HIGH);
  digitalWrite(e , LOW);
  digitalWrite(f , LOW);
  digitalWrite(g , HIGH);
  digitalWrite(dp , LOW);
}

void cuatro (){
  digitalWrite(a , LOW);
  digitalWrite(b , HIGH);
  digitalWrite(c , HIGH);
  digitalWrite(d , LOW);
  digitalWrite(e , LOW);
  digitalWrite(f , HIGH);
  digitalWrite(g , HIGH);
  digitalWrite(dp , LOW);
}

void cinco (){
  digitalWrite(a , HIGH);
  digitalWrite(b , LOW);
  digitalWrite(c , HIGH);
  digitalWrite(d , HIGH);
  digitalWrite(e , LOW);
  digitalWrite(f , HIGH);
  digitalWrite(g , HIGH);
  digitalWrite(dp , LOW);
}

void seis (){
  digitalWrite(a , HIGH);
  digitalWrite(b , LOW);
  digitalWrite(c , HIGH);
  digitalWrite(d , HIGH);
  digitalWrite(e , HIGH);
  digitalWrite(f , HIGH);
  digitalWrite(g , HIGH);
  digitalWrite(dp , LOW);
}

void siete (){
  digitalWrite(a , HIGH);
  digitalWrite(b , HIGH);
  digitalWrite(c , HIGH);
  digitalWrite(d , LOW);
  digitalWrite(e , LOW);
  digitalWrite(f , LOW);
  digitalWrite(g , LOW);
  digitalWrite(dp , LOW);
}

void ocho (){
  digitalWrite(a , HIGH);
  digitalWrite(b , HIGH);
  digitalWrite(c , HIGH);
  digitalWrite(d , HIGH);
  digitalWrite(e , HIGH);
  digitalWrite(f , HIGH);
  digitalWrite(g , HIGH);
  digitalWrite(dp , LOW);
}

void nueve (){
  digitalWrite(a , HIGH);
  digitalWrite(b , HIGH);
  digitalWrite(c , HIGH);
  digitalWrite(d , HIGH);
  digitalWrite(e , LOW);
  digitalWrite(f , HIGH);
  digitalWrite(g , HIGH);
  digitalWrite(dp , LOW);
}
//Fin Funciones

//Configuracion
void setup() {
  int i;
  for (i=1 ; i<=11 ; i++){
    pinMode(i , OUTPUT);
  }
}

//Bucle
void loop() {
  while(1){
    cero();
    delay(1000);
    uno();
    delay(1000);
    dos();
    delay(1000);
    tres();
    delay(1000);
    cuatro();
    delay(1000);
    cinco();
    delay(1000);
    seis();
    delay(1000);
    siete();
    delay(1000);
    ocho();
    delay(1000);
    nueve();
    delay(1000);
  }

}
