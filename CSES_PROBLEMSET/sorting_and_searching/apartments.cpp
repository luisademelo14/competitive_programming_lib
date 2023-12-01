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
#define debug cerr << "\ni'm here\n"<< endl;
#define PI 3.141592653589793
 
const ll MAX_N = 1000000007;
 
// resolver usando guloso
 
// ordenar os dois vetores e usar dois ponteiros que comecam
// no inicio deles
 
// se abs(a[j]-p[i])<=k -> temos uma resposta valida
 
// se nao entra nesse caso de cima, precisamos ver quem eh maior
// e, dependendo disso, andamos com apenas um dos ponteiros
 
// fazemos isso ate pelo menos um dos ponteiros chegar no final do seu vetor
 
// complexidade da solucao : O (n log(n) + m log(m))
 
void solve(){
    ll n, m, k, ans = 0;
    cin >> n >> m >> k;
 
    vll p (n); // pessoas 
 
    vll a (m); // apartamentos
 
    for(int i=0; i<n; i++)
        cin >> p[i];
 
    for(int i=0; i<m; i++)
        cin >> a[i];
 
    sort(all(p));
 
    sort(all(a));
 
    // um ponteiro pra cada vetor
    int i = 0;
    int j = 0;
 
    while(i<n && j<m){
        if(abs(a[j]-p[i])<=k){
            i++;
            j++;
            ans++;
        }
        else if(a[j]>p[i])
            i++;
        else
            j++;
    }
 
    cout << ans << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}