#include <Servo.h>

// Define los pines a los que están conectados los servomotores
const int servoPins[] = {9, 10, 11, 12, 13}; // Pines donde están conectados los servomotores
const int numServos = 5;

// Crea un array de objetos Servo
Servo servos[numServos];

// Variable para almacenar el ángulo actual de cada servomotor
int angulosActuales[numServos] = {90, 90, 90, 90, 90};  // Empieza en 90 grados o cualquier posición inicial deseada

void setup() {
  // Inicializa el puerto serie a una velocidad de 9600 baudios
  Serial.begin(9600);

  // Adjunta los objetos Servo a los pines de los servomotores
  for (int i = 0; i < numServos; ++i) {
    servos[i].attach(servoPins[i]);
  }
}

void loop() {
  // Variable para almacenar el número de servo seleccionado
  int servoSeleccionado;
  Serial.read();

  // Esperar a que se reciba el número de servo seleccionado desde Python
  while (Serial.available() <= 0);
  servoSeleccionado = Serial.parseInt();

  // Esperar a que se reciba el ángulo deseado desde Python
  while (Serial.available() <= 0);
  int nuevoAngulo = Serial.parseInt();

  // Limpiar el buffer del puerto serie
  while (Serial.available() > 0) {
    Serial.read();
  }

  // Verificar si el servo seleccionado está dentro del rango válido
  if (servoSeleccionado >= 0 && servoSeleccionado < numServos) {
    // Mover el servomotor al nuevo ángulo especificado
    servos[servoSeleccionado].write(nuevoAngulo);

    // Actualizar el ángulo actual del servo seleccionado
    angulosActuales[servoSeleccionado] = nuevoAngulo;
  }else{
    Serial.write("Numero fuera del limite de servos");
  }
}
