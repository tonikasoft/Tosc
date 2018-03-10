#include <stdlib.h>
#include <stdio.h>
#include "osct_encoder.h"

int main() {
    char o[20];
    osc_blob b = {11, "hello world"};

    encode_value_for_typetag((void*)(&b), 'b', o);

    fwrite(o, 1, b.size+4, stdout);

    return 0;
}
