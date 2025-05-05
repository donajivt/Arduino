// Autor: Vania Donaji
// Fecha: 02/11/23

void setup()
{
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

int arrayPinesLed[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};  
int numeroDeLeds = 10;  // Número de leds
int ledActual = 0;  // Iniciar con el primer LED
int estadoDelBoton = 0;
int nuevoEstadoDelBoton = 0;
int numeroDeVueltas = 0;
int ledAnterior=12;

void loop()
{
  // Leer el estado del botón
  nuevoEstadoDelBoton = digitalRead(3);

  // Si el botón está siendo presionado:
  if (estadoDelBoton == 0 && nuevoEstadoDelBoton == 1) {
    numeroDeVueltas++;
    Serial.println(numeroDeVueltas);
    if (ledActual < numeroDeLeds) {
      digitalWrite(arrayPinesLed[ledActual], HIGH); // Enciende el LED actual
      delay(500);
      ledActual++;  // Avanza al siguiente LED
    }else{
      if(ledActual == 10){
        digitalWrite(arrayPinesLed[ledAnterior-4], HIGH);  // Enciende el LED [8]
        delay(500);
        ledAnterior--;  // Decrementa al LED anterior
      }else{
        digitalWrite(arrayPinesLed[ledAnterior], HIGH);  // Enciende el LED 12
        delay(500);
        ledAnterior--;  // Decrementa al LED anterior
      }
    }
  }
  
  // Si el botón se deja de presionar: 
  if (estadoDelBoton == 1 && nuevoEstadoDelBoton == 0) {
    Serial.println(ledActual);
    if (ledActual > 0 && ledActual < 11 && ledActual != 9) {
      ledActual--;  // Retrocede al LED anterior
      digitalWrite(arrayPinesLed[ledActual], LOW);  // Apaga el LED actual
      delay(200);
      ledActual++;
    }else{
      ledActual--;  // Retrocede al LED anterior
      digitalWrite(arrayPinesLed[ledActual], LOW);  // Apaga el LED actual
      delay(200);
      ledActual++;
    }

	// Si el botón se deja de presionar: 
  if (estadoDelBoton == 1 && nuevoEstadoDelBoton == 0) {
    Serial.println(ledAnterior);
    if (ledAnterior > 0 && ledAnterior < 11 && ledAnterior != 9) {
      ledAnterior--;  // Retrocede al LED anterior
      digitalWrite(arrayPinesLed[ledAnterior-2], LOW);  // Apaga el LED actual
      delay(200);
      ledAnterior++;
    }else{
      ledAnterior--;  // Retrocede al LED anterior
      digitalWrite(arrayPinesLed[ledAnterior-2], LOW);  // Apaga el LED actual
      delay(200);
      ledAnterior++;
    }
  }
  }
  if(ledActual == 10 && ledAnterior == 3){
    ledActual = 1;
    ledAnterior = 12;
  }
  // Actualiza el estado anterior del botón
  estadoDelBoton = nuevoEstadoDelBoton;  
}
