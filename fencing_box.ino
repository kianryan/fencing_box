/*
  Epee fencing box demo.
*/

int red = 9;
int green = 10;
int lighton = 2000;

int f1_p0 = A5;
int f1_p1 = A4;
int f1_p2 = A3;

int f2_p0 = A2;
int f2_p1 = A1;
int f2_p2 = A0;

int workflow = 0;
boolean f1;
boolean f2;

int lockTime = 0;
int showTime = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  setupLights();
  test();
  
  setupEpee();
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  
  switch (workflow) {
    case 0:
        wait();
        break;
    case 1:
        lock();
        break;
    case 2:
        show();
        break;
  }
  delay(1);
}

void test() {
  digitalWrite(red, HIGH);
  digitalWrite(green, HIGH);
  delay(lighton);
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
}

void setupLights() {
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
}

void setupEpee() {
  pinMode(f1_p0, OUTPUT);
  pinMode(f1_p1, INPUT_PULLUP);
  pinMode(f1_p2, INPUT_PULLUP);
  
  digitalWrite(f1_p0, LOW);
  digitalWrite(f1_p1, HIGH);
  digitalWrite(f1_p2, HIGH);
  
  pinMode(f2_p0, OUTPUT);
  pinMode(f2_p1, INPUT_PULLUP);
  pinMode(f2_p2, INPUT_PULLUP);
}

void wait() {
  f1 = f1_hit();
  f2 = f2_hit();
  
  if (f1 || f2) {
    if (f1) {
      leftOn();
    }
    
    if (f2) {
      rightOn();
    }
    
    lockTime = 50;
    Serial.println("Workflow wait() -> lock()");
    workflow = 1;
  }
}

void lock() {
  int f1_now = f1_hit();
  int f2_now = f2_hit();
  
  if (f1 && !f2 && f2_now) {
    f2 = true;
    rightOn();
    Serial.println("Workflow lock() -> show()");
    workflow = 2;
  }
  if (f2 && !f1 && f1_now) {
    f1 = true;
    leftOn();
    Serial.println("Workflow lock() -> show()");
    workflow = 2;
  }
  
  lockTime = lockTime - 1;
  
  if (lockTime < 0) {
    Serial.println("Workflow lock() -> show()");
    workflow = 2;
  }
  
  showTime = 2000;
}

void show() {
  
  showTime = showTime - 1;
  
  if (showTime < 0) {
    Serial.println("Workflow show() -> wait()");
    workflow = 0;
    resetAll();
  }
}

boolean f1_hit() {
  int f1_hit = digitalRead(f1_p1); 
  return f1_hit == 0;
}

boolean f2_hit() {
  int f2_hit = digitalRead(f2_p1);
  return f2_hit == 0;
}

void leftOn() {
  digitalWrite(green, HIGH);
}

void rightOn() {
  digitalWrite(red, HIGH);
}

void resetAll() {
      // Reset Lights.
      digitalWrite(green, LOW);
      digitalWrite(red, LOW);
      
      // Reset Fencers.
      f1 = false;
      f2 = false;
}
