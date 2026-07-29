#include <stdio.h>

/* NO AI HAS BEEN USED TO MAKE THIS CODE. MADE BY HUMANS. */

/*
    A practical number is a positive integer N such that all smaller positive integers can be represented as sums of distinct divisors of N. 
    For example, 12 is a practical number because all the numbers from 1 to 11 can be expressed as sums of the divisors of 12, which are 1, 2, 3, 4, and 6. 
    However, 10 is not a practical number, because 4 and 9 cannot be expressed as a sum of 1, 2, and 5.


    This program determines if a given number is an practical number or not.
*/


bool is_prime_number(int num);
bool is_practical_number(int num);

int main(){
    int test_case = 30;

    bool result = is_practical_number(test_case);

    printf("%d is%sa practical number!\n", 
        test_case,
        (result ? " " : " NOT ") 
    );

    return 0;
}

bool is_practical_number(int num){

    // Index is the divisor
    // Value tells if it is a valid divisor
    bool divisors[num] = {};
    int divisors_size = sizeof(divisors) / sizeof(divisors[0]);

    // Get divisors
    for(int i = 1; i < divisors_size; i++){
        divisors[i] = (num % i == 0);
    }

    for(int i = 1; i < divisors_size; i++){
        printf("[%i]: %s\n",
            i,
            divisors[i] ? "TRUE": "FALSE"
        );
    }

    // Test prime divisors for neighbor
    bool has_neighbour_checked = false;
    for(int i = 1; i < divisors_size; i++){
        if(!divisors[i] || !is_prime_number(i)){
            continue;
        }

        // If neighbor divisor DOESNT exist
        if(!divisors[i - 1]){
            return false;
        }

        has_neighbour_checked = true;
    }

    // If it hasnt gotten the neighbour checked -> no practical number
    if(!has_neighbour_checked){
        return false;
    }

    return true;
}


bool is_prime_number(int num){
    if(num <= 1){
        return false;
    }

    for(int i = 2; i<num; i++){
        if(num % i == 0){
            return false;
        }
    }

    return true;
}