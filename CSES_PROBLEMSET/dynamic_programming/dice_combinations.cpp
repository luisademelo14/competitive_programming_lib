#include <bits/stdc++.h>
 
using namespace std;
 
long long int dp[1000006];
 
void solve(){
    long long int soma;
    cin >> soma;
 
    dp[0] = 1;
    for (int i=1; i<=soma; i++) {
        for (int k = 1; k <= 6; k++) {
            if (i - k >= 0) {
                dp[i] += dp[i - k];
                dp[i] = (dp[i] + 1000000007) % 1000000007;
            }
        }
    }
    cout << dp[soma] << '\n';
}
 
int main(){
    solve();
    return 0;
}