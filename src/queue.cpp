#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
#include <sstream>
using namespace std;

#define MAX 100
#define MAXROWS 5

class Queue{
public:
    int first;
    int last;
    int size = MAXROWS;
    int counter = 0;
    int array[MAX];
};

void initQueue(Queue *q) { //emptying rows of tokens to switch lines
    q->first = 1;
    q->last = 1;
}

void inQueue(Queue *q, int value) {
    if (q->last % MAX + 1 == q->first) 
        cout << "[Error] : The queue is already full" << endl;
    else {
        q->array[q->last] = value;
        q->last = q->last % MAX + 1;
    }
}

void printQueue(Queue *q) {
    for(int j = q->first; j < q->last; j++)
        cout << " " << q->array[j];
    cout << endl;
}

int requestDisk(Queue *q, int page) {
    int temp;
    for(int j = q->first; j < q->last; j++)
        if (page + 1 == j) {
            temp = q->array[j];
            q->array[j] = -1;
            return temp;
        }
    return -1;
}

void returnToDisk(Queue *q, int page, int value) {
    for(int j = q->first + 1; j < q->last; j++) {
        if (page + 1 == j)
            q->array[j] = value;
    }
}
