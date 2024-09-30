#include <WiFi.h> // Biblioteca WiFi para ESP32
#include <WebServer.h> // Biblioteca del servidor web para ESP32

// Configura tus credenciales WiFi
const char* ssid = "";
const char* password = "";


// Pines del sensor ultrasonido y del LED
const int pinEco = 23;
const int pinGatillo = 22;
const int pinLed = 2;

// Crea un servidor en el puerto 80
WebServer server(80);

// Variables para la distancia medida y el estado del LED
float DISTANCIA = 0;
bool ledState = false; // Estado del LED (apagado por defecto)

// Función para leer la distancia del sensor ultrasonido
long readUltrasonicDistance(int triggerPin, int echoPin) {
  digitalWrite(triggerPin, LOW); 
  delayMicroseconds(2); // Estabilizar el pin
  digitalWrite(triggerPin, HIGH); // Enviar pulso de 10us al pin de gatillo
  delayMicroseconds(10); 
  digitalWrite(triggerPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000); // Máximo 30 ms de espera
  return duration;
}

void setup() {
  Serial.begin(9600);
  
  // Configura los pines
  pinMode(pinGatillo, OUTPUT);
  pinMode(pinEco, INPUT);
  pinMode(pinLed, OUTPUT);

  // Inicia el servidor web
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a WiFi...");
  }
  
  server.on("/", handleRoot);
  server.begin();
  Serial.println("Servidor web iniciado");
}

void loop() {
  // Llama a la función para medir la duración del eco
  long duration = readUltrasonicDistance(pinGatillo, pinEco);
  
  if (duration > 0) {
    // Convertir duración a distancia en centímetros
    DISTANCIA = duration * 0.0343 / 2;
  } else {
    DISTANCIA = -1; // Indicador de error si no se recibió eco
  }

  // Mostrar en Serial Monitor la duración y la distancia para depurar
  Serial.print("Duración: ");
  Serial.print(duration);
  Serial.print(" microsegundos, Distancia: ");
  Serial.print(DISTANCIA);
  Serial.println(" cm");

  // Encender el LED si la distancia es 0 cm o menor a 2 cm
  if (DISTANCIA >= 0 && DISTANCIA <= 2) {
    ledState = true;
    digitalWrite(pinLed, HIGH);  // Enciende el LED
  } else {
    ledState = false;
    digitalWrite(pinLed, LOW);   // Apaga el LED
  }

  // Manejar solicitudes HTTP
  server.handleClient();
}

// Función para servir la página web principal
void handleRoot() {
  String page = "<html><head>";
  page += "<meta name='viewport' content='width=device-width, initial-scale=1.0'>";
  page += "<link href='https://fonts.googleapis.com/css2?family=Poppins:wght@400;600&display=swap' rel='stylesheet'>";
  page += "<style>body { font-family: 'Poppins', sans-serif; text-align: center; background-color: #f4f4f4; margin: 0; padding: 0; }";
  page += "h1 { color: #333; font-size: 28px; }";
  page += ".distancia { font-size: 24px; color: #666; margin-top: 20px; }";
  page += ".estado { font-size: 24px; color: #666; margin-top: 20px; }";
  page += "</style></head><body>";
  page += "<h1>Medici&oacuten de Distancia</h1>";
  
  if (DISTANCIA >= 0) {
    page += "<p class='distancia'>Distancia actual: " + String(DISTANCIA, 2) + " cm</p>";
  } else {
    page += "<p class='distancia'>Error al medir distancia</p>";
  }
  
  page += "<p class='estado'>Estado del LED: " + String(ledState ? "Encendido" : "Apagado") + "</p>";
  page += "</body></html>";

  server.send(200, "text/html", page);
}
