/**
 * @file 03Tries.c
 * @author Djonatan Riquelme Clein Bonelli
 * @version 0.1
 * @date 2023-06-10
 *
 * @copyright Copyright (c) 2023
 *
 * @brief Arquivo template para Quest√£o 03 do trabalho de Pesquisa e Ordena√ß√£o T2.
 *
 *      Implemente uma estrutura de Trie para armazenar chaves em formato de
 * caractere. Inclua opera√ß√µes de inser√ß√£o, remo√ß√£o e busca completa e busca
 * parcial na estrutura do Trie.
 *      Para a busca completa, o algoritmo deve apenas informar se a chave foi
 * encontrada ou n√£o dentro da estrutura. Para a busca parcial, o algoritmo deve
 * retornar todas as chaves armazenadas abaixo da string informada para a busca.
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAMANHO 13


typedef struct TrieNode {
    struct TrieNode* filho[26];  // cada index = uma letra
    bool terminal;  // fim de uma palavra
} TrieNode;

// cria um novo nÛ da Trie
TrieNode* createNode() {
    TrieNode* node = (TrieNode*) malloc(sizeof(TrieNode));
    node->terminal = false;
    for (int i = 0; i < 26; i++) {
        node->filho[i] = NULL;
    }
    return node;
}

// insere uma palavra na Trie
void insert(TrieNode* root, char* palavra) {
    TrieNode* atual = root;
    for (int i = 0; palavra[i] != '\0'; i++) {
        int index = palavra[i] - 'a';           // o (- 'a') serve para mapear cada letra em seu Ìndice no vetor
        if (atual->filho[index] == NULL) {      // atravÈs do cÛdigo ascii. Todas as letras tÍm seu cÛdigo subtraÌdo de 97 (a), 
            atual->filho[index] = createNode(); // ou seja, a = 0, b = 1, etc. Assim, cada letra vai para seu lugar no vetor.
        }
        atual = atual->filho[index];
    }
    atual->terminal = true;
}

// verifica se uma palavra est· presente
bool search(TrieNode* root, char* palavra) {
    TrieNode* atual = root;
    for (int i = 0; palavra[i] != '\0'; i++) {
        int index = palavra[i] - 'a';
        if (atual->filho[index] == NULL) {
            return false;
        }
        atual = atual->filho[index];
    }
    return (atual != NULL && atual->terminal);
}

// FunÁ„o auxiliar recursiva para obter todas as palavras com um determinado prefixo
void getAllWords(TrieNode* node, char* prefix, char** palavras, int* contagem) {
    if (node->terminal) {
        palavras[*contagem] = (char*)malloc((strlen(prefix) + 1) * sizeof(char));
        strcpy(palavras[*contagem], prefix);
        (*contagem)++;
    }

    for (int i = 0; i < 26; i++) {
        if (node->filho[i] != NULL) {
            char* newPrefix = (char*)malloc((strlen(prefix) + 2) * sizeof(char));
            sprintf(newPrefix, "%s%c", prefix, 'a' + i);
            getAllWords(node->filho[i], newPrefix, palavras, contagem);
            free(newPrefix);
        }
    }
}

bool prefixes(TrieNode* root, char* prefix, char** palavras, int* contagem) {
    TrieNode* atual = root;
    for (int i = 0; prefix[i] != '\0'; i++) {
        int index = prefix[i] - 'a';
        if (atual->filho[index] == NULL) {
            return false;
        }
        atual = atual->filho[index];
    }
    getAllWords(atual, prefix, palavras, contagem);
    return (atual != NULL);
}



// remove uma palavra 
bool removeWord(TrieNode* root, char* palavra) {
    if (root == NULL || palavra == NULL) {
        return false;
    }

    TrieNode* atual = root;
    TrieNode* caminho[26] = { NULL };  // rastreia o caminho percorrido
    int index;

    // encontra o ˙ltimo nÛ do prefixo da palavra
    for (int i = 0; palavra[i] != '\0'; i++) {
        index = palavra[i] - 'a';
        if (atual->filho[index] == NULL) {
            return false;  // n„o encontrado
        }
        caminho[i] = atual;
        atual = atual->filho[index];
    }

    if (!atual->terminal) {
        return false;  // n„o encontrado
    }

    atual->terminal = false;  // deixa de ser terminal

    // verifica se tem filhos ou È prefixo
    bool temfilhos = false;
    for (int i = 0; i < 26; i++) {
        if (atual->filho[i] != NULL) {
            temfilhos = true;
            break;
        }
    }

    // remove nÛs sem filhos e que n„o s„o prefixos
    int tamanho = strlen(palavra) - 1;
    for (int i = tamanho; i >= 0 && !temfilhos; i--) {
        index = palavra[i] - 'a';
        free(atual);
        atual = caminho[i];
        atual->filho[index] = NULL;

        // Verifica se o nÛ atual È prefixo de outra palavra
        for (int j = 0; j < 26; j++) {
            if (atual->filho[j] != NULL) {
                temfilhos = true;
                break;
            }
        }
    }

    return true;  // palavra removida
}

// libera a memÛria
void freeTrie(TrieNode* root) {
    if (root == NULL) {
        return;
    }
    for (int i = 0; i < 26; i++) {
        freeTrie(root->filho[i]);
    }
    free(root);
}

int main(){

    char chaves[][20] = {"amy", "ann", "emma", "rob" , "roger", "robert", "bob", "emmily"};


    TrieNode* root = createNode();

/*
    int numChaves = sizeof(chaves) / sizeof(chaves[0]);
    for (int i = 0; i < numChaves; i++) {
        insert(root, chaves[i]);
    }

    // busca palavras
    for (int i = 0; i < numChaves; i++) {
        search(root, chaves[i]);
    }

    char* prefixo_busca = "ro";

    int j = 0; 


    // obtÍm todas as palavras com o seguinte prefixo:
    char* palavras[100];
    int contagem = 0;
    prefixes(root, prefixo_busca, palavras, &contagem);           //
    printf("\nPalavras com o prefixo '%s':\n", prefixo_busca);


    for (int i = 0; i < contagem; i++) {
        printf("%s\n", palavras[i]);
        free(palavras[i]);
    }


    // remove
    printf("%s\n", removeWord(root, chaves[j]) ? "\nPalavra removida!" : "\nPalavra n„o encontrada!");

    // confirma remoÁ„o
    printf("%s\n", search(root, chaves[j]) ? "Palavra encontrada!" : "Palavra n„o encontrada!");

    // Libera a memÛria
    freeTrie(root);

*/
    return 0;
}