const int buzzer = 9; 
int sensePin = A0;
int sensorInput;
double temp;
#define pirPin 7
int calibrationTime = 30;
long unsigned int lowIn;
long unsigned int pause = 5000;
boolean lockLow = true;
boolean takeLowTime;
int PIRValue = 0;
void setup(){
Serial.begin(9600); 
pinMode(pirPin, INPUT);
pinMode(buzzer, OUTPUT);
}
void loop(){
sensorInput = analogRead(A0);
temp = (double)sensorInput / 1024;
temp = temp * 5;
temp = temp-0.5 ;
temp = temp * 100; 
if(temp > 60){
tone(buzzer, 1000); 
delay(1000); 
noTone(buzzer);
delay(1000);} 
Serial.print("Current Temperature: ");
Serial.println(temp);
PIRSensor();
}
void PIRSensor() {
if(digitalRead(pirPin) == HIGH) {
Serial.print("Motion Detected");
tone(buzzer, 2000); 
delay(1000); 
noTone(buzzer); 
delay(1000);}
}
