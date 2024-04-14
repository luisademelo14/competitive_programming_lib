#include <bits/stdc++.h>
#include <unordered_map>
 
using namespace std;
typedef long long ll;
 
int inf = 1e9;
 
int n, m;
 
vector<vector<pair<int, int>>> graph;
 
ll mst_prim(){
    // int n = (int) graph.size();
 
    vector<bool> taken(n,false);
 
    priority_queue<pair<int,int>> pq;
 
    pq.push(make_pair(0,0));
 
    ll total_sum = 0;
    int nodes_taken = 0;
 
    while(!pq.empty()){
        int node = pq.top().second;
        int edge = -pq.top().first;
        pq.pop();
        // se esse vertice ja esta na arvore, nao processar ele
        if(taken[node])
            continue;
 
        total_sum += edge;
        taken[node] = true;
        nodes_taken++;
 
        if(nodes_taken==n)
            break;
        
        for(pair<int,int> neighbour : graph[node]){
            int neighbour_index = neighbour.first;
            int edge_length = neighbour.second;
            if(!taken[neighbour_index])
                pq.push(make_pair(-edge_length, neighbour_index));
        }
 
    }
    if(nodes_taken<n)
        return -1;
 
    // soma de todas as arestas da mst
    return total_sum;
}
 
void solve(){
    cin >> n >> m;
    int a, b, c;
    graph = vector<vector<pair<int, int>>> (n);
 
    while(m--){
        cin >> a >> b >> c;
        a--;
        b--;
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }
 
    ll cost = mst_prim();
 
    if(cost==-1)
        cout << "IMPOSSIBLE" << endl;
 
    else
        cout << cost << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}