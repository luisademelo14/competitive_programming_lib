#include <bits/stdc++.h>
#include <unordered_map>
 
using namespace std;
typedef long long ll;

vector<vector<int>> graph; // lista de adj

int n; // numero de vertices


// incoming[i] representa a quantidade de vertices que devem vir antes de i
vector<int> get_incoming(){
    vector<int> incoming(n, 0);
    for(int i=0; i<n; i++){
        for(int neighbour : graph[i]){
            incoming[neighbour]++;
        }
    }
    return incoming;
}

queue<int> get_sources(vector<int> &incoming){
    queue<int> q;
    for(int i=0; i<n; i++){
        if(incoming[i]==0)
            q.push(i);
    }
    return q;
}


vector<int> get_order(vector<int> &incoming, queue<int> &sources){
    vector<int> order;
    // ideia parecida com o algoritmo da bfs
    while(!sources.empty()){
        int node = sources.front();
        sources.pop();
        order.push_back(node);
        for(int neighbour : graph[node]){
            incoming[neighbour]--;
            // se incoming[n] == 0, quer dizer que n é um vértice source
            if(incoming[neighbour]==0)
                sources.push(neighbour);
        }
    }
    return order;
}


vector<int> topological_sort(){
    vector<int> incoming = get_incoming();
    queue<int> sources = get_sources(incoming);
    return get_order(incoming, sources);
}