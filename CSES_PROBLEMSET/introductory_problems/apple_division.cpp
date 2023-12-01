#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;


#define endl '\n'
#define f first
#define s second
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()

#define PI 3.141592653589793
 
const ll MAX_N = 1000000007;
 
// ideia do problema: separar as macas em dois conjuntos e minimizar
// a diferenca entre esses dois conjuntos
 
// da pra fazer com recursao por conta do valor pequeno de n
 
// complexidade O(2^n) -> gerar todos os subconjuntos possiveis
 
ll min_diff(ll i, ll *arr, ll curr_sum, ll total_sum){
 
    // caso base: quando passamos pelo vetor inteiro e formamos um subconjunto possivel
    if(i==0)
        return abs((total_sum-curr_sum)-curr_sum);
 
    // decidindo se pegamos a[i] ou nao para este subconjunto
    return min(min_diff(i-1, arr, curr_sum+arr[i], total_sum), min_diff(i-1, arr, curr_sum, total_sum));
}
 
void solve(){
    ll n, total_sum = 0;
    cin >> n;
 
    ll arr [n];
 
    for(int i=0; i<n; i++){
        cin >> arr[i];
        // soma total dos elementos do array
        total_sum += arr[i];
    }
    cout << min_diff(n-1, arr, 0, total_sum) << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}