/*
Nome: Djonatan Bonelli
Matrícula: 2211100011
*/
#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct elemFila {
    Item *item;
    int id;
    char nome[30];
    struct elemFila *proximo;
} ElemFila;
typedef struct {
    ElemFila *primeiro;
    ElemFila *ultimo;
} Fila;
Fila *fila;

void insereFila(Fila *fila, Item *item, int id, char nome[]) {
    ElemFila *aux;

    // Cria um novo elemento da lista encadeada que representa a fila e
    // armazena neste novo elemento o item a ser inserido na fila
    aux = malloc(sizeof(ElemFila));
    aux->id = id;
    strcpy(aux->nome, nome);
    aux->proximo = NULL;
    if (fila->primeiro == NULL) { // Se a fila esta vazia
        fila->primeiro = aux;
        fila->ultimo = aux;
    }
    else { // Se a fila nao esta vazia
        fila->ultimo->proximo = aux;
        fila->ultimo = aux;
    }
}

void removeFila(Fila *fila, Item *item) {
    ElemFila *aux;

    // Verificar se a fila esta vazia!

    // Armazena o item a ser removido da fila
    *item = fila->primeiro->item; // ATENCAO: Depende da definicao do tipo do
                                  // item
    aux = fila->primeiro;
    if (fila->primeiro == fila->ultimo) {
        fila->primeiro = NULL;
        fila->ultimo = NULL;
    }
    else {
        fila->primeiro = fila->primeiro->proximo;
    }

    // Libera a memoria alocada para o elemento removido
    free(aux);
}
void inicializaFila(Fila *fila) {
    fila->primeiro = NULL;
    fila->ultimo = NULL;
}
int filaVazia(Fila *fila) {
    return (fila->primeiro == NULL);
}
void liberaFila(Fila *fila) {
    ElemFila *aux;

    while (fila->primeiro != NULL) {
        // Armazena o primeiro elemento da lista encadeada que representa a
        // fila e remove este primeiro elemento da lista
        aux = fila->primeiro;
        fila->primeiro = fila->primeiro->proximo;

        // Libera a memoria alocada para o elemento removido
        free(aux);
    }
    fila->ultimo = NULL;
}

void listarFila(Fila *fila){
    ElemFila *aux;
    printf("\nNa pista agora:\n");
    for(aux = fila->primeiro; aux != NULL; aux = aux->proximo){
    printf("%s\n", aux->nome);
    }
    
}

void contarFila(Fila *fila){
    ElemFila *aux;
    int contador = 0;
    for(aux = fila->primeiro; aux != NULL; aux = aux->proximo){
        contador++;
    }
    printf("%d aguardando na fila\n", contador);
}

void informarPrimeiro(Fila *fila){
    ElemFila *aux;
    for(aux = fila->primeiro; aux != NULL; aux = aux->proximo){
        if(aux == fila->primeiro){
            printf("\nPrimeiro na fila:\nId: %d\nNome: %s\n", aux->id, aux->nome);
        }
    }
}

void autorizarVoo(Fila *fila){
    ElemFila *aux;
    aux = fila->primeiro;
    if (fila->primeiro == fila->ultimo) {
        fila->primeiro = NULL;
        fila->ultimo = NULL;
    }
    else {
        fila->primeiro = fila->primeiro->proximo;
    }

    // Libera a memoria alocada para o elemento removido
    free(aux);

}

int main() {
    Fila fila;
    Item item;

    inicializaFila(&fila);

   while (filaVazia(&fila) == 0) { // Enquanto a fila nao esta vazia
        removeFila(&fila, &item);
        printf("Item %d removido da fila.\n", item);
    }

    liberaFila(&fila); // Sem efeito se a fila ja esta vazia

    insereFila(&fila, &item, 1, "Boing 767");
    insereFila(&fila, &item, 2, "Airbus A350");
    insereFila(&fila, &item, 3, "Boing 737");
    //inserir mais nodos
    contarFila(&fila);
    listarFila(&fila);
    informarPrimeiro(&fila);
    autorizarVoo(&fila);
    printf("\nUm voo foi autorizado!\n");
    listarFila(&fila);

    return 0;
}
