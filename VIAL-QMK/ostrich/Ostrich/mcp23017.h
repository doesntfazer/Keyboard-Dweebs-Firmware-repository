// Copyright 2022 zvecr<git@zvecr.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <stdint.h>
#include <stdbool.h>

/**
 * Port ID
 */
typedef enum {
    mcp23017_PORTA,
    mcp23017_PORTB,
} mcp23017_port_t;

/**
 * Helpers for set_config
 */
enum {
    ALL_OUTPUT = 0,
    ALL_INPUT  = 0xFF,
};

/**
 * Helpers for set_output
 */
enum {
    ALL_LOW  = 0,
    ALL_HIGH = 0xFF,
};



/**
 * Initialize expander and any other dependent drivers
 */

void mcp23017_init(void);

/**
 * Configure input/output to a given port
 */
bool mcp23017_set_config(uint8_t slave_addr, mcp23017_port_t port, uint8_t conf);

/**
 * Write high/low to a given port
 */
bool mcp23017_set_output(uint8_t slave_addr, mcp23017_port_t port, uint8_t conf);

/**
 * Write high/low to both ports sequentially
 *
 *  - slightly faster than multiple set_output
 */
bool mcp23017_set_output_all(uint8_t slave_addr, uint8_t confA, uint8_t confB);

/**
 * Read state of a given port
 */
bool mcp23017_readPins(uint8_t slave_addr, mcp23017_port_t port, uint8_t* ret);

/**
 * Read state of both ports sequentially
 *
 *  - slightly faster than multiple readPins
 */
bool mcp23017_readPins_all(uint8_t slave_addr, uint16_t* ret);
