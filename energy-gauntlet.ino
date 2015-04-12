int flexSensorPin_0 = A0; //analog pin for flex sensor

int flexSensorPin_1 = A4; //analog pin for flex sensor

int hand = 0;

int x_pin = A2; 
int y_pin = A3; 
int z_pin = A6; 
int accelSrc = 3;

int x;
int y;

int buttonPin = 1; // digital pin for btn
int buttonSrc = 2;
int buttonState = 0;

int flexSensorReading_0;
int flexSensorReading_1;
//int flex0to100;

void setup(){
  Serial.begin(9600);
  pinMode(buttonPin, INPUT); 
  pinMode(buttonSrc, OUTPUT); 
  pinMode(accelSrc, OUTPUT); 
  
  Spark.variable("flex_0", &flexSensorReading_0, INT);
  Spark.variable("flex_1", &flexSensorReading_1, INT);
  
  //Spark.variable("hand", &hand, INT);
  
  Spark.variable("button_0", &buttonState, INT);
  Spark.variable("x", &x, INT);
  Spark.variable("y", &y, INT);
}

void loop(){
  digitalWrite(buttonSrc, HIGH);
  digitalWrite(accelSrc, HIGH);
  
  flexSensorReading_0 = analogRead(flexSensorPin_0); 
  flexSensorReading_1 = analogRead(flexSensorPin_1); 
  
  x = analogRead(x_pin); 
  y = analogRead(y_pin); 

  
  buttonState = digitalRead(buttonPin);

  //flex0to100 = 100 - map(flexSensorReading, 150, 380, 0, 100);
  //Serial.print(flex0to100);
  //Serial.print(" ");
  //Serial.println(buttonState);

  delay(1); //just here to slow down the output for easier reading
}