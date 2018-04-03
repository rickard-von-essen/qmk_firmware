#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

void compose_int_char(int, int, int);

// Compose key style international characters for use with US (ANSI) layout
#define C_SE_AA compose_int_char(
#define C_SE_AE
#define C_SE_OSLH

enum custom_keycodes {
  C_OS_LIN = 0,
  C_OS_WIN,
  C_OS_MAC,
};


#endif
