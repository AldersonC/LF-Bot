#include <QTRSensors.h>
#include <SparkFun_TB6612.h>

// QTR Sensor setup
QTRSensors qtr;
const uint8_t SensorCount = 6;
uint16_t sensorValues[SensorCount];

// Motor Pins
#define AIN1 2  // Motor A input 1
#define AIN2 4  // Motor A input 2
#define BIN1 7  // Motor B input 1
#define BIN2 1  // Motor B input 2
#define PWMA 5  // Motor A PWM
#define PWMB 6  // Motor B PWM
#define STBY 3  // Standby pin

// Motor offsets
const int offsetA = 1;
const int offsetB = 1;

// Initialize motors
Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, STBY);

// PID control parameters
float Kp = 0.1;       // Proportional gain
float Kd = 0;       // Derivative gain
float Ki = 0;      // Integral gain
int baseSpeed = 200 ;  // Base motor speed
int maxSpeed = 250;   // Maximum motor speed
float lastError = 0;
float integral = 0;
int status = 0; 
unsigned long timeAttack = 0;

bool debug = false;
void setup() {
  // Initialize serial communication
  if(debug){
    Serial.begin(9600);
  }

  // Configure QTR sensors
  qtr.setTypeRC();
  qtr.setSensorPins((const uint8_t[]){ 8, 9, 10, 11, 12, 13 }, SensorCount);
  delay(500);

  // Calibrate sensors
  unsigned long startTime = millis();

  for (uint16_t i = 0; i < 400; i++) { //400 ticks is about 10 seconds
    qtr.calibrate();
  }

  unsigned long endTime = millis(); // Record end time
  unsigned long calibrationDuration = endTime - startTime; // Calculate duration

  if(debug){
    Serial.print("Calibration took "); // Calibration took 10642 ms or 10 seconds
    Serial.print(calibrationDuration);
    Serial.println(" ms");

    // Print calibration data
  for (uint8_t i = 0; i < SensorCount; i++) {
    Serial.print(qtr.calibrationOn.minimum[i]);
    Serial.print(' ');
  }
  Serial.println();
  for (uint8_t i = 0; i < SensorCount; i++) {
    Serial.print(qtr.calibrationOn.maximum[i]);
    Serial.print(' ');
  }
  Serial.println();
  }

  // start the time trial
  timeAttack = millis();
}

int checkStatus(){
  return 0;
}

void standard(){
  // Read line position (0 to 5000, center is 2500)
  uint16_t position = qtr.readLineWhite(sensorValues);

  // Calculate error (deviation from center line, 2500 is center)
  float error = position - 2500.0;
  // if error = positive then make it turn right
  // when negative value then turn left

  // Calculate PID terms
  integral += error;
  float derivative = error - lastError;
  float correction = Kp * error + Ki * integral + Kd * derivative;

  // Calculate motor speeds
  //correction=0;
  // correction if positive turn right if negative turn left
  int leftSpeed = baseSpeed + correction;
  int rightSpeed = baseSpeed - correction;

  // Constrain motor speeds
  leftSpeed = constrain(leftSpeed, -maxSpeed, maxSpeed);
  rightSpeed = constrain(rightSpeed, -maxSpeed, maxSpeed);

  // Drive motors
  motor1.drive(leftSpeed);
  motor2.drive(rightSpeed);

  // Update last error for derivative term
  lastError = error;
}

// white - no serial - pid
void loop() {

  status = checkStatus();

  if(status == 0){
    standard();
  }

  delay(10);  // Short delay for stability
}

