#include <bits/stdc++.h>
#include <unordered_map>
 
using namespace std;
typedef long long ll;

int num_sets;

vector<int> parent, set_size;

int max_set_size;

// funcao que acha o representante do set em que um certo nó está
int root(int node){
    if(parent[node] == node)
        return node;
    // passar o representante (parent) do nó diretamente para o representante do set como um todo
    return parent[node] = root(parent[node]); // há otimização de tempo aqui
}

// funcao que une dois sets
void merge(int node_a, int node_b){
    // achando o representante de cada set
    int root_a = root(node_a);
    int root_b = root(node_b);

    // se já pertencem ao mesmo set, nao precisamos fazer nada
    if(root_a == root_b)
        return;
    
    num_sets--;

    // otimização
    if(set_size[root_a] <= set_size[root_b]){
        parent[root_a] = root_b;
        set_size[root_b] += set_size[root_a];
        max_set_size = max(max_set_size, set_size[root_b]);
    }
    else{
        parent[root_b] = root_a;
        set_size[root_a] += set_size[root_b];
        max_set_size = max(max_set_size, set_size[root_a]);
    }
}

void solve(){
    max_set_size = 1;
    int n, m, a, b;
    cin >> n >> m;
    num_sets = n;

    parent = vector<int> (n);
    set_size = vector<int> (n);

    for(int i=0; i<n; i++){
        parent[i] = i;
        set_size[i] = 1;
    }
    
    for(int i=0; i<m; i++){
        cin >> a >> b;
        a--; b--;
        merge(a, b);
        cout << num_sets << ' ' << max_set_size << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}