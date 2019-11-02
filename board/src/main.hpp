#ifndef MAIN_
#define MAIN_

#include <Arduino.h>
#include <Dns.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "utils/handler.hpp"
#include "config.hpp"
#include "utils/parser.hpp"

void callback(char* topic, byte* payload, unsigned int length);
void setup_pins();
void setup();
void reconnect();
void loop();

#endif /*MAIN_*/