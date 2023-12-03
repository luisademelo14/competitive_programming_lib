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
 
// ideia: contar o numero n de componentes do grafo 
// res = n-1
// usar dfs pra contar o numero de componentes
// pra os nos que vao ser ligados:
// podemos add em um vetor os primeiros nos de cada vez q a dfs roda
 
vi grafo[100005];
int visitados[100005] = {0};
vi pontes;
int res = 0;
 
void dfs(int v){
    visitados[v] = 1;
    for(auto u : grafo[v]){
        if(visitados[u]==0)
            dfs(u);
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
    for(int i=1; i<=n; i++){
        if(visitados[i]==0){
            pontes.pb(i);
            dfs(i);
            res++;
        }
    }
    cout << pontes.size() - 1 << endl;
    for(int i=0; i<pontes.size()-1; i++){
        cout << pontes[i] << ' ' << pontes[i+1] << endl;
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}