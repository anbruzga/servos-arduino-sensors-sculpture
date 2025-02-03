#include <Servo.h>

struct ServoConfig { // MAP ON CONFIGURATIONS
  Servo* servo;
  float minAngle;
  float maxAngle;
  float duration; // Duration in milliseconds
};

// Constants
const float fullRotation = 145.0;      // Full rotation in degrees
const int FPS = 60;                    // Frames per second
const unsigned long alternateInterval = 10000; // Interval for alternation in ms // EVERY 10 seconds (10000) change the alternation
const float minAngle = 0.0;
const float maxAngle = fullRotation;
const float transitionDuration = 1000; // Transition period in milliseconds

// Global Variables
Servo servos[4];
bool alternate = false; // Alternation flag
unsigned long lastAlternateTime = 0;  // Last alternation time
unsigned long lastUpdateTime = 0;     // Last update time for motion
float progress[4] = {0.0, 0.0, 0.0, 0.0};  // Progress trackers for each servo

// Transition Variables
bool transitioning = false;
unsigned long transitionStartTime = 0;

ServoConfig oldConfigs[4];
ServoConfig newConfigs[4];

// PIR Sensor
const int pirPin = 13;                     // PIR sensor connected to pin 13
bool motionDetected = false;               // Flag for motion detection
unsigned long lastMotionTime = 0;          // Last time motion was detected
const unsigned long motionTimeout = 10000; // Keep running for 10 seconds after motion stops EDITABLE -  10000 is 10 seconds 3*60*1000= 3 minutes = 60000 * 3 = 180000


void setup() {
  Serial.begin(9600);

  // Attach servos
  servos[0].attach(9);
  servos[1].attach(10); // faster (higher duration) FASTER ATTACHED TO THESE
  servos[2].attach(8);  // faster (higher duration) FASTER ATTACHED TO THESE
  servos[3].attach(11);

  // Initialize servos at neutral position
  for (int i = 0; i < 4; ++i) { // JERKS ANNOYINGLY
    servos[i].write(static_cast<int>(maxAngle / 2));
  }

  // Initial servo configurations
  // MIN ANGLE CAN BE ONLY INCREASED, FOR EXAMPPLE minAngle+10
  // MAX ANGLE CAN BE ONLY DECREASED, FOR EXAMPPLE maxAngle-10, OR maxAngle / 1.25
  // NUMBER - is speed, closer to 0 is faster
  oldConfigs[0] = {&servos[0], minAngle, maxAngle, 6000};  
  oldConfigs[1] = {&servos[1], minAngle, maxAngle, 2000}; // FASTER ATTACHED TO THESE
  oldConfigs[2] = {&servos[2], minAngle, maxAngle, 2000}; // FASTER ATTACHED TO THESE
  oldConfigs[3] = {&servos[3], minAngle, maxAngle, 6000};


/* example how it can be
  oldConfigs[0] = {&servos[0], minAngle, maxAngle / 1.25, 3000};
  oldConfigs[1] = {&servos[1], minAngle, maxAngle, 2000};
  oldConfigs[2] = {&servos[2], minAngle, maxAngle / 1.5, 4000};
  oldConfigs[3] = {&servos[3], minAngle, maxAngle / 2, 2500};
*/


  for (int i = 0; i < 4; ++i) {
    newConfigs[i] = oldConfigs[i];
  }

  // light connection
  pinMode(pirPin, INPUT);

}



void loop() {
  // Handle alternation and initiate transition
  unsigned long currentTime = getCurrentTime();

  // Read PIR sensor state
  motionDetected = digitalRead(pirPin);
  if (motionDetected) {
    lastMotionTime = currentTime;  // Update last motion detected time
  }

  // Check if motion should continue
  bool shouldRun = (currentTime - lastMotionTime) <= motionTimeout;

  if (shouldRun) {
    if (!transitioning && (currentTime - lastAlternateTime >= alternateInterval)) {
      // Swap configurations and start transitioning
      lastAlternateTime = currentTime;
      transitioning = true;
      transitionStartTime = currentTime;

      // Define new configurations based on alternation flag
      // this is also example
      // newConfigs[0] = {&servos[0], minAngle, alternate ? maxAngle : maxAngle / 1.25, alternate ? 1300 : 5000};
      // newConfigs[1] = {&servos[1], minAngle, alternate ? maxAngle / 1.25 : maxAngle, alternate ? 3000 : 2000};
      // newConfigs[2] = {&servos[2], minAngle, alternate ? maxAngle / 1.5 : maxAngle, alternate ? 4000 : 2500};
      // newConfigs[3] = {&servos[3], minAngle, alternate ? maxAngle / 2 : maxAngle / 1.5, alternate ? 2500 : 3500};

        // ALTERNATIVE CONFIGURATIONS - BELOW IS SET TO DEFAULT CONFIGURATIONS
        newConfigs[0] = {&servos[0], minAngle, maxAngle, 6000};
        newConfigs[1] = {&servos[1], minAngle, maxAngle, 2000};
        newConfigs[2] = {&servos[2], minAngle, maxAngle, 2000};
        newConfigs[3] = {&servos[3], minAngle, maxAngle, 6000};


      alternate = !alternate;  // Flip alternation flag
    }

    // Update servos based on configurations
    if (transitioning) {
      // Perform smooth transition
      float transitionProgress = static_cast<float>(currentTime - transitionStartTime) / transitionDuration;
      if (transitionProgress >= 1.0) {
        // Transition complete
        transitionProgress = 1.0;
        transitioning = false;
        for (int i = 0; i < 4; ++i) {
          oldConfigs[i] = newConfigs[i];
        }
      }

      // Blend configurations
      ServoConfig blendedConfigs[4];
      for (int i = 0; i < 4; ++i) {
        blendedConfigs[i] = blendConfigs(oldConfigs[i], newConfigs[i], transitionProgress);
      }

      performServoMotion(blendedConfigs, currentTime);
    } else {
      // Normal operation with the current configurations
      performServoMotion(oldConfigs, currentTime);
    }
  } else {
    // Pause the servos by not updating their position
    pauseServos();
  }
}

// Function to pause servo updates by freezing their current position
void pauseServos() {
  Serial.println("No motion detected, pausing servos.");
}

// Perform servo motion with given configurations only if motion is detected
void performServoMotion(const ServoConfig configs[4], unsigned long currentTime) {
  if (currentTime - lastUpdateTime >= (1000 / FPS)) {
    lastUpdateTime = currentTime;

    for (int i = 0; i < 4; ++i) {
      // Increment progress based on time and duration
      progress[i] += (1.0 / (FPS * (configs[i].duration / 1000.0)));

      // Wrap progress smoothly
      if (progress[i] >= 1.0) progress[i] -= 1.0;

      // Compute sine wave values
      float sineValue = (sin(progress[i] * 2 * PI) + 1) / 2;

      // Map sine values to angles
      float angle = configs[i].minAngle + sineValue * (configs[i].maxAngle - configs[i].minAngle);

      // Write angles to servos
      configs[i].servo->write(static_cast<int>(angle));

      // Debugging output
      Serial.print("Servo ");
      Serial.print(i + 1);
      Serial.print(": Angle = ");
      Serial.println(angle, 2);
    }
  }
}


// Smoothly blend two configurations based on progress
ServoConfig blendConfigs(const ServoConfig& oldConfig, const ServoConfig& newConfig, float progress) {
  return {
    oldConfig.servo,
    oldConfig.minAngle + progress * (newConfig.minAngle - oldConfig.minAngle),
    oldConfig.maxAngle + progress * (newConfig.maxAngle - oldConfig.maxAngle),
    oldConfig.duration + progress * (newConfig.duration - oldConfig.duration)
  };
}

// Function to handle getting the current time
unsigned long getCurrentTime() {
  return millis();
}


