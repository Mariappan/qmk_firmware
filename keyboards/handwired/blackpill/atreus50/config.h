#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0x1209
#define PRODUCT_ID      0xA1E5
#define DEVICE_VER      0x0001

#define MANUFACTURER    QMK
#define PRODUCT         Atreus50 Keyboard
#define DESCRIPTION     QMK keyboard firmware for Atreus

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 13
#define DIODE_DIRECTION COL2ROW

#define MATRIX_ROW_PINS { A0, A1, A3, A2 }
#define MATRIX_COL_PINS { B13, B14, B15, A8, A9, A10, B12, A4, A5, A6, A7, B1, B0 }
#define UNUSED_PINS
