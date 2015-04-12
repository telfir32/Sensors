#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 4
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
DeviceAddress DS18B20;

void setup(void)
{
  Serial.begin(9600);
  
  sensors.begin();
  sensors.getAddress(DS18B20, 0);
  sensors.setResolution(DS18B20, 12);
}



void loop(void)
{ 
  sensors.requestTemperatures(); // Send the command to get temperatures
  float tempC = sensors.getTempC(DS18B20);
  Serial.print("Temp C: ");
  Serial.println(tempC);
  delay(250);
}
