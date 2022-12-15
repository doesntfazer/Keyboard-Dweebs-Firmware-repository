/* Copyright 2022 hakbraley <hakbraley@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "mcp23017.h"
#include <print.h>
#include "config_common.h"



// DEVICE ADDRESS DEFINITION ------------------------------------------------------------

// https://ww1.microchip.com/downloads/en/devicedoc/20001952c.pdf#page=15  FIGURE 3-6
#define MCP23017_I2C_ADDR (0b0100000 | (MCP23017_HW_ADDR_PINS))



// VARIABLE DEFINITIONS -----------------------------------------------------------------

#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof((arr)[0]))

static const pin_t   matrix_pins[] = MATRIX_PINS;
static const uint8_t num_matrix_pins = ARRAY_LENGTH(matrix_pins);

static bool is_mcp23017_ok = 0;  // Is MCP23017 initialized and performing correctly?

static uint8_t mcp23017_reset_loop = 0;  // Reset MCP23017 every 255 matrix scans if it errors



// INTERNAL FUNCTION DEFINITIONS --------------------------------------------------------

static void init_direct_pins(void) {
	// Set all MATRIX_PINS_MCU pins as inputs with pullup resistors
	for (int pin_index = 0; pin_index < num_matrix_pins; pin_index++) {
		pin_t pin = matrix_pins[pin_index];
		if (pin != NO_PIN) {
			setPinInputHigh(pin);
		}
	}
}

static bool init_mcp23017(void) {
    // Initialize i2c bus if not already done
	mcp23017_init();

	// Set all MCP23017 pins to inputs with pullup resistors enabled
	// Port A
	is_mcp23017_ok = mcp23017_set_config(MCP23017_I2C_ADDR, mcp23017_PORTA, ALL_INPUT);
	if (!is_mcp23017_ok) return false;

	// Port B
	is_mcp23017_ok = mcp23017_set_config(MCP23017_I2C_ADDR, mcp23017_PORTB, ALL_INPUT);
	if (!is_mcp23017_ok) return false;

	return true;
}

static void reset_mcp23017_if_error(void) {
	// If there was an error with MCP23017
	if (!is_mcp23017_ok) {
        // Since mcp23017_reset_loop is 8 bit - we'll try to reset once every 255 matrix scans
        // This will be a bit more frequent than once per second
        if (++mcp23017_reset_loop == 0) {
            dprint("Trying to reset MCP23017... \n");
            is_mcp23017_ok = init_mcp23017();					// Attempt to reinitialize MCP23017
            if (!is_mcp23017_ok) {								// If there is still an error
                dprint("MCP23017 is not responding. \n");		//   Print a debug message
            } else {											// If the error is gone
                dprint("MCP23017 back to normal status. \n");	//   Print a debug message
            }
        }
    }
}

static bool is_pin_on_mcp(uint8_t pin) {
	return (pin >= M_A0  &&  pin <= M_B7);
}

static bool get_mcp_pin_value(uint16_t mcp_pin_vals, uint8_t pin) {
	uint8_t pin_index = pin - M_A0;
	return mcp_pin_vals & (1 << pin_index);
}

static bool matrix_read_cols_on_row(matrix_row_t current_matrix[], uint8_t row_index, uint16_t mcp_pin_vals) {
    bool row_has_changed = false;

	// Start with a clear matrix row
    matrix_row_t current_row_value = 0;

	// For every column in the row
    for (uint8_t col_index = 0; col_index < MATRIX_COLS; col_index++) {
        // Select the pin for this (row, column) position
		uint8_t pin_index = (row_index * MATRIX_COLS) + col_index;
		if (pin_index >= num_matrix_pins) break;  // Quit if the end of MATRIX_PINS has been reached

		pin_t pin = matrix_pins[pin_index];
        
		if (pin == NO_PIN) continue;

		bool pin_value = 1;
		if (is_pin_on_mcp(pin)) {
			pin_value = get_mcp_pin_value(mcp_pin_vals, pin);
		} else {
			pin_value = readPin(pin);
		}
		
		// If pin reads LOW, switch is pressed. Write a 1 to the row in the col position
		if (pin_value == 0) {
			current_row_value |= 1 << col_index;
		}
    }

	// If the state of the row that was just read is different from what's already in the matrix
	if (current_row_value != current_matrix[row_index]) {
		row_has_changed = true;
		// Update the row in the matrix
		current_matrix[row_index] = current_row_value;
	}

	return row_has_changed;
}



// QMK MATRIX FUNCTIONS -----------------------------------------------------------------

void matrix_init_custom(void) {
	init_direct_pins();

	is_mcp23017_ok = init_mcp23017();
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    // If there was an error with MCP23017, attempt to reset it
	reset_mcp23017_if_error();

	bool matrix_has_changed = false;

	// Get the values of all 16 pins on MCP23017
	uint16_t mcp_pin_vals = 0;
	is_mcp23017_ok = mcp23017_readPins_all(MCP23017_I2C_ADDR, &mcp_pin_vals);


	// Read the direct matrix pins on the microcontroller
	for (int row_index = 0; row_index < 4; row_index++) {
		// Read the row of pins and update matrix_has_changed if there was a change
		matrix_has_changed |= matrix_read_cols_on_row(current_matrix, row_index, mcp_pin_vals);
	}

	return matrix_has_changed;
}


