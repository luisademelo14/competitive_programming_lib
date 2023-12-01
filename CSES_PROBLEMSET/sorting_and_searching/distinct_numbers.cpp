#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
set <ll> distintos;
 
void solve(){
    int n, numero;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> numero;
        distintos.insert(numero);
    }
    cout << distintos.size() << '\n';
}
 
int main(){
    solve();
    return 0;
}