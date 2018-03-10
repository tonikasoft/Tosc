#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "osct_encoder.h"

void encode_value_for_typetag(void* value, osc_typetag typetag, char* output) {
    switch(typetag) {
        case OSC_INT32:
        case OSC_RGBA:
        case OSC_MIDI:
            encode_int32(*((int32_t*)value), output);
            break;
        case OSC_FLOAT32:
            encode_float32(*((float*)value), output);
            break;
        case OSC_TIMETAG:
        case OSC_INT64:
            encode_int64(*((int64_t*)value), output);
            break;
        case OSC_DOUBLE:
            encode_double(*((double*)value), output);
            break;
        case OSC_STRING:
            encode_osc_string((char*)value, output);
            break;
        case OSC_BLOB:
            encode_osc_blob((osc_blob*)value, output);
            break;
        case OSC_TRUE:
        case OSC_FALSE:
        case OSC_NIL:
        case OSC_INFINITUM:
        case OSC_UNSUPPORTED:
        default:
            break;
    }
}

void encode_int32(int32_t value, char* buf) {
    osc32_t converter;
    converter.i = value;
    converter.u = htonl(converter.u);
    memcpy(buf, converter.b, 4);
}

void encode_float32(float value, char* buf) {
    osc32_t converter;
    converter.f = value;
    converter.u = htonl(converter.u);
    memcpy(buf, converter.b, 4);
}

void encode_int64(int64_t value, char* buf) {
    osc64_t converter;
    converter.i = value;
    converter.u = htonll(converter.u);
    memcpy(buf, converter.b, 8);
}

void encode_double(double value, char* buf) {
    osc64_t converter;
    converter.f = value;
    converter.u = htonll(converter.u);
    memcpy(buf, converter.b, 8);
}

void encode_osc_string(char* value, char* buf) {
    /* size_t s = strlen(value); */
    /* size_t output_s = s + (4-s%4); */
    memcpy((void*)buf, (void*)value, strlen(value));
}

void encode_osc_blob(osc_blob* blob, char* buf) {
    char blob_size[4];
    encode_int32((int32_t)blob->size, blob_size);
    strncat(buf, blob_size, 4);
    strcat(buf, blob->data);
}
