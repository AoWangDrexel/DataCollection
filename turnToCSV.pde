import processing.serial.*;
PrintWriter output;
Serial mySerial;
String serialData = null; // collect serial data
int nl = 10; // ASCII code for carage return in serial

void setup() {
  output = createWriter("data.txt"); // create file to save data
  String myPort = "/dev/cu.usbmodem1421"; // enter port name
  mySerial = new Serial(this, myPort, 9600); // create Serial object
}

void draw() {
  while (mySerial.available() > 0) {
    serialData = mySerial.readStringUntil(nl);
    if (serialData != null) {
      output.println(serialData);
    }
  }
}
void keyPressed() {
  output.flush(); // Writes the remaining data to the file
  output.close(); // Finishes the file
  exit(); // Stops the program
}
