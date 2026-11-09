/**
 * @file 01OrdenacaoExterna.c
 * @author Djonatan Riquelme Clein Bonelli
 * @version 0.1
 * @date 2023-06-10
 *
 * @copyright Copyright (c) 2023
 *
 * @brief Arquivo template para Questão 02 do trabalho de Pesquisa e Ordenação T2.
 *
 *      Implemente uma ordenação externa utilizando a restrição de que somente 5
 *  elementos podem ser armazenados em memória (vetores de teste no template). A
 *  definição deste limite está na variável MAX_IN_MEMORY abaixo.
 *
 *      Utilize os vetores comentados no código para realizar seus testes.
 *
 * Atenção: Antes de entregar, conferir se dos dados de documentação no início
 * do arquivo estão preenchidos corretamente.
 *
 */

#include <stdio.h>

#define MAX_IN_MEMORY 5
#include <stdio.h>
#include <stdlib.h>

#define MAX_IN_MEMORY 5

void merge(int array[], int esquerdo, int meio, int direito) {
    int i, j, k;
    int n1 = meio - esquerdo + 1;
    int n2 = direito - meio;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = array[esquerdo + i];
    for (j = 0; j < n2; j++)
        R[j] = array[meio + 1 + j];

    i = 0;
    j = 0;
    k = esquerdo;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int array[], int esquerdo, int direito) {
    if (esquerdo < direito) {
        int meio = esquerdo + (direito - esquerdo) / 2;
        mergeSort(array, esquerdo, meio);
        mergeSort(array, meio + 1, direito);
        merge(array, esquerdo, meio, direito);
    }
}

void externalSort(int array[], int size) {
    FILE* arquivosTemporarios[MAX_IN_MEMORY];
    int buffer[MAX_IN_MEMORY];

    int numChunks = size / MAX_IN_MEMORY;
    int restantes = size % MAX_IN_MEMORY;

    for (int i = 0; i < numChunks; i++) {
        char fileName[10];
        sprintf(fileName, "temp%d.txt", i);
        arquivosTemporarios[i] = fopen(fileName, "w");

        for (int j = 0; j < MAX_IN_MEMORY; j++) {
            fprintf(arquivosTemporarios[i], "%d\n", array[i * MAX_IN_MEMORY + j]);
        }

        fclose(arquivosTemporarios[i]);

        FILE* arquivoTemporario = fopen(fileName, "r");
        for (int j = 0; j < MAX_IN_MEMORY; j++) {
            fscanf(arquivoTemporario, "%d", &buffer[j]);
        }
        fclose(arquivoTemporario);

        mergeSort(buffer, 0, MAX_IN_MEMORY - 1);

        arquivosTemporarios[i] = fopen(fileName, "w");
        for (int j = 0; j < MAX_IN_MEMORY; j++) {
            fprintf(arquivosTemporarios[i], "%d\n", buffer[j]);
        }
        fclose(arquivosTemporarios[i]);
    }

    if (restantes > 0) {
        char fileName[10];
        sprintf(fileName, "temp%d.txt", numChunks);
        arquivosTemporarios[numChunks] = fopen(fileName, "w");

        for (int i = 0; i < restantes; i++) {
            fprintf(arquivosTemporarios[numChunks], "%d\n", array[numChunks * MAX_IN_MEMORY + i]);
        }

        fclose(arquivosTemporarios[numChunks]);

        FILE* arquivoTemporario = fopen(fileName, "r");
        for (int i = 0; i < restantes; i++) {
            fscanf(arquivoTemporario, "%d", &buffer[i]);
        }
        fclose(arquivoTemporario);

        mergeSort(buffer, 0, restantes - 1);

        arquivosTemporarios[numChunks] = fopen(fileName, "w");
        for (int i = 0; i < restantes; i++) {
            fprintf(arquivosTemporarios[numChunks], "%d\n", buffer[i]);
        }
        fclose(arquivosTemporarios[numChunks]);

        numChunks++;
    }

    int resultantes[size];
    int index[numChunks];
    FILE* arquivoResultante = fopen("resultantes.txt", "w");

    for (int i = 0; i < numChunks; i++) {
        char fileName[10];
        sprintf(fileName, "temp%d.txt", i);
        arquivosTemporarios[i] = fopen(fileName, "r");

        fscanf(arquivosTemporarios[i], "%d", &resultantes[i]);
        index[i] = i;

        fprintf(arquivoResultante, "%d\n", resultantes[i]);

        fclose(arquivosTemporarios[i]);
    }

    while (1) {
        int minIndex = -1;
        int minValue;

        for (int i = 0; i < numChunks; i++) {
            if (index[i] != -1 && (minIndex == -1 || resultantes[i] < minValue)) {
                minIndex = i;
                minValue = resultantes[i];
            }
        }

        if (minIndex == -1) {
            break;
        }

        fprintf(arquivoResultante, "%d\n", minValue);

        FILE* arquivoTemporario = fopen(arquivosTemporarios[minIndex], "r");
        if (fscanf(arquivoTemporario, "%d", &resultantes[minIndex]) == EOF) {
            index[minIndex] = -1;
        }
        fclose(arquivoTemporario);
    }

    fclose(arquivoResultante);

    for (int i = 0; i < numChunks; i++) {
        char fileName[10];
        sprintf(fileName, "temp%d.txt", i);
        remove(fileName);
    }
}


int main() {

    int chaves = {3, 98, 61, 62,  1, 99, 57, 98, 58, 18, 59, 35, 82, 91, 52, 95, 46,
        69, 48, 82, 52,  4, 87, 38, 44, 42, 72,  2, 95, 84, 34, 40, 23, 11, 75,
        37, 62, 96, 12, 22, 56, 20, 64,  2, 30, 48,  6, 19, 34, 31};
    int chaves = {57, 91, 21, 89, 72, 74, 46, 61, 26, 50, 85, 76, 53, 22, 15, 40, 90, 2, 94, 54};
    int chaves = {9,  2, 15, 19, 10, 14,  4, 13,  2, 19};
    int chaves = {178, 231, 244, 292, 321, 356, 389, 421, 482, 488, 490, 502, 546, 641, 694, 786, 841, 890, 899, 922};

    // chaves ordenadas
    /*
    int chaves1[] = {3, 98, 61, 62, 1, 99, 57, 98, 58, 18, 59, 35, 82, 91, 52, 95, 46, 69, 48, 82, 52, 4, 87, 38, 44, 42, 72, 2, 95, 84, 34, 40, 23, 11, 75, 37, 62, 96, 12, 22, 56, 20, 64, 2, 30, 48, 6, 19, 34, 31};
    int size1 = sizeof(chaves1) / sizeof(chaves1[0]);

    int chaves2[] = {57, 91, 21, 89, 72, 74, 46, 61, 26, 50, 85, 76, 53, 22, 15, 40, 90, 2, 94, 54};
    int size2 = sizeof(chaves2) / sizeof(chaves2[0]);

    int chaves3[] = {9, 2, 15, 19, 10, 14, 4, 13, 2, 19};
    int size3 = sizeof(chaves3) / sizeof(chaves3[0]);

    int chaves4[] = {178, 231, 244, 292, 321, 356, 389, 421, 482, 488, 490, 502, 546, 641, 694, 786, 841, 890, 899, 922};
    int size4 = sizeof(chaves4) / sizeof(chaves4[0]);

    externalSort(chaves1, size1);
    externalSort(chaves2, size2);
    externalSort(chaves3, size3);
    externalSort(chaves4, size4);
    */

    return 0;
}