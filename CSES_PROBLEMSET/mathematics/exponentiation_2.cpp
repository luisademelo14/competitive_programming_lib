#include <bits/stdc++.h>
 
using namespace std;
 
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
#define debug cerr << "\ni'm here\n" << endl;
#define PI 3.141592653589793
 
const ll MAX_N = 1000000007;
 
// ideia do problema: calcular 'a' elevado a 'b' elevado a 'c'
 
// usar o teorema de fermat (pagina 202 do cses) na parte de teoria
// do numeros
 
// usar a mesma funcao recursiva do exercicio anterior com umas
// modificacoes em relacao aos parametros
 
// vamos calcular a^[(b^c) (mod1e9+7−1)] (mod1e9+7)
 
// complexidade da solucao: O(log(MAX_N))
 
ll exp(ll a, ll b, ll mod){
    if(b==0)
        return 1;
    
    if(b==1)
        return a % mod;
 
    ll t = exp(a, b/2, mod)%mod;
 
    if(b%2)
        return (((t*t)%mod)*a)%mod;
 
    else
        return (t*t)%mod;
}
 
void solve(){
    ll a, b, c;
    cin >> a >> b >> c;
    ll t = exp(b, c, MAX_N-1);
    cout << exp(a, t, MAX_N) << endl; 
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    //solve();
    return 0;
}