/**
 * @file 02Hash.c
 * @author Djonatan Riquelme Clein Bonelli
 * @version 0.1
 * @date 2023-06-10
 *
 * @copyright Copyright (c) 2023
 *
 * @brief Arquivo template para Quest√£o 02 do trabalho de Pesquisa e Ordena√ß√£o T2.
 *
 *      Implemente uma tabela hash contendo 13 posi√ß√µes. O √≠ndice das chaves
 *  deve ser gerado utilizando a f√≥rmula k mod M, onde k √© a chave e M a
 *  quantidade de chaves. Resolva as colis√µes utilizando uma Lista Encadeada.
 *  Inclua opera√ß√µes de inser√ß√£o, remo√ß√£o e busca da chave nesta tabela hash,
 *  informando se a chave foi encontrada ou n√£o.  Aten√ß√£o: os elementos da
 *  lista encadeada n√£o precisam estar ordenados/em ordem.
 *
 *      Utilize os vetores comentados no c√≥digo para realizar seus testes.
 *
 * Aten√ß√£o: Antes de entregar, conferir se dos dados de documenta√ß√£o no in√≠cio
 * do arquivo est√£o preenchidos corretamente.
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 13

typedef struct Node {
    int chave;
    int valor;
    struct Node* proximo;
} Node;

typedef struct {
    Node* tabela[TAMANHO];
} TabelaHash;

int hashFunction(int chave) {
    return chave % TAMANHO;   // k mod m
}

Node* createNode(int chave, int valor) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->chave = chave;
    newNode->valor = valor;
    newNode->proximo = NULL;
    return newNode;
}

// Inicia tabela
void initHashTable(TabelaHash* tabelaHash) {
    for (int i = 0; i < TAMANHO; i++) {
        tabelaHash->tabela[i] = NULL;
    }
}

// Insere na tabela
void insert(TabelaHash* tabelaHash, int chave, int valor) {
    int index = hashFunction(chave);
    Node* newNode = createNode(chave, valor);

    if (tabelaHash->tabela[index] == NULL) {
        // A posiÁ„o est· vazia, insere o novo nÛ diretamente
        tabelaHash->tabela[index] = newNode;
    } else {
        // J· existe um nÛ na posiÁ„o, adiciona o novo nÛ ao final da lista
        Node* current = tabelaHash->tabela[index];
        while (current->proximo != NULL) {
            current = current->proximo;
        }
        current->proximo = newNode;
    }
}

// Busca chave
int search(TabelaHash* tabelaHash, int chave) {
    int index = hashFunction(chave);
    Node* current = tabelaHash->tabela[index];

    while (current != NULL) {
        if (current->chave == chave) {
            return current->valor;
        }
        current = current->proximo;
    }

    // Chave n„o encontrada
    return -1;
}

// Mostra tabela
void display(TabelaHash* tabelaHash) {
    for (int i = 0; i < TAMANHO; i++) {
        printf("PosiÁ„o %d: ", i);
        Node* current = tabelaHash->tabela[i];
        while (current != NULL) {
            printf("(%d, %d) ", current->chave, current->valor);
            current = current->proximo;
        }
        printf("\n");
    }
}

int main(){
    int chaves = {7, 13, 33, 12, 5, 1, 0};
    int chaves = {5, 6, 9, 19, 24, 32, 41, 42, 43, 58};
    int chaves = {178, 231, 244, 292, 321, 356, 389, 421, 482, 488, 490, 502, 546, 641, 694, 786, 841, 890, 899, 922};
    int chaves = {3, 29, 43, 45,  3, 17,  2,  7, 33, 17};

    TabelaHash tabelaHash;
    initHashTable(&tabelaHash);

    //chaves enumeradas
/*
    int chaves1[] = {7, 13, 33, 12, 5, 1, 0};
    int tamanho1 = sizeof(chaves1) / sizeof(chaves1[0]);

    int chaves2[] = {5, 6, 9, 19, 24, 32, 41, 42, 43, 58};
    int tamanho2 = sizeof(chaves2) / sizeof(chaves2[0]);

    int chaves3[] = {178, 231, 244, 292, 321, 356, 389, 421, 482, 488, 490, 502, 546, 641, 694, 786, 841, 890, 899, 922};
    int tamanho3 = sizeof(chaves3) / sizeof(chaves3[0]);

    int chaves4[] = {3, 29, 43, 45, 3, 17, 2, 7, 33, 17};
    int tamanho4 = sizeof(chaves4) / sizeof(chaves4[0]);

    printf("Tabela vazia:\n");
    display(&tabelaHash);

    for (int i = 0; i < tamanho1; i++) {
        insert(&tabelaHash, chaves1[i], chaves1[i]);
    }

    printf("\n\nTabela apÛs inserÁ„o das chaves 1:\n");
    display(&tabelaHash);

    for (int i = 0; i < tamanho2; i++) {
        insert(&tabelaHash, chaves2[i], chaves2[i]);
    }

    printf("\n\nTabela apÛs inserÁ„o das chaves 2:\n");
    display(&tabelaHash);

    for (int i = 0; i < tamanho3; i++) {
        insert(&tabelaHash, chaves3[i], chaves3[i]);
    }

    printf("\n\nTabela apÛs inserÁ„o das chaves 3:\n");
    display(&tabelaHash);

    for (int i = 0; i < tamanho4; i++) {
        insert(&tabelaHash, chaves4[i], chaves4[i]);
    }

    printf("\n\nTabela apÛs inserÁ„o das chaves 4:\n");
    display(&tabelaHash);

    printf("\n\nBuscando elementos:\n");
    printf("Chave 7: Valor %d\n", search(&tabelaHash, 7));
    printf("Chave 33: Valor %d\n", search(&tabelaHash, 33));
    printf("Chave 24: Valor %d\n", search(&tabelaHash, 24));
    printf("Chave 41: Valor %d\n", search(&tabelaHash, 41));
    printf("Chave 641: Valor %d\n", search(&tabelaHash, 641));
*/
    return 0;
}