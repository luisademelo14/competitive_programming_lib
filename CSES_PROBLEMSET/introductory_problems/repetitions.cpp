#include <bits/stdc++.h>
 
using namespace std;
 
void solve(){
    string linha;
    cin >> linha;
    int maior = 0, atual = 1;
    for(int i=1; i<linha.length(); i++){
        if(linha[i]!=linha[i-1]){
            maior = max(maior, atual);
            atual = 0;
        }
        atual ++;
    }
    maior = max(maior, atual);
    cout << maior << '\n';
}
 
int main(){
    solve();
    return 0;
}