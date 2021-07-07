#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void readFile(string nameFile, string *readed) {
    string reader;
    fstream file;
    file.open(nameFile);
    
    if (!file.is_open()) {
        cout << "Error while opening file";
        exit;
    } else {
        cout << "Reading file ... " << endl;
        while(file.good()) {
            getline(file, reader);
            *readed += reader + '\n';
        }
        file.close();
    }
}

int main() {
    string readed;
    string nameFile = "arquivos_exemplo.txt";
    readFile(nameFile, &readed);
    cout << "\tFile content:\n" << readed;
}
