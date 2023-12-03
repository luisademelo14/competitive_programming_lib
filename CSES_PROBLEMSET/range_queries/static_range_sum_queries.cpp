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
 
// ideia do problema: responder queries sobre qual eh a soma
// dos elementos contidos em um intervalo continuo do array
 
// usar soma de prefixos
 
void solve(){
    int n, q, l, r;
    cin >> n >> q;
 
    vll a (n+1);
 
    vll pref_sum (n+1, 0);
    
    for(int i=1; i<=n; i++){
        cin >> a[i];
        pref_sum[i] = pref_sum[i-1] + a[i];
    }
 
    while(q--){
        cin >> l >> r;
        cout << pref_sum[r] - pref_sum[l-1] << endl;
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}