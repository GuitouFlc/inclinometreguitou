/* sketch Arduino basé sur le travail de https://github.com/camerontech
 Affichage de l'angle sur lcd
 materiel : -1x Arduino nano
            -1x LCD 16x2 serial
            -1x accelerometre adxl335
lcd --> arduino vcc=5v gnd=gnd sda=a4 scl=a5
adxl335  -->  arduino vcc=3.3v gnd=gnd X=a0 Y=a1 Z=a2 
*/

#include <SoftwareSerial.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 
SoftwareSerial Serial1(3,2);

const bool DEBUG = true;

const int X_PIN = 0;
const int Y_PIN = 1;
const int Z_PIN = 2;

const int MIN = 295;
const int MAX = 496;

const int DEGREE = 223;

void setup() {


  if (DEBUG)
    Serial.begin(9600);
    lcd.begin(16,2);

  Serial1.begin(9600);
  lcd.begin(16,2);

  delay(500);

  clearDisplay();

  Serial1.write("  PITCH   ROLL ");
  lcd.print("  PITCH   ROLL ");
}

void loop() {
  int x = analogRead(X_PIN);
  int y = analogRead(Y_PIN);
  int z = analogRead(Z_PIN);

  int xAng = map(x, MIN, MAX, -90, 90);
  int yAng = map(y, MIN, MAX, -90, 90);
  int zAng = map(z, MIN, MAX, -90, 90);

  int pitch = RAD_TO_DEG * (atan2(-xAng, -zAng) + PI);
  int roll = RAD_TO_DEG * (atan2(-yAng, -zAng) + PI);

  if (pitch > 180) {
    pitch = pitch - 360;
  }
  if (roll > 180) {
    roll = roll - 360;
  }

  updateDisplay(pitch, roll);

  delay(250);
}

void updateDisplay(int pitch, int roll) {
  moveToSecondLine();

  String pitchString = String(pitch);
  String rollString = String(roll);

  String output = "   ";
  if (pitchString.length() == 1) {
    output += " ";
  }
  output += pitchString;

  Serial1.print(output);
  Serial1.write((char)223);
  lcd.print(output);
  lcd.print((char)223);

  int outputLength = output.length() + 1;

  output = "";
  for (int i=outputLength; i<10; i++) {
    output += " ";
  }
  if (rollString.length() == 1) {
    output += " ";
  }
  output += rollString;

  Serial1.print(output);
  Serial1.write(DEGREE);
  lcd.print(output);
  lcd.print((char)223);
  outputLength += output.length() + 1;

  for (int i=outputLength; i<16; i++) {
    Serial1.print(" ");
    lcd.print(" ");
  }

  if (DEBUG){
    Serial.print("pitch: ");
    Serial.print(pitchString);
    Serial.print(" roll: ");
    Serial.print(rollString);
    Serial.println("");
    
    lcd.print("pitch: ");
    lcd.print(pitchString);
    lcd.print("roll: ");
    lcd.print(rollString);
    lcd.print("");
    }
}

void clearDisplay() {
  moveToFirstLine();
  Serial1.write("                ");
  Serial1.write("                ");
  moveToFirstLine();
  lcd.print("                ");
  lcd.print("                ");
  
}

void moveToFirstLine() {
  Serial1.write(254);
  Serial1.write(128);
  lcd.setCursor(7,1);
}

void moveToSecondLine() {
  Serial1.write(254);
  Serial1.write(192);
  lcd.setCursor(1,1);
}
