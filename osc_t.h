#ifndef OSC_T
#define OSC_T 1
#include <string.h>
#include <stdint.h>
#if _WIN32
#include <winsock2.h>
#define osc_strncpy(_dst, _src, _len) strncpy_s(_dst, _len, _src, _TRUNCATE)
#else
#include <netinet/in.h>
#define osc_strncpy(_dst, _src, _len) strncpy(_dst, _src, _len)
#endif
#if __unix__ && !__APPLE__
#include <endian.h>
#define htonll(x) htobe64(x)
#define ntohll(x) be64toh(x)
#endif

typedef enum {
    OSC_INT32     = 'i',
    OSC_FLOAT32   = 'f',
    OSC_STRING    = 's',
    OSC_BLOB      = 'b',
    OSC_INT64     = 'h',
    OSC_TIMETAG   = 't',
    OSC_DOUBLE    = 'd',
    OSC_CHAR      = 'c',
    OSC_RGBA      = 'r',
    OSC_MIDI      = 'm',
    OSC_TRUE      = 'T',
    OSC_FALSE     = 'F',
    OSC_NIL       = 'N',
    OSC_INFINITUM = 'I',
    OSC_UNSUPPORTED
} osc_typetag;

typedef union {
    int32_t i;
    float f;
    uint32_t u;
    char c;
    char b[4];
} osc32_t;

typedef union {
    int64_t i;
    double f;
    uint64_t u;
    char b[8];
} osc64_t;

typedef struct {
    uint32_t size;
    char* data;
} osc_blob;

#endif
