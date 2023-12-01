#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
 
#define endl '\n'
const int MAX_N = 1000000007;
 
// ler a parte "pruning the search" do cses (esta no capitulo "complete search")
 
// ideia de podar a arvore de busca: adicionar otimizacoes ao algoritmo para que
// este note assim que possivel que uma solucao nao pode ser extendida dali pra frente
// ja que com certeza nao vai ser valida
 
bool visited[7][7]; // desse jeito fica tudo false no inicio
 
int steps = 0;
 
int paths = 0;
 
string str;

// funcao recursiva que faz o backtracking pra achar todos os 
// caminhos possiveis com aquela string
void count_paths(int r, int c){
    // caso base em que achamos mais um caminho possivel
    if(r==6 && c==0 && steps==48){
        paths++;
        return;
    }
 
    // nao podemos ir pra essa celula pq ja foi visitada
    if(visited[r][c])
        return;
 
    // tres otimizacoes feitas com pruning (busca para mais cedo)
 
    // se chegou na posicao final e nao passou pelo tabuleiro todo
    if(r==6 && c==0 && steps<48)
        return;
     
    // batemos na borda de cima ou na borda de baixo e podemos ir
    // tanto pra direita quanto pra esquerda
    if((c>=1 && c<=5 && !visited[r][c-1] && !visited[r][c+1]) 
    && ((r==0 && visited[r+1][c]) || (r==6 && visited[r-1][c])))
        return;
 
    // batemos na borda da esquerda ou na borda da direita e podemos ir
    // tanto pra cima quanto pra baixo
    if((r>=1 && r<=5 && !visited[r+1][c] && !visited[r-1][c]) 
    && ((c==0 && visited[r][c+1]) || (c==6 && visited[r][c-1])))
        return;
 
    // nao conseguimos ir pra frente, mas conseguimos ir pra esquerda ou pra direita
    if(r>=1 && r<=5 && c>=1 && c<=5 && visited[r+1][c] && visited[r-1][c]
    && !visited[r][c-1] && !visited[r][c+1])
        return;
 
    // nao conseguimos ir pra frente, mas conseguimos ir pra esquerda ou pra direita
    if(r>=1 && r<=5 && c>=1 && c<=5 && visited[r][c+1] && visited[r][c-1]
    && !visited[r-1][c] && !visited[r+1][c])
        return;
 
    // se nao caiu nos casos de parar a busca, marcamos essa celula como
    // visitada e continuamos a busca
    visited[r][c] = true;
 
    // casos da string ja ter a direcao que vamos seguir
    if(str[steps]=='U'){
        // se da pra seguir a direcao, vai
        if(r>0 && !visited[r-1][c]){
            steps++;
            count_paths(r-1,c);
            steps--;
        }
        // se nao da, marca a celula como false e para a busca
        visited[r][c] = false;
        return;
    }
 
    if(str[steps]=='D'){
        // se da pra seguir a direcao, vai
        if(r<6 && !visited[r+1][c]){
            steps++;
            count_paths(r+1,c);
            steps--;
        }
        // se nao da, marca a celula como false e para a busca
        visited[r][c] = false;
        return;
    }
 
    if(str[steps]=='L'){
        // se da pra seguir a direcao, vai
        if(c>0 && !visited[r][c-1]){
            steps++;
            count_paths(r,c-1);
            steps--;
        }
        // se nao da, marca a celula como false e para a busca
        visited[r][c] = false;
        return;
    }
 
    if(str[steps]=='R'){
        // se da pra seguir a direcao, vai
        if(c<6 && !visited[r][c+1]){
            steps++;
            count_paths(r,c+1);
            steps--;
        }
        // se nao da, marca a celula como false e para a busca
        visited[r][c] = false;
        return;
    }
 
    // vamos pra baixo
    if(r<6 && !visited[r+1][c]){
        steps++;
        count_paths(r+1,c);
        steps--;
    }
 
    // vamos pra cima
    if(r>0 && !visited[r-1][c]){
        steps++;
        count_paths(r-1,c);
        steps--;
    }
 
    // vamos pra esquerda
    if(c>0 && !visited[r][c-1]){
        steps++;
        count_paths(r,c-1);
        steps--;
    }
 
    // vamos pra direita
    if(c<6 && !visited[r][c+1]){
        steps++;
        count_paths(r,c+1);
        steps--;
    }
 
    // voltamos pra false pq podemos fazer um caminho
    // diferente sem passar por essa celula agora
    visited[r][c] = false;
}
 
void solve(){
    cin >> str;
 
    count_paths(0,0);
 
    cout << paths << endl;
}
 
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}