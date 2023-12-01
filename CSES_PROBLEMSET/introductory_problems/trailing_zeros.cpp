#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
#define endl '\n'

const ll MAX_N = 1000000007;
 
// precisamos ver qnts vezes o 5 aparece entre os numeros de 1 a n
// no for, estamos contando:
// qnts vezes 5¹ + qnts vezes 5² + ... assim por diante
// 2 aparece com maior frequencia, ent n precisamos considerar 
 
void solve(){
    ll n, ans = 0;
    cin >> n;
    for(int i=5; i<=n; i*=5){
        ans += n/i;
    }
    cout << ans << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}