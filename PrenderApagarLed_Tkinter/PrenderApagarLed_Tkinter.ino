void setup() {
  // Inicializar el puerto serie a 9600 baudios
  Serial.begin(9600);
  // Puedes inicializar otros pines aquí si es necesario
  pinMode(13, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char comando = Serial.read(); // Leer el comando enviado desde Python

    // Realizar acciones basadas en el comando recibido
    switch (comando) {
      case 'e':
        // Encender el LED
        digitalWrite(13, HIGH);
        break;
      case 'a':
        // Apagar el LED
        digitalWrite(13, LOW);
        break;
      case 'c':
        // Cerrar cualquier acción o limpiar recursos si es necesario
        break;
      default:
        // No hacer nada o enviar un mensaje de error si el comando no es reconocido
        break;
    }
  }
}
