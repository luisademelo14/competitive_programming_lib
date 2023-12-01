#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
ll numeros[200005];
 
void solve(){
    ll n, resposta=0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> numeros[i];
    }
    for(int i=1; i<n; i++){
        if(numeros[i]<numeros[i-1]){
            resposta += numeros[i-1] - numeros[i];
            numeros[i] = numeros[i-1];
        }
    }
    cout << resposta << '\n';
}
 
int main(){
    solve();
    return 0;
}