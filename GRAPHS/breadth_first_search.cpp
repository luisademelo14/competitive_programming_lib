#include "../template.h"

vector<vector<int>> g; // grafo como lista de adj

int n; // numero de vertices

int v0; // vertice do inicio da bfs

queue<int> q; // fila usada pro algoritmo

vector<bool> visited;

vector<int> d(n); // vetor com as distancias minimas

vector<int> p(n); // vetor com os vertices anteriores

void bfs(){
    q.push(v0);
    visited[v0] = true;
    p[v0] = -1;
    while(!q.empty()){
        int v = q.front(); // v eh o vertice atual
        q.pop();
        for(int u : g[v]){ // passando pelos vizinhos de v
            if(!visited[u]){
                visited[u] = true;
                q.push(u);
                // atualizando caminho minimo entre v0 e u
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }
}