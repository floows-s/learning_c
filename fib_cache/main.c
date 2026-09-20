#include <stdio.h>
#include <assert.h>

typedef unsigned long long ULL;

ULL fib_cache_lookup(int n, ULL cache[n]);
ULL fib_cache(int n);
ULL fib(int n);

void print_cache(size_t size, ULL cache[size]);

int main(){
    int n = 43;

    ULL result = fib_cache(n);

    // ULL result = fib(n);

    printf("%llu\n", result);

    return 0;
}

ULL fib(int n){
    if(n < 3){
        return 1;
    }

    return fib(n - 1) + fib(n - 2);
}


ULL fib_cache_lookup(int n, ULL cache[n]){
    int n_index = n - 1;

    // Look if is in cache
    if(!cache[n_index]){
        // If not -> calculate value and put in cache
        cache[n_index] = fib_cache_lookup(n - 1, cache) + fib_cache_lookup(n - 2, cache);
    }

    // Note: this printing makes it slower, its just for fun
    // print_cache(n, cache);

    return cache[n_index];
}

ULL fib_cache(int n){
    assert(n > 0);
    
    ULL cache[n] = {};

    cache[0] = 1;
    cache[1] = 1;

    return fib_cache_lookup(n, cache);
}

void print_cache(size_t size, ULL cache[size]){
    for(int i = 0; i < size; i++){
        if(cache[i] != 0){
            printf("[%d]: %llu\n", 
                i,
                cache[i]
            );
        }
    }
}