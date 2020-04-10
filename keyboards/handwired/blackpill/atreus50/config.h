#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0xBEEF
#define DEVICE_VER      0x0001

#define MANUFACTURER QMK
#define PRODUCT Atreus 50 Keyboard
#define DESCRIPTION Atreus layout with extra column

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 13
#define DIODE_DIRECTION ROW2COL

#define MATRIX_ROW_PINS { B12, B13, B14, B15 }
#define MATRIX_COL_PINS { A1, A2, A3, A4, A5, A6, A7, A8, A9, B3, A10, A12, A0 }
#define UNUSED_PINS
