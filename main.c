#include <stdio.h>
#include "osct_encoder.h"

int main() {
    /* int val = -112110; */
    const char* s = "hello world";

    /* const char* out = encode_value_for_typetag(&val, OSC_INT32); */
    const char* out = encode_value_for_typetag((void *)s, OSC_STRING);

    printf("%s\n", out);
    printf("%lu\n", strlen(out));

    return 0;
}
