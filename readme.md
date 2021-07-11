SIMULADOR DE PROCESSOS:
=
#### Primeiras informações

Primeiramente, para expor um pouco o *"backstage"* o sistema operacional utilizado foi o Windows 10 versão 20H2. Desse modo, a compilação foi feita por meio do seguinte comando "g++ main.cpp -o run" e em seguida executado com o comando "run".

Os arquivos foram distribuídos com base em inicialização do programa, restrito em 'main.cpp', em seguida implementado um menu em 'init.cpp', funções de leitura, tokenização e outras funções mais genéricas foram situadas em 'read&tokenizer.cpp', funções de fila para preenchimento do disco teve como destino 'queue.cpp' e funções para processos da memória direcionadas a 'memory.cpp'.

#### Sobre os passos