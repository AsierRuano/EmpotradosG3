//variables
int AvDer = 1; //motor derecho
int ReDer = 2; //motor derecho
int AvIzq = 3; //Motor izquierdo
int ReIzq = 4; //Motor Izquierdo
int Bumpers = 6 // señal de bumpers
int BumpD = 7; //BumperDerecho
int BumpI = 8; //BumperIzquierdo


void setup() {
  // put your setup code here, to run once:
 pinMode (AvIzq, OUTPUT); //
 pinMode (AvDer, OUTPUT);
 pinMode (ReIzq, OUTPUT);
 pinMode (ReDer, OUTPUT);
 pinMode (BumpD, INPUT);
 pinMode (BumpI, INPUT);
 pinMode (Bumpers, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(4000);
  RecorridoIzquierda(); //Funcion de recorrido actual
/*  for(int i= 0; i<=4 ; i++){
    Avanzar();
    Retroceder();
   GirarIzquierda();
   CambiarColumna();
   GirarIzquierda();
   Retroceder();
   Avanzar();
   Retroceder();
   GirarDerecha();
   CambiarColumna();
   GirarDerecha();
   Retroceder();
  }
  VueltaCasa();
  Parar();

delay (60000);*/

}
void Avanzar(){  //avanza el robot
  digitalWrite(AvIzq, LOW);
  digitalWrite(AvDer, LOW);
  digitalWrite(ReIzq, LOW);
  digitalWrite(ReDer, LOW);
  delay(500); //para 1 segundos
  
  digitalWrite(ReIzq, LOW);
  digitalWrite(ReDer, LOW);
  digitalWrite(AvIzq, HIGH);
  digitalWrite(AvDer, HIGH);
  delay(4000); //avanza 4 segundos
 }

 void Retroceder(){  //retrocede el robot
  digitalWrite(AvIzq, LOW);
  digitalWrite(AvDer, LOW);
  digitalWrite(ReIzq, LOW);
  digitalWrite(ReDer, LOW);
  delay(500); //para 1 segundos
  
  digitalWrite(AvIzq, LOW);
  digitalWrite(AvDer, LOW);
  digitalWrite(ReIzq, HIGH);
  digitalWrite(ReDer, HIGH);
  delay(1000); //retrocede 1 segundos
 }

 void GirarIzquierda() { //gira a la izquierda
  digitalWrite(AvIzq, LOW);
  digitalWrite(AvDer, LOW);
  digitalWrite(ReIzq, LOW);
  digitalWrite(ReDer, LOW);
  delay(500); //para 1 segundos
  
  digitalWrite(AvDer, HIGH);
  digitalWrite(ReIzq, HIGH);
  delay(1275); //gira izq 3 segundos
 }
 void GirarDerecha() {  //gira A la derecha
  digitalWrite(AvIzq, LOW);
  digitalWrite(AvDer, LOW);
  digitalWrite(ReIzq, LOW);
  digitalWrite(ReDer, LOW);
  delay(500); //para 1 segundos
  
  digitalWrite(AvIzq, HIGH);
  digitalWrite(ReDer, HIGH);
  delay(1275); //gira izq 3 segundos
 }

void CambiarColumna(){  //avanza muy poco para cambiar a la siguiente columna
  digitalWrite(AvIzq, LOW);
  digitalWrite(AvDer, LOW);
  digitalWrite(ReIzq, LOW);
  digitalWrite(ReDer, LOW);
  delay(500); //para 1 segundos
  
  digitalWrite(ReIzq, LOW);
  digitalWrite(ReDer, LOW);
  digitalWrite(AvIzq, HIGH);
  digitalWrite(AvDer, HIGH);
  delay(1500); //avanza 1 segundos
 }
void Fin() { //vuelve a los pies 
  digitalWrite(AvIzq, LOW);
  digitalWrite(AvDer, LOW);
  digitalWrite(ReIzq, LOW);
  digitalWrite(ReDer, LOW);
  delay(500); //para 1 segundos
  
  digitalWrite(AvIzq, LOW);
  digitalWrite(AvDer, LOW);
  digitalWrite(ReIzq, HIGH);
  digitalWrite(ReDer, HIGH);
  delay(1500); //retrocede 1 segundos
 }
void VueltaCasa(){ //vuelve al punto de inicio haciendo un cuadrado
  CambiarColumna();
  GirarDerecha();
  Avanzar();
  GirarIzquierda();
  Fin();
} 
void Parar(){ //el robot se para
  digitalWrite(AvIzq, LOW);
  digitalWrite(AvDer, LOW);
  digitalWrite(ReIzq, LOW);
  digitalWrite(ReDer, LOW);

}
void RecorridoIzquierda(){ //recorre las culumas girando primero a la izquierda
    for(int i= 0; i<=4 ; i++){
    Avanzar();
    Retroceder();
   GirarIzquierda();
   CambiarColumna();
   GirarIzquierda();
   Retroceder();
   Avanzar();
   Retroceder();
   GirarDerecha();
   CambiarColumna();
   GirarDerecha();
   Retroceder();
  }
  VueltaCasa();
  Parar();

delay (60000);}

void RecorridoDerecha(){ //lo mismo pero empezando a la derecha
    for(int i= 0; i<=4 ; i++){
    Avanzar();
    Retroceder();
   GirarDerecha();
   CambiarColumna();
   GirarDerecha();
   Retroceder();
   Avanzar();
   Retroceder();
   GirarIzquierda();
   CambiarColumna();
   GirarIzquierda();
   Retroceder();
  }
  VueltaCasa();
  Parar();

delay (60000);}
////////////////////////////////////////////////////////////////////////////77
void mainBumpers(){  //codigo principal para los bumpers
  while((BumpD == LOW)&&(BumpI == LOW)){ //avanza hasta que se choca y un bumper se activa
    Avanz();
  }
    while((BumpD == HIGH)&&(BumpI == HIGH)){ // retrocede hasta que un bumper queda libre
    Retro();
   digitalWrite(AvDer, LOW);
   digitalWrite(ReIzq, LOW);
   digitalWrite(AvIzq, HIGH);
   digitalWrite(ReDer, HIGH);
    delay(500) //gira a la derecha un poco para que no se peuge otra vez de frente
  }
  
  while(BumpD == HIGH){ //gira izquierda hasta que el bumper derecho queda libre
    Izquieda();
  }
  while(BumpI == HIGH){ //gira derecha hasta que el bumper izquierdo queda libre
    Derecha();
  }

  
  
}
void Avanz(){  //los motores avanzan
  digitalWrite(ReIzq, LOW);
  digitalWrite(ReDer, LOW);
  digitalWrite(AvIzq, HIGH);
  digitalWrite(AvDer, HIGH);
 }

void Iniciar(){ //se activan las resistencias de los pines de los bumpers
  digitalWrite(BumpD,HIGH);
  digitalWrite(BumpI,HIGH);
  digitalWrite(Bumpers,HIGH);
  
}
void Derecha(){ //el robot gira a la derecha (motor derecho gira hacia atras motor izquierdo  gira adelante)
  digitalWrite(AvDer, LOW);
  digitalWrite(ReIzq, LOW);
  digitalWrite(AvIzq, HIGH);
  digitalWrite(ReDer, HIGH);
}
void Izquierda(){
  digitalWrite(AvDer, HIGH);
  digitalWrite(ReIzq, HIGH);
  digitalWrite(AvIzq, LOW);
  digitalWrite(ReDer, LOW);
}
void Retro(){  //retroceder bumpers
  digitalWrite(ReIzq, HIGH);
  digitalWrite(ReDer, HIGH);
  digitalWrite(AvIzq, LOW);
  digitalWrite(AvDer, LOW);
  delay(500)
 
}
