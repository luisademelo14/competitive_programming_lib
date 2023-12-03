#include <bits/stdc++.h>
 
using namespace std;
 
int edit_distance(string a, string b, int m, int n){
	int dp[m+1][n+1];
	for(int i=0; i<=m; i++){
		for(int j=0; j<=n; j++){
			// se a primeira string esta vazia, inserimos todos os elementos da segunda nela
			if(i==0){
				dp[i][j] = j;
			}
			// se a segunda esta vazia, tiramos todos os caracteres da primeira
			else if(j==0){
				dp[i][j] = i;
			}
			// se os ultimos caracteres forem os mesmos, chamar a funcao para os proximos caracteres
			else if(a[i-1]==b[j-1]){
				dp[i][j] = dp[i-1][j-1];
			}
			// se os ultimos caracteres forem diferentes, considerar as tres opcoes possiveis de alteracao
			else{
				dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
			}
		}
	}
	return dp[m][n];
}
 
void solve(){
    string a, b;
    cin >> a >> b;
    int m = a.size();
    int n = b.size();
    cout << edit_distance(a, b, m, n) << '\n';
}
 
int main(){
    solve();
    return 0;
}