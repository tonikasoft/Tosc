#include <stdlib.h>
#include <stdio.h>
#include "osct_encoder.h"

int main() {
    /* int64_t val = -11211343434340; */
    char o[20];
    /* const char* s = "hello world"; */
    osc_blob b = {11, "hello world"};

    encode_value_for_typetag((void*)(&b), 'b', o);

    printf("%s\n", o);
    printf("%lu\n", strlen(o));

    return 0;
}
