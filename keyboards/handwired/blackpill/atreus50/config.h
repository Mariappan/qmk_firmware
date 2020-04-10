#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0xBEEF
#define DEVICE_VER      0x0001

#define MANUFACTURER "QMK"
#define PRODUCT "Atreus 50 Keyboard"
#define DESCRIPTION "Atreus layout with extra column"

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 13
#define DIODE_DIRECTION COL2ROW

#define MATRIX_ROW_PINS { D3, D2, D1, D0 }
#define MATRIX_COL_PINS { D4, D7, E6, B4, B5, B6, B2, B3, B1, F7, F6, F5, F4 }
#define UNUSED_PINS

// Iso fix for Space Cadet, comment for ANSI layouts
#define LSPO_KEY KC_8
#define RSPC_KEY KC_9
