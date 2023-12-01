#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
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
 
// ideia do problema: imprimir a ordem das criancas que saem
// da roda no problema de josephus (eh dado um k que eh a quantidade
// de criancas que pulamos ate remover a proxima)
 
// usar a estrutura de dados ordered set
 
// lembrar de ir aplicando o modulo, ja que k pode ser maior
// que n e estamos lidando com um circulo de criancas
 
// lembrar de incluir as bibliotecas necessarias e o template do ordered_set
 
// complexidade da solucao: O(n log(n))
 
void solve(){
    int n, k;
    cin >> n >> k;
 
    ordered_set <int> children;
 
    // comecamos colocando todas as criancas no ordered set
    for(int i=1; i<=n; i++)
        children.insert(i);
 
    int start_pos = 0;
    int removal_pos;
 
    while(!children.empty()){
        // ajustando a posicao de inicio pra nao ultrapassar
        // o limite de criancas
        start_pos %= children.size();
 
        // pulamos k criancas a partir da posicao de inicio
        // e removemos quem esta na posicao de remocao
        removal_pos = (start_pos+k)%children.size();
 
        // atualizando a posicao inicial pra proxima rodada
        start_pos = removal_pos;
 
        // encontrando a crianca que esta na posicao de remocao
        // no ordered set
        auto t = children.find_by_order(removal_pos);
 
        cout << *t << ' ';
 
        // removendo a crianca do ordered set
        children.erase(t);
    }
 
    cout << endl;
}
 
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}