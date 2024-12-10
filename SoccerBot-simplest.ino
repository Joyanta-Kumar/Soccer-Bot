// Change the pins according to your bot.
int leftMotorPins[2] = { 2, 3 };
int rightMotorPins[2] = { 4, 5 };


void setPinMode() {
    pinMode(leftMotorPins[0], OUTPUT);
    pinMode(leftMotorPins[1], OUTPUT);
    pinMode(rightMotorPins[0], OUTPUT);
    pinMode(rightMotorPins[1], OUTPUT);
    Serial.println("Pin mode set.");
}

void forward() {
    // Left forward.
    digitalWrite(leftMotorPins[0], 0);
    digitalWrite(leftMotorPins[1], 1);
    // Right forward.
    digitalWrite(rightMotorPins[0], 0);
    digitalWrite(rightMotorPins[1], 1);
    Serial.println("Forward.");
}

void forwardLeft() {
    // Left stop.
    digitalWrite(leftMotorPins[0], 0);
    digitalWrite(leftMotorPins[1], 0);
    // Right forward.
    digitalWrite(rightMotorPins[0], 0);
    digitalWrite(rightMotorPins[1], 1);
    Serial.println("Forward Left.");
}

void forwardRight() {
    // Left forward.
    digitalWrite(leftMotorPins[0], 0);
    digitalWrite(leftMotorPins[1], 1);
    // Right stop.
    digitalWrite(rightMotorPins[0], 0);
    digitalWrite(rightMotorPins[1], 0);
    Serial.println("Forward Right.");
}

void backward() {
    // Left backward.
    digitalWrite(leftMotorPins[0], 1);
    digitalWrite(leftMotorPins[1], 0);
    // Right backward.
    digitalWrite(rightMotorPins[0], 1);
    digitalWrite(rightMotorPins[1], 0);
    Serial.println("Backward.");
}

void backwardLeft() {
    // Left stop.
    digitalWrite(leftMotorPins[0], 0);
    digitalWrite(leftMotorPins[1], 0);
    // Right backward.
    digitalWrite(rightMotorPins[0], 1);
    digitalWrite(rightMotorPins[1], 0);
    Serial.println("Backward Left.");
}

void backwardRight() {
    // Left backward.
    digitalWrite(leftMotorPins[0], 1);
    digitalWrite(leftMotorPins[1], 0);
    // Right stop.
    digitalWrite(rightMotorPins[0], 0);
    digitalWrite(rightMotorPins[1], 0);
    Serial.println("Backward Right.");
}

void spinLeft() {
    // Left backward.
    digitalWrite(leftMotorPins[0], 1);
    digitalWrite(leftMotorPins[1], 0);
    // Right forward.
    digitalWrite(rightMotorPins[0], 0);
    digitalWrite(rightMotorPins[1], 1);
    Serial.println("Spin Left.");
}

void spinRight() {
    // Left forward.
    digitalWrite(leftMotorPins[0], 0);
    digitalWrite(leftMotorPins[1], 1);
    // Right backward.
    digitalWrite(rightMotorPins[0], 1);
    digitalWrite(rightMotorPins[1], 0);
    Serial.println("Spin Right.");
}

void stop() {
    // Left stop.
    digitalWrite(leftMotorPins[0], 0);
    digitalWrite(leftMotorPins[1], 0);
    // Right stop.
    digitalWrite(rightMotorPins[0], 0);
    digitalWrite(rightMotorPins[1], 0);
    Serial.println("Stop.");
}


void setup() {
    setPinMode();
    Serial.begin(9600);
}

void loop() {
    while (Serial.available) {
        char command = Serial.read();
        switch (command)
        {
        case 'w': forward(); break;
        case 's': backward(); break;
        case 'a': spinLeft(); break;
        case 'd': spinRight(); break;
        case 'q': forwardLeft(); break;
        case 'e': forwardRight(); break;
        case 'z': backwardLeft(); break;
        case 'c': backwardRight(); break;
        default: stop();
        }
    }
    delay(100);
}