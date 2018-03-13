#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "osct_decoder.h"

void decode_value_for_typetag(char* value, osc_type type, void* output) {
    switch(type) {
        case OSC_INT32:
        case OSC_RGBA:
        case OSC_MIDI:
            decode_int32(value, (int32_t*)output);
            break;
        case OSC_FLOAT32:
            decode_float32(value, (float*)output);
            break;
        case OSC_TIMETAG:
        case OSC_INT64:
            decode_int64(value, (int64_t*)output);
            break;
        case OSC_DOUBLE:
            decode_double(value, (double*)output);
            break;
        case OSC_STRING:
            decode_osc_string(value, output);
            break;
        case OSC_BLOB:
            decode_osc_blob(value, output);
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

void decode_int32(char* value, int32_t* output) {
    osc32_t converter;
    memcpy(converter.b, value, sizeof(osc32_t));
    converter.u = ntohl(converter.u);
    memcpy(output, &converter.i, sizeof(osc32_t));
}

void decode_float32(char* value, float* output) {
    osc32_t converter;
    memcpy(converter.b, value, sizeof(osc32_t));
    converter.u = ntohl(converter.u);
    memcpy(output, &converter.f, sizeof(osc32_t));
}

void decode_int64(char* value, int64_t* output) {
    osc64_t converter;
    memcpy(converter.b, value, sizeof(osc64_t));
    converter.u = ntohll(converter.u);
    memcpy(output, &converter.i, sizeof(osc64_t));
}

void decode_double(char* value, double* output) {
    osc64_t converter;
    memcpy(converter.b, value, sizeof(osc64_t));
    converter.u = ntohll(converter.u);
    memcpy(output, &converter.f, sizeof(osc64_t));
}

void decode_osc_string(char* value, char* output) {
    memcpy(output, value, strlen(value));
}

void decode_osc_blob(char* value, osc_blob* output) {
    decode_int32(value, (int32_t*)&output->size);
    // we assigning a pointer to the data bellow, but
    // what if the input data will be deallocated?
    output->data = value+sizeof(output->size); 
}
