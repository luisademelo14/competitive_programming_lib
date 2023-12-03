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
 
// ideia do problema: detectar um ciclo no grafo
// imprimir o ciclo
// usar dfs para detectar esse ciclo
// a qnt de vertices pode ser qq uma
// guardar o caminho em um vetor dinamico
// enquanto a dfs roda -> se n forma ciclo com aquele no, dar pop_back
// no inicio da dfs: verificar se ja achou ciclo
// precisa ter o controle do pai (no que veio antes do q esta sendo processado)
 
vi g[100005];
int visitados[100005];
bool cycle = false;
 
void print_path(vi &path){
    int ans = 1; 
    string str = to_string(path[path.size()-1]);
    for(int i=path.size()-2; i>=0; i--){
        if(path[i]!=path[path.size()-1]){
            ans++;
            str += " ";
            str += to_string(path[i]);
        }
        else
            break;
    }
    str += " ";
    str += to_string(path[path.size()-1]);
    cout << ans + 1 << endl;
    cout << str << endl;
}
 
void dfs(int v, int parent, vi &path){
    if(cycle)
        return;
    if(visitados[v]==1){
        if(path.size()>2){
            path.pb(v);
            print_path(path);
            cycle = true;
            return;
        }
    }
    visitados[v] = 1;
    path.pb(v);
    for(auto u : g[v]){
        if(u != parent){
            dfs(u, v, path);
        }
    }
    path.ppb();
}
 
void solve(){
    int n, m, a, b;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    for(int i=1; i<=n; i++){
        if(visitados[i]==0){
            vi path;
            dfs(i, -1, path);
        }
    }
    if(!cycle)
        cout << "IMPOSSIBLE" << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}