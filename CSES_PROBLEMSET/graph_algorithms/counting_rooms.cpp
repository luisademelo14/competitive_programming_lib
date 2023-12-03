#include <bits/stdc++.h>

using namespace std;
 
// declarando aqui, pq precisa usar nas outras funcoes
int n, m, resposta = 0;
 
char mapa[1003][1003];
int visitado[1003][1003];
int lado_x[] = {0, 1, -1, 0};
int lado_y[] = {1, 0, 0, -1};
 
bool eh_sala(int x, int y){
    // verifica se a posicao eh valida
    if(x<0)
        return false;
    if(y<0)
        return false;
    if(x>=m)
        return false;
    if(y>=n)
        return false;
    if(mapa[y][x] == '#')
        return false;
    return true;
}
 
void dfs(int x, int y){
    // a partir de um ponto do mapa, passa pelos vizinhos
    // e marca todos os vizinhos (pontos) como visitados
    visitado[y][x] = 1;
    for(int i=0; i<4; i++){
        int vizinho_x = x + lado_x[i];
        int vizinho_y = y + lado_y[i];
        if(eh_sala(vizinho_x, vizinho_y)){
            if(!visitado[vizinho_y][vizinho_x]){
                dfs(vizinho_x, vizinho_y);
            }
        }
    }
}
 
void solve(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> mapa[i][j];
            visitado[i][j] = 0;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mapa[i][j]=='.' && !visitado[i][j]){
                dfs(j, i);
                resposta++;
            }
        }
    }
    cout << resposta << '\n';
}
 
int main(){
    solve();
    return 0;
}