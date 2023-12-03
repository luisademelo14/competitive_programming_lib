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
 
// ideia: usar dfs (em cada nivel mudar o times)
// caso impossivel: se tivermos ciclo com numero impar de vertices
// se o grafo for bipartido -> possivel
// caso contrario -> impossivel
// lembrar: mlr usar dfs pra checar se o grafo eh bipartido
 
int n, m;
vi grafo[200005];
int visitados[200005] = {0};
int times[200005];
 
// a dfs vai retornar se eh bipartido ou nao
bool dfs(int v, int cor){
    visitados[v] = 1;
    times[v] = cor;
    for(auto u : grafo[v]){
        if(visitados[u]==0){
            int x = times[v]^3;
            if(!dfs(u, x))
                return false;
        }
        if(times[u]==times[v])
            return false;
    }
    return true;
}
 
void solve(){
    int a, b;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        grafo[a].pb(b);
        grafo[b].pb(a);
    }
    for(int i=1; i<=n; i++){
        if(visitados[i]==0){
            if(!dfs(i,1)){
            cout << "IMPOSSIBLE" << endl;
            return;
            }
        }
    }
    for(int i=1; i<=n; i++){
        cout << times[i] << ' ';
    }
    cout << endl;
}
 
// OBSERVACAO IMPORTANTE: para facilitar, podemos usar operacao XOR
// 1 XOR 3 = 2
// 2 XOR 3 = 1
// isso ajuda na hora de ir mudando as cores entre 1 e 2 
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}