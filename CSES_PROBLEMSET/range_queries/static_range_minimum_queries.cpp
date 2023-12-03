#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<char, int>> vpci;
typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef map<char, int> mci;
typedef map<string, int> msi;
typedef set<int> si;
typedef set<char> sc;
typedef set<string> ss;
 
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define lbnd lower_bound
#define ubnd upper_bound
#define debug cerr << "\ni'm here\n"  << endl;
#define PI 3.141592653589793
 
const int MAX_N = 1000000007;
 
// ideia do problema: responder q queries sobre o minimo elementos
// de cada range dado dentro de um array
 
// ja que trata-se de um array estatico (que nao se altera), podemos usar
// a tecnica sparse table antes de processar as queries
 
// complexidade da solucao: O(n log(n))
 
// respondemos cada querie em O(1)
 
void solve(){
    int n, q, l, r;
    cin >> n >> q;
 
    vi a (n+1);
 
    // calculando o numero de colunas do array 2D lookup
    int size = (int) log2(n);
 
    // declarar desse jeito pra nao dar erro na alocacao pra
    // numeros muito elevados
    int lookup[n][size+1];
 
    for(int i=0; i<n; i++)
        cin >> a[i];
 
    // subarrays de tamanho 1 (o min eh o proprio elemento)
    for(int i=0; i<n; i++)
        lookup[i][0] = i;
    
    // j eh o tamanho do subarray
    for(int j=1; (1<<j)<=n; j++){
        // i eh onde comeca (posicao)
        for(int i=0; (i+(1<<j)-1)<n; i++){
            if(a[lookup[i][j-1]]<=a[lookup[i+(1<<(j-1))][j-1]])
                lookup[i][j] = lookup[i][j-1];
            else
                lookup[i][j] = lookup[i+(1<<(j-1))][j-1];
        }
    }
 
    // eh uma boa imprimir o array lookup para entender oq esta 
    // acontecendo dentro dele
 
    while(q--){
        cin >> l >> r;
 
        // lembrar que o array esta 0-indexado
        l--; 
        r--;
 
        // maxima potencia de 2 que pode ser tamanho de um subarray
        // considerando o range da querie
        int max_pow2 = (int) log2(r-l+1);
 
        // pegar dois dos resultados ja calculados e comparar pra chegar
        // na resposta final
        if(a[lookup[l][max_pow2]]<=a[lookup[r-(1<<(max_pow2))+1][max_pow2]])
            cout << a[lookup[l][max_pow2]] << endl;
 
        else
            cout << a[lookup[r-(1<<(max_pow2))+1][max_pow2]] << endl;
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}