#include <WiFi.h>
#include <WebServer.h>

// Configura tus credenciales WiFi
const char* ssid = "";
const char* password = "";


// Pines
int sensorPin = 34; // Pin ADC compatible para el sensor de nivel de agua (GPIO34)
int ledPin = 2;     // Pin para el LED

// Valor del sensor
int sensorValue = 0;

// Crea un servidor web en el puerto 80
WebServer server(80);

// Configuración inicial
void setup() {
  Serial.begin(115200);

  // Configura los pines
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // Conexión WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a WiFi...");
  }
  Serial.println("Conectado a WiFi");

  // Inicia el servidor web
  server.on("/", handleRoot);
  server.on("/data", handleData);  // Ruta para enviar datos del sensor
  server.begin();
  Serial.println("Servidor web iniciado");
}

// Bucle principal
void loop() {
  // Lee el valor del sensor de agua
  sensorValue = analogRead(sensorPin);

  // Enciende el LED si el nivel de agua es mayor que 0
  if (sensorValue > 0) {
    digitalWrite(ledPin, HIGH);  // Enciende el LED
  } else {
    digitalWrite(ledPin, LOW);   // Apaga el LED
  }

  // Muestra el valor en el monitor serie
  Serial.print("Valor del sensor de nivel de agua: ");
  Serial.println(sensorValue);

  // Maneja las solicitudes del servidor web
  server.handleClient();

  delay(500);
}

// Función para manejar la página principal
void handleRoot() {
  String page = "<html><head>";
  page += "<meta name='viewport' content='width=device-width, initial-scale=1.0'>";
  page += "<link href='https://fonts.googleapis.com/css2?family=Poppins:wght@400;600&display=swap' rel='stylesheet'>";
  page += "<style>body { font-family: 'Poppins', sans-serif; text-align: center; background-color: #f4f4f4; margin: 0; padding: 0; }";
  page += "h1 { color: #333; font-size: 28px; }";
  page += ".valor { font-size: 24px; color: #666; margin-top: 20px; }";
  page += ".estado { font-size: 24px; color: #666; margin-top: 20px; }";
  page += "</style>";
  
  // Añadimos JavaScript para actualización automática
  page += "<script>";
  page += "function updateData() {";
  page += "fetch('/data')";  // Llama a la ruta /data para obtener el valor del sensor
  page += ".then(response => response.json())";
  page += ".then(data => {";
  page += "document.getElementById('valorSensor').innerText = data.sensorValue;";
  page += "document.getElementById('estadoLed').innerText = data.ledState ? 'Encendido' : 'Apagado';";
  page += "});";
  page += "}";
  page += "setInterval(updateData, 1000);";  // Actualiza cada segundo
  page += "</script>";

  page += "</head><body>";
  page += "<h1>Lectura del Nivel de Agua</h1>";
  page += "<p class='valor'>Valor del sensor: <span id='valorSensor'>0</span></p>";
  page += "<p class='estado'>Estado del LED: <span id='estadoLed'>Apagado</span></p>";
  page += "</body></html>";

  server.send(200, "text/html", page);
}

// Función para manejar los datos del sensor y el LED en formato JSON
void handleData() {
  String json = "{";
  json += "\"sensorValue\":" + String(sensorValue) + ",";
  json += "\"ledState\":" + String(digitalRead(ledPin));
  json += "}";
  server.send(200, "application/json", json);  // Envía los datos como JSON
}
