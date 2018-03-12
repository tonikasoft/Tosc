#include <stdlib.h>
#include <stdio.h>
#include "osct_encoder.h"
#include "osct_decoder.h"
#include "greatest/greatest.h"

TEST decode_encode_int32() {
    char o[20];
    int32_t in = 123456789;
    int32_t out;

    encode_value_for_typetag(&in, 'i', o);
    decode_value_for_typetag(o, 'i', &out);

    ASSERT_EQ(in, out);

    PASS();
}

TEST decode_encode_float32() {
    char o[20];
    float in = 234234.2348120;
    float out;

    encode_value_for_typetag(&in, 'f', o);
    decode_value_for_typetag(o, 'f', &out);

    ASSERT_EQ(in, out);

    PASS();
}

TEST decode_encode_int64() {
    char o[20];
    int64_t in = 1234567893434222;
    int64_t out;

    encode_value_for_typetag(&in, 'h', o);
    decode_value_for_typetag(o, 'h', &out);

    ASSERT_EQ(in, out);

    PASS();
}

TEST decode_encode_double() {
    char o[20];
    double in = 234234.2348232321120;
    double out;

    encode_value_for_typetag(&in, 'd', o);
    decode_value_for_typetag(o, 'd', &out);

    ASSERT_EQ(in, out);

    PASS();
}

TEST decode_encode_string() {
    char o[20];
    const char* in = "hello world";
    char out[20];

    encode_value_for_typetag((void*)in, 's', o);
    decode_value_for_typetag(o, 's', out);

    ASSERT_STRN_EQ(in, out, strlen(in));

    PASS();
}

TEST decode_encode_blob() {
    char o[20];
    osc_blob in = {11, "hello world"};
    osc_blob out;

    encode_value_for_typetag(&in, 'b', o);
    decode_value_for_typetag(o, 'b', &out);

    ASSERT_EQ(in.size, out.size);
    ASSERT_STRN_EQ(in.data, out.data, in.size);

    PASS();
}

SUITE(decode_encode) {
    RUN_TEST(decode_encode_int32);
    RUN_TEST(decode_encode_float32);
    RUN_TEST(decode_encode_int64);
    RUN_TEST(decode_encode_double);
    RUN_TEST(decode_encode_string);
    RUN_TEST(decode_encode_blob);
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
    GREATEST_MAIN_BEGIN();

    RUN_SUITE(decode_encode);

    GREATEST_MAIN_END();
}
