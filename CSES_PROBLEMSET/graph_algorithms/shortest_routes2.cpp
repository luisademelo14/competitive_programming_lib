#include <bits/stdc++.h>
#include <unordered_map>
 
using namespace std;
typedef long long ll;
 
const ll inf = 1e18;
 
// quando usar: para cada par de vertices do grafo, calculamos 
// o menor caminho entre ambos (se existir um caminho entre tais vertices)
 
// funciona tanto pra grafos nao direcionados quanto pra grafos direcionados
 
// eh um algoritmo bom para grafos muito densos (quando o numero 
// de arestas é muito maior que o numero de vertices)
 
// a resposta vai ser armazenada na propria matriz de 
// adjacencia que representa o grafo
 
// complexidade do algoritmo: O(N³), onde N eh o numero de vertices do grafo
 
// grafo representado com matriz de adjacencia
vector<vector<ll>> adj_matrix;
 
// no inicio do algoritmo, temos que 
// adj_matrix[u][v] = menor aresta entre u e v
 
void floyd_warshall(){
    int n = (int) adj_matrix.size();
 
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            if(i==k || adj_matrix[i][k]==inf)
                continue;
            for(int j=0; j<n; j++){
                adj_matrix[i][j] = min(adj_matrix[i][j],
                adj_matrix[i][k]+adj_matrix[k][j]);
            }
        }
    }
 
    // ao final da execucao do algoritmo, teremos que 
    // adj_matrix[u][v] = menor distancia entre u e v
}
 
void solve(){
    ll n, m, q;
    cin >> n >> m >> q;
 
    adj_matrix = vector<vector<ll>> (n, vector<ll>(n, inf));
 
 
    ll a, b, c;
 
    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        a--;
        b--;
        if(c<adj_matrix[a][b]){
            adj_matrix[a][b] = c;
            adj_matrix[b][a] = c;
        }
    }
 
    floyd_warshall();
 
    while(q--){
        cin >> a >> b;
        a--;
        b--;
        if(a==b)
            adj_matrix[a][b] = 0;
        else if(adj_matrix[a][b]==inf)
            adj_matrix[a][b] = -1;
        cout << adj_matrix[a][b] << endl;
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}