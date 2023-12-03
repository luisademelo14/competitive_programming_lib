#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <char> vc;
typedef vector <string> vs;
typedef vector <pair<int, int>> vpii;
typedef vector <pair<char, int>> vpci;
typedef pair <int, int> pii;
typedef map <int, int> mii;
typedef map <char, int> mci;
typedef map <string, int> msi;
typedef set <int> si;
typedef set <char> sc;
typedef set <string> ss;
 
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define lbnd lower_bound
#define ubnd upper_bound
#define debug cerr<<"\ni'm here\n"<<endl;
#define PI 3.141592653589793
 
const ll MAX_N = 1000000007;
 
// foi usada a estrutura BIT
 
// na funcao update(), tomar cuidado pra nao colocar o proprio
// valor de k no loop (foi usada a variavel temp)
 
ll a [200005];
ll tree [200005];
ll n, q, l, r, op, k, u;
 
ll sum(ll k){
    ll ans=0;
    while(k>=1){
        ans += tree[k];
        k -= (k&(~(k-1)));
    }
    return ans;
}
 
ll sum_interval(ll l, ll r){
    return sum(r) - sum(l-1);
}
 
void update(ll k, ll x){
    ll diff = x-a[k];
    ll temp = k;
    while(temp<=n){
        tree[temp] += diff;
        temp += (temp&(~(temp-1)));
    }
    a[k] = x;
}
 
void solve(){
    cin >> n >> q;
 
    // tem que ser 1-indexado 
 
    for(int i=1; i<=n; i++){
        ll val;
        cin >> val;
        update(i, val);
    }
 
    while(q--){
        cin >> op;
        if(op==1){
            cin >> k >> u;
            update(k,u);
        }
        else{
            cin >> l >> r;
            cout << sum_interval(l,r) << endl;
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}