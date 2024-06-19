// Copyright 2024 Ming-Gih Lam (@dcpedit)
// SPDX-License-Identifier: GPL-2.0-or-later
#include "quantum.h"

#define LED_LAYER_PIN A2
#define NUM_LAYER     1

void matrix_init_kb(void) {
  setPinOutput(LED_LAYER_PIN);
}

// Initialize your default layer
layer_state_t layer_state_set_kb(layer_state_t state) {
  if (IS_LAYER_ON_STATE(state, NUM_LAYER)) {
    writePinLow(LED_LAYER_PIN);
  }
  else {
    writePinHigh(LED_LAYER_PIN);
  }

  return state;
}
