// sensor keys
int key1 = 6;
int key2 = 9;
int key3 = 10;
int key4 = 11;
int key5 = A2;
int key6 = A3;
int key7 = A4;
int speaker = 5;                 // name of the speaker key
int touchValue;                  // will store sensor readings

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
    pinMode(key5, INPUT);
    pinMode(key6, INPUT);
    pinMode(key7, INPUT);
    pinMode(speaker, OUTPUT);   // set speaker to be an output
    Serial.begin(9600);         // initialize the communication
}

void loop() {
    checkPianoKey(key1, C);
    checkPianoKey(key2, D);
    checkPianoKey(key3, E);
    checkPianoKey(key4, G);
    checkPianoKey(key5, A);
    checkPianoKey(key6, C1);
    checkPianoKey(key7, D1);
    delay(100);
}

void checkPianoKey (int key, int note)
{
    touchValue = readCapacitivePin(key); // read the touch sensor value
    Serial.println(touchValue);          // send touchValue to computer
    if (touchValue > 1)                  // if the key is pressed
    {
        tone(speaker, note);             // play a note
        delay(100);                      // wait for 1/10th of a second
    }
    else                                 // if the key is not pressed
    {
        noTone(speaker);                 // stop playing the note
    }
}
