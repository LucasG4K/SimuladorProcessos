#include "tokenizer.cpp"

void initializer() {
    Queue q1[MAX], q2[MAX];
    string readedFile1; //destination of readed file from txt
    string readedFile2; //destination of readed file from txt
    string arquivosFile = "R:/GitHub/ManipulacaoMatrizes/data/arquivos_exemplo.txt";
    string processosFile = "R:/GitHub/ManipulacaoMatrizes/data/arquivos_exemplo.txt";
    cout << "....................................." << endl;
    cout << "   ... <INITIALIZING PROGRAM> ..." << endl << endl;
    
    cout << "Reading fileS and setting things up..." << endl;
    cout << "....................................." << endl;
    readFile(arquivosFile, &readedFile1, q1); //reader
    cout << "File '" << arquivosFile << "' readed and tokenized!" << endl;
    cout << "....................................." << endl;
    //readFile(processosFile, &readedFile2, q2); //reader
    cout << "File '" << processosFile << "' readed and tokenized!" << endl;   
    cout << "....................................." << endl;
    do {
        cout << "====================" << endl;
        cout << "\tMENU" << endl;
        cout << "1 -> PRINT 'ARQUIVO'" << endl;
        cout << "2 -> PRINT 'PROCESSO'" << endl;
        cout << "3 ->" << endl;
        cout << "4 ->" << endl;
        cout << "5 ->" << endl;
        cout << "0 -> EXIT" << endl;
        cout << "====================" << endl;
        cout << "Choose an option: ";
        int option;
        cin >> option;
        switch (option) {
        case 1:
            
            //readFile(processosFile, &readed, q); //reader
            //printQueue(q, readed.length());
            system("pause");
            system("cls");
            break;
        case 2:
            printQueue(q1);/*, readed.length()); not working*/
            printQueue(q2);/*, readed.length()); not working*/
            system("pause");
            system("cls");
            break;

        case 0:
            cout << "Closing program..." << endl;
            exit(1);
        
        default:
            cout << "Choose a valid option to proceed" << endl;
            system("pause");
            system("cls");
            break;
        }
    } while(true);
}