#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

 
#define endl '\n'

const ll MAX_N = 1000000007;
 
void solve(){
    ll a, b;
    cin >> a >> b;
    if((a+b)%3==0 && min(a,b)*2>=max(a,b))
        cout << "YES" << endl;
    else
        cout << "NO" << endl; 
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}