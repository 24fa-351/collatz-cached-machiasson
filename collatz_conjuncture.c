#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "lrucache.h"
#include "rrcache.h"

int collatz_steps(int n) {
    int steps = 0;
    while (n!=1) {
        if (n%2==0) {
            n=n/2;
        } else {
            n=3*n+1;
        }
        steps++;
    }
    return steps;
}

int main(int argc, char *argv[]) {
    LRU_cache lru_cache[100];
    RR_cache rr_cache[100];
    int cache_size = atoi(argv[5]);
    if (strcmp(argv[4], "LRU") == 0) {
        init_lru_cache(lru_cache, cache_size);
    } else if (strcmp(argv[4], "RR") == 0) {
        init_rr_cache(rr_cache, cache_size);
    } else {
        //nothing 
    }
    int counter=cache_size, N = atoi(argv[1]), MIN = atoi(argv[2]), MAX = atoi(argv[3]);
    double hits=0.0, total=0.0;
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        int RN = MIN + rand() % (MAX - MIN + 1);
        int steps = collatz_steps(RN);
        printf("%d,%d\n", RN, steps);
        if (strcmp(argv[4], "LRU") == 0) {
            if(lookup_lru_cache(lru_cache, cache_size, RN)){
                hits=hits+1.0;
            }
        } else if (strcmp(argv[4], "RR") == 0) {
            if(lookup_rr_cache(rr_cache, cache_size, RN)){
                hits=hits+1.0;
            }
        }
        total=total+1.0;
        printf("%f\n",hits/total);
        if (strcmp(argv[4], "LRU") == 0) {
            update_lru_cache(lru_cache, cache_size, RN, steps, &counter);
        } else if (strcmp(argv[4], "RR") == 0) {
            update_rr_cache(rr_cache, cache_size, RN, steps);
        }
    }
    return 0;
}