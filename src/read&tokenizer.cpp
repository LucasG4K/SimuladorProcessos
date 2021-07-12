#include "pageMiss.cpp"

void tokenizer(string reader, Queue *q) {
    int counter = 0;
    char* copied = new char[reader.length() + 1];
    memcpy(copied, reader.c_str(), reader.length() + 1);

    const char sep[] = "A P <> , ' ' ";
    int value;
    bool control = false;
    char* tokens = strtok(copied, sep);
    

    while (tokens != NULL) {
        value = stoi(tokens);
        inQueue(q, value); //coloca na fila
        tokens = strtok(NULL, sep);
        control = true;
    }
}

void readFile(string nameFile, string* readed, Queue* q) {
    int numOfRows = 0;
    string reader;

    fstream file;
    file.open(nameFile);

    if (!file.is_open()) {
        cout << "Error while opening file";
        exit;
    }
    
    while (file.good()) {
        getline(file, reader);            //read line by line while file is open
        *readed += reader + '\n';         //save the file content into a single string
        initQueue(&q[numOfRows]);
        tokenizer(reader, &q[numOfRows]);
        numOfRows++; //num of lines
    }
    file.close();
}


int searchInDisk(Queue *disk, int index, int page) {
    int temp;
    for (int i = 0; i < 4; i++) {
        if (index == i + 1) {
            temp = requestDisk(&disk[i], page);
            if (temp != -1) {
                //cout << " " << temp;
                return temp;
            }
        }
    }
    return -1;
}

void freeMemory(Memory *m, Queue *q) {
    for (int i = 0; i < 4; i++) {
        for (int j = m[i].first; j < m[i].last; j++) {
            if (m[i].array[j].value != -1) {
                for (int k = 0; k < 4; k++) {
                    if(k + 1 == m[i].array[j].index) {
                        returnToDisk(&q[k], m[i].array[j].page, m[i].array[j].value);
                        m[i].array[j].value = -1;
                    }
                }
            }
        }
    }
}

int searchInMemory(Memory *m, int index, int page) {
    int temp;
    for (int i = 0; i < 4; i++) {
        temp = requestMemory(&m[i], index, page);

        if (temp != -1) {
            //cout << " " << temp;
            return temp;
        }
    }
    return -1;
}

void searchProcess(Queue *disk, Queue *process, Memory *m) {
    int index;
    int page;
    int temp;
    Process p;
    for (int i = 0; i < 4; i++) {
        initMemory(&m[i]);

        for (int j = process[i].first + 1; j < process[i].last - 1; j+=2) {
            index = process[i].array[j];
            page = process[i].array[j + 1];

            p.index = index;
            p.page = page;

            temp = requestMemory(m, index, page);

            if(temp == -1)
                temp = searchInDisk(disk, index, page);

            p.value = temp;

            inMemory(&m[i], p);
        }
    }
}
