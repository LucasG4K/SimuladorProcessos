#include "memory.cpp"

class Misses {
public:
    int A1;
    int A2;
    int A3;
    int A4;

    int P1;
    int P2;
    int P3;
    int P4;
};

void pageMissInit(Misses *miss) {
    miss->A1 = 0;
    miss->A2 = 0;
    miss->A3 = 0;
    miss->A4 = 0;

    miss->P1 = 0;
    miss->P2 = 0;
    miss->P3 = 0;
    miss->P4 = 0;
}

void countFilesRequest(Misses *miss, int page) {
    page == 1? miss->A1 += 1 : NULL;
    page == 2? miss->A2 += 1 : NULL;
    page == 3? miss->A3 += 1 : NULL;
    page == 4? miss->A4 += 1 : NULL;
}

void countPageMiss(Misses *miss, int index) {
    index == 1? miss->P1 += 1 : NULL;
    index == 2? miss->P2 += 1 : NULL;
    index == 3? miss->P3 += 1 : NULL;
    index == 4? miss->P4 += 1 : NULL;
}