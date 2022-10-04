#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

#define SS_IF_SHIFT(c, s) ((get_mods() & ((MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)))) ? SEND_STRING(c) : SEND_STRING(s))

void compose_int_char(int, int, int);

// Compose key style international characters for use with US (ANSI) layout
#define C_SE_AA
#define C_SE_AE
#define C_SE_OSLH

// void my_custom_function(void);

#endif
