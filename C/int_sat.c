/** @} */

/**
 * Integer saturation function
 *
 * This function takes an interger input, a min, a max
 * and returns the same values if it is within min and max
 * or returns the min if less than min, or max if greater than max.
 * If the value is outside the min or max the valid pointer is set to zero.
 */

int Int_Sat(int input, int min, int max, uint8_t *valid) {
  if (input > max) {
    *valid = 0;
    return max;
  } else if (input < min) {
    *valid = 0;
    return min;
  } else {
    *valid = 1;
    return input;
  }
}
