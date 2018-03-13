#include <stdlib.h>
#include <stdio.h>
#include "osct_decoder.h"
#include "message_encoder.h"
#include "greatest/greatest.h"
#include "encode_decode_test.h"

GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
    GREATEST_MAIN_BEGIN();

    RUN_SUITE(encode_decode);

    GREATEST_MAIN_END();
}
