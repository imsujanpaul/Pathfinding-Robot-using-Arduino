// Motor A connections
const int in1 = 7;
const int in2 = 8;
// Motor B connections
const int in3 = 6;
const int in4 = 5;
//Sensor connections
const int trigPin= 10;
const int echoPin=11;
const int vcc = 9;
const int ground = 12;
int duration, distance;

void setup() {
  // Set all the motor control pins to outputs
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(vcc, OUTPUT);
  digitalWrite(vcc, HIGH);
  pinMode(ground, OUTPUT);
  digitalWrite(ground, LOW);
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Turn off motors - Initial state
  stop();
  distance=readPing();
}
void loop() {
  moveForward();
  distance=readPing();
  if(distance<=20){
  Serial.print("Distance: ");
  Serial.println(distance);
  Serial.println("Robot will change it's direction");
    stop();
    delay(500);
    turnLeft();
    delay(500);
  }else{
    Serial.println("Robot is moving forward");
  }

}
void stop(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void turnLeft(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}
void moveForward(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW); 
  digitalWrite(in4, HIGH);
}

  int readPing(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  return distance;  
  }
