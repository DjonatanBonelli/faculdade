#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct Node {
    char data;
    unsigned frequencia;
    struct Node* left;
    struct Node* right;
};
struct Node* novoNo(char data, unsigned frequencia)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->frequencia = frequencia;
    temp->left = temp->right = NULL;
    return temp;
}

int compara(const void* a, const void* b)
{
    struct Node* node1 = *(struct Node**)a;
    struct Node* node2 = *(struct Node**)b;
    return (node1->frequencia) - (node2->frequencia);
}
struct Node* criaArvore(char data[], int tamanho)
{
    struct Node *left, *right, *top;

    //cria lista de inserção
    struct Node** heap = (struct Node**)malloc(tamanho * sizeof(struct Node*));
    int tamanhoHeap = 0;

    // Verifica se o nó já existe no heap antes de inserir
    int i;
    for (i = 0; i < tamanho; ++i) {
        int j;
        for (j = 0; j < tamanhoHeap; ++j) {
            if (heap[j]->data == data[i]) {
                // Nó já existe, não insere novamente
                break;
            }
        }
        if (j == tamanhoHeap) {
            // Nó não existe, insere no heap
            heap[tamanhoHeap] = novoNo(data[i], 0);
            tamanhoHeap++;
        }
    }

    while (tamanhoHeap > 1) {
        qsort(heap, tamanhoHeap, sizeof(struct Node*), compara);

        left = heap[0];
        right = heap[1];
        top = novoNo('$', left->frequencia + right->frequencia);
        top->left = left;
        top->right = right;

        heap[0] = top;
        heap[1] = heap[tamanhoHeap - 1];
        tamanhoHeap--;
    }

    struct Node* root = heap[0];
    free(heap);
    return root;
}

void geraCodigo(struct Node* root, int code[], int top)
{
    if (root->left) {
        code[top] = 0;
        geraCodigo(root->left, code, top + 1);
    }

    if (root->right) {
        code[top] = 1;
        geraCodigo(root->right, code, top + 1);
    }

    if (!(root->left) && !(root->right)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", code[i]);
        printf("\n");
    }
}

void imprimeArvore(struct Node* root)
{
    int code[100];
    geraCodigo(root, code, 0);
}

int main()
{
    char input[100];

    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';  // remove o caractere de nova linha

    int tamanho = strlen(input);

    unsigned frequencia[256] = { 0 };
    for (int i = 0; i < tamanho; ++i)
        frequencia[(unsigned char)input[i]]++;

    struct Node* root = criaArvore(input, tamanho);

    imprimeArvore(root);

    return 0;
}