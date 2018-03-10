#ifndef OSCT_ENCODER
#define OSCT_ENCODER 1
#include "osc_t.h"

const char* encode_value_for_typetag(void* value, osc_typetag typetag);

const char* encode_int32(int32_t value);
const char* encode_float32(float value);
const char* encode_int64(int64_t value);
const char* encode_double(double value);
// const char* encode_blob(char* value);

#endif
