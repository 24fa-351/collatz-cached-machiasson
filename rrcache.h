#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#ifndef RR_CACHE_H
#define RR_CACHE_H

typedef struct RR_cache {
    int val; int steps;
} RR_cache;

void init_rr_cache(RR_cache* cache, int size) {
    for (int i = 0; i < size; i++) {
        cache[i].val = 0;
        cache[i].steps = 0;
    }
}

void update_rr_cache(RR_cache* cache, int size, int val, int steps) {
    int index=rand() % size;
    cache[index].val = val;
    cache[index].steps = steps;
}

bool lookup_rr_cache(RR_cache* cache, int size, int val){
    for (int i = 0; i < size; i++){
        if(cache[i].val==val){
        return true;
        }
    }
    return false;
}

#endif
