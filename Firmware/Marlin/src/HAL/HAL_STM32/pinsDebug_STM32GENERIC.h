/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * Support routines for STM32GENERIC (Maple)
 */

/**
 * Translation of routines & variables used by pinsDebug.h
 */

#ifdef BOARD_NR_GPIO_PINS  // Only in STM32GENERIC (Maple)

#ifdef __STM32F1__
  #include "../HAL_STM32F1/fastio_STM32F1.h"
#elif defined(STM32F4) || defined(STM32F7)
  #include "../HAL_STM32_F4_F7/fastio_STM32_F4_F7.h"
#endif

extern const stm32_pin_info PIN_MAP[BOARD_NR_GPIO_PINS];

#define NUM_DIGITAL_PINS BOARD_NR_GPIO_PINS
#define NUMBER_PINS_TOTAL BOARD_NR_GPIO_PINS
#define VALID_PIN(pin) (pin >= 0 && pin < BOARD_NR_GPIO_PINS)
#define GET_ARRAY_PIN(p) pin_t(pin_array[p].pin)
#define pwm_status(pin) PWM_PIN(pin)
#define digitalRead_mod(p) extDigitalRead(p)
#define NAME_FORMAT(p) PSTR("%-##p##s")
#define PRINT_PIN(p) do{ sprintf_P(buffer, PSTR("%3hd "), int16_t(p)); SERIAL_ECHO(buffer); }while(0)
#define PRINT_PORT(p) print_port(p)
#define PRINT_ARRAY_NAME(x) do{ sprintf_P(buffer, PSTR("%-" STRINGIFY(MAX_NAME_LENGTH) "s"), pin_array[x].name); SERIAL_ECHO(buffer); }while(0)
#define MULTI_NAME_PAD 21 // space needed to be pretty if not first name assigned to a pin

// pins that will cause hang/reset/disconnect in M43 Toggle and Watch utilities
#ifndef M43_NEVER_TOUCH
  #define M43_NEVER_TOUCH(Q) (Q >= 9 && Q <= 12) // SERIAL/USB pins PA9(TX) PA10(RX)
#endif

static inline int8_t get_pin_mode(pin_t pin) {
  return VALID_PIN(pin) ? _GET_MODE(pin) : -1;
}

static inline pin_t DIGITAL_PIN_TO_ANALOG_PIN(pin_t pin) {
  if (!VALID_PIN(pin)) return -1;
  int8_t adc_channel = int8_t(PIN_MAP[pin].adc_channel);
  #ifdef NUM_ANALOG_INPUTS
    if (adc_channel >= NUM_ANALOG_INPUTS) adc_channel = ADCx;
  #endif
  return pin_t(adc_channel);
}

static inline bool IS_ANALOG(pin_t pin) {
  if (!VALID_PIN(pin)) return false;
  if (PIN_MAP[pin].adc_channel != ADCx) {
    #ifdef NUM_ANALOG_INPUTS
      if (PIN_MAP[pin].adc_channel >= NUM_ANALOG_INPUTS) return false;
    #endif
    return _GET_MODE(pin) == GPIO_INPUT_ANALOG && !M43_NEVER_TOUCH(pin);
  }
  return false;
}

static inline bool GET_PINMODE(const pin_t pin) {
  return VALID_PIN(pin) && !IS_INPUT(pin);
}

static inline bool GET_ARRAY_IS_DIGITAL(const int16_t array_pin) {
  const pin_t pin = GET_ARRAY_PIN(array_pin);
  return (!IS_ANALOG(pin)
    #ifdef NUM_ANALOG_INPUTS
      || PIN_MAP[pin].adc_channel >= NUM_ANALOG_INPUTS
    #endif
  );
}

static inline void pwm_details(const pin_t pin) {
  if (PWM_PIN(pin)) {
    timer_dev * const tdev = PIN_MAP[pin].timer_device;
    const uint8_t channel = PIN_MAP[pin].timer_channel;
    const char num = (
      #if defined(STM32_HIGH_DENSITY) || defined(STM32_XL_DENSITY)
        tdev == &timer8 ? '8' :
        tdev == &timer5 ? '5' :
      #endif
      tdev == &timer4 ? '4' :
      tdev == &timer3 ? '3' :
      tdev == &timer2 ? '2' :
      tdev == &timer1 ? '1' : '?'
    );
    char buffer[10];
    sprintf_P(buffer, PSTR(" TIM%c CH%c"), num, ('0' + channel));
    SERIAL_ECHO(buffer);
  }
}

static inline void print_port(pin_t pin) {
  const char port = 'A' + char(pin >> 4); // pin div 16
  const int16_t gbit = PIN_MAP[pin].gpio_bit;
  char buffer[8];
  sprintf_P(buffer, PSTR("P%c%hd "), port, gbit);
  if (gbit < 10) SERIAL_CHAR(' ');
  SERIAL_ECHO(buffer);
}

#endif // BOARD_NR_GPIO_PINS
