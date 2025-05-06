#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "utils/send-data-to-server/send-data.h"
#include "utils/wifi-connection/wifi-connect.h"

const int MARGEM = 600;

const char* get_direcao(int x, int y) {
    if (abs(x - 2048) < MARGEM && abs(y - 2048) < MARGEM) return "Centro";
    if (x > 2048 + MARGEM && abs(y - 2048) < MARGEM) return "Leste";
    if (x < 2048 - MARGEM && abs(y - 2048) < MARGEM) return "Oeste";
    if (y > 2048 + MARGEM && abs(x - 2048) < MARGEM) return "Norte";
    if (y < 2048 - MARGEM && abs(x - 2048) < MARGEM) return "Sul";
    if (x > 2048 + MARGEM && y > 2048 + MARGEM) return "Nordeste";
    if (x < 2048 - MARGEM && y > 2048 + MARGEM) return "Noroeste";
    if (x > 2048 + MARGEM && y < 2048 - MARGEM) return "Sudeste";
    if (x < 2048 - MARGEM && y < 2048 - MARGEM) return "Sudoeste";

    return "Indefinido";
}

int main() {
    stdio_init_all();
    init_wifi();

    adc_init();
    adc_gpio_init(26); // X
    adc_gpio_init(27); // Y

    while (true) {
        adc_select_input(0);
        int x = adc_read();
        sleep_ms(10);
    
        adc_select_input(1);
        int y = adc_read();
        sleep_ms(10);
    
        const char* direcao = get_direcao(x, y);
    
        printf("X: %d, Y: %d, Direção: %s\n", x, y, direcao);
    
        create_request_json(x, y, direcao); // Envia x, y e direção
    
        
        cyw43_arch_poll();
    
        sleep_ms(1000); // Espera 1 segundo para próxima leitura
    }
}
