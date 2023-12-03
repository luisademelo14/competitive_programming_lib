#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <char> vc;
typedef vector <string> vs;
typedef vector <pair<int, int>> vpii;
typedef vector <pair<char, int>> vpci;
typedef pair <int, int> pii;
typedef map <int, int> mii;
typedef map <char, int> mci;
typedef map <string, int> msi;
typedef set <int> si;
typedef set <char> sc;
typedef set <string> ss;
 
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define lbnd lower_bound
#define ubnd upper_bound
#define debug cerr<<"\ni'm here\n"<<endl;
#define PI 3.141592653589793
 
// usar bfs pra achar o caminho de A ate B
 
// quando eh grafo na forma de tabuleiro (matriz):
// representar o grafo como vetor de strings
 
// na fila pra bfs:
// colocar pairs de inteiros (p.first=i e p.second=j)
 
// ir mudando os chars do tabuleiro pra operacao realizada
// no final vamos fazer o caminho inverso (p/ imprimir a resposta) 
 
int n, m, start_i, start_j, end_i, end_j;
 
// grafo
vs g;
 
bool valid_pos(int i, int j){
    // verificando se podemos ir p/ essa posicao
    return i>=0 && j>=0 && i<n && j<m && g[i][j]=='.';
}
 
void solve(){
    cin >> n >> m;
    g = vs (n);
    for(int i=0; i<n; i++)
        cin >> g[i];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(g[i][j]=='A'){
                start_i = i;
                start_j = j;
            }
            if(g[i][j]=='B'){
                end_i = i;
                end_j = j;
                // mudando B pra ficar visivel na bfs
                g[i][j] = '.';
            }
        }
    }
    
    // bfs de fato aqui:
    // fila pra bfs
    queue <pair<int,int>> q;
    bool found_B = false;
    // add A na fila pra comecar
    q.push({start_i, start_j});
    while(!found_B && !q.empty()){
        auto curr = q.front();
        q.pop();
        int i = curr.f;
        int j = curr.s;
        if(valid_pos(i+1, j)){
            g[i+1][j] = 'D';
            q.push({i+1, j});
            if(i+1==end_i && j==end_j)found_B = true;
        }
        if(valid_pos(i-1, j)){
            g[i-1][j] = 'U';
            q.push({i-1, j});
            if(i-1==end_i && j==end_j)found_B = true;
        }
        if(valid_pos(i, j+1)){
            g[i][j+1] = 'R';
            q.push({i, j+1});
            if(i==end_i && j+1==end_j)found_B = true;
        }
        if(valid_pos(i, j-1)){
            g[i][j-1] = 'L';
            q.push({i, j-1});
            if(i==end_i && j-1==end_j)found_B = true;
        }
    }
    if(!found_B){
        cout << "NO" << endl;
        return;
    }
    string ans = "";
    int curr_i = end_i;
    int curr_j = end_j;
    while(!(curr_i==start_i && curr_j==start_j)){
        ans += g[curr_i][curr_j];
        // fazendo o caminho contrario p/ achar a resposta
        if(g[curr_i][curr_j]=='D')
            curr_i--;
        else if(g[curr_i][curr_j]=='U')
            curr_i++;
        else if(g[curr_i][curr_j]=='R')
            curr_j--;
        else
            curr_j++;
    }
    reverse(all(ans));
    cout << "YES" << endl;
    cout << ans.size() << endl;
    cout << ans << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}