// Change the pins according to your bot.
int leftMotorPins[2] = { 2, 3 };    // At least one of the pin must support PWM.
int rightMotorPins[2] = { 4, 5 };   // At least one of the pin must support PWM.
// The function of movements are defined in a way that motorPins[1] supports PWM.

int speed = 255;


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
    analogWrite(leftMotorPins[1], speed);
    // Right forward.
    digitalWrite(rightMotorPins[0], 0);
    analogWrite(rightMotorPins[1], speed);
    Serial.println("Forward.");
}

void forwardLeft() {
    // Left stop.
    digitalWrite(leftMotorPins[0], 0);
    digitalWrite(leftMotorPins[1], 0);
    // Right forward.
    digitalWrite(rightMotorPins[0], 0);
    analogWrite(rightMotorPins[1], speed);
    Serial.println("Forward Left.");
}

void forwardRight() {
    // Left forward.
    digitalWrite(leftMotorPins[0], 0);
    analogWrite(leftMotorPins[1], speed);
    // Right stop.
    digitalWrite(rightMotorPins[0], 0);
    digitalWrite(rightMotorPins[1], 0);
    Serial.println("Forward Right.");
}

void backward() {
    // Left backward.
    digitalWrite(leftMotorPins[0], 1);
    analogWrite(leftMotorPins[1], (255 - speed));
    // Right backward.
    digitalWrite(rightMotorPins[0], 1);
    analogWrite(rightMotorPins[1], (255 - speed));
    Serial.println("Backward.");
}

void backwardLeft() {
    // Left stop.
    digitalWrite(leftMotorPins[0], 0);
    digitalWrite(leftMotorPins[1], 0);
    // Right backward.
    digitalWrite(rightMotorPins[0], 1);
    analogWrite(rightMotorPins[1], (255 - speed));
    Serial.println("Backward Left.");
}

void backwardRight() {
    // Left backward.
    digitalWrite(leftMotorPins[0], 1);
    analogWrite(leftMotorPins[1], (255 - speed));
    // Right stop.
    digitalWrite(rightMotorPins[0], 0);
    digitalWrite(rightMotorPins[1], 0);
    Serial.println("Backward Right.");
}

void spinLeft() {
    // Left backward.
    digitalWrite(leftMotorPins[0], 1);
    analogWrite(leftMotorPins[1], (255 - speed));
    // Right forward.
    digitalWrite(rightMotorPins[0], 0);
    analogWrite(rightMotorPins[1], speed);
    Serial.println("Spin Left.");
}

void spinRight() {
    // Left forward.
    digitalWrite(leftMotorPins[0], 0);
    analogWrite(leftMotorPins[1], speed);
    // Right backward.
    digitalWrite(rightMotorPins[0], 1);
    analogWrite(rightMotorPins[1], (255 - speed));
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

        // Change speed
        case 10: speed = 10;
        case 20: speed = 20;
        case 30: speed = 30;
        case 40: speed = 40;
        case 50: speed = 50;
        case 60: speed = 60;
        case 70: speed = 70;
        case 80: speed = 80;
        case 90: speed = 90;

        default: stop();
        }
    }
    delay(100);
}