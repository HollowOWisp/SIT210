const int porchLightPin = 12;
const int hallwayLightPin = 10;
const int switchPin = 5;

const unsigned long porchDuration = 30000;   // 30 sec
const unsigned long hallwayDuration = 60000; // 60 sec

unsigned long porchStartTime = 0;
unsigned long hallwayStartTime = 0;

bool porchOn = false;
bool hallwayOn = false;

void setup() {
  pinMode(porchLightPin, OUTPUT);
  pinMode(hallwayLightPin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);
}
// The setup() function is what sets up the input and output pins. 

void loop() {
//The loop() function keeps checking to see if the switch is pressed and changes the state of the two lights as needed
  if (isSwitchPressed()) {
    turnOnLights();
    delay(200); 
  }

  updatePorchLight();
  updateHallwayLight();
}


bool isSwitchPressed() {
  return digitalRead(switchPin) == LOW;
}
// The isSwitchPressed() function checks to see if the user has pressed the switch.
void turnOnLights() { // 
  digitalWrite(porchLightPin, HIGH);
  digitalWrite(hallwayLightPin, HIGH);

  porchStartTime = millis();
  hallwayStartTime = millis();

  porchOn = true;
  hallwayOn = true;
}
// The turnOnLights() function turns on the two lights and uses the millis() function to keep track of when it starts. 
void updatePorchLight() {
  if (porchOn && millis() - porchStartTime >= porchDuration) {
    digitalWrite(porchLightPin, LOW);
    porchOn = false;
  }
}
// The updatePorchLight() and updateHallwayLight() functions figure out how long the two lights will be on by comparing the current time to the start time.
void updateHallwayLight() {
  if (hallwayOn && millis() - hallwayStartTime >= hallwayDuration) {
    digitalWrite(hallwayLightPin, LOW);
    hallwayOn = false;
  }
}