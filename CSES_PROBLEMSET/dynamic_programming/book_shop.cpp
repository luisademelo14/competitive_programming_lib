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
 
const ll MAX_N = 1000000007;
 
// precisamos de um array para os precos
// precisamos de um array para as paginas
 
// dp sera um array 2D, onde dp[i][j] eh o maximo numero de paginas
// considerando ate o i-esimo livro e com limite de j reais 
 
void solve(){
    int n, x;
    cin >> n >> x;
 
    vi prices (n+1);
    vi pages (n+1);
    int dp[n+1][x+1];
 
    //vector<vector<int>> dp(n+1,vector<int>(x+1,0));
 
    for(int i=1; i<=n; i++)
        cin >> prices[i];
 
    for(int i=1; i<=n; i++)
        cin >> pages[i];
    
    for(int i=0; i<=x; i++)
        dp[0][i] = 0;
 
    for(int i=1; i<=n; i++){
        for(int j=0; j<=x; j++){
            if(j-prices[i]>=0)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-prices[i]]+pages[i]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
 
    cout << dp[n][x] << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}