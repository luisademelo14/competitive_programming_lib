#include "../template.h"

// complexidade do algoritmo: O(n+m)

vector<vector<int>> g; // grafo como lista de adj

int n; // numero de vertices

vector<bool> visited(n);

// funcao recursiva que passa pr todos os vertices que
// estao conectados em um grafo
void dfs(int v){
    visited[v] = true;
    for(int u : g[v]){
        if(!visited[u])
            dfs(u);
    }
}