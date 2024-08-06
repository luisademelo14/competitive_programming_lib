#include <bits/stdc++.h>
#include <unordered_map>
 
using namespace std;
typedef long long ll;
 
const ll inf = 1e18;
 
vector<vector<pair<ll,ll>>> graph;
 
ll n, m;
 
// complexidade do algoritmo: O(E * log(V)), 
// onde E eh o numero de arestas e V eh o numero de vertices do grafo
 
// IMPORTANTE: o grafo nao pode conter arestas de peso negativo
 
// quando usar: temos um vertice de saida e queremos calcular 
// a menor distancia entre ele e pelo menos um dos outros vertices do grafo
 
// dependendo do problema, podemos mudar a funcao pra retornar 
// o vetor distance (e nao um inteiro)
 
vector<ll> dijkstra(int source){
    //int n = (int) graph.size();
 
    // vetor com as menores distancias do vertice source ate os outros
    vector<ll> distance(n+1, inf);
 
    distance[source] = 0; // distancia do vertice source ate ele mesmo eh 0
 
    // na fila de prioridade, temos: {distancia, vertice}
    priority_queue<pair<ll,ll>> pq;
 
    pq.push({0,source});
 
    while(!pq.empty()){
        // extraindo o menor caminho da fila de prioridade
        ll node = pq.top().second;
        ll path_length = -pq.top().first;
        pq.pop();
 
        // descartamos, porque ja haviamos encontrado um caminho menor ate 'node'
        if(path_length>distance[node])
            continue;
        
        for(pair<int,int> neighbour : graph[node]){
            ll neighbour_index = neighbour.first;
            ll edge_length = neighbour.second;
            ll new_path = distance[node] + edge_length;
            // caso em que achamos um caminho menor que o atual
            if(new_path < distance[neighbour_index]){
                distance[neighbour_index] = new_path;
                pq.push({-new_path, neighbour_index});
            }
        }
    }
 
    return distance;
}
 
void solve(){
    //int n, m;
    cin >> n >> m;
 
    graph = vector<vector<pair<ll,ll>>> (n+1);
 
    ll a, b, c;
 
    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        //graph[b].push_back({a,c});
    }
 
    vector <ll> dist = dijkstra(1);
 
    for(int i=1; i<=n; i++){
        cout << dist[i] << ' ';
    }
 
    cout << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}