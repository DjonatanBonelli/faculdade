/*
 * Tarefa 02 - Potenciais Comparsas
 *
 * GEN254 - Grafos - 2023/2
 *
 * Nome:      Djonatan Riquelme Clein Bonelli
 * Matricula: 2211100011
 */

#ifndef GRAFO_H

#define GRAFO_H

#include <list>
#include <vector>

#include "Aresta.h"

class Grafo {
public:
    Grafo(int num_vertices);
    // ~Grafo(); // Se necessario
    int num_vertices();
    int num_arestas();
    void insere_aresta(Aresta e);
    void remove_aresta(Aresta e);
    void remove_vertice(int v);
    std::vector<int> buscaEmProfundidade(int origem);
    std::vector<int> buscaEmLargura(int origem);
    void imprime();
private:
    int num_vertices_;
    int num_arestas_;
    std::vector<std::list<int>> lista_adj_;
};

#endif /* GRAFO_H */
