#include <Servo.h>
#include <ESP8266WebServer.h>

// Create a servo object
Servo myservo;

// Set up the web server
ESP8266WebServer server(80);

// This function will be called when a request is received
void handleSetAngle() {
  // Get the servo angle from the request data
  int angle = server.arg("angle").toInt();

  // Set the servo angle
  myservo.write(angle);

  // Send a response back to the client
  server.send(200, "text/plain", "Angle set to " + String(angle));
}

void setup() {
  // Set up the servo
  myservo.attach(14);  // Attach the servo to pin 14

  // Set up the web server
  server.on("/setAngle", handleSetAngle);  // Register the request handler
  server.begin();  // Start the server
}

void loop() {
  server.handleClient();  // Handle incoming requests
}
