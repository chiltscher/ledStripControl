// to the pins used:
const int red = 10;
const int green = 9;
const int blue = 11;

void setup() {
    Serial.begin(9600);
    pinMode(red, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(blue, OUTPUT);
}

void setColor(int r, int g, int b) {
  analogWrite(red, r);
  analogWrite(green, g);
  analogWrite(blue, b);
}

void turnOn(int color) {
    for (int brightness = 0; brightness < 255; brightness++) {
      analogWrite(color, brightness);
      delay(10);
    }
}

void turnOff(int color) {
    for (int brightness = 255; brightness >= 0; brightness--) {
      analogWrite(color, brightness);
      delay(10);
    }
}

void toggle(int color) {
  turnOn(color);
  delay(500);
  turnOff(color);
  delay(100);
}

void strobe(int r, int g, int b, int speed) {
  analogWrite(red, r);
  analogWrite(green, g);
  analogWrite(blue, b);
  delay(speed);
  analogWrite(red, 0);
  analogWrite(green, 0);
  analogWrite(blue, 0);
  delay(speed);
}


void mode1() {
  turnOn(red);
  turnOn(green);
  turnOn(blue);
  delay(1000);
  turnOff(red);
  turnOff(green);
  turnOn(red);
  turnOff(blue);

}

void mode2() {
  turnOn(blue);
  turnOff(red);
  turnOn(green);
  turnOff(blue);
  turnOn(red);
  turnOn(blue);
  turnOff(green);
  turnOff(blue);
}

void mode3() {
 turnOn(red);
 strobe(255, 255, 255, 200);
 strobe(255, 255, 255, 200);
 delay(100);
 turnOn(green);
 strobe(255, 255, 255, 200);
 strobe(255, 255, 255, 200);
 delay(100);
 turnOn(blue);
 strobe(255, 255, 255, 200);
 strobe(255, 255, 255, 200);
 delay(100);
}

void sos() {
  strobe(255, 255, 255, 200);
  strobe(255, 255, 255, 200);
  strobe(255, 255, 255, 200);
  strobe(255, 255, 255, 500);
  strobe(255, 255, 255, 500);
  strobe(255, 255, 255, 500);
  strobe(255, 255, 255, 200);
  strobe(255, 255, 255, 200);
  strobe(255, 255, 255, 200);
  delay(1000);
}

void loop() {
  mode3();

}
