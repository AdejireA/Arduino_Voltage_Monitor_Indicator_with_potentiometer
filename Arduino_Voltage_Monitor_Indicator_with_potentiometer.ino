int mypin = A0;
int readvalue;
float v2;
int delaytime = 500;
int greensignalpin = 7;
int redsignalpin = 8;
int signaldelaytime = 300;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(greensignalpin, OUTPUT);
pinMode(redsignalpin, OUTPUT);
pinMode(mypin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
readvalue = analogRead(mypin);
v2 = (5./1023.)*readvalue;   // Convert analog value to voltage (0-5V range)

Serial.print("Potentiometer voltage is = ");
Serial.println(v2);    // Print the calculated voltage value
if (v2 >= 4.0){
  Serial.println("it is extremely high");
  digitalWrite(redsignalpin, HIGH);
  delay(signaldelaytime);
  digitalWrite(redsignalpin, LOW);
  delay(signaldelaytime);
}
else if (v2 < 4.0 && v2 >= 2.5){
  Serial.println("it is moderate");
  digitalWrite(greensignalpin, HIGH);
  delay(signaldelaytime);
  digitalWrite(greensignalpin, LOW);
     
}
else{
  Serial.println("it is low");
  digitalWrite(greensignalpin, HIGH);
  digitalWrite(redsignalpin, HIGH);
     
}
delay(delaytime);
}
