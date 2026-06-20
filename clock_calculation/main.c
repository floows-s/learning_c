#include <stdio.h>

/*
    In this program I demonstrate a clock wrap around using the modulo. 
    By using modulo i can ensure the result stays between 0 & 23.
    This effectively simulates how a clock rolls over to zero after reaching midnight.
*/

int main(){
    int current_time = 21;
    int time_passed = 6;

    int new_time = (current_time + time_passed) % 24;

    printf("Current time: %02d:00\n", current_time);
    printf("Time passed (hours): %d\n", time_passed);
    printf("New time: %02d:00\n", new_time);

    return 0;
}