/*
 * aes-cmac.h: AES Cipher-based Message Authentication Code (AES-CMAC)
 *
 * https://github.com/andrebdo/c-crumbs/blob/master/aes-cmac.h
 *
 * This is free and unencumbered software released into the public domain.
 * For more information, please refer to UNLICENSE or https://unlicense.org
 */

/*
 * Computes the MAC (message authentication code) of a message
 * as described in RFC 4493 The AES-CMAC Algorithm.
 *
 * Uses the aes_encrypt function in aes.h, so you need to include that too:
 * #include "aes.h"
 * #include "aes-cmac.h"
 *
 * mac: pointer to 16 bytes to store the computed MAC
 * key: pointer to the 16-byte (128-bit) AES key
 * message: pointer to the input message
 * length: number of bytes of the message
 */
static void aes_cmac(void *mac, const void *key, const void *message, int length) {
  static const unsigned char zero[16] = { 0 };
  unsigned char l[16];
  unsigned char *m, *x, *y;
  int i, k1, k2;

  /* Generate_Subkey Step 1. L := AES-128(K, const_Zero) */
  aes_encrypt(l, zero, key);

  /* AES-CMAC Step 5. X := const_Zero */
  x = (unsigned char *)zero;

  /* AES-CMAC Step 6 */
  m = (unsigned char *)message;
  y = (unsigned char *)mac;
  if (length > 16) {
    /* X := AES-128(K,Y) */
    aes_encrypt(y, m, key);
    x = y;
    m += 16;
    length -= 16;
    while (length > 16) {
      /* Y := X XOR M_i */
      for (i = 0; i < 16; i++) {
        y[i] ^= m[i];
      }
      /* X := AES-128(K,Y) */
      aes_encrypt(y, y, key);
      m += 16;
      length -= 16;
    }
  }

  if (length == 16) {
    /*
     * Generate_Subkey Step 2. K1 := ...
     * AES-CMAC Step 4. M_last := M_n XOR K1
     * AES-CMAC Step 6. Y := M_last XOR X
     */
    for (i = 0; i < 15; i++) {
      k1 = l[i] << 1 | l[i + 1] >> 7;
      y[i] = k1 ^ m[i] ^ x[i];
    }
    y[15] = (l[15] << 1) ^ m[15] ^ x[15];
    if (l[0] & 0x80) {
      y[15] ^= 0x87;
    }
  } else {
    /*
     * Generate_Subkey Step 3. K2 := ...
     * AES-CMAC Step 4. M_last := padding(M_n) XOR K2
     * AES-CMAC Step 6. Y := M_last XOR X
     */
    for (i = 0; i < length; i++) {
      k2 = l[i] << 2 | l[i + 1] >> 6;
      y[i] = k2 ^ m[i] ^ x[i];
    }
    for (; i < 15; i++) {
      k2 = l[i] << 2 | l[i + 1] >> 6;
      y[i] = k2 ^ x[i];
    }
    y[length] ^= 0x80;
    y[15] = (l[15] << 2) ^ x[15];
    if (l[0] & 0x80) {
      y[14] ^= 1;
      y[15] ^= 0x0E;
    }
    if (l[0] & 0x40) {
      y[15] ^= 0x87;
    }
  }

  /*
   * AES-CMAC Step 6. T := AES-128(K,Y)
   * AES-CMAC Step 7. return T
   */
  aes_encrypt(y, y, key);
}
