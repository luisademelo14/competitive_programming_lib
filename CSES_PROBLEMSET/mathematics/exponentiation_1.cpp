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
 
// calcular 'a' elevado a 'b' usando recursao
 
// ideia da funcao recursiva:
// 1) se b for par, fazemos: a^(b/2) * a^(b/2)
// 2) se b for impar, fazemos: a^(b/2) * a^(b/2) * a
 
// complexidade da solucao: O(n * log(max(b)))
 
ll exp(ll a, ll b){
    if(b==0)
        return 1;
 
    if(b==1)
        return a % MAX_N;
 
    ll t = exp(a, b/2);
 
    if(b%2)
        return (((t*t)%MAX_N)*a)%MAX_N;
    
    else
        return (t*t)%MAX_N;
}
 
void solve(){
    ll a, b;
    cin >> a >> b;
    cout << exp(a,b) << endl;
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