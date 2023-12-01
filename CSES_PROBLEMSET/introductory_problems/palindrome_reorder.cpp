#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef map <char, int> mci;
 
#define endl '\n'
#define f first
#define s second

const ll MAX_N = 1000000007;
 
mci qnt;
 
void solve(){
    string str, res;
    char char_impar;
    int qnt_impar = 0;
    cin >> str;
 
    int n = str.size();
 
    for(int i=0; i<n; i++)
        qnt[str[i]]++;
 
    for(auto u : qnt){
        if(u.s%2){
            qnt_impar++;
            char_impar = u.f;
        }
    }
 
    // casos sem solucao: ou tem mais de um char com qnt impar
    // ou tem um char com qnt impar e o tam da string eh par
    if(qnt_impar>1 || (qnt_impar==1 && n%2==0)){
        cout << "NO SOLUTION" << endl;
        return;
    }
 
    string s1 = "", s2 = "";
 
    for(auto u : qnt){
        // string temporaria de tamanho
        // u.second/2 com chars do tipo u.first
        string t(u.s/2, u.f);
 
        // add na ordem certa nas strings 
        // pra ficar palindromo
 
        s1 = s1 + t; // add t no final
        s2 = t + s2; // add t no inicio
    }
 
    // se ainda faltar add um char na string
    // (vai ser o char com qnt impar)
    if(qnt_impar)
        res = s1 + char_impar + s2;
 
    else
        res = s1 + s2;
 
    cout << res << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}