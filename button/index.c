// https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf
#include <avr/io.h>
// https://onlinedocs.microchip.com/oxy/GUID-317042D4-BCCE-4065-BB05-AC4312DBC2C4-en-US-2/GUID-FA604377-8E19-44A7-A13D-DC652C3E97F4.html
#include <util/delay.h>

// Pino digital 12 do Arduino Nano = PB4 no ATmega328P

int main(void) {
    // Configura PB4 (D12) como entrada
    DDRB &= ~(1 << PB4);

    // Desativa pull-up interno (opcional)
    PORTB &= ~(1 << PB4);

    // Inicializa UART (para printf)
    // Baud rate: 9600 (F_CPU = 16MHz)
    uint16_t ubrr = 103;
    UBRR0H = (ubrr >> 8);
    UBRR0L = ubrr;
    UCSR0B = (1 << TXEN0); // habilita transmissão
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // 8 bits

    while (1) {
        // Lê o estado do pino PB4 (D12)
        uint8_t buttonState = (PINB & (1 << PB4)) ? 1 : 0;

        // Envia o valor pela UART
        if (buttonState) {
            send_string("1\r\n");
        } else {
            send_string("0\r\n");
        }

        _delay_ms(200);
    }
}

// Envia um caractere pela UART
void uart_putchar(char c) {
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = c;
}

// Envia uma string pela UART
void send_string(const char* s) {
    while (*s) {
        uart_putchar(*s++);
    }
}
