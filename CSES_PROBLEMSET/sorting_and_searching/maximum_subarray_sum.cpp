#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;

 
#define endl '\n'

const ll MAX_N = 1000000007;
 
// ideia do problema: dado um array, acha a maior soma possivel de um
// intervalo continuo do array
 
// para resolver -> usar o algoritmo de kadane (DP)
 
// ideia do algoritmo de kadane: para cada posicao do array, calcular 
// a soma maxima do subarray que termina naquela posicao
 
// transicoes da DP (temos duas possiblidades):
// 1) ou o subarray tem apenas o elemento na posicao k
// 2) ou o subarray eh uma uniao do elemento na posicao k
// com o subarray que termina na posicao k-1
 
// lembrar que o subarray nao pode ser nulo (entao se o array so
// tiver numeros negativos, pegamos apenas o menor em modulo)
 
// complexidade da solucao: O(n)
 
void solve(){
    int n;
    cin >> n;
 
    vll a (n);
 
    for(int i=0; i<n; i++)
        cin >> a[i];
 
    ll ans = -MAX_N, sum = 0;
 
    for(int i=0; i<n; i++){
        sum = max(sum+a[i], a[i]);
        ans = max(ans, sum);
    }
 
    cout << ans << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}