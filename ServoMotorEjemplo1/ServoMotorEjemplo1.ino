#include <Servo.h>
// Define el pin al que está conectado el servomotor
const int servoPin = 13;

// Crea un objeto Servo
Servo servoMotor;

// Variable para almacenar el ángulo actual del servomotor
int anguloActual = 90;  // Empieza en 90 grados o cualquier posición inicial deseada

void setup() {
  // Inicializa el puerto serie a una velocidad de 9600 baudios
  Serial.begin(9600);
  // Adjunta el objeto Servo al pin del servo
  servoMotor.attach(servoPin);
}

void loop() {
  // Variable para almacenar el nuevo ángulo deseado
  int nuevoAngulo;

  // Solicitar al usuario que ingrese el nuevo ángulo
  Serial.println("Ingrese un ángulo entre 0 y 180 grados:");
  
  // Esperar a que el usuario ingrese un valor
  while (!Serial.available());
  
  // Leer el valor ingresado por el usuario
  nuevoAngulo = Serial.parseInt();

  // Limpiar el buffer del puerto serie
  while (Serial.available() > 0) {
    Serial.read();
  }

  // Limitar el nuevo ángulo dentro del rango de 0 a 180 grados
  nuevoAngulo = constrain(nuevoAngulo, 0, 181);
  Serial.println(nuevoAngulo);

  // Verificar si el nuevo ángulo está dentro del rango válido
  if (nuevoAngulo >= 0 && nuevoAngulo <= 180) {
    // Mover el servomotor solo si el nuevo ángulo es diferente al ángulo actual
    if (nuevoAngulo != anguloActual) {
      // Mover el servomotor al nuevo ángulo especificado
      servoMotor.write(nuevoAngulo);
      
      // Actualizar el ángulo actual
      anguloActual = nuevoAngulo;
    }
  } else {
    Serial.println("Ingresa un valor correcto de 0 a 180");
  }
  
  // Puedes ajustar este valor según la velocidad de respuesta de tu servomotor
  delay(1000);
}