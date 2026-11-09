/*
 * @file Ordenação.c
 * @author Djonatan Riquelme Clein Bonelli
 * @version 0.3
 * @date 2023-03-30
 *
 * @copyright Copyright (c) 2023
 *
 *
 * @brief Arquivo template para trabalho de Pesquisa e Ordenação.
 *
 *      Cada estudante deve implementar as funções conforme as assinaturas
 * abaixo e realizar as impressões dos vetores após a ordenação. Desta forma,
 * o(a) estudante deve implementar o trecho de código para impressão dos vetores
 * ordenados dentro da função `main` conforme o exemplo do Bubble Sort abaixo.
 *
 * Se necessário, declare e implemente funções auxiliares para realizar as
 * ordenações.
 *
 * Importante:Não altere as assinaturas dos métodos de ordenação!
 *
 * Caso o vetor não possa ser ordenado por algum método, imprima uma mensagem de
 * aviso e o vetor original.
 *
 * Atenção: Antes de entregar, conferir se dos dados de documentação no início
 * do arquivo estão preenchidos corretamente.
 *
 */
#include <stdio.h>

void troca(int *a, int *b);
void copia(int *A, int *v, int size);
void bubbleSort(int *A, int size);
void selectionSort(int *A, int size);
void insertionSort(int *A, int size);
void mergeSort(int *A, int size);
void quickSort(int *A, int size);
void heapSort(int *A, int size);
void countingSort(int *A, int size);
void radixSort(int *A, int size);


int main(){
    int flag = 0;
    int i;
    int vetor[] = {1, 22, -10, 38, 5, 7};
    int tamanhoVetor = (int)sizeof(vetor)/sizeof(int);

    printf("\nVetor original: ");
    for (i = 0 ; i < tamanhoVetor ; i++)
        printf("%d ", vetor[i]);

    printf("\nVetor tamanho = %d\n", tamanhoVetor);

    // bubble sort
    int bubbleVec[tamanhoVetor];
    copia(vetor, bubbleVec, tamanhoVetor);
    bubbleSort(bubbleVec, tamanhoVetor);
    printf("\nBubble sort: ");
    for (i = 0 ; i < tamanhoVetor; i++)
        printf("%d ", bubbleVec[i]);
    printf("\n");

    // selection sort
    int selectionVec[tamanhoVetor];
    copia(vetor, selectionVec, tamanhoVetor);
    selectionSort(selectionVec, tamanhoVetor);
    printf("\nSelection sort: ");
    for(i = 0; i < tamanhoVetor; i++)
        printf("%d ", selectionVec[i]);
    printf("\n");

    // insertion sort
    int insertionVec[tamanhoVetor];
    copia(vetor, insertionVec, tamanhoVetor);
    insertionSort(insertionVec, tamanhoVetor);
    printf("\nInsertion sort: ");
    for (i = 0; i < tamanhoVetor; i++)
        printf("%d ", insertionVec[i]);
    printf("\n");
    
    // merge sort
    int mergeVec[tamanhoVetor];
    copia(vetor, mergeVec, tamanhoVetor);
    mergeSort(mergeVec, tamanhoVetor);
    printf("\nMerge sort: ");
    for (i = 0; i < tamanhoVetor; i++)
        printf("%d ", mergeVec[i]);
    printf("\n");

    // quick sort
    int quickVec[tamanhoVetor];
    copia(vetor, quickVec, tamanhoVetor);
    quickSort(quickVec, tamanhoVetor-1);
    printf("\nQuick sort: ");
    for (i = 0; i < tamanhoVetor; i++)
        printf("%d ", quickVec[i]);
    printf("\n");

    // heap sort
    int heapVec[tamanhoVetor];
    copia(vetor, heapVec, tamanhoVetor);
    heapSort(heapVec, tamanhoVetor);
    printf("\nHeap sort: ");
    for (i = 0; i < tamanhoVetor; i++)
        printf("%d ", heapVec[i]);
    printf("\n");

    // counting sort
        int countingVec[tamanhoVetor];
        copia(vetor, countingVec, tamanhoVetor);
        
        for(int i = 0; i != tamanhoVetor; i++){
        
        if(vetor[i] < 0){ //verifica a validade do vetor
            flag += 1;
        }
    }

        if(flag == 0){ //chama a funcao se o vetor for valido

            countingSort(countingVec, tamanhoVetor);
            printf("\nCounting sort: ");
            for (i = 0; i < tamanhoVetor; i++)
                printf("%d ", countingVec[i]);
            printf("\n");
        }

        if(flag != 0){ //se o vetor for invalido
            printf("\nIndice negativo. Vetor invalido para counting sort!\n");
                printf("\nVetor original: ");
                for (i = 0 ; i < tamanhoVetor ; i++)
                    printf("%d ", vetor[i]);
        }
        printf("\n");

    flag = 0;

    // radix sort
    int radixVec[tamanhoVetor];
    copia(vetor, radixVec, tamanhoVetor);
        for(int i = 0; i < tamanhoVetor; i++){

        if(vetor[i] < 0){ //verifica a validade do vetor
            flag += 1;          
        }
    }   
        if(flag == 0) { //chama a funcao se o vetor for valido

            radixSort(radixVec, tamanhoVetor);
            printf("\nRadix sort: ");
            for (i = 0; i < tamanhoVetor; i++)
                printf("%d ", radixVec[i]);
            printf("\n");

        }
        if(flag != 0){ //se o vetor for invalido
            printf("\nIndice negativo. Vetor invalido para radix sort!\n");
            printf("\nVetor original: ");
            for (i = 0 ; i < tamanhoVetor ; i++)
                printf("%d ", vetor[i]);
        }
            printf("\n");
    flag = 0;

    return 0;
}

void troca(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void copia(int *A, int *V, int size){
    int i;
    for (i = 0 ; i < size ; i++)
        V[i] = A[i];
}

int particao(int *A, int low, int size) {
    int aux = A[size];
    int i = (low - 1);
    for (int j = low; j <= size - 1; j++) {
        if (A[j] <= aux) {
            i++;
            troca(&A[i], &A[j]);
        }
    }
    troca(&A[i + 1], &A[size]);
    return (i + 1);
}

void heap(int *A, int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && A[left] > A[largest]) {
        largest = left;
    }
    if (right < size && A[right] > A[largest]) {
        largest = right;
    }
    if (largest != i) {
        troca(&A[i], &A[largest]);
        heap(A, size, largest);
    }
}

void merge(int *A, int *left, int left_size, int *right, int right_size) {
    int i = 0, j = 0, k = 0;
    while (i < left_size && j < right_size) {
        if (left[i] < right[j]) {
            A[k++] = left[i++];
        } else {
            A[k++] = right[j++];
        }
    }
    while (i < left_size) {
        A[k++] = left[i++];
    }
    while (j < right_size) {
        A[k++] = right[j++];
    }
}

void quick(int *A, int k, int size){
    if (k < size) {
        int aux = particao(A, k, size);
        quick(A, k, aux - 1);
        quick(A, aux + 1, size);
    }
}

int buscaMaior(int *A, int size){
    int k = A[0];   //maior indice
    for (int i = 0; i < size; i++)
        if (A[i]<A[i+1])
        {
            k = A[i+1];
        }
        return k;
}

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Realiza a ordenação do array com base no dígito especificado pelo exp
void countSort(int *A, int size, int exp) {
    int output[size];
    int count[10] = {0};

    // Contagem da ocorrência de cada dígito
    for (int i = 0; i < size; i++) {
        count[(A[i]/exp)%10]++;
    }

    // Soma acumulativa das contagens
    for (int i = 1; i < 10; i++) {
        count[i] += count[i-1];
    }

    // Coloca os elementos em output de acordo com a posição do dígito
    for (int i = size-1; i >= 0; i--) {
        output[count[(A[i]/exp)%10]-1] = A[i];
        count[(A[i]/exp)%10]--;
    }

    // Copia o array ordenado para o array original
    for (int i = 0; i < size; i++) {
        A[i] = output[i];
    }
}


void bubbleSort(int *A, int size){
    int aux, houve_troca, i, j;

    for(i = 0; i < size-1; i++){
        houve_troca = 0;
        for(j = 0; j < size-i-1; j++){
            if(A[j] > A[j+1]){
               aux = A[j];
               A[j] = A[j+1];
               A[j+1] = aux;
               houve_troca += 1; 
            }
        }
        if(houve_troca == 0){
            break;
        }   
    }
}

void selectionSort(int *A, int size){
    int menor_numero, i, j, aux;

    for(i = 0; i != size; i++){
        menor_numero = i;
        for(j = i+1; j != size; j++){
            if(A[menor_numero] > A[j]){
                menor_numero = j;
            }
        }
        aux = A[i];
        A[i] = A[menor_numero];
        A[menor_numero] = aux;
    }
    
}

void insertionSort(int *A, int size){
   int i, j, key;
   for (i = 1; i <  size; i++) {
       key = A[i];
       j = i - 1;
       while (j >= 0 && A[j] > key) {
           A[j+1] = A[j];
           j = j - 1;
       }
       A[j+1] = key;
   }
}

void mergeSort(int *A, int size) {
    if (size > 1) {
        int mid = size / 2;
        int left[mid];
        int right[size - mid];
        for (int i = 0; i < mid; i++) {
            left[i] = A[i];
        }
        for (int i = mid; i < size; i++) {
            right[i - mid] = A[i];
        }
        mergeSort(left, mid);
        mergeSort(right, size - mid);
        merge(A, left, mid, right, size - mid);
    }
}

void quickSort(int *A, int size){
    quick(A, 0, size);
}


void heapSort(int *A, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heap(A, size, i);
    }
    for (int i = size - 1; i >= 0; i--) {
        troca(&A[0], &A[i]);
        heap(A, i, 0);
    }
}

void countingSort(int *A, int size) {
    int k = buscaMaior(A, size);
    int count[k+1];
    for (int i = 0; i <= k; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        count[A[i]]++;
    }
    for (int i = 1; i <= k; i++) {
        count[i] += count[i-1];
    }
    int output[size];
    for (int i = size-1; i >= 0; i--) {
        output[count[A[i]]-1] = A[i];
        count[A[i]]--;
    }
    for (int i = 0; i < size; i++) {
        A[i] = output[i];
    }
}

void radixSort(int *A, int size) {
    int m = getMax(A, size);
    for (int exp = 1; m/exp > 0; exp *= 10) {
        countSort(A, size, exp);
    }
}