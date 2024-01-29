#include <bits/stdc++.h>
#include <unordered_map>
 
using namespace std;
typedef long long ll;

const int inf = 1e9;

vector<vector<pair<int,int>>> graph;

// complexidade do algoritmo: O(E * log(V)), 
// onde E eh o numero de arestas e V eh o numero de vertices do grafo

// quando usar: temos um vertice de saida e queremos calcular 
// a menor distancia entre ele e pelo menos um dos outros vertices do grafo

// dependendo do problema, podemos mudar a funcao pra retornar 
// o vetor distance (e nao um inteiro)

int dijkstra(int source, int destination){
    int n = (int) graph.size();

    // vetor com as menores distancias do vertice source ate os outros
    vector<int> distance(n, inf);

    distance[source] = 0; // distancia do vertice source ate ele mesmo eh 0

    // na fila de prioridade, temos: {distancia, vertice}
    priority_queue<pair<int,int>> pq;

    pq.push(make_pair(0,source));

    while(!pq.empty()){
        // extraindo o menor caminho da fila de prioridade
        int node = pq.top().second;
        int path_length = -pq.top().first;
        pq.pop();

        // descartamos, porque ja haviamos encontrado um caminho menor ate 'node'
        if(path_length>distance[node])
            continue;
        
        for(pair<int,int> neighbour : graph[node]){
            int neighbour_index = neighbour.first;
            int edge_length = neighbour.second;
            int new_path = distance[node] + edge_length;
            // caso em que achamos um caminho menor que o atual
            if(new_path < distance[neighbour_index]){
                distance[neighbour_index] = new_path;
                pq.push(make_pair(-new_path, neighbour_index));
            }
        }
    }

    return distance[destination];
}