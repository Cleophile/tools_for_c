#pragma once

#include <stdint.h>
#include "vector.h"

typedef struct {
    IntVector* heap;
} MaxHeap;

typedef struct {
    IntVector* heap;
} MinHeap;

MaxHeap* create_maxheap();

void maxheap_insert(MaxHeap* maxheap, int32_t value);
int32_t maxheap_popmax(MaxHeap* maxheap);

int32_t maxheap_max(MaxHeap* maxheap);

int32_t maxheap_heapsize(MaxHeap* maxheap);

MinHeap* create_minheap();

void minheap_insert(MinHeap* minheap, int32_t value);
int32_t minheap_popmin(MinHeap* minheap);

int32_t minheap_min(MinHeap* minheap);

int32_t minheap_heapsize(MinHeap* minheap);
