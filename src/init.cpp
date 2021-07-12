#include "read&tokenizer.cpp"

void initializer() {
    Queue disk[MAX], process[MAX];
    Memory m[MAX];
    Misses miss;
    int numOfLines = 4;
    string readedFile1; //destination of readed file from txt
    string readedFile2; //destination of readed file from txt
    string arquivosFile = "R:/GitHub/SimuladorProcessos/data/arquivos_exemplo.txt";
    string processosFile = "R:/GitHub/SimuladorProcessos/data/processos_exemplo.txt";
    pageMissInit(&miss);
    
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
        cout << "6 -> PAGE MISS" << endl;
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
            pageMissInit(&miss);
            cout << "MEMORY IS FREE!" << endl;
            break;
        
        case 6:
            cout << "FILE REQUESTS:" << endl;
            cout << "A1: " << miss.A1 << endl;
            cout << "A2: " << miss.A2 << endl;
            cout << "A3: " << miss.A3 << endl;
            cout << "A4: " << miss.A4 << endl;
            cout << "PAGE MISSES:" << endl;
            cout << "P1: " << miss.P1 << endl;
            cout << "P2: " << miss.P2 << endl;
            cout << "P3: " << miss.P3 << endl;
            cout << "P4: " << miss.P4 << endl;

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