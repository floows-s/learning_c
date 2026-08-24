#include <stdio.h>
#include "structs.h"

/*
    An exercise from the book Modern C: Third Edition

    Create six different structure types for each possibility to order three fields inside a structure: 
    one unsigned char, one unsigned, and one unsigned long long. Print the sizes of these six structures; they should be significantly different. 
    
    Compute the minimal size as the sum of the sizes of each member. 
    
    Does any of your structure have this size? Which of your structures comes closest to that ideal size?

    Topics: byte-padding, alignment  
*/



size_t print_size(void * val);

int main(){
    // Setup
    struct_1 s1;
    struct_2 s2;
    struct_3 s3;
    struct_4 s4;
    struct_5 s5;
    struct_6 s6;

    size_t sizes[6] = {sizeof(s1), sizeof(s2), sizeof(s3), sizeof(s4), sizeof(s5), sizeof(s6)};

    // Calculate closest
    // Note: i know this doesn't keep into account more then 1 size that is closest, but at this moment i dont care
    int curr_closest_to_min_size_index = -1;
    int curr_closest_to_min_size_delta = -1;

    for(int i = 0; i < 6; i++){        
        printf("Struct %d: %zu bytes\n", 
            i + 1, 
            sizes[i]
        );

        int delta_to_min_size = sizes[i] - MINIMAL_SIZE;

        if(delta_to_min_size < curr_closest_to_min_size_delta || 
           curr_closest_to_min_size_delta == -1 // -1 -> Means not set
        ){
            
            curr_closest_to_min_size_delta = delta_to_min_size;
            curr_closest_to_min_size_index = i;
        }

    }
    printf("-----------------------------------\n\n");


    // Print result
    printf("Minimal size: %zu bytes (sum of members)\n", MINIMAL_SIZE);
    printf("Closest to minimal size: \n");
    printf("Struct %d | Bytes: %zu\n", 
        curr_closest_to_min_size_index + 1,
        sizes[curr_closest_to_min_size_index]
    );

    return 0;
}
