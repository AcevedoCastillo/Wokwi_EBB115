const int pirPin = 3;       // Pin del sensor PIR
const int lm35Pin = A0;     // Pin del sensor LM35

void setup() {
  Serial.begin(9600);       // Inicializar la comunicación serial a 9600 baudios
  pinMode(pirPin, INPUT);   // Configurar el PIR como entrada
}

void loop() {
  int motion = digitalRead(pirPin);        // Leer movimiento (1 = detectado, 0 = no detectado)
  int tempValue = analogRead(lm35Pin);     // Leer valor analógico del LM35
  float temperature = tempValue * 0.48828125; // Convertir a grados Celsius

  // Enviar datos al Arduino 2 a través del puerto serial
  Serial.print(motion);          // Enviar movimiento
  Serial.print(",");             // Separador
  Serial.println((int)temperature); // Enviar temperatura como entero

  delay(1000); // Esperar 1 segundo antes de enviar nuevamente
}
