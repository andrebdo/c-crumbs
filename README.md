# c-crumbs

Small pieces of standalone ANSI C code that you can use in your programs simply by grabbing the desired .h file and #including it from your C or C++ code, inspired by Sean Barrett's [stb](https://github.com/nothings/stb) libraries.

## Contents

* aes.h: Advanced Encryption Standard (AES) algorithm
* aes-ccm.h: AES Counter CBC MAC (AES-CCM) algorithm
* aes-cmac.h: AES Cipher-based Message Authentication Code (AES-CMAC)
* aes-gcm.h: AES Galois/Counter Mode (AES-GCM) algorithm
* aes-kw.h: AES Key Wrap (AES-KW) algorithm
* aes-mmo.h: AES Matyas-Meyer-Oseas (AES-MMO) hash function
* base64.h: base 64 encoding
* sha1.h: Secure Hash Algorithm 1 (SHA-1)
* sha256.h: Secure Hash Algorithm 256 (SHA-256)

## Usage

1. Copy the .h file you want into your program's directory
2. #include it in one of your C or C++ source code files

## Tests

sh tests/run.sh tests/*.c

## License

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>
