#include <bits/stdc++.h>
#include <unordered_map>
 
using namespace std;
typedef long long ll;

const int inf = 1e9;

vector<vector<pair<int,int>>> graph;

// quando usar: temos um vertice de saida e queremos calcular a menor distancia
// entre ele e pelo menos um dos outros vertices do grafo (mesma situacao do dijkstra)

// detecta se existe ciclo negativo acalcavel a partir
// do vertice source

// o algoritmo so consegue retornar as menores distancias se o grafo 
// nao tiver ciclo negativo

// complexidade do algoritmo: O(V*E) - onde V eh o numero de vertices e 
// E eh o numero de arestas


bool has_negative_cycle(int source){
    int n = (int) graph.size();

    vector<int> dist(n, inf);

    dist[source] = 0;

    // parte do algoritmo que calcula as menores distancias
    // partindo de vertice source
    for(int i=1; i<=n-1; i++){
        for(int node=0; node<n; node++){
            for(auto neighbour : graph[node]){
                int neighbour_index = neighbour.first;
                int edge_length = neighbour.second;
                dist[neighbour_index] = min(dist[neighbour_index],
                dist[node] + edge_length);
            }
        }
    }

    // parte do algoritmo que detecta se ha ciclo negativo no grafo
    // alcancavel a partir do vertice source
    for(int node=0; node<n; node++){
        for(auto neighbour : graph[node]){
            int neighbour_index = neighbour.first;
            int edge_length = neighbour.second;
            // detectando a existencia de um ciclo negativo
            if(dist[node] + edge_length < dist[neighbour_index])
                return true;
        }
    }

    // nao detectamos ciclos negativos a partir de source
    return false;
}