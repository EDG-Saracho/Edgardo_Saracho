#include <WiFi.h> // Biblioteca WiFi para ESP32
#include <WebServer.h> // Biblioteca del servidor web para ESP32

// Configura tus credenciales WiFi
const char* ssid = "";
const char* password = "";

// Pin donde está conectado el LED
const int ledPin = 2; // Cambia si es necesario

// Crea un servidor en el puerto 80
WebServer server(80);

// Variable para controlar el estado del LED
bool ledState = false;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  
  // Conexión a la red WiFi
  WiFi.begin(ssid, password);
  Serial.println("Conectando a la red WiFi...");

  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 10) {
    delay(2000);
    Serial.println("Conectando...");
    attempts++;
  }

  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Error: No se pudo conectar a la red WiFi");
    while (true);
  }

  Serial.println("Conectado a la red WiFi");
  Serial.print("Dirección IP: ");
  Serial.println(WiFi.localIP());

  // Define la ruta para la página web
  server.on("/", handleRoot);
  server.on("/toggle", handleToggle);
  
  // Inicia el servidor web
  server.begin();
  Serial.println("Servidor web iniciado");
}

void loop() {
  server.handleClient();
}

// Función para servir la página web principal
void handleRoot() {
  String page = "<html><head>";
  page += "<meta name='viewport' content='width=device-width, initial-scale=1.0'>"; // Metaetiqueta para hacer la página responsiva
  page += "<link href='https://fonts.googleapis.com/css2?family=Poppins:wght@400;600&display=swap' rel='stylesheet'>";
  page += "<style>body { font-family: 'Poppins', sans-serif; text-align: center; background-color: #f4f4f4; margin: 0; padding: 0; }";
  page += "h1 { color: #333; font-size: 28px; }"; // Aumenta el tamaño de la fuente del título
  page += ".custom-button { width: 80%; max-width: 300px; height: 70px; border-radius: 35px; opacity: 1; border: none; color: white; font-size: 24px; cursor: pointer; transition: background-color 0.3s ease; }"; 
  page += ".on { background: #D9534F; }"; // Color verde para encendido
  page += ".off { background: #59C999; }"; // Color rojo para apagado
  page += "@media (max-width: 600px) { body { padding: 20px; } .custom-button { font-size: 28px; height: 80px; } h1 { font-size: 32px; } }"; // Estilos para pantallas pequeñas
  page += "</style></head><body>";
  page += "<h1>Control de LED</h1>";
  page += "<p>Estado del LED: " + String(ledState ? "Encendido" : "Apagado") + "</p>";
  page += "<form action=\"/toggle\" method=\"POST\">";
  page += "<button type=\"submit\" class=\"custom-button " + String(ledState ? "on" : "off") + "\">" + String(ledState ? "Apagar LED" : "Encender LED") + "</button>";
  page += "</form></body></html>";

  server.send(200, "text/html", page);
}

// Función para cambiar el estado del LED
void handleToggle() {
  ledState = !ledState; // Cambia el estado del LED
  digitalWrite(ledPin, ledState ? HIGH : LOW); // Enciende o apaga el LED
  server.sendHeader("Location", "/"); // Redirige a la página principal
  server.send(303); // Redirige al cliente con código HTTP 303
}
