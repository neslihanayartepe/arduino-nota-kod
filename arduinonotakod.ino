#define NUMREADINGS 25 // Raise number to increase data smoothing
#define buzzer 13
int speakerPin = 11; // Pin connected to the piezo
int length = 15; // Number of notes
char notes[] = "cdefgabC"; // A space represents a rest
int beats[] = { 1, 1, 1, 1, 1, 1, 1, 1};
int tempo = 300;
void playTone(int tone, int duration) {
for (long i = 0; i < duration * 1000L; i += tone * 2) {
digitalWrite(speakerPin, HIGH);
delayMicroseconds(tone);
digitalWrite(speakerPin, LOW);
delayMicroseconds(tone);
}
}
// Set timeHigh value to specific notes
void playNote(char note, int duration) {
char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
for (int i = 0; i < 8; i++) { // Play tone that corresponds
// to note name
if (names[i] == note) {
playTone(tones[i], duration);
}
}
}
int senseLimit = 1023; // Raise number to decrease sensitivity of
// the antenna (up to 1023 max)
int probePin = 5; // Set analog pin 5 as the antenna pin
int val = 0; // Reading from probePin
// Pin connections to LED bar graph with resistors in series
int LED1 = 9;
int LED2 = 8;
int LED3 = 7;
int LED4 = 6;
int LED5 = 5;
int LED6 = 4;
int LED7 = 3;
int LED8 = 2;
int readings[NUMREADINGS]; // Readings from the analog input
int index = 0; // Index of the current reading
int total = 0; // Running total
int average = 0; // Final average of the probe reading
void setup() {
  pinMode(speakerPin, OUTPUT); // Set speakerPin as output

// Play the tune


pinMode(2, OUTPUT); // Set LED bar graph pins as outputs
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);

// Serial.pinMode(9600); // Initiate serial connection with IDE for
// debugging and so on
// for (int i = 0; i < NUMREADINGS; i++)
// readings[i] = 0; // Initialize all readings to 0
//for (int i = 0; i < length; i++) {
//if (notes[i] == ' ') {
//delay(beats[i] * tempo); // Rest
//}
//else {
//playNote(notes[i], beats[i] * tempo);
//}
//delay(tempo / 2); // Pause between notes
//}
}

void loop() {


   val = analogRead(probePin); // Take a reading from probe
if (val >= 1) { // If the reading isn't zero, proceed
val = constrain(val, 1, senseLimit); // If the reading is
// higher than the current
// senseLimit value, update
// senseLimit value with
// higher reading
val = map(val, 1, senseLimit, 1, 1023); // Remap the constrained
// value within a 1 to
// 1023 range
total -= readings[index]; // Subtract the last reading
readings[index] = val; // Read from the sensor
total += readings[index]; // Add the reading to the total
index = (index + 1); // Advance to the next index
if (index >= NUMREADINGS) // If we're at the end of the array
index = 0; // loop around to the beginning
average = total / NUMREADINGS; // Calculate the average reading
if (average > 50) { // If the average reading is higher than 50
digitalWrite(LED1, HIGH); // turn on the first LED
digitalWrite(speakerPin,HIGH);

}
else { // If it's not
digitalWrite(LED1, LOW); // turn off that LED
digitalWrite(speakerPin,LOW);
}
if (average > 150) { // And so on
digitalWrite(LED2, HIGH);
}
else {
digitalWrite(LED2, LOW);
}
if (average > 250) {
digitalWrite(LED3, HIGH);
}
else {
digitalWrite(LED3, LOW);
}
if (average > 350) {
digitalWrite(LED4, HIGH);
}
else {
digitalWrite(LED4, LOW);
}
if (average > 450) {
digitalWrite(LED5, HIGH);
}
else {
digitalWrite(LED5, LOW);
}
if (average > 550) {
digitalWrite(LED6, HIGH);
}
else {
digitalWrite(LED6, LOW);
}
if (average > 650) {
digitalWrite(LED7, HIGH);
}
else {
digitalWrite(LED7, LOW);
}
if (average > 750) {
digitalWrite(LED8, HIGH);
}
else {
digitalWrite(LED8, LOW);

}
Serial.println(val); // Use output to aid in calibrating
}
}
