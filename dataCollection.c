#include <DS3231.h>
#include <dht.h>
#define DHT11_PIN 10 // the digital pin for the dht11 sensor

dht DHT;
DS3231  rtc(SDA, SCL);

void setup() {
  Serial.begin(9600);
  // creates title separated by comma
  Serial.print("date-time, ");
  Serial.print("temperature, ");
  Serial.print("humidity");
  Serial.println();
  rtc.begin();

  // The following lines can be uncommented to set the date and time
  //rtc.setDOW(MONDAY);     // Set Day-of-Week to MONDAY
  //rtc.setTime(23, 24, 0);     // Set the time to 23:00:00 (24hr format) 11 PM
  //rtc.setDate(15, 7, 2019);   // Set the date to July 15th, 2019 but in 15/07/19 format
}

void loop() {
  double temp = DHT.temperature;
  // could also get the temperature from the DS3231 by typing rtc.getTemp()
  double humidity = DHT.humidity;
  int chk = DHT.read11(DHT11_PIN);
  if ((temp != -999 && humidity != -999) && (temp != 0 && humidity != 0)) { // prevent absurd values
    Serial.print(rtc.getDateStr());
    Serial.print("-");
    Serial.print(rtc.getTimeStr());
    Serial.print(", ");
    Serial.print(temp);
    Serial.print(", "); // separate by commas in order to create csv file
    Serial.println(humidity);
  }
  delay(1000); // update data every second
}
