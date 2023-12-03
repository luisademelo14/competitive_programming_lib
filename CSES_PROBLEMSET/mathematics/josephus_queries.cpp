#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

 
#define endl '\n'

const ll MAX_N = 1000000007;
 
// ideia do problema: ha 'n' criancas em um circulo e a cada rodada
// pula-se uma crianca e remove a proxima 
// devemos imprimir a k-esima crianca que sera removida
 
int josephus(int n, int k) {
    // caso base n=1
    if(n==1)
        return 1;
    
    // a k-esima crianca a ser removida eh um numero
    // par ou eh 1 (se cair nesse 'if' de primeira)
    if(k<=(n+1)/2){
        if(2*k>n)
            return 1;
        else
            return 2*k;
    }
 
    // se chega aqui, quer dizer que a k-esima crianca
    // eh um numero impar
    int c = josephus(n/2, k-(n+1)/2);
 
    // calcular pra o circulo que sobrou como se fosse da forma
    // 1, 2, ..., n/2
 
    // esse resultado fica armazenado em 'c'
 
    // converter o resultado encontrado dependendo da paridade 
    // do 'n'
 
    if(n%2)
        return 2*c + 1;
    else
        return 2*c - 1;
}
 
void solve(){
    ll n, k;
    cin >> n >> k;
    cout << josephus(n, k) << endl;
} 
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    //solve();
    return 0;
}