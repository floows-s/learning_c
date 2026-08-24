#define MINIMAL_SIZE (sizeof(unsigned char) + sizeof(unsigned long long) + sizeof(unsigned))

typedef struct {
    unsigned char uc;
    unsigned u;
    unsigned long long ull;
} struct_1;

typedef struct {
    unsigned u;
    unsigned char uc;
    unsigned long long ull;
} struct_2;

typedef struct {
    unsigned u;
    unsigned long long ull;
    unsigned char uc;
} struct_3;

typedef struct {
    unsigned long long ull;
    unsigned u;
    unsigned char uc;
} struct_4;

typedef struct {
    unsigned long long ull;
    unsigned char uc;
    unsigned u;
} struct_5;

typedef struct {
    unsigned char uc;
    unsigned long long ull;
    unsigned u;
} struct_6;