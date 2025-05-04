#include <LiquidCrystal_I2C.h>

// Configuración del LCD: dirección I2C y dimensiones (20 columnas, 4 filas)
LiquidCrystal_I2C lcd(0x27, 20, 4);

const int relayPin = 8; // Pin para el relé

int simulatedMotion = 0; // Variable para el movimiento simulado
int simulatedTemperature = 25; // Variable para la temperatura simulada
unsigned long previousMillis = 0; // Para manejar el cambio de datos simulados
const long interval = 2000; // Intervalo de 2 segundos para cambiar los datos simulados

void setup() {
  Serial.begin(9600);        // Inicializar la comunicación serial a 9600 baudios
  lcd.begin(20, 4);          // Inicializa el LCD con 20 columnas y 4 filas
  lcd.backlight();           // Activa la retroiluminación del LCD

  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Inicialmente apagado

  lcd.setCursor(0, 0);
  lcd.print("Esperando datos");
}

void loop() {
  // Verificar si hay datos disponibles en el puerto serial
  if (Serial.available()) {
    String data = Serial.readStringUntil('\n'); // Leer datos hasta un salto de línea
    int commaIndex = data.indexOf(',');        // Encontrar el índice de la coma
    int motion = data.substring(0, commaIndex).toInt();  // Extraer movimiento
    int temperature = data.substring(commaIndex + 1).toInt(); // Extraer temperatura

    // Actualizar el LCD con los valores recibidos
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Mov: ");
    lcd.print(motion == 1 ? "Detectado" : "No detectado");

    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(temperature);
    lcd.print(" C");

    // Control del relé basado en temperatura
    if (temperature > 30) {
      digitalWrite(relayPin, HIGH); // Activa el relé
      lcd.setCursor(0, 2);
      lcd.print("Ventilador ON");
    } else {
      digitalWrite(relayPin, LOW);  // Desactiva el relé
      lcd.setCursor(0, 2);
      lcd.print("Ventilador OFF");
    }
  } else {
    // Si no hay datos seriales, mostrar datos simulados que cambian
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;

      // Cambiar los datos simulados cada 2 segundos
      simulatedMotion = (simulatedMotion == 0) ? 1 : 0; // Alterna entre 0 y 1
      simulatedTemperature = random(20, 35); // Genera una temperatura aleatoria entre 20 y 35

      // Actualizar el LCD con los valores simulados
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Mov: ");
      lcd.print(simulatedMotion == 1 ? "Detectado" : "No detectado");

      lcd.setCursor(0, 1);
      lcd.print("Temp: ");
      lcd.print(simulatedTemperature);
      lcd.print(" C");

      // Control del relé basado en temperatura simulada
      if (simulatedTemperature > 30) {
        digitalWrite(relayPin, HIGH); // Activa el relé
        lcd.setCursor(0, 2);
        lcd.print("Ventilador ON");
      } else {
        digitalWrite(relayPin, LOW);  // Desactiva el relé
        lcd.setCursor(0, 2);
        lcd.print("Ventilador OFF");
      }
    }
  }
}
