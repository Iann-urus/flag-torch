#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

//create the object
#define OLED_RESET -1
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int mq_5_pin = A1;
int mq_135_pin = A0 ;
int r_led = 5;
int g_led = 6;
int b_led = 7;
int reading_mq_135 = 0 ;
int reading_mq_5 = 0 ;
int text_size = 1;

void setup() {
  pinMode(mq_135_pin, INPUT);
  pinMode(mq_5_pin, INPUT);

  pinMode(r_led, OUTPUT);
  pinMode(g_led, OUTPUT);
  pinMode(b_led, OUTPUT);
  digitalWrite(r_led, 0);
  digitalWrite(g_led, 0);
  digitalWrite(b_led, 0);
  
  Serial.begin(9600);
  //init the OLED Display
  //init the display
  display.begin(0x3C, true);
  display.clearDisplay();
  display.setTextSize(text_size);
  display.setTextColor(SH110X_WHITE);
  

   //display.clearDisplay();
   //display.drawBitmap(0,10,myBitmapstatic,32,47,SH110X_WHITE);
   display.setCursor(0,10);
   display.println("Stem Maker Fair");
   display.setCursor(0,20);
   display.println("& American Spaces");
   display.setCursor(0,40);
   display.println("Embedded Systems");
   display.display();
   delay(2500);
   text_size = 2;
   display.setTextSize(text_size);
   display.clearDisplay();
   display.setCursor(0,30);
   display.println("Team Atlas");
   display.display();
   delay(2500);
   display.clearDisplay();
   display.setCursor(0,20);
   display.println("Warming up..../");
   display.display();
   delay(2500);
   display.clearDisplay();
 
}

void loop() {
  text_size = 2;
  display.setTextSize(text_size);
  reading_mq_135 = analogRead(mq_135_pin);
  reading_mq_5 = analogRead(mq_5_pin);  
  Serial.print("MQ-135 : ");
  Serial.println(reading_mq_135);
  Serial.print("MQ-5 : ");
  Serial.println(reading_mq_5);
  display.setCursor(0,5);
  display.print("MQ-135:");
  display.println(reading_mq_135);
  display.setCursor(0,30);
  display.print("MQ-5:");
  display.println(reading_mq_5);
  display.display();
  
  if(reading_mq_135 > 220){
    text_size = 1;
    display.setTextSize(text_size);
    digitalWrite(r_led, 1);
    digitalWrite(g_led, 1);
    digitalWrite(b_led, 1);
    analogWrite(r_led, 252);
    analogWrite(g_led, 107);
    analogWrite(b_led, 3);
    Serial.println("Gas detected");
    Serial.println("Possible gases: Ammonia (NH3), nitrogen oxides (NOx), benzene, smoke or CO2");
    display.clearDisplay();
    display.setCursor(0,20);
    display.println("Gas detected!");
    display.display();
    delay(2000);
    display.clearDisplay();
    display.setCursor(0,10);
    display.println("Possible gases: ");
    display.println("Ammonia (NH3), nitrogen oxides (NOx), benzene, smoke or CO2");
    display.display();
    delay(10000);//Delay for 10 seconds
    display.clearDisplay();
    digitalWrite(r_led, 0);
    digitalWrite(g_led, 0);
    digitalWrite(b_led, 0);
    
  }

  if(reading_mq_5 > 190){
    display.setTextSize(1);
    digitalWrite(r_led, 1);
    digitalWrite(g_led, 1);
    digitalWrite(b_led, 1);
    analogWrite(r_led, 3);
    analogWrite(g_led, 252);
    analogWrite(b_led, 215);
    Serial.println("Gas detected");
    Serial.println("Possible gases: LPG, Natural Gas, Coal Gas");
    display.clearDisplay();
    display.setCursor(0,20);
    display.println("Gas detected!");
    display.display();
    delay(2000);
    display.clearDisplay();
    display.println("Possible gases:");
    display.println("LPG, Natural Gas, Coal Gas");
    display.display();
    delay(10000);//Delay for 10 seconds
    display.clearDisplay();
    digitalWrite(r_led, 0);
    digitalWrite(g_led, 0);
    digitalWrite(b_led, 0);
    
  }
  

  delay(1200);
  display.clearDisplay();
  

}
