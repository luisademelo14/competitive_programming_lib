#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector <string> vs;

#define endl '\n'

const ll MAX_N = 1000000007;
 
// ideia do problema: eh dado um tabuleiro e devemos imprimir
// o total de possibilidades de posicionamento de 8 rainhas nesse
// tabuleiro, sendo que elas nao se atacam
 
// nao podemos colocar rainhas nos lugares marcados com (*)
 
// devemos ter exatamente uma rainha em cada linha (ideia de partida)
 
// usamos 3 arrays para guardar se uma coluna ou uma diagonal ja
// esta ocupada
 
// funcao recursiva ways(): recebe como parametro a linha
// caso base -> se r==8 quer dizer que temos uma das possibilidades formada
// outros casos: passamos pelas colunas e vamos chamando a funcao para as 
// proximas linhas se conseguimos colocar uma rainha na linha atual
 
// aritmetica pra diag1[i] -> i = r+c
// aritmetica pra diag1[i] -> i = r-c+7
 
int ans = 0;
 
bool col[15], diag1[15], diag2[15];
 
bool reserved[8][8];
 
void ways(int r){
    // caso base em que ja posicionamos todas as rainhas
    // no tabuleiro
    if(r==8){
        ans++;
        return;
    }
 
    for(int c=0; c<8; c++){
        // casos em que nao podemos colocar a rainha
        if(col[c] || diag1[r+c] || diag2[r-c+7] || reserved[r][c])
            continue;
 
        col[c] = diag1[r+c] = diag2[r-c+7] = true; // coloca a rainha
        ways(r+1); // chama a funcao pras proximas linhas
        col[c] = diag1[r+c] = diag2[r-c+7] = false; // mudamos tudo 
        // pra false pra tentar colocar uma rainha nessa mesma linha, mas
        // em uma coluna diferente (quando o "for" continuar)
    }
}
 
 
void solve(){
    // inicializar tudo como false pra garantir
    for(int i=0; i<15; i++){
        col[i] = diag1[i] = diag2[i] = false;
    }
 
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            reserved[i][j] = false;
        }
    }
 
    // usar o tabuleiro como um vetor de strings
    vs board (8);
    for(int i=0; i<8; i++){
        cin >> board[i];
        for(int j=0; j<8; j++){
            // marcando se nao podemos colocar a rainha aqui
            if(board[i][j]=='*')
                reserved[i][j] = true;
        }
    }
 
    ways(0);
    cout << ans << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}