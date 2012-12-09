void foil_setup() {
  setup_fencer(f1_p0, f1_p1, f1_p2, true, false, true);
  setup_fencer(f2_p0, f2_p1, f2_p2, true, false, true);
}

void foil_wait() {
  
  hit_f1 = readFencer(1, f1, f1_p0, f2_p2);
  hit_f2 = readFencer(2, f2, f2_p0, f1_p2);
  
  if (hit_f1 || hit_h2) {
    if (hit_f1) {
      lightsOn(f1, green, off_green);
    }
    if (hit_f2) {
      lightsOn(f2, red, off_red);
    }
    workflow = 1;
    lockTime = 200;
  }
  
  delay(100);
}

void foil_lock() {

  int f1_now[] = {0, 0};
  int f2_now[] = {0, 0};
  
  boolean hit_f1_now = readFencer(1, f1_now, f1_p0, f2_p0);
  boolean hit_h2_now = readFencer(2, f2_now, f2_p0, f2_p1);
  
  if (hit_f1_now && hit_f2 || hit_f2_now && hit_f1) {
     if (hit_f1_now && hit_f2) {
       f1 = f1_now;
       lightsOn(f1, green, off_green);
     }
     if (hit_f2_now && hit_f1) {
       f2 = f2_now;
       lightsOn(f2, red, off_red);
     }
     
     workflow = 2;
     showTime = 4000;
  }
}

boolean readFencer(int id, int fencer[], int weapon, int bodywire) {
  int weapon_signal = digitalRead(weapon);
  int bodywire_signal = digitalRead(bodywire);
  
  Serial.println("ReadFencer: id: " + String(id) + " weapon:" + String(weapon_signal) + " bodywire:" + String(bodywire_signal));
  
  if (weapon_signal == 0) {
    if (bodywire_signal == 1) {
      fencer[0] = 1;
    } else {
      fencer[1] = 1;
    }
  }
  
  return fencer[0] == 1 || fencer[1] == 1;
}
