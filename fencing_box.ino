/*
  fencing box demo.
*/

int red = 9;
int green = 10;

int off_red = 11;
int off_green = 12; 

int power_light = 13;

int lighton = 2000;

int f1_p0 = A5;
int f1_p1 = A4;
int f1_p2 = A3;

int f2_p0 = A2;
int f2_p1 = A1;
int f2_p2 = A0;

int workflow = 0;
boolean hit_f1 = false;
boolean hit_f2 = false;
int f1[2] = {1, 1};
int f2[2] = {1, 1};

int lockTime = 0;
int showTime = 0;

int weapon = 1; // 0 = epee, 1 = foil, 2 = sabre

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  setupLights();
  test();
  
  pinMode(power_light, OUTPUT);
  digitalWrite(power_light, HIGH);
  
  switch(weapon) {
    case 0:
      epee_setup();
      break;
     case 1:
      foil_setup();
      break;
  }
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
  lightsOn(f1, green, off_green);
  lightsOn(f2, red, off_red);
  delay(lighton);
  resetAll();
}

void setupLights() {
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(off_red, OUTPUT);
  pinMode(off_green, OUTPUT);
}

void wait() {
      switch(weapon) {
      case 0:
        epee_wait();
        break;
      case 1:
        foil_wait();
        break;
    }
}

void lock() {
      switch(weapon) {
      case 0:
        epee_lock();
        break;
      case 1:
        foil_lock();
        break;
    }
}

void show() {
  showTime = showTime - 1;
  
  if (showTime < 0) {
    Serial.println("Workflow show() -> wait()");
    workflow = 0;
    resetAll();
  }
}

void lightsOn(int fencer[], int hit, int off) {
  if (fencer[0] == 1) {
    digitalWrite(hit, HIGH);
  }
  if (fencer[1] == 1) {
    digitalWrite(off, HIGH);
  }
}

void setup_fencer(int p0, int p1, int p2, boolean s0, boolean s1, boolean s2) {
  pinMode(p0, s0 ? INPUT : OUTPUT);
  pinMode(p1, s1 ? INPUT : OUTPUT);
  pinMode(p2, s2 ? INPUT : OUTPUT);
  
  digitalWrite(p0, s0 ? LOW : HIGH);
  digitalWrite(p1, s1 ? LOW : HIGH);
  digitalWrite(p2, s2 ? LOW : HIGH);
}

void resetAll() {
      // Reset Lights.
      digitalWrite(green, LOW);
      digitalWrite(red, LOW);
      digitalWrite(off_red, LOW);
      digitalWrite(off_green, LOW);
      
      // Reset Fencers.
      resetFencer(f1);
      resetFencer(f2);
}

void resetFencer(int fencer[]) {
  fencer[0] = 0;
  fencer[1] = 0;
}
