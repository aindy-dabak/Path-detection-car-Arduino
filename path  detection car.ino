// Declare variables
int enA = 5;
int enB = 6;
int in1 = 7;
int in2 = 8;
int in3 = 9;
int in4 = 10;
int leftSense = 11;
int rightSense = 12;

int leftState;
int rightState;

void setup() {
  // Set pins
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(leftSense, INPUT);
  pinMode(rightSense, INPUT);
  // Do initializations
  Serial.begin(9600);
}

void loop() {
  // Move forward
  forward();
  
  // Read sensor values
  leftState = digitalRead(leftSense);
  rightState = digitalRead(rightSense);
  Serial.print(leftState);
  Serial.print("  ");
  Serial.println(rightState);
  // if path diverts, check divertion direction
  if (leftState == 1 and rightState == 0){
    turnLeft();
  }
  else{
    if (leftState == 0 and rightState == 1){
      turnRight();
  }
  }
    // If direction changes towards left, then turn car left, and If direction changes towards right, then turn car right
}

void forward(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 150);
  analogWrite(enB, 150);
}

void turnLeft(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 150);
  analogWrite(enB, 150);
}

void turnRight(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, 150);
  analogWrite(enB, 150);
}
