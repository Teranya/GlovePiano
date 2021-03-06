// sensor keys
int key1 = A5;
int key2 = A2;
int key3 = A3;
int key4 = A4;

int speaker = 5;                 // name of the speaker key
int sensorValue;                  // will store sensor readings

//musical notes
int C = 1046;
int D = 1175;
int E = 1319;
int F = 1397;
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
    checkPianoKey(key1, C);
    checkPianoKey(key2, D);
    checkPianoKey(key3, E);
    checkPianoKey(key4, G);
    delay(100);
}

void checkPianoKey (int key, int note)
{
    sensorValue = analogRead(key); // read the touch sensor value
    Serial.println(sensorValue);          // send touchValue to computer
    
    if (sensorValue <= 200)                  // if the key is pressed
    {
        tone(speaker, note, 1000);             // play a note
       
        
       delay(1500);
        
        
    }
   
    else                                 // if the key is not pressed
    {
        noTone(speaker);                 // stop playing the note
    }
}
