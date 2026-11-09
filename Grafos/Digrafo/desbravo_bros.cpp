/*
 * Tarefa 04 - Desbravo Bros.
 *
 * GEN254 - Grafos - 2023/2
 *
 * Nome:      Djonatan Riquelme Clein Bonelli
 * Matricula: 2211100011
 */

#include <iostream>
#include "Digrafo.h"

int main() {

    int R, C;
    std::cin >> R >> C;
    Digrafo digrafo(R);

    for (int i = 0; i < C; ++i) {
        int X, Y, D;
        std::cin >> X >> Y >> D;
        digrafo.insere_aresta(Aresta(X, Y, -D));
    }

    int O;
    std::cin >> O;

    for (int i = 0; i < O; ++i) {
        int X;
        std::cin >> X;
        digrafo.bellman_ford(X);
    }

    return 0;
}
