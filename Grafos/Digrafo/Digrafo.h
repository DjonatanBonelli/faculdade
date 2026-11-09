/*
 * Tarefa 04 - Desbravo Bros.
 *
 * GEN254 - Grafos - 2023/2
 *
 * Nome:      Djonatan Riquelme Clein Bonelli
 * Matricula: 2211100011
 */

#ifndef DIGRAFO_H

#define DIGRAFO_H

#include <list>
#include <vector>
#include <utility>
#include "Aresta.h"

class Digrafo {
public:
    Digrafo(int num_vertices);
    int num_vertices();
    int num_arestas();
    void insere_aresta(Aresta e);
    void remove_aresta(Aresta e);
    void remove_vertice(int v);
    std::vector<int> bellman_ford(int r);
    void imprime();
private:
    int num_vertices_;
    int num_arestas_;
    std::vector<std::list<std::pair<int, int>>> lista_adj_;
};

#endif /* DIGRAFO */