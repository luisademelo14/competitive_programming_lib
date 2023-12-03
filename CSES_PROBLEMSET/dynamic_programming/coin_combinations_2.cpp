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
 
ll dp[1000006];
const int mod = (int) 1e9 + 7;
 
void solve(){
    int n, x;
    cin >> n >> x;
    vi moedas (n);
    for(int i=0; i<n; i++){
        cin >> moedas[i];
    }
    dp[0] = 1;
    for(int i=0; i<n; i++){
        for(int valor=1; valor<=x; valor++){
            if(moedas[i]<=valor){
                dp[valor] += dp[valor - moedas[i]];
                dp[valor] %= mod;
            }
        }
    }
    cout << dp[x] << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}