#include "read&tokenizer.cpp"

void initializer() {
    Queue disk[MAX], process[MAX];
    Memory m[MAX];
    int numOfLines = 4;
    string readedFile1; //destination of readed file from txt
    string readedFile2; //destination of readed file from txt
    string arquivosFile = "R:/GitHub/ManipulacaoMatrizes/data/arquivos_exemplo.txt";
    string processosFile = "R:/GitHub/ManipulacaoMatrizes/data/processos_exemplo.txt";
    
    cout << "....................................." << endl;
    cout << "   ... <INITIALIZING PROGRAM> ..." << endl << endl;
    
    cout << "Reading fileS and setting things up..." << endl;
    cout << "....................................." << endl;
    
    readFile(arquivosFile, &readedFile1, disk); //disk save 'arquivos'
    cout << "File '" << arquivosFile << "' readed and tokenized!" << endl;
    cout << "....................................." << endl;
    
    readFile(processosFile, &readedFile2, process); //process save 'processos'
    cout << "File '" << processosFile << "' readed and tokenized!" << endl;   
    cout << "....................................." << endl;
    
    do {
        cout << "====================" << endl;
        cout << "\tMENU" << endl;
        cout << "1 -> PRINT 'ARQUIVO'" << endl;
        cout << "2 -> PRINT 'PROCESSO'" << endl;
        cout << "3 -> SEARCH IN DISK or MEMORY" << endl;
        cout << "4 -> PRINT MEMORY" << endl;
        cout << "5 -> FREE MEMORY" << endl;
        cout << "0 -> EXIT" << endl;
        cout << "====================" << endl;
        cout << "Choose an option: ";
        int option;
        cin >> option;
        switch (option) {
        case 1:
            for (int i = 0; i < numOfLines; i++) {
                printQueue(&disk[i]);
            }
            break;
        case 2:
            for (int i = 0; i < numOfLines; i++) {
                printQueue(&process[i]);
            }
            break;

        case 3:
            searchProcess(disk, process, m);
            cout << "SEARCH DONE!" << endl;
            break;

        case 4:
            for (int i = 0; i < numOfLines; i++) {
                printMemory(&m[i]);
            }
            break;

        case 5:
            freeMemory(m, disk);
            cout << "MEMORY IS FREE!" << endl;
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
        system("pause");
        system("cls");
    } while(true);
}