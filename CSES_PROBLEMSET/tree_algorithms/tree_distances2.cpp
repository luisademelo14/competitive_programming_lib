#include <bits/stdc++.h>
#include <unordered_map>
 
using namespace std;
typedef long long ll;
 
// ideia da solucao: usar programacao dinamica
 
// tecnica utilizada: re-rooting (pesquisar mais depois)
 
// comecar enraizando a arvore no vertice 1 e pagar as somas das distancias
 
// guardar o tamanho das sub-arvores no array subtree_size (quando a arvore eh enraizada
// em 1)
 
// primeira dfs: pra pre-computar a arvore (achar a resposta pro vertice 1, que eh dist_to_root, e 
// calcular os tamanhos das sub-arvores)
 
// segunda dfs: a partir da resposta de 1 (raiz), calcular as respostas para os outros vertices
 
// ans[neighbour] = ans[v] - subtree_size[neighbour] + (n - subtree_size[neighbour]);
//                                  |                                   |
//                                  v                                   v
//                            encurta (em uma unidade)            aumenta (em uma unidade) o
//                            o caminho pros                      caminhos pros vertices que nao
//                            vertices que fazem parte            fazem parte daquela sub-arvore
//                            daquela sub-arvore                   
 
int inf = 1e9;
 
vector<vector<int>> graph;
 
vector<ll> subtree_size;
 
vector<ll> ans;
 
ll dist_to_root = 0;
 
int n;
 
void dfs_compute(int v, int parent, ll depth){
    subtree_size[v] = 1;
    dist_to_root += depth;
    for(int neighbour : graph[v]){
        if(neighbour != parent){
            dfs_compute(neighbour, v, depth+1);
            subtree_size[v] += subtree_size[neighbour];
        }
    }
}
 
void dfs_calculate(int v){
    for(int neighbour : graph[v]){
            // caso base pra nao ficar em loop infinito
            if(ans[neighbour]!=-1)
                continue;
            ans[neighbour] = ans[v] - subtree_size[neighbour] + (n - subtree_size[neighbour]);
            dfs_calculate(neighbour);
    }
}
 
 
void solve(){
    cin >> n;
    int a, b;
    graph = vector<vector<int>> (n);
    subtree_size = vector<ll> (n);
    ans = vector<ll> (n, -1);
    for(int i=0; i<n-1; i++){
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
 
    dfs_compute(0, -1, 0);
    ans[0] = dist_to_root;
    dfs_calculate(0);
 
    for(int i=0; i<n; i++){
        cout << ans[i];
        if(i<n-1)
            cout << ' ';
    }
 
    cout << endl;
}
 
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}