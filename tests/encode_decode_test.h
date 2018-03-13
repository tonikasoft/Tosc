TEST decode_encode_int32() {
    char o[20];
    int32_t in = 123456789;
    int32_t out;

    encode_int32(in, o);
    decode_int32(o, &out);

    ASSERT_EQ(in, out);

    PASS();
}

TEST decode_encode_float32() {
    char o[20];
    float in = 234234.2348120;
    float out;

    encode_float32(in, o);
    decode_float32(o, &out);

    ASSERT_EQ(in, out);

    PASS();
}

TEST decode_encode_int64() {
    char o[20];
    int64_t in = 1234567893434222;
    int64_t out;

    encode_int64(in, o);
    decode_int64(o, &out);

    ASSERT_EQ(in, out);

    PASS();
}

TEST decode_encode_double() {
    char o[20];
    double in = 234234.2348232321120;
    double out;

    encode_double(in, o);
    decode_double(o, &out);

    ASSERT_EQ(in, out);

    PASS();
}

TEST decode_encode_string() {
    char o[20];
    const char* in = "hello world";
    char out[20];

    encode_osc_string((char*)in, o);
    decode_osc_string(o, out);

    ASSERT_STRN_EQ(in, out, strlen(in));

    PASS();
}

TEST decode_encode_blob() {
    char o[20];
    osc_blob in = {11, "hello world"};
    osc_blob out;

    encode_osc_blob(&in, o);
    decode_osc_blob(o, &out);

    ASSERT_EQ(in.size, out.size);
    ASSERT_STRN_EQ(in.data, out.data, in.size);

    PASS();
}

TEST encode_decode_message() {
    osc_packet packet;

    encode_message(&packet, "/hello/world", "iff", 10, 1.23, 34.556);

    printf("%lu\n", packet.size);
    
    fwrite(packet.content, 1, packet.size, stdout);

    puts("");

    SKIP();
}

SUITE(encode_decode) {
    RUN_TEST(decode_encode_int32);
    RUN_TEST(decode_encode_float32);
    RUN_TEST(decode_encode_int64);
    RUN_TEST(decode_encode_double);
    RUN_TEST(decode_encode_string);
    RUN_TEST(decode_encode_blob);
    RUN_TEST(encode_decode_message);
}
