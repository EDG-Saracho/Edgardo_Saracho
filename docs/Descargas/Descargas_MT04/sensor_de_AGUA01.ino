int sensorAgua = A0; // Pin del sensor de agua
int motor = 3;      // Pin del transistor que controla el motor

void setup() {
  Serial.begin(9600); // Inicializa el monitor serie a 9600 bps
  pinMode(motor, OUTPUT); // Configura el pin del motor como salida
}

void loop() {
  int sensorValue = analogRead(sensorAgua); // Lee el valor del sensor de agua

  Serial.println(sensorValue); // Muestra el valor en el monitor serie

  if (sensorValue > 500) { // Umbral para detectar agua (ajusta según sea necesario)
    digitalWrite(motor, HIGH); // Enciende el motor
  } else {
    digitalWrite(motor, LOW); // Apaga el motor
  }

  delay(100); // Pequeño retraso para estabilidad
}
