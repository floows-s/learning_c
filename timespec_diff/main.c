#include "time.h"

/*
    An exercise from the book: Modern C: Third Edition

    Write a function timespec_diff that computes the difference between two timespec values.
*/


typedef struct timespec timespec;

timespec timespec_diff(timespec t0, timespec t1);

int main(){
    const timespec t0 = {.tv_sec = 10, .tv_nsec = 0};
    const timespec t1 = {.tv_sec = 5, .tv_nsec = 1};


    const timespec diff = timespec_diff(t0, t1);

    printf("Difference: %d seconds and %ld nano seconds\n",
        diff.tv_sec, 
        diff.tv_nsec
    );

    return 0;
}

timespec timespec_diff(timespec t0, timespec t1){
    time_t sec_diff = 0;
    long nsec_diff = 0;

    nsec_diff = t0.tv_nsec - t1.tv_nsec;
    if(nsec_diff < 0){
        nsec_diff += 1000000000;
        sec_diff--;
    }

    sec_diff += t0.tv_sec - t1.tv_sec;

    return (timespec) {
        .tv_sec = sec_diff,
        .tv_nsec = nsec_diff
    };
}
