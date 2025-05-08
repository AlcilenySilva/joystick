
#ifndef WIFI_CONNECT_H
#define WIFI_CONNECT_H

#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

#define WIFI_SSID ""
#define WIFI_PASSWORD ""

void init_wifi(void);

extern bool wifi_conectado;

#endif