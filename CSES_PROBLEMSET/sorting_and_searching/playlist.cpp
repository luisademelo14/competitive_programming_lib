#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<char, int>> vpci;
typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef map<char, int> mci;
typedef map<string, int> msi;
typedef set<int> si;
typedef set<char> sc;
typedef set<string> ss;
 
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define lbnd lower_bound
#define ubnd upper_bound
#define debug cerr << "\ni'm here\n" << endl;
#define PI 3.141592653589793
 
const ll MAX_N = 1000000007;
 
// ideia do problema: imprimir o tamanho da maior subsequencia
// formada apenas por numeros diferentes de um array (numeros sucessivos)
 
// usar two pointers e um set de inteiros
 
// os dois ponteiros comecam no inicio do vetor e 'r' vai pra frente ate 
// achar o primeiro numero que repete no intervalo entre 'l' e 'r'
 
// quando acha esse numero que repete, muda 'l' pra posicao que estava o 'r'
// e pega o maximo entre r-l+1 e a resposta atual
 
// usar o set para verificar as repeticoes
 
// complexidade da solucao: O(n)
 
void solve(){
    int n;
    cin >> n;
 
    si dif_songs;
    vi songs (n);
 
    for(int i=0; i<n; i++)
        cin >> songs[i];
 
    // two pointers
    int l = 0;
    int r = 0;
 
    int ans = 0;
 
    while(l<n && r<n){
        while(r<n && dif_songs.find(songs[r])==dif_songs.end()){
            dif_songs.insert(songs[r]);
            ans = max(ans, r-l+1);
            r++;
        }
        
        while(l<n && dif_songs.find(songs[r])!=dif_songs.end()){
            dif_songs.erase(songs[l]);
            l++;
        }
    }
 
    cout << ans << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}