#include "Queue.cpp"


void tokenizer(string reader, Queue* q) {
    char* copy = new char[reader.length() + 1];
    memcpy(copy, reader.c_str(), reader.length() + 1);

    const char sep[] = "<> , ' '";
    int value;
    bool control = false;
    char* tokens = strtok(copy, sep);

    while (tokens != NULL) {
        if (control) {
            value = stoi(tokens);
            q->vet[q->last++] = value;
            q->first = q->last % MAX + 1;
            inQueue(q, value);
            cout << " " << value;
        }
        tokens = strtok(NULL, sep);
        control = true;
    }
    cout << endl;
}

void readFile(string nameFile, string* readed, Queue* q, int* numOfRows) {
    int numOfColumns = 0;
    string reader;
    fstream file;
    file.open(nameFile);

    if (!file.is_open()) {
        cout << "Error while opening file";
        exit;
    }
    cout << "Reading file ... " << endl;
    while (file.good()) {
        getline(file, reader);              //read line by line while file is open
        *readed += reader + '\n';           //save the file content into a single string
        initQueue(&q[numOfColumns           /**numOfRows*/  ]);
        tokenizer(reader, &q[numOfColumns   /**numOfRows*/  ]);
        numOfColumns++;                     //*numOfRows++;
    }
    file.close();
}