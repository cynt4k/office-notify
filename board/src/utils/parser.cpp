#include "parser.hpp"

Bounce buttonRed;
Bounce buttonGreen;
Bounce buttonYellow;

void _setup_pin() {
    static uint8_t is_setup = 0;

    if (is_setup == 1) {
        buttonRed.update();
        buttonGreen.update();
        buttonYellow.update();
        return;
    }

    buttonRed.attach(PIN_BUTTON_RED);
    buttonGreen.attach(PIN_BUTTON_GREEN);
    buttonYellow.attach(PIN_BUTTON_YELLOW);
    buttonRed.interval(50);
    buttonGreen.interval(50);
    buttonYellow.interval(50);
    is_setup = 1;
    return;
}

void test_publish(PubSubClient client) {
    _setup_pin();

    if (buttonRed.fell()) {
        Serial.println("Red Button pressed");
        client.publish(MQTT_TOPIC, create_data(InputMapping::BUTTON_RED, 1));
    }
}

void parse_input(PubSubClient client) {
    _setup_pin();

    if (buttonRed.fell()) {
        Serial.println("Red Button pressed");
        client.publish(MQTT_TOPIC, create_data(InputMapping::BUTTON_RED, 1));
    }

    if (buttonGreen.fell()) {
        Serial.println("Green Button pressed");
        client.publish(MQTT_TOPIC, create_data(InputMapping::BUTTON_GREEN, 1));
    }

    if (buttonYellow.fell()) {
        Serial.println("Yellow Button pressed");
        client.publish(MQTT_TOPIC, create_data(InputMapping::BUTTON_YELLOW, 1));
    }
}