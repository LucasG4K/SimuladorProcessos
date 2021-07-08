#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
#include <sstream>
using namespace std;

#define MAX 15
#define MAXROWS 5

class Queue{
public:
    int first;
    int last;
    int size = MAXROWS;
    int counter = 0;
    int vet[MAX];
};

void initQueue(Queue *q) { //emptying rows of tokens to switch lines
    q->first = 1;
    q->last = 1;
}

void inQueue(Queue *q, int value) {
	if(q->last == q->size-1)
		q->last = -1;

	q->last++;
	q->vet[q->last] = value; // incrementa ultimo e insere
	q->counter++; // mais um item inserido
}