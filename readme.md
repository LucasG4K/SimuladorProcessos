SIMULADOR DE PROCESSOS:
=
## Primeiras informações

Primeiramente, para expor um pouco o *"backstage"* o sistema operacional utilizado foi o Windows 10 versão 20H2. Desse modo, a compilação pode ser feita por meio do seguinte comando "g++ main.cpp -o run" e em seguida executado através do comando "run".

Os arquivos foram distribuídos com base em inicialização do programa, restrito em 'main.cpp', em seguida implementado um menu em 'init.cpp', funções de leitura, tokenização e outras funções genéricas foram situadas em 'read&tokenizer.cpp'. As funções referentes a fila para o preenchimento do disco teve como destino 'queue.cpp' e funções para processos da memória direcionadas a 'memory.cpp'.

## Sobre os passos

Para a simulação de um processo de leitura e escrita em disco foram utilizados dois arquivos pré-definidos que são: "arquivos_exemplo" e "processos_exemplo" e se tratam de dados e instruções respectivamente. O intuito é que mostrassemos o funcionamento da leitura e escrita em disco/memória por meio de manipulação de matrizes, usando as estruturas que foram apresentadas em sala. 

Dessa maneira, o elemento mais explorado em meu projeto foi a estrutura de dados "fila". Essa foi uma estrutura de grande importância para armazenar e/ou utilizar dados em disco e memória pois ficam de prontidão e são fáceis de manusear. 

Por meio da fila, as validações feitas em meus processos durante as requisições e chamadas dos arquivos em disco ou memórias, os seus valores eram alterados para '-1' para indicar que estavam sendo utilizados e ao liberar a memória os valores anteriores eram restaurados e ficavam prontos para serem reutilizados sempre que o processo começasse.

Além disso, para mais detalhes, o swap não foi realizado com êxito e portanto, por se tratar de arquivos em que possuíam processos iguais, eles foram descartados.

Devido ao grau de dificuldade do trabalho e o desafio de implementação não consegui encontrar formas mais eficazes de organizar a memória e por fim reduzir os números de page miss.