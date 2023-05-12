// Copyright 2023 doesntfazer (@doesntfazer)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include_next <mcuconf.h>

#undef RP_SPI_USE_SPI0
#define RP_SPI_USE_SPI0 TRUE

#undef RP_SPI_USE_SPI1
#define RP_SPI_USE_SPI1 FALSE


//use this for I2c
//#pragma once

//#include_next <mcuconf.h>

//#undef RP_I2C_USE_I2C0
//#define RP_I2C_USE_I2C0 TRUE
