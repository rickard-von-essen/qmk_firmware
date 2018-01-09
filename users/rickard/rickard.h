#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

// Compose key style international characters for use with US (ANSI) layout
#define C_SE_AA
#define C_SE_AE
#define C_SE_OSLH

enum custom_keycodes {
  OS_LIN = 0,
  OS_WIN,
  OS_MAC,
};

void compose_int_char(int, int, int);

#endif
