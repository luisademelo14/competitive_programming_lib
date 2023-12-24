#include <bits/stdc++.h>
#include <unordered_map>
 
using namespace std;

typedef long long ll;

// https://codeforces.com/problemset/problem/1520/D

ll same_diff(vector<int> &a){
    ll ans = 0;
    unordered_map<int, int> qnt;
    for(int i=0; i<(int)a.size(); i++){
        a[i] -= i;
        ans += qnt[a[i]];
        qnt[a[i]]++;
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cout << same_diff(a) << endl;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}