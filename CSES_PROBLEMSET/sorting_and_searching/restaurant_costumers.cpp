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
#define debug cerr << "\ni'm here\n"<< endl;
#define PI 3.141592653589793
 
const ll MAX_N = 1000000007;
 
// objetivo do problema: achar o numero maximo de interseccoes
// em qualquer ponto, dado um conjunto de segmentos
 
// criar um vetor de pair <int, char> que relaciona o tempo
// com 'x' (se eh de chegada) ou 'y' (se eh de saida)
 
// ordendar esse vetor (ja ordena pelo .first do pair)
 
// percorrer o vetor ordenado e ver se o .second eh x ou y
// 1) se for 'x' -> add 1 no contador
// 2) se for 'y' -> sub 1 do contador (pq um dos intervalos q foi aberto fechou
// e o proximo q vai abrir com certeza na vai ter interseccao com ele)
 
// para entender a logica do item anterior -> lembrar que o vetor esta ordenado
// e desenhar os intervalos a partir do vetor ordenado
 
// complexidade da solucao: O(n log(n))
 
void solve(){
    ll n, a, b;
    cin >> n;
 
    vector <pair<ll, char>> ranges;
 
    for(int i=0; i<n; i++){
        cin >> a >> b;
        ranges.pb({a, 'x'});
        ranges.pb({b, 'y'});
    }
 
    sort(all(ranges));
 
    // resposta temporaria
    ll cnt = 0;
 
    // resposta final
    ll ans = 0;
 
    for(int i=0; i<ranges.size(); i++){
        if(ranges[i].s=='x')
            cnt++;
        else
            cnt--;
 
        ans = max(cnt, ans);
    }

    cout << ans << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}