void epee_setup() {
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

void epee_wait()
{
  /*
  f1 = f1_hit_epee();
  f2 = f2_hit_epee();
  
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
  */
}

void epee_lock()
{
/*  int f1_now = f1_hit_epee();
  int f2_now = f2_hit_epee();
  
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
  */
}

/*
boolean f1_hit_epee() {
  int hits = {0, 0};
  boolean hit = read_hit_epee(hits, f1_p0, f1_p1, f1_p2); 
  return hit[0] == 1;
}

boolean f2_hit_epee() {
  int hits = {0, 0};
  boolean hit = read_hit_epee(
  return f2_hit == 0;
}

int[] read_hit_epee(int parray, int p0, int p1, int p2) {
 int p0_result = digitalRead(p0);
 int p1_result = digitalRead(p1);
 int p2_result
  
}
*/
