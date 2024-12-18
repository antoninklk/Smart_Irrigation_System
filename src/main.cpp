/* Le but de ce programme est de nous donner 
la mesure de l'humiditié par le sensor toutes les 1 s */
// Just with WiFi classes sufficient

#include <Arduino.h>
#include "Sensors.h"
#include "Actuators.h"
#include "Network.h"
#include "SendHTTPWebServer.h"

#include <WiFi.h>

void setup(void)
{
  //Set the baudrate to 115200
  Serial.begin(115200);

  //Pump init
  pump_init();

  //network init
  network_setup();

}

void loop(void)
{
  //Measure Humidity with Sensors
  sensor_data_acquisition();
  
  //WebPage Send Data
  http_send_data_to_web_server(String(humidity));

  //TO DO Grafana with influxdb to visualize datas on a dashboard

  //Irrigation
  pump_irrigation_automation();
}