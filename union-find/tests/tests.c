#include "tests.h"
#include <assert.h>
#include <string.h>

/*
    Two trees

    1.  Root [0]
        Nodes [1, 2, 3, 7, 8, 9]

    2.  Root [6]
        Nodes [4, 5]

    Total: 10 elements
*/

void init_parent_test(size_t parent_size, size_t parent[parent_size]){
    size_t test_values[] = { __SIZE_MAX__, 0, 1, 2, 
                             6, 4, __SIZE_MAX__, 
                             3, 2, 1
                            };

    size_t test_values_size = sizeof(test_values) / sizeof(test_values[0]);
    assert(test_values_size == parent_size); // Note: This is not a proper way to do it, i know, but for this test program its okay
    
    memcpy(
        parent,
        test_values,
        parent_size * sizeof(parent[0])
    );
}

bool test_findroot(size_t parent_size, const size_t parent[parent_size], size_t handler(size_t parent_size, const size_t parent[parent_size], size_t target)){
    printf("--- Find root ---\n");


    // SETUP
    // Node to find root of
    size_t target = 5;

    // Root index of target
    size_t expected = 6; 


    // TEST
    size_t result = handler(
        parent_size,
        parent,
        target
    );

    bool has_passed_test = result == expected;

    
    // RESULT
    printf("Target: %zu\n", target);
    printf("Expected index of root: %zu\n", expected);
    printf("Result: %zu | %s\n", 
        result,
        (has_passed_test ? "PASSED" : "FAILED")
    );
    
    return has_passed_test;
}


bool test_find_replace(size_t size, const size_t parent[size], void handler(size_t size, size_t parent[size], size_t entry_point, size_t value)){
     printf("--- Find replace ---\n");


    // SETUP
    size_t path_entry_point = 8;
    size_t replace_value = 69; // nice

    size_t expected[] = { 69, 69, 69, 2, 
                          6, 4, __SIZE_MAX__, 
                          3, 69, 1
                        };
    size_t expected_size = sizeof(expected) / sizeof(expected[0]);

    if(expected_size != size){
        printf("FAILED: the expected size is not equal to the result size\n");
        printf("Expected: %zu | Result: %zu\n",
            expected_size,
            size
        );

        return false;
    }

    // Copy over values so original doenst have to be modified
    size_t parent_copy[size];
    memcpy(parent_copy, parent, sizeof(parent[0]) * size);


    // TEST
    handler(
        size,
        parent_copy,
        path_entry_point,
        replace_value
    );

    bool has_passed_test = true;

    for(int i=0; i<size; i++){
        bool is_as_expected = parent_copy[i] == expected[i];
        
        if(!is_as_expected){
            has_passed_test = false;
        }

        printf("%s [%d] Expected: %zu | Result: %zu\n",
            (is_as_expected ? "PASSED" : "FAILED"),
            i,
            parent_copy[i],
            expected[i]
        );
    }

    // RESULT
    printf("Path entry point: %zu\n", path_entry_point);
    printf("Replace value: %zu\n", replace_value);
    printf("Result: %s\n", (has_passed_test ? "PASSED" : "FAILED"));
    
    return has_passed_test;
}

bool test_find_compress(size_t size, const size_t parent[size], size_t handler(size_t size, size_t parent[size], size_t target)){
    // SETUP
    size_t target = 3;

    size_t expected[] = { __SIZE_MAX__, 0, 0, 0, 
                          6, 4, __SIZE_MAX__, 
                          0, 0, 0
                        };
    size_t expected_size = sizeof(expected) / sizeof(expected[0]);

    if(expected_size != size){
        printf("FAILED: the expected size is not equal to the result size\n");
        printf("Expected: %zu | Result: %zu\n",
            expected_size,
            size
        );

        return false;
    }


    // Copy over values so original doenst have to be modified
    size_t parent_copy[size];
    memcpy(parent_copy, parent, sizeof(parent[0]) * size);


    // TEST
    handler(
        size,
        parent_copy,
        target
    );

    bool has_passed_test = true;
    for(int i=0; i<size; i++){
        bool is_as_expected = parent_copy[i] == expected[i];
        
        if(!is_as_expected){
            has_passed_test = false;
        }

        printf("%s [%d] Expected: %zu | Result: %zu\n",
            (is_as_expected ? "PASSED" : "FAILED"),
            i,
            expected[i],
            parent_copy[i]
        );
    }

    // RESULT
    printf("Target: %zu\n", target);
    printf("Result: %s\n", (has_passed_test ? "PASSED" : "FAILED"));
    
    return has_passed_test;
}

bool test_Union(size_t size, const size_t parent[size], size_t handler(size_t size, size_t parent[size], size_t target_1, size_t target_2)){
    // SETUP
    size_t target_1 = 3;
    size_t target_2 = 5;

    size_t expected[] = { __SIZE_MAX__, 0, 0, 0, 
                          0, 0, 0, 
                          0, 0, 0
                        };
    size_t expected_size = sizeof(expected) / sizeof(expected[0]);

    if(expected_size != size){
        printf("FAILED: the expected size is not equal to the result size\n");
        printf("Expected: %zu | Result: %zu\n",
            expected_size,
            size
        );

        return false;
    }


    // Copy over values so original doenst have to be modified
    size_t parent_copy[size];
    memcpy(parent_copy, parent, sizeof(parent[0]) * size);


    // TEST
    handler(
        size,
        parent_copy,
        target_1,
        target_2
    );

    bool has_passed_test = true;
    for(int i=0; i<size; i++){
        bool is_as_expected = parent_copy[i] == expected[i];
        
        if(!is_as_expected){
            has_passed_test = false;
        }

        printf("%s [%d] Expected: %zu | Result: %zu\n",
            (is_as_expected ? "PASSED" : "FAILED"),
            i,
            expected[i],
            parent_copy[i]
        );
    }

    // RESULT
    printf("Target 1: %zu\n", target_1);
    printf("Target 2: %zu\n", target_2);
    printf("Result: %s\n", (has_passed_test ? "PASSED" : "FAILED"));
    
    return has_passed_test;
}