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
 
using namespace std;
const int max_n = 1005;
const int inf = 1e9;
 
// usar bfs para A e para os monstros
 
// para a bfs -> usar uma fila de pairs
 
// se um monstro consegue chegar em uma saida antes do A:
// n da pro A sair por essa saida
// assim, dist(A, saida)<dist(A, monstro) deve ser satisfeita
 
// usar o conceito de bfs multi-source (colocar todos os monstros na fila
// no inicio da bfs) -> assim, ja pega o monstro mais proximo
 
int h [4] = {1, -1, 0, 0};
int v [4] = {0, 0, 1, -1};
struct point { int x, y; };
 
int n, m, sx, sy;
bool visited[max_n][max_n];
char ans[max_n*max_n], c[max_n][max_n], p[max_n][max_n];
int d1[max_n][max_n], d2[max_n][max_n];
queue<pair<int,int>> q;
 
bool valid_pos(int x, int y){
    return (0<=x && x<n && 0<=y && y<m);
}
 
void print_solution(int x, int y){
    int d = d2[x][y];
    cout << "YES" << endl;
    cout << d << endl;
    for(int i = d-1; i >= 0; i--){
        ans[i] = p[x][y];
        if(ans[i] == 'D')       x--;
        else if(ans[i] == 'U')  x++;
        else if(ans[i] == 'R')  y--;
        else if(ans[i] == 'L')  y++;
    }
    for(int i = 0; i < d; i++)
        cout << ans[i];
    cout << endl;
}
 
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> c[i][j];
            if(c[i][j] == '#')  visited[i][j] = true;
            else if(c[i][j] == 'M'){
                visited[i][j] = true;
                q.push({i, j});
            } else if(c[i][j] == 'A'){
                sx = i; sy = j;
            }
        }
    }
 
    while(!q.empty()){
        int x  = q.front().first;
        int y  = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int xx = x + h[i];
            int yy = y + v[i];
            if(valid_pos(xx, yy) && !visited[xx][yy]){
                d1[xx][yy] = d1[x][y] + 1;
                visited[xx][yy] = true;
                q.push({xx, yy});
            }
        }
    }
 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j])  d1[i][j] = inf;
            visited[i][j] = (c[i][j] == '#');
        }
    }
 
    visited[sx][sy] = true;
    q.push({sx, sy});
    while(!q.empty()){
        int x  = q.front().first;
        int y  = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int xx = x + h[i];
            int yy = y + v[i];
            if(valid_pos(xx, yy) && !visited[xx][yy] && d2[x][y]+1 < d1[xx][yy]){
                if(i == 0)      
                    p[xx][yy] = 'D';
                else if(i == 1) 
                    p[xx][yy] = 'U';
                else if(i == 2) 
                    p[xx][yy] = 'R';
                else if(i == 3) 
                    p[xx][yy] = 'L';
                d2[xx][yy] = d2[x][y] + 1;
                visited[xx][yy] = true;
                q.push({xx, yy});
            }
        }
    }
 
    for(int i = 0; i < n; i++){
        if(c[i][0] != '#' && c[i][0] != 'M' && visited[i][0]){
            print_solution(i, 0);
            return 0;
        } else if(c[i][m-1] != '#' && c[i][m-1] != 'M' && visited[i][m-1]){
            print_solution(i, m-1);
            return 0;
        }
    }
 
    for(int i = 0; i < m; i++){
        if(c[0][i] != '#' && c[0][i] != 'M' && visited[0][i]){
            print_solution(0, i);
            return 0;
        } else if(c[n-1][i] != '#' && c[n-1][i] != 'M' && visited[n-1][i]){
            print_solution(n-1, i);
            return 0;
        }
    }
 
    cout << "NO" << endl;
}