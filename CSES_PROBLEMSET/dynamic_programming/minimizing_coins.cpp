#include <bits/stdc++.h>
 
using namespace std;
 
int moedas[101];
int dp[1000006];
const int INF = 1000006;

void solve(){
    int qnt_moedas, soma;
    cin >> qnt_moedas >> soma;
    for(int i=0; i<qnt_moedas; i++){
        cin >> moedas[i];
    }
    dp[0] = 0;
    for(int x=1; x<=soma; x++){
        dp[x] = INF;
        for(int i=0; i<qnt_moedas; i++){
            if(x-moedas[i]>=0 && dp[x-moedas[i]]+1 < dp[x]){
                dp[x] = dp[x-moedas[i]] + 1;
            }
        }
    }
    if(dp[soma]==INF){
        cout << -1 << '\n';
        return;
    }
    cout << dp[soma] << '\n';
}
 
int main(){
    solve();
    return 0;
}