#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da lista ligada
typedef struct Node {
    int page;
    struct Node *next;
} Node;

// Função para criar um novo nó
Node* createNode(int page) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->page = page;
    newNode->next = NULL;
    return newNode;
}

// Função para verificar se uma página está na lista
int isPageInList(Node *head, int page) {
    Node *current = head;
    while (current != NULL) {
        if (current->page == page) {
            return 1; // Página encontrada
        }
        current = current->next;
    }
    return 0; // Página não encontrada
}

// Função para remover o nó mais antigo da lista
void removeOldestPage(Node **head) {
    if (*head == NULL) return;
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Função para adicionar uma nova página na lista
void addPage(Node **head, int page, int num_frames) {
    if (*head == NULL) {
        *head = createNode(page);
        return;
    }
    
    Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = createNode(page);
}

// Função para exibir o estado atual da lista
void displayList(Node *head, int num_frames) {
    printf("Estado da memória: [");
    Node *current = head;
    int count = 0;
    while (current != NULL) {
        printf("%d", current->page);
        count++;
        if (count < num_frames) {
            printf(", ");
        }
        current = current->next;
    }
    printf("]\n");
}

// Função principal para executar o algoritmo FIFO
void fifoPageReplacement(int pages[], int num_pages, int num_frames) {
    Node *head = NULL;
    int num_faults = 0;
    int current_frames = 0;

    for (int i = 0; i < num_pages; i++) {
        int current_page = pages[i];
        
        if (!isPageInList(head, current_page)) {
            printf("Falha de página: %d ", current_page);
            if (current_frames >= num_frames) {
                printf("substituindo %d\n", head->page);
                removeOldestPage(&head);
            } else {
                printf("inserindo nova página\n");
                current_frames++;
            }
            addPage(&head, current_page, num_frames);
            num_faults++;

            displayList(head, num_frames);
        }
    }

    printf("Total de falhas de página: %d\n", num_faults);
    printf("Estado final da memória: [");
    Node *current = head;
    int count = 0;
    while (current != NULL) {
        printf("%d", current->page);
        count++;
        if (count < num_frames) {
            printf(", ");
        }
        current = current->next;
    }
    printf("]\n");

    // Liberar memória
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // Desafios

    // Entrada 01
    int pages1[] = {1, 3, 0, 3, 5, 6, 3, 1, 6, 1, 2};
    int num_frames1 = 3;
    printf("Desafio 01:\n");
    fifoPageReplacement(pages1, sizeof(pages1) / sizeof(pages1[0]), num_frames1);

    // Entrada 02
    int pages2[] = {5, 6, 7, 8, 5, 6, 8, 9, 7, 6};
    int num_frames2 = 4;
    printf("\nDesafio 02:\n");
    fifoPageReplacement(pages2, sizeof(pages2) / sizeof(pages2[0]), num_frames2);

    // Entrada 03
    int pages3[] = {0, 2, 1, 6, 4, 0, 1, 0, 2, 1, 4};
    int num_frames3 = 3;
    printf("\nDesafio 03:\n");
    fifoPageReplacement(pages3, sizeof(pages3) / sizeof(pages3[0]), num_frames3);

    // Entrada 04
    int pages4[] = {9, 3, 4, 2, 5, 6, 4, 9, 7, 1, 3};
    int num_frames4 = 4;
    printf("\nDesafio 04:\n");
    fifoPageReplacement(pages4, sizeof(pages4) / sizeof(pages4[0]), num_frames4);

    // Entrada 05
    int pages5[] = {0, 2, 1, 6, 4, 0, 1, 0, 2, 1, 4};
    int num_frames5 = 3;
    printf("\nDesafio 05:\n");
    fifoPageReplacement(pages5, sizeof(pages5) / sizeof(pages5[0]), num_frames5);

    // Entrada 06
    int pages6[] = {8, 5, 7, 5, 4, 6, 8, 6, 1, 4, 8, 7};
    int num_frames6 = 2;
    printf("\nDesafio 06:\n");
    fifoPageReplacement(pages6, sizeof(pages6) / sizeof(pages6[0]), num_frames6);

    return 0;
}
