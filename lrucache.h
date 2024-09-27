#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#ifndef LRU_CACHE_H
#define LRU_CACHE_H

typedef struct LRU_cache {
    int val; int steps; int last_used;
} LRU_cache;

void init_lru_cache(LRU_cache* cache, int size) {
    for (int i = 0; i < size; i++) {
        cache[i].val = 0;
        cache[i].steps = 0;
        cache[i].last_used = i;
    }
}

void update_lru_cache(LRU_cache* cache, int size, int val, int steps, int* counter) {
    int index_of_lowest=0;
    int lowest=cache[0].last_used;
    for (int y = 0; y < size; y++) {
        if (cache[y].last_used < lowest) {
            lowest=cache[y].last_used;
            index_of_lowest=y;
        }
    }
    cache[index_of_lowest].val = val;
    cache[index_of_lowest].steps = steps;
    cache[index_of_lowest].last_used = *counter;
    (*counter)++;
}

bool lookup_lru_cache(LRU_cache* cache, int size, int val){
    for (int i = 0; i < size; i++){
        if(cache[i].val==val){
        return true;
        }
    }
    return false;
}

#endif
