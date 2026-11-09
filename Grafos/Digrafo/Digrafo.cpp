/*
 * Tarefa 04 - Desbravo Bros.
 *
 * GEN254 - Grafos - 2023/2
 *
 * Nome:      Djonatan Riquelme Clein Bonelli
 * Matricula: 2211100011
 */

#include "Digrafo.h"
#include <vector>
#include <iostream>
#include <limits>

int Digrafo::num_vertices() {
    return num_vertices_;
}

int Digrafo::num_arestas() {
    return num_arestas_;
}

Digrafo::Digrafo(int num_vertices){
    num_vertices_ = num_vertices;
    num_arestas_ = 0;
    lista_adj_.resize(num_vertices);
}

void Digrafo::insere_aresta(Aresta e) {
    int flag = 0;
    if (e.v1 >= 0 && e.v1 < num_vertices_ &&
        e.v2 >= 0 && e.v2 < num_vertices_ && e.v1 != e.v2) {
        for (auto it = lista_adj_[e.v1].begin(); it != lista_adj_[e.v1].end(); ++it) {
            if (it->first == e.v2) {
                flag++;
                break;
            }
        }
        if (flag == 0) {
            lista_adj_[e.v1].push_front(std::make_pair(e.v2, e.peso));
            num_arestas_++;
        }
    }
}

void Digrafo::remove_aresta(Aresta e) {
    if (e.v1 >= 0 && e.v1 < num_vertices_ && e.v2 >= 0 && e.v2 < num_vertices_) {
        lista_adj_[e.v1].remove_if([v2 = e.v2](const std::pair<int, int>& aresta) {
            return aresta.first == v2;
        });
    } else {
        std::cout << "Vértices inválidos!\n";
    }
}
void Digrafo::remove_vertice(int vertice) {
    if (vertice >= 0 && vertice < num_vertices_) {
        // Remover arestas que saem do vértice
        for (auto& lista : lista_adj_) {
            lista.remove_if([vertice](const std::pair<int, int>& aresta) {
                return aresta.first == vertice;
            });
        }

        // Remover arestas que chegam ao vértice
        lista_adj_[vertice].clear();

        // Atualizar o número de vértices
        num_vertices_--;
    } else {
        std::cout << "Vértice inválido!\n";
    }
}

void Digrafo::imprime(){
    for(int i = 0; i < num_vertices_ ; i++){
        std::cout << i << ":";
        for (const auto& vizinho : lista_adj_[i]) {
            int vizinho_vertice = vizinho.first;
            int peso_aresta = vizinho.second;
}
        std::cout << "\n";
    }
}
void Digrafo::bellman_ford(int source) {
    const int INF = std::numeric_limits<int>::max();
    const int MINF = std::numeric_limits<int>::min();
    std::vector<int> distance(num_vertices_, INF);
    distance[source] = 0;

    // Relaxamento de arestas numVertices - 1 vezes
    for (int i = 1; i <= num_vertices_ - 1; ++i) {
        for (int u = 0; u < num_vertices_; ++u) {
            for (const auto& edge : lista_adj_[u]) {
                int v = edge.first;
                int peso = edge.second;

                if (distance[u] != INF && distance[u] + peso < distance[v]) {
                    distance[v] = distance[u] + peso;
                }
            }
        }
    }

    // Verificação de ciclo negativo
    for (int u = 0; u < num_vertices_; ++u) {
        for (const auto& edge : lista_adj_[u]) {
            int v = edge.first;
            int peso = edge.second;

            if (distance[u] != INF && distance[u] + peso < distance[v]) {
                std::cout << source << ": ilimitada\n";
                return;
            }
        }
    }
    
    // Exibir as distâncias mais curtas
    int ilimitada = 0;    
    int menor = INF;
    for (int i = 0; i < num_vertices_; ++i) {
        if (distance[i] == INF) {
            ilimitada = 1;
        } else {
            ilimitada = 0;
            if(distance[i] < menor){
                menor = distance[i];                
            }
        }
    }
    if(ilimitada == 1 && menor == 9999){
        std::cout << source << ": 0\n";
    }
    else{
        std::cout << source << ": " << -menor << "\n";
    }
    return;
}