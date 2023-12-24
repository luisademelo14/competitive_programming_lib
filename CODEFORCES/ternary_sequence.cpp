#include <bits/stdc++.h>
#include <unordered_map>
 
using namespace std;
typedef long long ll;

// https://codeforces.com/problemset/problem/1401/B

// usar guloso:
// maximizar a qnt de pares do tipo (2,1)
// minimizar a qnt de pares de tipo (1,2)

int get_max_sum(int x1, int y1, int z1, int x2, int y2, int z2){
    int ans = 0;
    // pares de tipo (2,1)
    int two_one = min(z1, y2);
    z1 -= two_one;
    y2 -= two_one;
    ans += (2*two_one);

    // pares do tipo (0,2)
    int zero_two = min(x1, z2);
    x1 -= zero_two;
    z2 -= zero_two;

    // pares do tipo (2,2)
    int two_two = min(z1, z2);
    z1 -= two_two;
    z2 -= two_two;

    //pares do tipo (1,2)
    int one_two = min(y1, z2);
    ans -= (2*one_two);

    // os outros pares podem se formados de qualquer maneira
    // ja que o resultado de cada combinacao restate
    // resultara em 0
    return ans;
}

void solve(){
    int x1, y1, z1;
    int x2, y2, z2;

    cin >> x1 >> y1 >> z1;
    cin >> x2 >> y2 >> z2;

    cout << get_max_sum(x1, y1, z1, x2, y2, z2) << endl;
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