#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0xBEEF
#define DEVICE_VER      0x0001

#define MANUFACTURER    QMK
#define PRODUCT         Atreus42 Keyboard
#define DESCRIPTION     QMK keyboard firmware for Atreus

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 11
#define DIODE_DIRECTION ROW2COL

#define MATRIX_ROW_PINS { A5, A6, A7, B0 }
// #define MATRIX_COL_PINS { A1, A2, A3, A4, A5, A6, A7, A8, A9, B3, A10, A12, A0 }
#define MATRIX_COL_PINS { B5, B6, B7, A10, A9, A8, A4, A3, A2, A1, A0 }
#define UNUSED_PINS
