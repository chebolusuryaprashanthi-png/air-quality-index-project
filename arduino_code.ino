#define MQ135_PIN A0
#define BUZZER 9
#define GREEN_LED 6
#define YELLOW_LED 7
#define RED_LED 8

int sensorValue = 0;
int AQI = 0;

void setup() {
  Serial.begin(9600);

  pinMode(BUZZER, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
}

void loop() {
  sensorValue = analogRead(MQ135_PIN);

  // Convert sensor value to AQI range (approximation)
  AQI = map(sensorValue, 0, 1023, 0, 500);

  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print(" | AQI: ");
  Serial.println(AQI);

  // Reset outputs
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(BUZZER, LOW);

  if (AQI < 100) {
    digitalWrite(GREEN_LED, HIGH);
  }
  else if (AQI >= 100 && AQI <= 200) {
    digitalWrite(YELLOW_LED, HIGH);
  }
  else {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(BUZZER, HIGH); // Alert
  }

  delay(2000);
}
