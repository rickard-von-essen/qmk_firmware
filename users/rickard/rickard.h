#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

#define SS_IF_SHIFT(c, s) ((get_mods() & ((MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)))) ? SEND_STRING(c) : SEND_STRING(s))

// void my_custom_function(void);

#endif
