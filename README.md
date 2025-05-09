# 🧩 embedded-components-examples

Repositório com exemplos práticos de como utilizar componentes eletrônicos básicos (como botões, sensores, etc.) com microcontroladores AVR, como o ATmega328P (usado no Arduino Nano), programando em **C puro** e **C++** com acesso direto aos **registradores**.



---

## 📘 Exemplos disponíveis

| Componente | Linguagem | Arquivo base     | Descrição                      |
|------------|-----------|------------------|-------------------------------|
| Botão      | C (puro)  | `button/button.c` | Lê um botão via PORTB e envia via UART |

---

## ✅ Requisitos

- **Microcontrolador:** ATmega328P (Arduino Nano, Uno)
- **Compilador:** `avr-gcc`
- **Ferramentas recomendadas:**
  - `avrdude` (gravação)
  - `minicom` ou `PuTTY` (monitor UART)
  - Simuladores: [SimulIDE](https://www.simulide.com/) ou [AVR8js](https://avr8js.uqbar-project.org/)

---

## 🛠️ Compilação com avr-gcc

```bash
avr-gcc -mmcu=atmega328p -DF_CPU=16000000UL -Os -o button.elf button.c
avr-objcopy -O ihex -R .eeprom button.elf button.hex
avrdude -c arduino -p m328p -P /dev/ttyUSB0 -b 115200 -U flash:w:button.hex
