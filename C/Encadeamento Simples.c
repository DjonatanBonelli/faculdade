#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct funcionario{
        int id;
        char nome[31];
        double salario;
        struct funcionario *proximo;
}; 

typedef struct funcionario Funcionario;

Funcionario* insereNodoInicio(Funcionario *primeiro, int id, char nome[], double salario){
    
    Funcionario *aux;
    aux = malloc(sizeof(Funcionario));
    aux->id = id;
    strcpy(aux->nome, nome);
    aux->salario = salario;
    
    aux->proximo = primeiro;
    primeiro = aux;
    
    return primeiro;
    
}

Funcionario* insereNodoFim(Funcionario *primeiro, int id, char nome[], double salario){
    
    Funcionario *aux, *auxB, *anterior;
    
    for(aux = primeiro; aux != NULL; aux = aux->proximo){
        anterior = aux;
    }
    auxB = malloc(sizeof(Funcionario));
    auxB->id = id;
    strcpy(auxB->nome, nome);
    auxB->salario = salario;
    
    anterior->proximo = auxB;
    
    return primeiro;
}

Funcionario* deletaNodo(Funcionario *primeiro, int idDelete){
    
    Funcionario *aux, *anterior;
    for(aux = primeiro; aux != NULL; aux = aux->proximo){
        if(aux->id == idDelete){
            if(aux == primeiro){
            primeiro = primeiro->proximo;
        }
        else{
            anterior->proximo = aux->proximo;
      }
        free(aux);
        break;
    }
    anterior = aux;
 }
 return primeiro;
}

void imprimeLista(Funcionario *primeiro){
    printf("\nImprimindo lista:\n");
    Funcionario *aux;
    for(aux = primeiro; aux != NULL; aux = aux->proximo){
        printf("id: %d\nnome: %s\nsalário: %.2lf\n", aux->id, aux->nome, aux->salario);
};
}

void imprimeAoContrario(Funcionario *aux){
    if(aux!=NULL){
        imprimeAoContrario(aux->proximo);
        printf("id: %d\nnome: %s\nsalário: %.2lf\n", aux->id, aux->nome, aux->salario);
    }
}

int contaNodos(Funcionario *primeiro){
    Funcionario *aux;
    int nodos = 0;
    for(aux = primeiro; aux != NULL; aux = aux->proximo){
        nodos = nodos + 1;
};
nodos = nodos + 1;
    printf("\nTotal de nodos: %d\n", nodos);
}
void destroiLista(Funcionario *primeiro){
    Funcionario *aux;
    while (primeiro != NULL)
    {
        aux = primeiro;
        primeiro = primeiro->proximo;
        free(aux);   
        }
}

int main(){
    Funcionario *primeiro = NULL;

    primeiro = insereNodoInicio(primeiro, 54, "Bety", 5000);
    primeiro = insereNodoInicio(primeiro, 55, "Mary", 8000);
    primeiro = insereNodoFim(primeiro, 59, "Bill", 1500);
    primeiro = insereNodoFim(primeiro, 60, "John", 3500);

    // inserir mais nodos...
    
    imprimeLista(primeiro);
    printf("\nImprimindo lista ao contrario:\n");
    imprimeAoContrario(primeiro);
    primeiro = deletaNodo(primeiro, 54);
    contaNodos(primeiro);
    destroiLista(primeiro);

return 0;
}