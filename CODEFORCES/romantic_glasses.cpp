#include <bits/stdc++.h>
#include <unordered_map>
 
using namespace std;
 
typedef long long ll;

// https://codeforces.com/contest/1915/problem/E
 
void solve(){
	int n;
    cin >> n;
    vector<int> a (n+1);
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    map<ll,ll> diff;

    ll odd = 0;
    ll even = 0;

    for(int i=1; i<=n; i++){
        if(i%2)
            odd += a[i];
        else
            even += a[i];
        
        ll curr_diff = odd-even;

        if(curr_diff==0 || diff.find(curr_diff)!=diff.end()){
            cout <<"YES" << endl;
            return;
        }
        diff[curr_diff] = i;
    }

    
    cout << "NO" << endl;

 
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
       solve();
    //solve();
    return 0;
}