/** @} */

/**
 * PEC15 CRC function
 *
 * This function takes an a pointer to uint8_t data and a length.
 * The function returns the PEC15 CRC value.
 * Run this function on the receiver and compare the CRC to check for errors.
 */

int16_t pec15Table[256];
int16_t CRC15_POLY = 0x4599;

/** PEC result value union */
typedef union
{
	struct
	{
		uint8_t BYTE0;
		uint8_t BYTE1;
	} Bytes;
	uint16_t All;
} PEC_Result_S;

PEC_Result_S PEC_Result;

void PEC15_Init() {
	int16_t remainder;
	int i,bit;
	for (i=0; i < 256; i++) {
		remainder = i << 7;
		for (bit=8; bit > 0; --bit) {
			if (remainder & 0x4000) {
				remainder = ((remainder << 1));
				remainder = (remainder ^ CRC15_POLY);
			}
			else {
				remainder = ((remainder << 1));
			}
		}
		pec15Table[i] = remainder&0xFFFF;
	}
}

void PEC15(uint8_t *data, int len) {
	int16_t remainder, address;
	int i;
	remainder = 16;
	for (i=0; i < len; i++) {
		address = ((remainder >> 7) ^ data[i]) & 0xff;
		remainder = (remainder << 8 ) ^ pec15Table[address];
	}
	PEC_Result.All = (remainder*2);
}
