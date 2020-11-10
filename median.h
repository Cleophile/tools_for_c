#include "vector.h"
#include "heap.h"

typedef struct {
    // two heaps?
    // A:最大堆 B:一个最小堆
    // max(A) <= min(B)
    // 存储 is_odd
    // is_odd 0: 两个平均
    // is_odd 1: 左边的
    // 不平衡 push and pop
    // O(NlogN)
    MinHeap* bigger_heap;
    MaxHeap* smaller_heap;
    int32_t odd;
} MedianFinder;

MedianFinder* medianFinderCreate();

void medianFinderAddNum(MedianFinder* obj, int num);

double medianFinderFindMedian(MedianFinder* obj);

void medianFinderFree(MedianFinder* obj);
