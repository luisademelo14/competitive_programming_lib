#include <bits/stdc++.h>
#include <unordered_map>
 
using namespace std;
typedef long long ll;
 
const ll inf = 1e18;
 
ll n, m, k;
 
vector<vector<pair<ll,ll>>> graph; // grafo direcionado com peso nas arestas
 
vector<vector<ll>> dist; // dist[i][j] = j-ésima menor distancia de 1 ate i
 
void print_solution(){
    for(int i=0; i<k; i++){
        cout << dist[n][i] << ' ';
    }
 
    cout << endl;
}
 
void dijkstra(){
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
 
    pq.push({0,1}); // custo 0 para chegar em 1
 
    while(!pq.empty()){
        ll cost = pq.top().first;
        ll v = pq.top().second;
        pq.pop();
 
        if(dist[v][k-1] < cost)
            continue;
        
        for(auto u : graph[v]){
            ll a = u.first;
            ll b = u.second;
 
            if(dist[a][k-1]>cost+b){
                dist[a][k-1]=cost+b;
                pq.push({dist[a][k-1], a});
                sort(dist[a].begin(), dist[a].end());
            }
        }
    }
}
 
void solve(){
    cin >> n >> m >> k;
 
    graph = vector<vector<pair<ll,ll>>> (n+5);
 
    dist = vector<vector<ll>> (n+5);
 
    ll a, b, c;
 
    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
    }
 
    for(int i=1; i<=n; i++){
        dist[i].resize(k);
        for(int j=0; j<k; j++){
            dist[i][j] = inf;
        }
    }
 
    dist[1][0] = 0; // caso base
 
    dijkstra();
 
    print_solution();
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}