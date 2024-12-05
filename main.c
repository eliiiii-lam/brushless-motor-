#include <Servo.h> // Library to send PWM signals

Servo esc; // Create an ESC object

void setup() {
    esc.attach(9); // Attach the ESC to pin 9
    Serial.begin(9600); // Initialize serial communication

    // Arm the ESC
    Serial.println("Arming ESC...");
    esc.writeMicroseconds(1000); // Send minimum throttle
    delay(2000); // Wait for the ESC to initialize
    Serial.println("ESC Armed!");
}

void loop() {
    // Example: Gradually increase speed, hold, then stop
    Serial.println("Increasing speed...");
    for (int speed = 1000; speed <= 2000; speed += 10) { // 1000-2000 range for PWM
        esc.writeMicroseconds(speed);
        delay(50); // Adjust delay for smoother acceleration
    }
    
    Serial.println("Holding speed...");
    delay(5000); // Hold max speed for 5 seconds

    Serial.println("Stopping motor...");
    esc.writeMicroseconds(1000); // Minimum throttle to stop the motor
    delay(2000);
}
