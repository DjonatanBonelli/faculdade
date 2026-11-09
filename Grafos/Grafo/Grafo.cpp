/*
 * Tarefa 02 - Potenciais Comparsas
 *
 * GEN254 - Grafos - 2023/2
 *
 * Nome:      Djonatan Riquelme Clein Bonelli
 * Matricula: 2211100011
 */

#include "Grafo.h"
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <iostream>

int Grafo::num_vertices() {
    return num_vertices_;
}

int Grafo::num_arestas() {
    return num_arestas_;
}

Grafo::Grafo(int num_vertices){
    num_vertices_ = num_vertices;
    num_arestas_ = 0;
    lista_adj_.resize(num_vertices);
}

void Grafo::insere_aresta(Aresta e){
    int flag = 0;
    if (e.v1 >= 0 && e.v1 < num_vertices_ &&
        e.v2 >= 0 && e.v2 < num_vertices_ && e.v1 != e.v2) {
        for (auto it = lista_adj_[e.v1].begin(); it != lista_adj_[e.v1].end(); ++it) {
            if (*it == e.v2) {
                flag++;
            break;
            }    
}
        if(flag == 0){
        lista_adj_[e.v1].push_front(e.v2);
        lista_adj_[e.v2].push_front(e.v1); 
        num_arestas_++;
    }
}
}

void Grafo::remove_aresta(Aresta e){
    if (e.v1 >= 0 && e.v1 < num_vertices_ &&
        e.v2 >= 0 && e.v2 < num_vertices_) {
        for (auto it = lista_adj_[e.v1].begin(); it != lista_adj_[e.v1].end(); ++it) {
            if (*it == e.v2) {
                lista_adj_[e.v1].erase(it);
                num_arestas_--;
            break;
            }
        }
        for (auto it = lista_adj_[e.v2].begin(); it != lista_adj_[e.v2].end(); ++it) {
            if (*it == e.v1) {
                lista_adj_[e.v2].erase(it);
            break;    
        }
    }
    } else {
        std::cerr << "Erro: Tentativa de remover uma aresta inválida." << std::endl;
    }
} 

void Grafo::remove_vertice(int vertice) {
    if (vertice >= 0 && vertice < num_vertices_) {
        for (int i = 0; i < num_vertices_; i++) {
            if (i != vertice) {
                lista_adj_[i].remove(vertice);
            }
        }

        num_arestas_ -= lista_adj_[vertice].size();

        lista_adj_.erase(lista_adj_.begin() + vertice);

        num_vertices_--;

        for (int i = 0; i < num_vertices_; i++) {
            for (auto &vizinho : lista_adj_[i]) {
                if (vizinho > vertice) {
                    vizinho--;
                }
            }
        }
    } else {
        std::cerr << "Erro: Tentativa de remover um vértice inválido." << std::endl;
    }
}

void Grafo::imprime(){
    for(int i = 0; i < num_vertices_ ; i++){
        std::cout << i << ":";
        for(int vizinho : lista_adj_[i]){
            std::cout << " " << vizinho;
        }
        std::cout << "\n";
    }
}
    
std::vector<bool> Grafo::buscaEmProfundidade(int origem) {
    std::vector<bool> visitado(num_vertices_, false);
    std::stack<int> pilha;
    int contador = 0;
    pilha.push(origem);

    while (!pilha.empty() and contador < 4) {
        int atual = pilha.top();
        pilha.pop();
        
        for (int vizinho : lista_adj_[atual]) {
            if (!visitado[vizinho]) {
                visitado[vizinho] = true;
                pilha.push(vizinho);
            }
        }
    contador++;
    }
    visitado[origem] = false;
    return visitado;
};

std::vector<bool> Grafo::buscaEmLargura(int origem) {
    std::vector<bool> visitado(num_vertices_, false);
    std::queue<int> fila;
    
    visitado[origem] = true;
    fila.push(origem);
    
    int profundidadeAtual = 0;

    while (!fila.empty() && profundidadeAtual < 4) {
        int tamanhoFila = fila.size();
        
        for (int i = 0; i < tamanhoFila; i++) {
            int vertice = fila.front();
            fila.pop();
            
            for (int vizinho : lista_adj_[vertice]) {
                if (!visitado[vizinho]) {
                    visitado[vizinho] = true;
                    fila.push(vizinho);
                }
            }
        }
        profundidadeAtual++;
    }
    visitado[origem] = false;
    return visitado;
};