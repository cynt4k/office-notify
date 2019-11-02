#include "handler.hpp"

char *create_data(uint8_t pin, uint8_t status) {
    static char output[128];
    const size_t capacity = JSON_OBJECT_SIZE(2);
    DynamicJsonDocument doc(capacity);

    doc["button"] = pin;
    doc["status"] = status;

    serializeJson(doc, output);
    return output;
}
