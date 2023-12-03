#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <char> vc;
typedef vector <string> vs;
typedef vector <pair<int, int>> vpii;
typedef vector <pair<char, int>> vpci;
typedef pair <int, int> pii;
typedef map <int, int> mii;
typedef map <char, int> mci;
typedef map <string, int> msi;
typedef set <int> si;
typedef set <char> sc;
typedef set <string> ss;
 
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define lbnd lower_bound
#define ubnd upper_bound
#define debug cerr<<"\ni'm here\n"<<endl;
#define PI 3.141592653589793
 
// caso impossivel: os computadores estao
// em componentes diferentes do grafo
 
// ideia: usar bfs e fazer o grafo com lista de adj
 
// para imprimir a ordem dos computadores:
 
// para ver se eh impossivel: verificar se
// visitados[N] == 0
 
vi grafo[200005];
int dist[200005];
int antes[200005];
int visitados[200005] = {0};
 
// a fila guarda os nos que serao processados 
// em ordem crescente de distancia
queue <int> fila;
 
void bfs(int v){
    visitados[v] = 1;
    dist[v] = 0;
    fila.push(v);
    while(!fila.empty()){
        //essa eh a parte que percorre o grafo em
        // camadas (niveis)
        int a = fila.front();
        fila.pop();
        for(auto u : grafo[a]){
            if(visitados[u]==0){
                visitados[u] = 1;
                dist[u] = dist[a]+1;
                antes[u] = a;
                fila.push(u);
            }
        }
    }
}
 
void solve(){
    int n, m, a, b;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        grafo[a].pb(b);
        grafo[b].pb(a);
    }
    bfs(1);
    if(visitados[n]==0){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    vi res;
    while(n!=1){
        res.pb(n);
        n = antes[n];
    }
    res.pb(1);
    cout << res.size() << endl;
    cout << 1;
    for(int i=res.size()-2; i>=0; i--){
        cout << ' ' << res[i];
    }
    cout << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}