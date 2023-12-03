#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

 
#define endl '\n'
#define pb push_back
#define ppb pop_back
#define all(c) (c).begin(), (c).end()

const int MAX_N = 1000000007;
 
// ideia do problema: eh dado um conjunto de intervalos e precisamos
// dizer pra cada intervalo se ele contem algum outro e se ele esta contido
// em outro
 
// criar uma struct que representa um intervalo (l, r e index)
 
// o index eh importante pra guardar a posicao original do intervalo
// no vetor de ranges
 
// criar um vetor pra cada pergunta (contido e contem)
 
// ordenar o vetor de intervalos pelo limite esq (l)
// se der empate, priorizar o maior r 
 
// passar pelo vetor ordenado atualizando os vetores contained e contains
 
// complexidade da solucao: O(n log(n))
 
struct range {
    int l, r, index;
};
 
// funcao que compara pra ordenacao
// e prioriza o maior limite direito em caso de empate
bool compare (range r1, range r2){
    if(r1.l == r2.l)
        return r1.r > r2.r;
 
    return r1.l < r2.l;   
}
 
void solve(){
    int n;
    cin >> n;
    vector <range> ranges (n);
    vi contained (n, 0);
    vi contains (n, 0);
 
    // lendo os intervalos e guardando no vetor
    for(int i=0; i<n; i++){
        cin >> ranges[i].l;
        cin >> ranges[i].r;
        ranges[i].index = i;
    }
 
    // ordenando o vetor pela funcao compare
    sort(all(ranges), compare);
 
    int max_r = 0;
 
    int min_r = MAX_N;
 
    for(int i=0; i<n; i++){
        if(ranges[i].r <= max_r)
            contained[ranges[i].index] = 1;
        max_r = max(ranges[i].r, max_r);
    }
 
    for(int i=n-1; i>=0; i--){
        if(ranges[i].r >= min_r)
            contains[ranges[i].index] = 1;
        min_r = min(ranges[i].r, min_r);
    }
 
    for(int i=0; i<n; i++){
        cout << contains[i];
        if(i<n-1)
            cout << ' ';
    }
 
    cout << endl;
 
    for(int i=0; i<n; i++){
        cout << contained[i];
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