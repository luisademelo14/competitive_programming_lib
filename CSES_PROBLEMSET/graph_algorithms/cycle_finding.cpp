#include <bits/stdc++.h>
#include <unordered_map>
 
using namespace std;
typedef long long ll;
 
ll inf = 1e18;
 
int n, m;
 
vector<vector<pair<int,int>>> graph;
 
vector<int> previous;
 
void get_cycle(int node, int cycle_beginning){
    if(node!=cycle_beginning)
        get_cycle(previous[node], cycle_beginning);
    cout << node+1 << ' ';
}
 
void has_negative_cycle(int source){
    int n = (int) graph.size();
 
    vector<ll> dist(n, inf);
    previous.assign(n,-1);
 
    dist[source] = 0;
 
    // parte do algoritmo que calcula as menores distancias
    // partindo de vertice source
    for(int i=1; i<=n-1; i++){
        for(int node=0; node<n; node++){
            for(auto neighbour : graph[node]){
                int neighbour_index = neighbour.first;
                int edge_length = neighbour.second;
                if(dist[node] + edge_length < dist[neighbour_index]){
                    dist[neighbour_index] = dist[node] + edge_length;
                    previous[neighbour_index] = node;
                }
            }
        }
    }
 
    int cycle_node = -1;
    // parte do algoritmo que detecta se ha ciclo negativo no grafo
    // alcancavel a partir do vertice source
    for(int node=0; node<n; node++){
        for(auto neighbour : graph[node]){
            int neighbour_index = neighbour.first;
            int edge_length = neighbour.second;
            // detectando a existencia de um ciclo negativo
            if(dist[node] + edge_length < dist[neighbour_index]){
                dist[neighbour_index] = dist[node] + edge_length;
                previous[neighbour_index] = node;
                cycle_node = neighbour_index;                
            }     
        }
    }
 
    // nao detectamos ciclos negativos a partir de source
    if(cycle_node==-1){
        cout << "NO" << endl;
        return;
    }
 
    cout << "YES" << endl;
 
    // executar essa iteracao pelo menos n vezes pra garantir que estamos
    // em um dos vertices do loop!!
    for(int i=0; i<n; i++)
        cycle_node = previous[cycle_node];
    
    get_cycle(previous[cycle_node], cycle_node);
 
    cout << cycle_node+1;
}
 
void solve(){
    cin >> n >> m;
    int a, b, w;
    graph = vector<vector<pair<int,int>>> (n);
    while(m--){
        cin >> a >> b >> w;
        a--;
        b--;
        graph[a].push_back(make_pair(b,w));
    }
    has_negative_cycle(0);
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    cout << endl;
    return 0;
}