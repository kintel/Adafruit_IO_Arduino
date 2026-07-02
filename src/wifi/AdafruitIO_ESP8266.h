/*!
 * @file AdafruitIO_ESP8266.h
 *
 * Adafruit invests time and resources providing this open source code.
 * Please support Adafruit and open source hardware by purchasing
 * products from Adafruit!
 *
 * Copyright (c) 2015-2016 Adafruit Industries
 * Authors: Tony DiCola, Todd Treece
 * Licensed under the MIT license.
 *
 * All text above must be included in any redistribution.
 */

#ifndef ADAFRUITIO_ESP8266_H
#define ADAFRUITIO_ESP8266_H

#ifdef ESP8266

#include "AdafruitIO.h"
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#include "Arduino.h"
#include "ESP8266WiFi.h"

/* NOTE - As of 07/21/26, this library no longer supports "Secure MQTT"
 * (TLS/SSL) on the ESP8266 due to new automatic certificate updates that
 * require a new certificate every 199 days (or less) -
 * https://forums.adafruit.com/viewtopic.php?t=224362 If you would like a secure
 * Adafruit IO Arduino project, please switch to using the modern ESP32 (and
 * related models) instead of the ESP8266.
 */

class AdafruitIO_ESP8266 : public AdafruitIO {

public:
  AdafruitIO_ESP8266(const char *user, const char *key, const char *ssid,
                     const char *pass);
  ~AdafruitIO_ESP8266();

  aio_status_t networkStatus();
  const char *connectionType();

protected:
  void _connect();
  void _disconnect();

  const char *_ssid;
  const char *_pass;
  WiFiClient *_client;
};

#endif // ESP8266
#endif // ADAFRUITIO_ESP8266_H
