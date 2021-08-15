// ---------------------------------------------------------------- //
// COVID Proximity Sensor  =  "Back Off Inator"
// Originally by Kennedy Synan
// with some help from daddy
// ---------------------------------------------------------------- //

#define echoPin 9  
#define trigPin 10  
#define ledPin 13 

// defines variables
long duration; // variable for the duration of sound wave travel
long distance; // variable for the distance measurement
long max_dist = 182.88;


void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(ledPin, OUTPUT); // Sets the ledPin as an OUTPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Kennedy's Back Off Inator"); // print some text in Serial Monitor
}

void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  if (distance < max_dist) {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
   }
  
}
