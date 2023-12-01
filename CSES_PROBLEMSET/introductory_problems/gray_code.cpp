#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <string> vs;
 
#define endl '\n'
#define pb push_back

const ll MAX_N = 1000000007;
 
// resolver de forma recursiva
 
// funcao recursiva retorna um vetor de strings
 
// add prefixos "1" e "0" em cada elemento do vetor 
// gerado pela funcao para n-1
 
// caso base: n=1 -> ans = {"1", "0"}
 
vs gray_code(int n){
    // caso base n=1
    if(n==1)
        return {"0", "1"};
 
    // resposta anterior para montarmos a atual
    vs prev = gray_code(n-1);
    // resposta atual
    vs gc;
 
    // add o prefixo "0"
    for(int i=0; i<prev.size(); i++){
        gc.pb("1" + prev[i]);
    }
 
    // add o sufixo "1"
    // trocar a ordem pra garantir q so vai ter
    // um bit de diferenca entre os elementos
    for(int i=prev.size()-1; i>=0; i--){
        gc.pb("0" + prev[i]);
    }
 
    // devolve a resposta gerada
    return gc;
 
}
 
void solve(){
    int n;
    cin >> n;
 
    vs ans = gray_code(n);
 
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}