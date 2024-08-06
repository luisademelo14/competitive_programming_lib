#include <bits/stdc++.h>
#include <unordered_map>
 
using namespace std;
typedef long long ll;
 
int inf = 1e9;
 
vector<vector<pair<int, int>>> graph;
 
int n;
 
// manipular a funcao de diametro pra retornar um vetor com todas as distancias
pair<int,vector<int>> farthest_node(int root){
    //int n = (int) graph.size();
    vector<int> dist(n,inf);
    dist[root] = 0;
    queue<int> q;
    q.push(root);
    int last_node = root;
    // usando bfs pra achar o vertice mais distante de root
    while(!q.empty()){
        int node = q.front();
        q.pop();
        last_node = node;
        for(pair<int,int> neighbour : graph[node]){
            int neighbour_index = neighbour.first;
            int edge_length = neighbour.second;
            if(dist[neighbour_index]==inf){
                dist[neighbour_index] = dist[node] + edge_length;
                q.push(neighbour_index);
            }
        }
    }
    // no final, last_node eh o vertice mais distante de root
    // na arvore
    return make_pair(last_node, dist);
}
 
void max_dists_solver(){
    pair<int,vector<int>> farthest_from0 = farthest_node(0);
    pair<int,vector<int>> diameter_node1 = farthest_node(farthest_from0.first);
    pair<int,vector<int>> diameter_node2 = farthest_node(diameter_node1.first);
 
    for(int i=0; i<n; i++){
        cout << max(diameter_node1.second[i], diameter_node2.second[i]) << ' ';
    }
}
 
void solve(){
    cin >> n;
    int a, b;
    graph = vector<vector<pair<int, int>>> (n);
    for(int i=0; i<n-1; i++){
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(make_pair(b,1));
        graph[b].push_back(make_pair(a,1));
    }
 
    max_dists_solver();
    cout << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}