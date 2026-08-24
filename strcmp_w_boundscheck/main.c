#include "stdio.h"
#include "string.h"

/*
    An exercise from the book Modern C: Third Edition

    Use memchr and memcmp to implement a bounds-checking version of strcmp.
*/

int strcmp_safe(size_t len, char const s0[len], char const s1[len]);

int main(){
    char const s0[] = {'a', 'b', 'c', 'X'};
    char const s1[] = {'a', 'b', 'c', '\0'};

    // This shouldt result in -1 (which i slopply used to indicate a error) and say that s0 is not null terminated 
    int result = strcmp_safe(4, s0, s1);

    printf("Result: %d\n", result);

    return 0;
}

int strcmp_safe(size_t len, char const s0[len], char const s1[len]){
    char const * s0_null_char = memchr(s0, '\0', len);
    if(s0_null_char == nullptr){
        printf("Error: s0 is not null terminated\n");
        return -1;
    }

    char const * s1_null_char = memchr(s1, '\0', len);
    if(s1_null_char == nullptr){
        printf("Error: s1 is not null terminated\n");
        return -1;
    }

    return memcmp(s0, s1, len);
}
