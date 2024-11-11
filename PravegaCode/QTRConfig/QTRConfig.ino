#include <QTRSensors.h>

// Define pins for the QTR-8RC sensor
QTRSensorsRC qtrrc((unsigned char[]) {16, 17, 18, 19, 20, 21, 22, 23}, 8); // Adjust pins as needed
unsigned int sensorValues[8];

QTRSensors qtrrc;
void setup() {
  Serial.begin(9600);
  qtrrc.setTypeAnalog();
  qtrrc.setSensorPins((const uint16_t[]){26, 27, 14, 12, 13},8);
  // Optional: Set timeout to ensure readings complete within a specific time
  qtrrc.setTimeout(2500);
  delay(500); // Wait for sensor initialization
}

void loop() {
  // Read the values from the QTR-8RC sensor
  qtrrc.read(sensorValues);

  // Print each sensor reading
  for (int i = 0; i < 8; i++) {
    Serial.print(sensorValues[i]);
    Serial.print("\t");
  }
  delay(10);
}
