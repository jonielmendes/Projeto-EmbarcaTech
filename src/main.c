#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/pio.h"
#include "ws2812.pio.h"

// biblioteca para manipulação de leds
#include "lib/led.h"
// biblioteca para manipulação de botões
#include "lib/button.h"
// biblioteca para manipulação de interrupções
#include "lib/interrupt.h"
// biblioteca para manipulação da matriz de leds
#include "lib/matrix.h"

// controla a intensidade da cor dos leds
uint8_t led_r = 0;
uint8_t led_g = 0;
uint8_t led_b = 100;

// Variável para armazenar o número atual
extern volatile uint actual_number;

int main() {
    stdio_init_all();
    // Inicializa o led Azul
    init_led(LED_BLUE);
    
    // Inicialização dos botões e configuração de eventos de interrupção
    init_button_with_interrupt(BUTTON_A, GPIO_IRQ_EDGE_FALL, true);
    init_button_with_interrupt(BUTTON_B, GPIO_IRQ_EDGE_FALL, true);
    init_button_with_interrupt(JOYSTICK_BUTTON, GPIO_IRQ_EDGE_FALL, true);
  
    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);

    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);
    
    // Inicialmente exibe o número zero
    set_one_led(numbers[actual_number], led_r, led_g, led_b);

    // Variável para armazenar o último número exibido
    uint last_number = actual_number;

    while(true) {
        // Verifica se o número atual é diferente do último número exibido
        if (actual_number != last_number) {
            // Atualiza o último número exibido
            last_number = actual_number;

            // Verifica se o número atual é par ou ímpar
            if (actual_number % 2 == 0) {
                // Número par: vermelho
                led_r = 100;
                led_g = 0;
                led_b = 0;
                printf("Número %d é Par\n", actual_number);
            } else {
                // Número ímpar: azul
                led_r = 0;
                led_g = 0;
                led_b = 100;
                printf("Número %d é Ímpar\n", actual_number);
            }
            
            // Atualiza a cor do LED
            set_one_led(numbers[actual_number], led_r, led_g, led_b);
        }
        
        // 5 ciclos de 200ms totalizando 1 segundo
            // 100ms ligado
            // 100ms desligado
        blink_led(LED_BLUE, 100, 5);
    }
    return 0;
}