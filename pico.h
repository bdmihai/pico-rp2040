/*
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef PICO_H_
#define PICO_H_

/** \file pico.h
 *  \defgroup pico_base pico_base
 *
 * Core types and macros for the Raspberry Pi Pico SDK. This header is intended to be included by all source code
 * as it includes configuration headers and overrides in the correct order
 *
 * This header may be included by assembly code
*/

#define	__PICO_STRING(x)	#x
#define	__PICO_XSTRING(x)	__PICO_STRING(x)

#include "pico/config.h"
#include "pico/types.h"
#include "pico/assert.h"
#include "pico/platform.h"
#include "pico/error.h"

#endif
