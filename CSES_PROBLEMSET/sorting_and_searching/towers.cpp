#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
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
 
// ideia do problema: imprimir o menor numero possivel de torres
// que conseguimos construir com os cubos dados em ordem
 
// um cubo so fica em cima de outro se for menor que ele
 
// ideia pra solucao: usar um multiset pra guardar os topos de todas
// as torres atuais e usar upper_bound pra procurar onde colocar o
// proximo cubo
 
// a resposta vai ser o tamanho do multiset
 
// complexidade da solucao: O(n log(n))
 
void solve(){
    int n, cube;
    cin >> n;    
 
    multiset <int> towers;
 
    for(int i=0; i<n; i++){
        cin >> cube;
        // procurando onde colocar o proximo cubo
        auto t = towers.upper_bound(cube);
        // temos que criar uma nova torres com esse cubo
        // como base
        if(t == towers.end())
            towers.insert(cube);
        else{
            // trocando o topo da torre em que
            // colocamos o cubo
            towers.erase(t);
            towers.insert(cube);
        }
    }
    cout << towers.size() << endl;
}
 
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}