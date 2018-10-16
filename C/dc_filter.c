#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

uint16_t dc_estimator(int32_t *p, uint16_t x) {
        uint16_t z;
        /* Noise shaped DC estimator. */
        *p += ((((int32_t) x << 16) - *p) >> 7);
        z = (*p >> 16);
        if (x < z) {
                *p = (*p&0xFFFF) | ((int32_t)x<<16);
                return x;
        }
        return z;
}

uint16_t GetADC_Values()
{
  return (rand()%0xFFFF)+2);
}

int32_t signal_dc_component;
uint16_t adc_value;

void main(void)
{
  uint8_t count=0;
  srand(time(NULL));
  while(count > 100){
    count++;
    signal_dc_component = dc_estimator(&signal_dc_component, GetADC_Values());
  }
}
