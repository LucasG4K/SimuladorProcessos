#include "Queue.cpp"

void tokenizer(string reader, Queue q) {
    int counter = 0;
    char* copied = new char[reader.length() + 1];
    memcpy(copied, reader.c_str(), reader.length() + 1);

    const char sep[] = "<> , ' '";
    int value;
    bool control = false;
    char* tokens = strtok(copied, sep);

    while (tokens != NULL) {
        if (control) {
            value = stoi(tokens);
            initQueue(&q);
            inQueue(&q, value);
        }
        printQueue(&q);
        tokens = strtok(NULL, sep);
        control = true;
    }
    cout << endl;
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
        tokenizer(reader, q[numOfRows]);
        numOfRows++; //num of lines
    }
    file.close();
}
