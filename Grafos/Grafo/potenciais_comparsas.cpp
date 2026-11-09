/*
 * Tarefa 02 - Potenciais Comparsas
 *
 * GEN254 - Grafos - 2023/2
 *
 * Nome:      Djonatan Riquelme Clein Bonelli
 * Matricula: 2211100011
 */

#include <iostream>
#include "Grafo.h"

int main() {
    
    int P, L, X, Y, O, comparsa;
    char T;
    std::cin >> P >> L;

    Grafo grafo(P);

    for (int i = 0; i < L; i++) {

        std::cin >> X >> Y >> T;

        switch (T)
        {
        case 'W':
            grafo.insere_aresta(Aresta(X, Y));
            break;
        
        default:
            break;
        }

    }

    std::vector<int> comparsas;

    std::cin >> O;

    for (int i = 0; i < O; i++) {
        std::cin >> comparsa;
        comparsas.push_back(comparsa);
    }
    
    for (int i = 0; i < comparsas.size(); i++){
        
        std::vector<bool> visitados = grafo.buscaEmProfundidade(comparsas[i]);
        std::cout << comparsas[i] << ": ";
      
        for (int i = 0; i < visitados.size(); i++) {
            if(visitados[i] == true){
                std::cout << i << " ";
            }
    }
        std::cout << "\n";
    
}
    return 0;
}
