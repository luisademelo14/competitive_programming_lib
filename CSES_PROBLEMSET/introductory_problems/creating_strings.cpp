#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef set <string> ss;
 
#define endl '\n'

const ll MAX_N = 1000000007;
 
// ideia: imprimir todas as permutacoes de uma string em ordem
// alfabetica (imprimir tb a qnt de permutacoes)
 
// funcao recursiva gera todas as permutacoes (permute())
 
// caso base: str.size()==0 -> temos uma permutacao pronta
// ans guarda as permutacoes
 
// usar o set por conta da ordenacao
 
// dentro do 'for' na funcao permute():
// passamos por cada char ch da string str e pegamos o prefixo e o sufixo
// de str sem esse char e chamamos recursivamente permute(res, ans+ch)
 
ss permutations;
 
void permute(string str, string ans){
    if(str.size()==0){
        permutations.insert(ans);
        return;
    }
    for(int i=0; i<str.size(); i++){
        // para ajudar a entender: imprimir ch, left, right e res
        // em cada iteracao
        char ch = str[i];
        string left = str.substr(0, i);
        string right = str.substr(i+1);
        string res = left + right;
        permute(res, ans+ch);
    }
}
 
void solve(){
    string str, ans = "";
    cin >> str;
 
    permute(str, ans);
 
    cout << permutations.size() << endl;
 
    for(auto u : permutations)
        cout << u << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}