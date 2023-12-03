#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
typedef long long ll;
typedef long double ld;

 
#define endl '\n'

const int MAX_N = 1000000007;
 
// ideia do problema: para cada querie, imprimir o numero de divisores do
// numero dado
 
// ideia da solucao: calcular todas as potencias dos primos que 
// dividem 'n' incrementadas de 1
 
// a resposta eh a multiplicacao de todas essas potencias
 
// se o numero que sobrar for primo -> ans *= 2 (pow=1+1)
 
// complexidade da solucao: O(sqrt(n))
 
void solve(){
    int n;
    cin >> n;
 
    int ans = 1;
 
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0){
            int pow = 1;
            while(n%i==0){
                pow++;
                n/=i;
            }
            ans *= pow;
        }
    }
 
    // o numero eh primo
    if(n!=1)
        ans*=2;
 
    cout << ans << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}