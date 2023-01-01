/*
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _PICO_TYPES_H
#define _PICO_TYPES_H

#ifndef __ASSEMBLER__

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef unsigned int uint;

typedef volatile uint32_t io_rw_32;
typedef const volatile uint32_t io_ro_32;
typedef volatile uint32_t io_wo_32;
typedef volatile uint16_t io_rw_16;
typedef const volatile uint16_t io_ro_16;
typedef volatile uint16_t io_wo_16;
typedef volatile uint8_t io_rw_8;
typedef const volatile uint8_t io_ro_8;
typedef volatile uint8_t io_wo_8;

typedef volatile uint8_t *const ioptr;
typedef ioptr const const_ioptr;


/*! \typedef absolute_time_t
    \brief An opaque 64 bit timestamp in microseconds

    The type is used instead of a raw uint64_t to prevent accidentally passing relative times or times in the wrong
    time units where an absolute time is required. It is equivalent to uint64_t in release builds.

    \see to_us_since_boot()
    \see update_us_since_boot()
    \ingroup timestamp
*/
#ifdef NDEBUG
typedef uint64_t absolute_time_t;
#else
typedef struct {
    uint64_t _private_us_since_boot;
} absolute_time_t;
#endif

#ifdef NDEBUG
#define ABSOLUTE_TIME_INITIALIZED_VAR(name, value) name = value
#else
#define ABSOLUTE_TIME_INITIALIZED_VAR(name, value) name = {value}
#endif

/** \struct datetime_t
 *  \ingroup util_datetime
 *  \brief Structure containing date and time information
 *
 *    When setting an RTC alarm, set a field to -1 tells
 *    the RTC to not match on this field
 */
typedef struct {
    int16_t year;    ///< 0..4095
    int8_t month;    ///< 1..12, 1 is January
    int8_t day;      ///< 1..28,29,30,31 depending on month
    int8_t dotw;     ///< 0..6, 0 is Sunday
    int8_t hour;     ///< 0..23
    int8_t min;      ///< 0..59
    int8_t sec;      ///< 0..59
} datetime_t;

#define bool_to_bit(x) ((uint)!!(x))

#endif
#endif
