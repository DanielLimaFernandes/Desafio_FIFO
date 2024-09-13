# Desafio_FIFO

O código implementa o algoritmo FIFO (First-In-First-Out) para simular a substituição de páginas em uma memória com um número fixo de molduras usando uma lista ligada. Cada nó da lista representa uma página na memória, e a ordem dos nós define a ordem de inserção das páginas. O código possui funções para criar nós, verificar a presença de uma página, adicionar uma nova página ao final da lista e remover a página mais antiga, que está no início da lista.

Na função principal, o algoritmo percorre uma sequência de páginas solicitadas. Se a página não estiver na memória (ou seja, na lista), uma falha de página ocorre. Se a memória estiver cheia, o código remove a página mais antiga antes de adicionar a nova. Após cada falha, o estado atual da memória é exibido, mostrando as páginas presentes e contando o número total de falhas.

Finalmente, o código testa o algoritmo com diferentes conjuntos de dados para verificar seu funcionamento. A memória final e o total de falhas são apresentados após a execução de todas as páginas. A implementação faz uso eficiente da lista ligada para gerenciar a memória e aplicar o algoritmo FIFO de maneira clara e funcional.
