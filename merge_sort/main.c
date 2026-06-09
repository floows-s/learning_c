#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_arr(size_t size, int arr[size]);
void merge_sort(size_t size_a, int a[size_a], int* output);
void merge(size_t size_a, int a[size_a], size_t size_b, int b[size_b], int* output);
bool test(int size_input, int input[size_input], int size_expected, int expected[size_expected], bool print_result);

int main (){
    int test_values[] = {2, 5, 9, 4, 3};
    int size_test_values = sizeof(test_values) / sizeof(test_values[0]);
    
    int expected[] = {2, 3, 4, 5, 9};
    int size_expected = sizeof(expected) / sizeof(expected[0]);

    int result[size_test_values];

    merge_sort(size_test_values, test_values, result);

    test(sizeof(result) / sizeof(result[0]), result, size_expected, expected, true);

    return 0;
} 

bool test(int size_input, int input[size_input], int size_expected, int expected[size_expected], bool print_result){
    if(print_result){
        printf("--- Test ---\n");
    }

    if(size_input != size_expected){
        if(print_result){
            printf("Test has failed\n Input size is not equal to the expected size\n");
            printf(
                "Input size: %d | Expected size: %d\n", 
                size_input,
                size_expected
            );
        }

        return false;
    }

    if(print_result){
        printf("RESULT [Index]: Input | Expected\n");
    }

    bool has_passed_test = true;
    for(int i = 0; i < size_input; i++){
        bool is_as_expected = input[i] == expected[i];

        if(!is_as_expected){
            has_passed_test = false;
        }

        if(print_result){
            printf(
                "%s [%d]: %d | %d \n",
                (is_as_expected ? "PASSED" : "FAILED"),
                i,
                input[i],
                expected[i]
            );
        }
    }

    return has_passed_test;
}


void merge_sort(size_t size_a, int a[size_a], int* output){
    // Split to 1 element
    if(size_a == 1){
        memcpy(output, a, 1 * sizeof(int));
        return;
    }

    size_t half = size_a / 2;
    
    // Sort left side
    size_t arr_one_size = half;
    int arr_one[arr_one_size];
    merge_sort(arr_one_size, a, arr_one);
    
    // Sort right side
    size_t arr_two_size = size_a - half;
    int arr_two[arr_two_size];
    merge_sort(arr_two_size, &a[arr_one_size], arr_two);

    // Merge two sorted arrays together
    size_t merged_size = arr_one_size + arr_two_size;
    int merged[merged_size];
    merge(arr_one_size, arr_one, arr_two_size, arr_two, merged);

    // Return merged array
    memcpy(output, merged, merged_size * sizeof(int));
}

void merge(size_t size_a, int a[size_a], size_t size_b, int b[size_b], int* output){
    size_t merged_size = size_a + size_b;
    int merged[merged_size];
    
    int m_i = 0, a_i = 0, b_i = 0;
    while(a_i < size_a && b_i < size_b){
        if(a[a_i] <= b[b_i]){
            merged[m_i] = a[a_i];
            a_i++;
        }else{
            merged[m_i] = b[b_i];
            b_i++;
        }

        m_i++;
    }

    // Copy rest to the array
    if(a_i < size_a){
        memcpy(
            &merged[m_i], 
            (a + a_i),
            (size_a - a_i) * sizeof(int)
        );
    }

    if(b_i < size_b){
        memcpy(
            &merged[m_i], 
            (b + b_i),
            (size_b - b_i) * sizeof(int)
        );
    }

    printf("Merged\n");
    print_arr(merged_size, merged);

    memcpy(output, merged, merged_size * sizeof(int));
}

void print_arr(size_t size, int arr[size]){
    for(int i=0; i<size; i++){
        printf("[%d]: %d\n", i, arr[i]);
    }
}