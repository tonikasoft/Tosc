#ifndef OSCT_ENCODER
#define OSCT_ENCODER 1
#include "osc_t.h"

void encode_value_for_typetag(void* value, osc_typetag typetag, char* output);

void encode_int32(int32_t value, char* buf);
void encode_float32(float value, char* buf);
void encode_int64(int64_t value, char* buf);
void encode_double(double value, char* buf);
void encode_osc_string(char* value, char* buf);
// const char* encode_blob(char* value);

#endif
