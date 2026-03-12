// Project 05: Battery Voltage Meter

// Resistor values for the voltage divider
float R1 = 10000.0; // 10k Ohm
float R2 = 10000.0; // 10k Ohm

void setup() {
  // Initialize serial communication to display readings
  Serial.begin(9600);
}

void loop() {
  // Read the analog value from pin A0 (0-1023)
  int sensorValue = analogRead(A0);

  // Convert the analog reading to a voltage (0-5V)
  float voltage_in = (sensorValue * 5.0) / 1023.0;

  // Calculate the original battery voltage using the divider formula
  float battery_voltage = voltage_in * (R1 + R2) / R2;

  // Print the voltage to the Serial Monitor
  Serial.print("Battery Voltage: ");
  Serial.println(battery_voltage);

  delay(1000); // Wait a second before the next reading
}
