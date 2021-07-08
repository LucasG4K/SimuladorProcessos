#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
#include <sstream>
#define MAX 15
using namespace std;

class Token {
public:
    int first;
    int last;
    int vet[MAX];
};

void initToken(Token* t) { //emptying rows of tokens to switch lines
    t->first = 1;
    t->last = 1;
}

void tokenizer(string reader, Token* t) {
    char* copy = new char[reader.length() + 1];
    memcpy(copy, reader.c_str(), reader.length() + 1);

    const char sep[] = "<> , ' '";
    int value;
    bool control = false;
    char* tokens = strtok(copy, sep);

    while (tokens != NULL) {
        if (control) {
            value = stoi(tokens);
            t->vet[t->last++] = value;
            t->first = t->last % MAX + 1;
            cout << " " << value;
        }
        tokens = strtok(NULL, sep);
        control = true;
    }
    cout << endl;
}

void readFile(string nameFile, string* readed, Token* t, int* numOfRows) {
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
        initToken(&t[numOfColumns           /**numOfRows*/  ]);
        tokenizer(reader, &t[numOfColumns   /**numOfRows*/  ]);
        numOfColumns++;                     //*numOfRows++;
    }
    file.close();
}

int main() {
    //-----------------variable declaration-------------
    Token t[8];
    int numOfRows = 0;
    int num[MAX];
    string readed;                              //destination of readed file from txt
    string nameFile = "arquivos_exemplo.txt";
    //---------------------------------------------------
    readFile(nameFile, &readed, t, &numOfRows); //reader

    //cout << "\tFile content:\n" << readed; // full file content
}

// if(t->fundo % MAX + 1 == t->frente)
//         printf("[Erro]: Fila cheia.\n");
// else {
//         t->partes[t->fundo] = p;
//         t->fundo = t->fundo % MAX + 1;
//     }
