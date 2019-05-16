const int ledPin = 13; // The LED is connected to port 13
const int ldrPin = A0; // The LDR is connected to port A0

void setup() {
  // Initializing the Serial monitor, the LED as output and the LDR as an input
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);
}

void loop() {
  int ldrStatus = analogRead(ldrPin); // Getting the light sensitivity from the LDR, as a number between 0-1023
  int ldrStatusPercantage = map(ldrStatus, 0, 1023, 0, 100); // converting the sensitivity into a percentage 
  
  if (ldrStatusPercantage <= 50) { // Lower or equal to 50 means it's dark
    digitalWrite(ledPin, HIGH);
    Serial.println("LDR is DARK, LED is ON!");
  }
  else { // Otherwise the LED should be turned off
    digitalWrite(ledPin, LOW);
    Serial.println("LDR is LIGHT, LED is OFF!");
  }
  
  delay(750); // 750ms delay
}
