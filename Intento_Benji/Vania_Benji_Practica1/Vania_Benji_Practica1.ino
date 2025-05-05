// Autor: VANIA Y BENJI
// Fecha: 02/11/23

void setup() {
  pinMode(3, INPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
}

int arrayPinesLed[] = { 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };  // Pines de los leds en un arreglo
int numeroDeLeds = 10;                                       // Número de leds
int ledActual = 0;                                           // Iniciar con el primer LED
int estadoDelBoton = 0;                                      //Inicar estado del botón
int nuevoEstadoDelBoton = 0;                                 //Para cambiar estado del botón
int numeroDeVueltas = 0;                                     //contar las vueltas para retroceder o avanzar

void loop() {
  // Leer el estado del botón
  nuevoEstadoDelBoton = digitalRead(3);

  // Si el botón está siendo presionado:
  if (estadoDelBoton == 0 && nuevoEstadoDelBoton == 1) {
    Serial.println("NUMERO DE VUELTAS 0:");
    Serial.println(numeroDeVueltas);
    Serial.println("LED ACTUAL 0:");
    Serial.println(ledActual);
    //Para que se vuelva a prender las veces que sean
    if (numeroDeVueltas == 19) {
      Serial.println("REINICIO DE VARIABLES");
      // actualizamos el numero de led con el que se empezara, para no prender el 0 dos veces
      ledActual = 1;
      //le decimos que empiece en la vuelta 1 para controlar nuestras vueltas.
      numeroDeVueltas = 1;
      Serial.println("LED ACTUAL 1:");
      Serial.println(ledActual);
    }
    numeroDeVueltas++;
    Serial.println("NUMERO DE VUELTAS 1:");
    Serial.println(numeroDeVueltas);
    if (ledActual < numeroDeLeds && numeroDeVueltas <= 10) {
      digitalWrite(arrayPinesLed[ledActual], HIGH);  // Enciende el LED actual
      delay(200);
      ledActual++;  // Avanza al siguiente LED
    } else {
      Serial.println("LED ACTUAL 2:");
      Serial.println(ledActual);
      //Encendemos en retroceso
      if (ledActual == 10) {
        digitalWrite(arrayPinesLed[ledActual - 2], HIGH);  // Enciende el LED [8]
        delay(250);
        ledActual--;  // Decrementa al LED anterior
      } else {
        digitalWrite(arrayPinesLed[ledActual - 2], HIGH);  // Enciende el LED 12
        delay(250);
        ledActual--;  // Decrementa al LED anterior
      }
    }
    Serial.println("LED ACTUAL 3:");
    Serial.println(ledActual);
    Serial.println("NUMERO DE VUELTAS 2:");
    Serial.println(numeroDeVueltas);
  }

  // Si el botón se deja de presionar:
  if (estadoDelBoton == 1 && nuevoEstadoDelBoton == 0) {
    if (ledActual > 0 && ledActual < 11 && ledActual != 9) {
      ledActual--;                                  // Retrocede al LED anterior
      digitalWrite(arrayPinesLed[ledActual], LOW);  // Apaga el LED actual
      delay(100);
      ledActual++;
    } else {
      ledActual--;                                  // Retrocede al LED anterior
      digitalWrite(arrayPinesLed[ledActual], LOW);  // Apaga el LED actual
      delay(100);
      ledActual++;
    }
    Serial.println("LED ACTUAL 4:");
    Serial.println(ledActual);
    Serial.println("NUMERO DE VUELTAS 3:");
    Serial.println(numeroDeVueltas);
    Serial.println("///////////////////////////////////////");
  }

  // Actualiza el estado anterior del botón
  estadoDelBoton = nuevoEstadoDelBoton;
}