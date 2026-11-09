#include <stdio.h>

typedef int Item;

typedef struct elemPilha {
    Item item;
    struct elemPilha *proximo;
} ElemPilha;

typedef struct {
    ElemPilha *topo;
} Pilha;

Pilha *pilha;

void inicializaPilha(Pilha *pilha) {
    pilha->topo = NULL;
}

void removePilha(Pilha *pilha, Item *item) {
    ElemPilha *aux;

    *item = pilha->topo->item; 

    aux = pilha->topo;
    pilha->topo = pilha->topo->proximo;

    free(aux);
}

void inserePilha(Pilha *pilha, Item item) {
    ElemPilha *aux;

    aux = malloc(sizeof(ElemPilha));
    aux->item = item;

    aux->proximo = pilha->topo;
    pilha->topo = aux;
}

void liberaPilha(Pilha *pilha) {
    ElemPilha *aux;

    while (pilha->topo != NULL) {

        aux = pilha->topo;
        pilha->topo = pilha->topo->proximo;

        free(aux);
    }
}

int pilhaVazia(Pilha *pilha) {
    return (pilha->topo == NULL);
}

int main() {
    Pilha pilha;
    Item item;

    //início da lógica a ser adaptada
    inicializaPilha(&pilha);

    for (int i = 0; i < 10; i++) {
        item = i;

        printf("Inserindo na pilha o item %d.\n", item);
        inserePilha(&pilha, item);

    while (pilhaVazia(&pilha) == 0) {
        removePilha(&pilha, &item);
        printf("Item %d removido da pilha.\n", item);
    }

    liberaPilha(&pilha); 
    }
    //fim da lógica a ser adaptada

    void inserePilha(Pilha *pilha, Item item);

    void removePilha(Pilha *pilha, Item *item);

    void inicializaPilha(Pilha *pilha);

    int pilhaVazia(Pilha *pilha);

    void liberaPilha(Pilha *pilha);
    
    return 0;
}