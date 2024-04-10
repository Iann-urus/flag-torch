
int mq_135_pin = A0;
int mq_5_pin = A1 ;
float reading_mq_135 = 0 ;
float reading_mq_5 = 0 ;
void setup() {
  // put your setup code here, to run once:
  pinMode(mq_135_pin, INPUT);
  pinMode(mq_5_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  reading_mq_135 = analogRead(mq_135_pin);
  reading_mq_5 = analogRead(mq_5_pin);  
  Serial.print("MQ-135 : ");
  Serial.println(reading_mq_135);
  Serial.print("MQ-5 : ");
  Serial.println(reading_mq_5);
  delay(2000);
}
