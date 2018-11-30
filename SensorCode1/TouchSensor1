int led = 11;
int speaker = A5;
int aluminumFoil = A2;
int sensorValue;

void setup() {
    pinMode(led, OUTPUT);
    pinMode(speaker, OUTPUT);
    pinMode(aluminumFoil, INPUT);
    digitalWrite(aluminumFoil, HIGH);
    Serial.begin(9600);               // initialize serial port
}

void loop() {
    // blinkPattern();
    // song(2000);
    // delay(5000);
    sensorValue = analogRead(aluminumFoil);
    Serial.println(sensorValue);      // send sensorValue to computer
    delay(100);                       // delay 1/10 of a second
    if (sensorValue<=800)
    {
        digitalWrite(led, HIGH);
    }
    else
    {
        digitalWrite(led, LOW);
    }
}
