void setup() {
  while(!Serial);
  Serial.begin(9600);
  Serial.println("Welcome to the IntruderBeware setup wizard! Wait a moment as I setup the inputs and outputs...");
  pinMode(27, INPUT);
  pinMode(32, OUTPUT);
  pinMode(15, OUTPUT);
  Serial.println("Done! First, let's setup your PIR. Go behind your PIR, so it can't see you. In five seconds, I'll take 10 snapshots of the PIR pin.");
  delay(5000);
  Serial.println("Taking shapshots...");
  byte onSnaps = 0;
  byte offSnaps = 0;
  for (int i = 0; i < 10; i++) {
    if (digitalRead(27) == HIGH) {
      onSnaps++;
    } else {
      offSnaps++;
    }
    delay(100);
  }
  Serial.println("Okay, now let's have you make a whole bunch of motion. Again, in 5 seconds, I'll take 10 snapshots.");
  delay(5000);
  byte onSnapsMotion = 0;
  byte offSnapsMotion = 0;
  for (int i = 0; i < 10; i++) {
    if (digitalRead(27) == HIGH) {
      onSnapsMotion++;
    } else {
      offSnapsMotion++;
    }
    delay(100);
  }
  Serial.println("Hmm... let me figure out if your PIR is reverse...");
  if (onSnaps > offSnaps && onSnapsMotion < offSnapsMotion) {
    Serial.println("It's reverse!");
  } else if (onSnaps < offSnaps && onSnapsMotion > offSnapsMotion) {
    Serial.println("It's not reverse!");
  } else {
    Serial.println("Hmm... I'm having trouble. Try again by resetting this, and put up a issue on GitHub.");
    while(true);
  }
  Serial.println("Now, let's test the buzzer. In 5 seconds, I'll play a low tone, a medium tone, and then a high tone.");
  delay(5000);
  tone(15, 1500, 500);
  delay(500);
  tone(15, 2000, 500);
  delay(500);
  tone(15, 2500, 500);
  delay(500);
  Serial.println("Did you hear the tones? y/n");
  checkWords:
  while(!Serial.available());
  if (Serial.peek() == 'y') {
    Serial.println("Great!");
  } else if (Serial.peek() == 'n') {
    Serial.println("Hmm... try making a issue on GitHub.");
  } else {
    while (Serial.available()) {Serial.read();}
    Serial.println("Please type y or n.");
    goto checkWords;
  }
  while (Serial.available()) {Serial.read();}
  Serial.println("Cover your ears! In 5 seconds, I'll test the siren.");
  delay(5000);
  // TODO: figure out if you use tone(32, 2000, 1000) or digitalWrite(32, HIGH)
  // put code to test siren here
    Serial.println("Did you hear the tone? y/n");
  checkWordsSiren:
  while(!Serial.available());
  if (Serial.peek() == 'y') {
    Serial.println("Great!");
  } else if (Serial.peek() == 'n') {
    Serial.println("Hmm... try making a issue on GitHub.");
  } else {
    while (Serial.available()) {Serial.read();}
    Serial.println("Please type y or n.");
    goto checkWordsSiren;
  }
  while (Serial.available()) {Serial.read();}
  Serial.println("Let's try 
}

void loop() {
  
}