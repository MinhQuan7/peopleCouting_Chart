
/*************************************************************
  Download latest ERa library here:
    https://github.com/eoh-jsc/era-lib/releases/latest
    https://www.arduino.cc/reference/en/libraries/era
    https://registry.platformio.org/libraries/eoh-ltd/ERa/installation

    ERa website:                https://e-ra.io
    ERa blog:                   https://iotasia.org
    ERa forum:                  https://forum.eoh.io
    Follow us:                  https://www.fb.com/EoHPlatform
 *************************************************************/

// Enable debug console
// Set CORE_DEBUG_LEVEL = 3 first
#define ERA_DEBUG

#define DEFAULT_MQTT_HOST "mqtt1.eoh.io"

// You should get Auth Token in the ERa App or ERa Dashboard
#define ERA_AUTH_TOKEN "7d47f69f-b84e-4b72-af1d-84f1306caf53"

#include <Arduino.h>
#include <ERa.hpp>
#include <ERa/ERaTimer.hpp>

const char ssid[] = "eoh.io";
const char pass[] = "Eoh@2020";

ERaTimer timer;

/* This function print uptime every second */
void timerEvent() {
    ERA_LOG("Timer", "Uptime: %d", ERaMillis() / 1000L);
}

void setup() {
    /* Setup debug console */
    Serial.begin(115200);
    ERa.begin(ssid, pass);
    /* Setup timer called function every second */
    timer.setInterval(1000L, timerEvent);
}

void loop() {
    ERa.run();
    timer.run();
    int people1, people2, people3, people4;
    people1 = 11 ;
    people2 = 10;
    ERa.virtualWrite(V0,people1);
    ERa.virtualWrite(V1,people2);
    people3 = 12;
    people4 = 12;
    ERa.virtualWrite(V0,people3);
    ERa.virtualWrite(V1,people4);
    delay(10000);
    people1 = 9 ;
    people2 = 10;
    ERa.virtualWrite(V0,people1);
    ERa.virtualWrite(V1,people2);
    people3 = 9;
    people4 = 9;
    ERa.virtualWrite(V0,people3);
    ERa.virtualWrite(V1,people4);
}

