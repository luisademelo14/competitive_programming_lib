#include <bits/stdc++.h>
#include <unordered_map>
 
using namespace std;
typedef long long ll;

// algoritmo de kosaraju para encontrar SCCs de um grafo

// complexidade do algoritmo: O(n+m)

vector<vector<int>> graph, inv_graph;

vector<int> visited;

vector<int> scc; // scc[i] = numero que corresponde ao SCC
                 // ao qual o vertice i pertence 

int n; // numero de vertices do grafo

// primeira dfs a ser rodada
// coloca os nos que ja foram processados (incluindo seus vizinhos) na pilha
void dfs_scc(int node, stack<int> &s){
    visited[node] = true;
    for(int neighbour : graph[node]){
        if(!visited[neighbour])
            dfs_scc(neighbour, s);
    }
    s.push(node);
}

// forma a pilha a partir da primeira dfs
stack<int> get_stack(){
    stack<int> s;
    visited.assign(n, false);
    for(int i=0; i<n; i++){
        if(!visited[i])
            dfs_scc(i, s);
    }
    return s;
}

// inverte todas as arestas do grafo
void invert_graph(){
    inv_graph.assign(n, vector<int>());
    for(int i=0; i<n; i++){
        for(int u : graph[i]){
            inv_graph[u].push_back(i);
        }
    }
}

// segunda dfs do algoritmo, que vai contar os SCCs do grafo 
void dfs_cc(int node, int cnt){
    scc[node] = cnt;
    for(int neighbour : inv_graph[node]){
        if(scc[neighbour]==-1){
            dfs_cc(neighbour, cnt);
        }
    }
}

// tirando os elementos da pilha e rodando a segunda dfs 
// pra achar os SCCs do grafo 
void find_scc(stack<int> &s){
    scc.assign(n, -1);
    int qnt_scc = 0;
    int curr_node;
    while(!s.empty()){
        curr_node = s.top();
        s.pop();
        if(scc[curr_node]==-1){
            dfs_cc(curr_node, qnt_scc);
            qnt_scc++;
        }
    }
}


// funcao problem solver (chama as outras)
void strongly_connected_comp(){
    n = (int) graph.size();

    stack<int> s = get_stack();

    invert_graph();

    find_scc(s);
}