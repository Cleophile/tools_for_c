/*  
 * Created By Hikari Software
 *
 * Y-Enterprise
 *
 */

#include <stdlib.h>
#include "heap.h"

int32_t parent_(int32_t k) {
    return (k - 1) / 2;
}

int32_t left_(int32_t k) {
    return 2 * k + 1;
}

int32_t right_(int32_t k) {
    return 2 * k + 2;
}

MaxHeap* create_maxheap() {
    MaxHeap* h = malloc(sizeof(MaxHeap));
    h->heap = create_intvector(8);
    return h;
}

MinHeap* create_minheap() {
    MinHeap* h = malloc(sizeof(MinHeap));
    h->heap = create_intvector(8);
    return h;
}

void maxheap_insert(MaxHeap* maxheap, int32_t value) {
    int32_t op = maxheap_heapsize(maxheap);
    int32_t p = parent_(op);
    int32_t pv = intvector_get_element(maxheap->heap, p);
    maxheap->heap = intvector_push(maxheap->heap, value);
    
    while(op > 0 && value > pv) {
        int32_t buffer = value;
        intvector_change(maxheap->heap, op, pv);
        op = p;
        p = parent_(p);
        pv = intvector_get_element(maxheap->heap, p);
    }
    intvector_change(maxheap->heap, op, value);
}

void minheap_insert(MinHeap* minheap, int32_t value) {
    int32_t op = minheap_heapsize(minheap);
    int32_t p = parent_(op);
    int32_t pv = intvector_get_element(minheap->heap, p);
    minheap->heap = intvector_push(minheap->heap, value);
    
    while(op > 0 && value < pv) {
        int32_t buffer = value;
        intvector_change(minheap->heap, op, pv);
        op = p;
        p = parent_(p);
        pv = intvector_get_element(minheap->heap, p);
    }
    intvector_change(minheap->heap, op, value);
}

int32_t maxheap_popmax(MaxHeap* maxheap) {
    int32_t result = intvector_get_element(maxheap->heap, 0);
    int32_t last_val = intvector_pop(maxheap->heap);
    intvector_change(maxheap->heap, 0, last_val);
    int32_t heap_size = maxheap_heapsize(maxheap);
    int32_t p = 0;
    while(1) {
        int32_t l = left_(p);
        if (l >= heap_size) {
            break;
        }
        int32_t left_value = intvector_get_element(maxheap->heap, l);
        int32_t r = l + 1;
        if (r >= heap_size) {
            if(left_value > last_val) {
                intvector_change(maxheap->heap, p, left_value);
                intvector_change(maxheap->heap, l, last_val);
            }
            break;
        }
        int32_t right_value = intvector_get_element(maxheap->heap, r);
        int32_t next_p = l;
        if(left_value < right_value) {
            left_value = right_value;
            l = r;
            next_p = r;
        }
        if(left_value > last_val) {
            intvector_change(maxheap->heap, p, left_value);
            intvector_change(maxheap->heap, l, last_val);
            p = next_p;
        }
        else {
            break;
        }
    }
    return result;
}

int32_t minheap_popmin(MinHeap* minheap) {
    int32_t result = intvector_get_element(minheap->heap, 0);
    int32_t last_val = intvector_pop(minheap->heap);
    intvector_change(minheap->heap, 0, last_val);
    int32_t heap_size = minheap_heapsize(minheap);
    int32_t p = 0;
    while(1) {
        int32_t l = left_(p);
        if (l >= heap_size) {
            break;
        }
        int32_t left_value = intvector_get_element(minheap->heap, l);
        int32_t r = l + 1;
        if (r >= heap_size) {
            if(left_value < last_val) {
                intvector_change(minheap->heap, p, left_value);
                intvector_change(minheap->heap, l, last_val);
            }
            break;
        }
        int32_t right_value = intvector_get_element(minheap->heap, r);
        int32_t next_p = l;
        if(right_value < left_value) {
            left_value = right_value;
            l = r;
            next_p = r;
        }
        if(left_value < last_val) {
            intvector_change(minheap->heap, p, left_value);
            intvector_change(minheap->heap, l, last_val);
            p = next_p;
        }
        else {
            break;
        }
    }
    return result;
}

int32_t maxheap_max(MaxHeap* maxheap) {
    return intvector_get_element(maxheap->heap,0);
}

int32_t minheap_min(MinHeap* minheap) {
    return intvector_get_element(minheap->heap,0);
}

int32_t maxheap_heapsize(MaxHeap* maxheap) {
    return maxheap->heap->current_length;
}

int32_t minheap_heapsize(MinHeap* minheap) {
    return minheap->heap->current_length;
}
