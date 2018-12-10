// sensor keys
int key1 = 11;
int key2 = A2;
int key3 = A3;
int key4 = A4;

int speaker = 5;                 // name of the speaker key
int sensorValue;                  // will store sensor readings

//musical notes
int G = 1598;
int A = 1760;
int B = 1976;
int C1 = 2093;
int D1 = 2349;

void setup() {
    // set all keys to be inputs
    pinMode(key1, INPUT);
    pinMode(key2, INPUT);
    pinMode(key3, INPUT);
    pinMode(key4, INPUT);
    pinMode(speaker, OUTPUT);   // set speaker to be an output
    Serial.begin(9600);         // initialize the communication
}

void loop() {
    checkPianoKey(key1, A);
    checkPianoKey(key2, B);
    checkPianoKey(key3, C1);
    checkPianoKey(key4, D1);
    delay(100);
}

void checkPianoKey (int key, int note)
{
    sensorValue = analogRead(key); // read the touch sensor value
    Serial.println(sensorValue);          // send touchValue to computer
    
    if (sensorValue == 0)                  // if the key is pressed
    {
        tone(speaker, note, 1000);             // play a note
       
        
       delay(1500);
        
        
    }
   
    else                                 // if the key is not pressed
    {
        noTone(speaker);                 // stop playing the note
    }
}
