#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
#define endl '\n'

 
// calcular o total de possibilidades e subtrair os cenarios de ataque
 
// total pra colocar no tabuleiro:
// ((k*k)*(k*k-1))/2
 
// total pro ataque:
// 4*(k-1)*(k-2) -> pensando nos blocos 2x3 e 3x2 no tabuleiro
// pra cada bloco desse, temos 2 possibilidades pros cavalos
 
void solve(){
    ll n;
    cin >> n;
    for(ll k=1; k<=n; k++){
        ll res = ((k*k)*(k*k-1))/2 - 4*(k-1)*(k-2);
        cout << res << endl;
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}