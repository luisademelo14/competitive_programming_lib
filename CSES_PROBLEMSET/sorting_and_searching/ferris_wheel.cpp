#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;

 
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()

const ll MAX_N = 1000000007;
 
// resolver usando two pointers
 
// comecar ordenando o vetor
 
// montar pares com a mais leve e a mais pesada, se isso nao
// passar de x
 
// se for maior que x, andar apenas com o ponteiro da direita
 
// se conseguirmos montar um par, andamos com os dois ponteiros
 
// criar uma vetor para controlar quantas criancas ainda nao tem 
// gondola -> somar isso na resposta final
 
// complexidade da solucao: O(n log(n))
 
void solve(){
    ll n, x, ans = 0;
    cin >> n >> x;
 
    vll a (n);
 
    for(int i=0; i<n; i++)
        cin >> a[i];
 
    sort(all(a));
 
    vector <bool> has_gondola (n, false);
 
    int l = 0;
    int r = n-1;
 
    while(l<r){
        if(a[l]+a[r]<=x){
            ans++;
            has_gondola[l] = true;
            has_gondola[r] = true;
            l++;
            r--;
        }
        else
            r--;
    }
 
    for(int i=0; i<n; i++)
        ans += (has_gondola[i]==false);
 
    cout << ans << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}