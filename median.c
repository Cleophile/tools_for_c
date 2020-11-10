/*  
 * Created By Hikari Software
 *
 * Y-Enterprise
 *
 */

#include "median.h"

MedianFinder* medianFinderCreate() {
    MedianFinder* r = malloc(sizeof(MedianFinder));   
    // left
    r->smaller_heap = create_maxheap();
    // right
    r->bigger_heap = create_minheap();
    r->odd = 0;
    return r;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    int32_t left_max = maxheap_max(obj->smaller_heap);
    if(obj->odd) {
        // 大于等于左边, 直接加右边minheap
        // 小于左边，先加入左边 然后pop左边最大 加入到右边的末尾
        obj->odd = 0;
        if(num < left_max) {
            maxheap_insert(obj->smaller_heap, num);
            int32_t buffer = maxheap_popmax(obj->smaller_heap);
            minheap_insert(obj->bigger_heap, buffer);
            return;
        }
        minheap_insert(obj->bigger_heap, num);
        return;
    }
    
    if(num < left_max) {
        maxheap_max(obj->smaller_heap);
    }
    minheap_insert(obj->bigger_heap,num);
    int32_t buffer = minheap_popmin(obj->bigger_heap);
    maxheap_insert(obj->smaller_heap, buffer);
    obj->odd = 1;
}

double medianFinderFindMedian(MedianFinder* obj) {
    int32_t left = maxheap_max(obj->smaller_heap);
    if(obj->odd) {
        return (double)left;
    }
    return (left + minheap_min(obj->bigger_heap)) / 2.0;
}

void medianFinderFree(MedianFinder* obj) {
    free(obj);
}
