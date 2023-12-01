#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

#define endl '\n'

const ll MAX_N = 1000000007;
 
void solve(){
    ll n, res = 1;
    cin >> n;
    for(ll i=1; i<=n; i++){
        res = (res*2) % MAX_N;
    }
    cout << res << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}