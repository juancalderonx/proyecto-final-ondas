#define trigPin 11 //numero del pin en donde se ubica el Trig del sensor de distancia
#define echoPin 10 //numero del pin en donde se ubica el Echo del sensor de distancia

int ledVerde = 4; // Aqui vamos a declarar como INT los puertos
int ledAmarillo = 5; // en donde van a ir los leds para hacer
int ledRojo = 6; // mas legible el codigo.
int brillo = 255;

int BUZZER = 7; // Declaramos como INT el puerto donde
// va a ir el positivo de nuestro BUZZER

void setup()
{ Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}

void loop(){
  long duracion, distancia ;
  digitalWrite(trigPin, LOW); // Con esto nos aseguramos de que el trigger está desactivado
  delayMicroseconds(2); // y activaos el pulso de salida, para asegurarnos de que el pin de
  digitalWrite(trigPin, HIGH); // TRIG esta en LOW.
  delayMicroseconds(10); // El pulso sigue activo Todo este tiempo.
  digitalWrite(trigPin, LOW); // Cortamos el pulso y ahora solo queda esperar la señal de ECHO
  duracion = pulseIn(echoPin, HIGH) ;
  distancia = duracion / 2 / 29.1 ; //formula correcta para calcular la duracion de la onda y pasarla a centimetros

Serial.println(String(distancia) + " cm.") ;

if ( distancia > 30) { //condicion que indica si el sensor capta un objeto a mas de 30cm
noTone(BUZZER); //noTone es para hacer que el buzzer no suene
}

if (distancia <= 60 && distancia >= 40) { //si tetecta un objeto de 20cm 30cm se efectua la funcion
luzVerde(); //se añade la funcion que hace parpadear el led Verde
sonidoLargo(); //se añade la funcion que hace que el BUZZER emita el sonido
delay(800); // se agrega un "delay" para apagar el sonido cada medio segundo
}
else {
noTone(BUZZER);
}
if(distancia < 39 && distancia >= 20){ //se efectua la funcion
//si la distancia a un objeto es detectada entre 10cm-19cm
luzAmarilla(); //se añade la funcion que hace parpadear el led Amarilla
sonidoMedio(); //se añade la funcion que hace que el BUZZER emita el sonido
delay(500); // se agrega un "delay" para apagar el sonido cada 200 milisegundos
}
else{
noTone(BUZZER);
}
if ( distancia < 19 && distancia >= 1) { //condicion de distancia que la efectua si la distancia es menor a 10cm
luzRoja(); //se añade la funcion que hace parpadear el led Rojo
sonidoCorto(); //se añade la funcion que hace que el BUZZER emita el sonido
delay(300); //se agrega un "delay" para apagar el sonido cada 100 milisegundos
}
else {
noTone(BUZZER);
}
}

///////////////////////////////////////////////////////////////////
/// Aqui hice unas funciones basicas para el parpadeo del led a ///
/// distinta velocidad dependiendo de la distancia y para que ///
/// los sonidos sean igual mas cortos y agudos dependiendo su ///
/// distancia ///
///////////////////////////////////////////////////////////////////

void luzVerde (){
analogWrite(ledVerde, brillo);
delay(800);
analogWrite(ledVerde, LOW);

}
void sonidoLargo (){
tone(BUZZER, 2000, 200);

}
void luzAmarilla (){
analogWrite(ledAmarillo, brillo);
delay(500);
digitalWrite(ledAmarillo, LOW);

}
void sonidoMedio (){
tone(BUZZER, 2300, 200);

}
void luzRoja (){
analogWrite(ledRojo, brillo);
delay(300);
digitalWrite(ledRojo, LOW);

}
void sonidoCorto (){
tone(BUZZER, 2500, 200);

}
