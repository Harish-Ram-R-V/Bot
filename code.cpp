// OBSTACLE DETECTION BOT

// C++ code
//
const int trigPin = 3;
const int echoPin = 2;

const int motor1F = 6;
const int motor1B = 10;
const int motor2F = 5;
const int motor2B = 11;

const int filterSize = 5;
float distanceReadings[filterSize];
int index = 0;

// setup pins of uv sensor and motors
void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(motor1F, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2F, OUTPUT);
  pinMode(motor2B, OUTPUT);
  // initialise reading array values to zero to begin with
  for (int i = 0; i < filterSize; i++)
  {
    distanceReadings[i] = 0;
  }
}

// function description to make reading and do desired bot movements
void loop() {
  float distance = getDistance();
  distanceReadings[index] = distance;
  index = (index + 1) % filterSize;

  float filteredDistance = getMedianDistance();

  Serial.print("Distance (median): ");
  Serial.println(filteredDistance);

  if (filteredDistance < 20) 
  {
    stopMotors();
    delay(200);
    turnRight();
    delay(500);
  } else 
  {
    moveForward();
  }

  delay(100);
}

// get distance using basic physics formula
float getDistance() 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;
  return distance;
}

// function to find median
float getMedianDistance() 
{
  float sorted[filterSize];
  memcpy(sorted, distanceReadings, sizeof(sorted));
  
  // bubble sort
  for (int i = 0; i < filterSize - 1; i++) {
    for (int j = i + 1; j < filterSize; j++) {
      if (sorted[j] < sorted[i]) {
        float temp = sorted[i];
        sorted[i] = sorted[j];
        sorted[j] = temp;
      }
    }
  }
  
  return sorted[filterSize / 2];
}


// functions for bot movements (to send signals to motors)
void moveForward() 
{
  digitalWrite(motor1F, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2F, HIGH);
  digitalWrite(motor2B, LOW);
}

void stopMotors() 
{
  digitalWrite(motor1F, LOW);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2F, LOW);
  digitalWrite(motor2B, LOW);
}

void turnRight() 
{
  digitalWrite(motor1F, LOW);
  digitalWrite(motor1B, HIGH);
  digitalWrite(motor2F, HIGH);
  digitalWrite(motor2B, LOW);
}

