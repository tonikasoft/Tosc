#include <string.h>
#include "osct_encoder.h"

const char* encode_value_for_typetag(void* value, osc_typetag typetag) {
    switch(typetag) {
        case OSC_INT32:
        case OSC_RGBA:
        case OSC_MIDI:
            return encode_int32(*((int32_t*)value));
        case OSC_FLOAT32:
            return encode_float32(*((float*)value));
        case OSC_TIMETAG:
        case OSC_INT64:
            return encode_int64(*((int64_t*)value));
        case OSC_DOUBLE:
            return encode_double(*((double*)value));
        case OSC_CHAR:
        case OSC_STRING:
            return (char*)value;
        case OSC_TRUE:
        case OSC_FALSE:
        case OSC_NIL:
        case OSC_INFINITUM:
        case OSC_UNSUPPORTED:
        default:
            return "";
    }
}

const char* encode_int32(int32_t value) {
    static osc32_t converter;
    converter.i = value;
    converter.u = htonl(converter.u);
    return converter.b;
}

const char* encode_float32(float value) {
    static osc32_t converter;
    converter.f = value;
    converter.u = htonl(converter.u);
    return converter.b;
}

const char* encode_int64(int64_t value) {
    static osc64_t converter;
    converter.i = value;
    converter.u = htonll(converter.u);
    return converter.b;
}

const char* encode_double(double value) {
    static osc64_t converter;
    converter.f = value;
    converter.u = htonll(converter.u);
    return converter.b;
}
