//Autor: Paul Adrian Padilla Guerrero
//Este codigo programa la secuencia de un semaforo, utiliza un potenciometro para que el usuario le asigne el tiempo de duracion al siga y un boton para el paso del peaton
//Ademas se agrego un timbre para el paso del peaton
//definicion de entradas de todos los dispositivos y variables
#define pot A1
#define bocina 9
#define led_verde 2
#define led_amarillo 3
#define led_rojo 4
#define btn   5
#define led_peaton 6

int valorPot= 0;
boolean valor_boton = HIGH;
float tiempo = 0;
float tiem=0;

void setup() {
  pinMode(led_verde, OUTPUT);
  pinMode(led_amarillo, OUTPUT);
  pinMode(led_rojo, OUTPUT);
  pinMode(led_peaton, OUTPUT);
  pinMode(bocina, OUTPUT);
  pinMode(btn, INPUT);
  Serial.begin(9600);
}


void loop() {
    digitalWrite(led_peaton,LOW);
    digitalWrite(led_rojo,LOW);
    //valorPot toma el valor del potenciometro y lo usa para darle tiempo al led verde
    valorPot=analogRead(pot)*3;
    //for para el tiempo que dura el led del semaforo en verde
     for(tiempo=0;tiempo <= valorPot;tiempo = tiempo + 0.01){ 
     digitalWrite(led_verde,HIGH);
      valor_boton = digitalRead(btn);
      //si se presiona el boton el tiempo del verde se termina y prende el verde del peaton
      while(valor_boton == LOW){
        digitalWrite(led_verde,LOW);
        digitalWrite(led_verde,HIGH);
        delay(500);
        digitalWrite(led_verde,LOW);
        delay(500);
        digitalWrite(led_verde,HIGH);
        delay(500);
        digitalWrite(led_verde,LOW);
        delay(500);
        digitalWrite(led_verde,HIGH);
        delay(500);
        digitalWrite(led_verde,LOW);
        delay(500);
        digitalWrite(led_amarillo,HIGH);
        delay(500);
        digitalWrite(led_amarillo,LOW);
        delay(500);
        analogWrite(bocina,128);
        digitalWrite(led_peaton,HIGH);
        digitalWrite(led_rojo,HIGH);
        delay(3000);
        analogWrite(bocina,LOW);
        digitalWrite(led_rojo,LOW);
        digitalWrite(led_peaton,LOW);
        delay(1000);
        valor_boton = HIGH;
        valorPot=analogRead(pot)*3;
      }  
     }
      digitalWrite(led_verde,LOW);
      delay(500); 
      digitalWrite(led_verde,HIGH);
      delay(500);
      digitalWrite(led_verde,LOW);
      delay(500);
      digitalWrite(led_verde,HIGH);
      delay(500);
      digitalWrite(led_verde,LOW);
      delay(500);
      digitalWrite(led_amarillo,HIGH);
      delay(500);
      digitalWrite(led_amarillo,LOW);
      delay(500);
      analogWrite(bocina,128);
      digitalWrite(led_rojo,HIGH);
      digitalWrite(led_peaton,HIGH);
      delay(3000);
      analogWrite(bocina,LOW);
      digitalWrite(led_rojo,LOW);
      digitalWrite(led_peaton,LOW);
      delay(1000);
}
