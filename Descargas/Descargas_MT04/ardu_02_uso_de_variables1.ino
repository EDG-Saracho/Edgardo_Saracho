// C++ code
//
int Led_rojo=12; // los numeros corresponden a los pin digitales
int Led_azul=11;
int Led_naranja=10;

int tiempo= 800; // tiempo de luz encendida
int tiempo2=100; // tiempo de luz apagada

void setup()
{
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
}

void loop()
{
  digitalWrite(12, HIGH);
  delay(tiempo); // tiempo de luz encendida
  digitalWrite(12, LOW);
  delay(tiempo2); // tiempo de luz apagada
  
  digitalWrite(10, HIGH);
  delay(tiempo); 
  digitalWrite(10, LOW);
  delay(tiempo2); 
  
  digitalWrite(11, HIGH);
  delay(tiempo); 
  digitalWrite(11, LOW);
  delay(tiempo2);

   digitalWrite(11, HIGH);
  delay(tiempo); 
  digitalWrite(11, LOW);
  delay(tiempo);
}