#include <bits/stdc++.h>
#include <unordered_map>
 
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
 
typedef long long ll;

//https://codeforces.com/contest/1915/problem/F

// tipo de problema relativamente clessico em contest

// ideia principal: no array ordenado, contar o numero de 
// pares de segmentos em que um esta contido no outro

void solve(){
    int n;
    cin >> n;

    vector<pair<int,int>> a (n);

    ll ans = 0;

    ordered_set o_set;

    for(int i=0; i<n; i++){
        cin >> a[i].first >> a[i].second;
        o_set.insert(a[i].second);
    }

    sort(a.begin(), a.end());

    for(int i=0; i<n; i++){
        ans += o_set.order_of_key(a[i].second);
        o_set.erase(o_set.find(a[i].second));
    }

    cout << ans << endl;
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