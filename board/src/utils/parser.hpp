#ifndef PARSER_
#define PARSER_

#include <Arduino.h>
#include <PubSubClient.h>
#include <Bounce2.h>
#include "handler.hpp"
#include "config.hpp"
#include "../main.hpp"

enum InputMapping {
    BUTTON_RED,
    BUTTON_GREEN,
    BUTTON_YELLOW,
    BUTTON_EMERGENCY,
    KEY_LEFT,
    KEY_RIGHT,
};


void _setup_pin();

void parse_input(PubSubClient client);

void test_publish(PubSubClient client);

#endif /*PARSER_*/