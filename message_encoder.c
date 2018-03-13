#include <stdlib.h>
#include "message_encoder.h"

void encode_message(osc_packet* out_packet,
        const char* address_pattern,
        const char* typetag,
        ...) {

    va_list ap;
    size_t buf_size = get_max_size_for_message(address_pattern, typetag);
    char* buffer = malloc(buf_size);
    memset(buffer, 0, buf_size);
    out_packet->size = 0;

    out_packet->size += encode_osc_string((char*)address_pattern, buffer);
    out_packet->size += encode_osc_string((char*)typetag, buffer+out_packet->size);
    
    va_start(ap, typetag);
    out_packet->size += encode_arguments(typetag, ap, buffer+out_packet->size);
    va_end(ap);

    out_packet->content = buffer;

    free(buffer);
}

size_t get_max_size_for_message(const char* address_pattern, const char* typetag) {
    size_t result = strlen(address_pattern) + 3;
    result += strlen(typetag) + 3;
    result += (strlen(typetag) * 8);
    return result;
}

size_t encode_arguments(const char* typetag, va_list ap, char* buffer) {
    int i;
    size_t result = 0;

    for(i = 0; typetag[i] != '\0'; i++) {
        result += encode_argument_for_type(ap, typetag[i], buffer + result);
    }

    return result;
}

size_t encode_argument_for_type(va_list ap, osc_type type, char* output) {
    osc32_t t32;
    osc64_t t64;

    switch(type) {
        case OSC_INT32:
        case OSC_RGBA:
        case OSC_MIDI:
            t32.i = va_arg(ap, int32_t);
            return encode_int32(t32.i, output);
        case OSC_FLOAT32:
            t32.f = (float) va_arg(ap, double);
            return encode_float32(t32.f, output);
        case OSC_TIMETAG:
        case OSC_INT64:
            t64.i = va_arg(ap, int64_t);
            return encode_int64(t64.i, output);
        case OSC_DOUBLE:
            t64.f = va_arg(ap, double);
            return encode_double(t64.f, output);
        case OSC_STRING:
            /* return encode_osc_string((char*)value, output); */
            return 0;
        case OSC_BLOB:
            /* return encode_osc_blob((osc_blob*)value, output); */
            return 0;
        case OSC_TRUE:
        case OSC_FALSE:
        case OSC_NIL:
        case OSC_INFINITUM:
        case OSC_UNSUPPORTED:
        default:
            return 0;
    }
}

size_t encode_int32(int32_t value, char* buf) {
    osc32_t converter;
    converter.i = value;
    converter.u = htonl(converter.u);
    memcpy(buf, converter.b, 4);
    
    return 4;
}

size_t encode_float32(float value, char* buf) {
    osc32_t converter;
    converter.f = value;
    converter.u = htonl(converter.u);
    memcpy(buf, converter.b, 4);

    return 4;
}

size_t encode_int64(int64_t value, char* buf) {
    osc64_t converter;
    converter.i = value;
    converter.u = htonll(converter.u);
    memcpy(buf, converter.b, 8);

    return 8;
}

size_t encode_double(double value, char* buf) {
    osc64_t converter;
    converter.f = value;
    converter.u = htonll(converter.u);
    memcpy(buf, converter.b, 8);

    return 8;
}

size_t encode_osc_string(char* value, char* buf) {
    memcpy(buf, value, strlen(value));
    return strlen_to_osc_strlen(strlen(value));
}

size_t strlen_to_osc_strlen(size_t len) {
    return len + (4-len%4);
}

size_t encode_osc_blob(osc_blob* blob, char* buf) {
    encode_int32((int32_t)blob->size, buf);
    memcpy(buf+4, blob->data, blob->size);

    return strlen_to_osc_strlen((size_t)blob->size) + 4;
}
