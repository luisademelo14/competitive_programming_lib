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
 
// resolver usando busca binaria
 
// usar upper_bound(), porque entre pegar o numero e um menor que ele,
// eh melhor pegar o proprio numero
 
// lembrar que importa a ordem das pessoas que chegam
 
// se a busca binaria falha -> imprimir -1
 
// usar multiset, pq os precos podem repetir e fica mais facil tanto
// pra busca binaria (eh ordenado) quanto pra dar .erase()
 
void solve(){
    ll n, m, p, costumer;
    cin >> n >> m;
 
    multiset <ll> prices;
 
    for(int i=0; i<n; i++){
        cin >> p;
        prices.insert(p);
    }
 
    for(int i=0; i<m; i++){
        cin >> costumer;
        auto t = prices.upper_bound(costumer);
        if(t == prices.begin())
            cout << -1 << endl;
        else{
            t--;
            cout << *(t) << endl;
            prices.erase(t);
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}