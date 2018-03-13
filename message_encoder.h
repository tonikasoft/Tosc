#ifndef MESSAGE_ENCODER
#define MESSAGE_ENCODER 1
#include <stdarg.h>
#include "osc_t.h"

void encode_message(osc_packet* out_packet, 
        const char* address_pattern, 
        const char* typetag, 
        ...);

size_t encode_arguments(const char* typetag, va_list ap, char* buffer);
size_t encode_argument_for_type(va_list ap, osc_type type, char* buffer);

size_t encode_int32(int32_t value, char* buf);
size_t encode_float32(float value, char* buf);
size_t encode_int64(int64_t value, char* buf);
size_t encode_double(double value, char* buf);
size_t encode_osc_string(char* value, char* buf);
size_t encode_osc_blob(osc_blob* blob, char* buf);

size_t strlen_to_osc_strlen(size_t len);
inline size_t get_max_size_for_message(const char* address_pattern, const char* typetag);

#endif
