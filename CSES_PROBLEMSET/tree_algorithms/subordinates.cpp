#include <bits/stdc++.h>
#include <unordered_map>
 
using namespace std;
typedef long long ll;
 
int inf = 1e9;
 
int n;
 
// ideia principal para a solucao do problema:
// o numero de empregados de V eh igual a soma dos empregados
// diretos de V com todos os empregados diretos desses ultimos
 
// lembrar que, neste caso, o grafo eh direcionado
 
// da pra resolver usando dfs, ja que eh garantido que todos os vertices
// vao estar conectados pelo menos com o 0 (raiz)
 
vector<vector<int>> graph;
vector<int> subordinates;
 
// funcao recursiva que calcula o numero de subordinados para
// cada pessoa
int num_subordinates(int employee){
    int sum = 0;
    for(int v : graph[employee]){
        sum += (1+num_subordinates(v));
    }
    return subordinates[employee] = sum;
}
 
void solve(){
    int boss;
    cin >> n;
    // lembrar de deixar 0-indexado
    graph = vector<vector<int>> (n);
    subordinates.assign(n, 0);
    // lendo os dados e guardando no grafo
    for(int i=0; i<n-1; i++){
        cin >> boss;
        graph[--boss].push_back(i+1);
    }
 
    num_subordinates(0);
 
    for(int i=0; i<n; i++){
        cout << subordinates[i];
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