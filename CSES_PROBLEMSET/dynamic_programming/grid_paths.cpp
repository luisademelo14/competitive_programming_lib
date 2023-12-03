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
 
void solve(){
    int n;
    cin >> n;
 
    vs grid (n);
 
    vector<vector<int>> dp (n, vector<int>(n, 0));
 
    for(int i=0; i<n; i++)
        cin >> grid[i];
 
    if(grid[0][0]=='.')
        dp[0][0] = 1;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]=='.'){
                if(i>0)
                    (dp[i][j] += dp[i-1][j]) %= MAX_N;
                if(j>0)
                    (dp[i][j] += dp[i][j-1]) %= MAX_N;
            }
        }
    }
 
    cout << dp[n-1][n-1] << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}