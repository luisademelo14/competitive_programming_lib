#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;

 
#define endl '\n'
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()

const ll MAX_N = 1000000007;
 
// ideia do problema: temos 'n' palitos e podemos esticar ou comprimir
// para que todos tenham o mesmo tamanho no final
 
// temos um custo para cada mudanca, que eh a diferenca: abs(h_i - h_f)
 
// queremos saber qual eh o menor custo possivel pra fazer isso
 
// resolver usando guloso: ordenar o vetor e pegar o elemento do meio
// como mediana
 
// o menor custo eh dado pela soma das diferencas de todos os palitos
// em relacao a mediana
 
// complexidade da solucao: O(n log(n))
 
void solve(){
    int n;
    cin >> n;
 
    vll a (n);
 
    for(int i=0; i<n; i++)
        cin >> a[i];
 
    sort(all(a));
 
    ll median = a[n/2];
 
    ll ans = 0;
 
    for(int i=0; i<n; i++)
        ans += abs(a[i]-median);
 
    cout << ans << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}