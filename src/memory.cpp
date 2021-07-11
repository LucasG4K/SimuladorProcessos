#include "queue.cpp"

typedef struct Process {
    int index;
    int page;
    int value;
} Process;


class Memory {
public:
    int index;
    int first;
    int last;
    Process array[MAX];
};

void initMemory(Memory *m) { //emptying rows of tokens to switch lines
    m->first = 1;
    m->last = 1;
}

void inMemory(Memory *m, Process p) {
    if (m->last % MAX + 1 == m->first) 
        cout << "[Error] : The Memory is already full" << endl;
    else {
        m->array[m->last] = p;
        m->last = m->last % MAX + 1;
    }
}

void printMemory(Memory *m) {
    for(int j = m->first; j < m->last; j++) {
        cout << " " << m->array[j].index;
        cout << " - " << m->array[j].page;
        cout << " : " << m->array[j].value << endl;
    }
    cout << endl;
}

int requestMemory(Memory *m, int index, int page) {
    int temp;
    for(int j = m->first; j < m->last; j++) {
        if(index == m->array[j].index) {
            if(page == m->array[j].page) {
                temp = m->array[j].value;
                m->array[j].value = -1;
                return temp;
            }
        }
    }
    return -1;
}
