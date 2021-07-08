#include "tokenizer.cpp"

int main() {
    //-----------------variable declaration-------------
    int num[MAX];
    int numOfRows = 0;
    Queue q[5];    
    string readed;                              //destination of readed file from txt
    string nameFile = "arquivos_exemplo.txt";
    //---------------------------------------------------
    readFile(nameFile, &readed, q, &numOfRows); //reader
    cout << "printing queue: " << endl;
    //cout << "\tFile content:\n" << readed; // full file content
}
