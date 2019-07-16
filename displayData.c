#include <dht.h>
#include <LiquidCrystal.h>
#define DHT11_PIN 10 // the digital pin for the dht11 sensor

dht DHT;
LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // the pins in the diagram
void setup() {
  lcd.begin(16, 2);
}

void loop() {
  double temp = DHT.temperature;
  double humidity = DHT.humidity;
  int chk = DHT.read11(DHT11_PIN);

  // prevents the output of absurd values
  if ((temp != -999 && humidity != -999) && (temp != 0 && humidity != 0)) {
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temp);
    lcd.print((char)223); // ASCII for the degree symbol
    lcd.print("C");
    lcd.setCursor(0, 1);
    lcd.print("Humidity: ");
    lcd.print(humidity);
    lcd.print("%");
  }
  delay(1000); // updates data every second
}
