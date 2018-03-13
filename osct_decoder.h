#ifndef OSCT_DECODER
#define OSCT_DECODER 1
#include "osc_t.h"

void decode_value_for_typetag(char* value, osc_type type, void* output);

void decode_int32(char* value, int32_t* output);
void decode_float32(char* value, float* output);
void decode_int64(char* value, int64_t* output);
void decode_double(char* value, double* buf);
void decode_osc_string(char* value, char* output);
void decode_osc_blob(char* value, osc_blob* output);

#endif
