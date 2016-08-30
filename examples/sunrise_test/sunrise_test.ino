/* Short explanation
  Create an instance of the Sunrise class
  Pass month and day to Rise() or Set(), returning minutes since midnight of the event
  Read the hour and minute if desired
  See the website for more detailed instructions
  http://www.swfltek.com/arduino/sunrise
*/

#include <Sunrise.h>

// create a Sunrise object
Sunrise mySunrise(37.24, 127.11, 9);//Lisbon, Portugal, Europe - Latitude/Longitude and Timezone 	38.79/-9.12, 0

void setup() {
  Serial.begin(115200);
  mySunrise.Actual(); //Actual, Civil, Nautical, Astronomical
  Serial.println();

  byte h, m;
  int t;
  // t= minutes past midnight of sunrise (6 am would be 360)
  t = mySunrise.Rise(8, 30); // (month,day) - january=1
  if (t >= 0) {
    h = mySunrise.Hour();
    m = mySunrise.Minute();
    Serial.print("The sun rises on June 30 at ");
    Serial.print(h, DEC);
    Serial.print(":");
    if (m < 10) Serial.print("0");
    Serial.println(m, DEC);
  } else { //
    Serial.println("There are either penguins or polar bears around here!");
  }
  // t= minutes past midnight of sunrise (6 am would be 360)
  t = mySunrise.Set(8, 30); // (month,day) - january=1
  if (t >= 0) {
    h = mySunrise.Hour();
    m = mySunrise.Minute();
    Serial.print("The sun sets on June 30 at ");
    Serial.print(h, DEC);
    Serial.print(":");
    if (m < 10) Serial.print("0");
    Serial.println(m, DEC);
  } else { //
    Serial.println("There are either penguins or polar bears around here!");
  }

}

void loop() {
}

