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
 
// ideia do problema: eh dado um array de tamanho n com numeros
// de 1 ate n 
 
// cada rodada: pegamos os numeros em ordem crescente
 
// dizer quantas rodadas sao necessarias pra pegar todos os numeros
// do array
 
// para resolver: criar um array pos em que pos[num] eh a posicao do
// numero "num" no array original
 
// percorrer esse array sob o seguinte condicional: se pos[i]<pos[i-1]
// ans++;
 
// a resposta comeca com 1
 
void solve(){
    int n, num;
    cin >> n;
 
    vi pos (n+1, 0);
 
    for(int i=0; i<n; i++){
        cin >> num;
        pos[num] = i;
    }
 
    int ans = 1;
 
    for(int i=1; i<=n; i++){
        if(pos[i]<pos[i-1])
            ans++;
    }
 
    cout << ans << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}