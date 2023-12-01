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
#define lbnd lower_bound
#define ubnd upper_bound
#define debug cerr << "\ni'm here\n" << endl;
#define PI 3.141592653589793
 
const ll MAX_N = 1000000007;
 
// ideia do problema: imprimir a ordem das criancas que saem
// da roda no problema de josephus
 
// usar a estrutura de dados fila
 
// pular o primeiro da fila e colocar ele no final
// depois, pegar o que sobrou na frente e tirar ele da fila
 
// complexidade da solucao: O(n)
 
void solve(){
    int n;
    cin >> n;
 
    queue <int> children;
 
    for(int i=1; i<=n; i++)
        children.push(i);
 
    while(!children.empty()){
        int a = children.front();
        children.pop();
 
        children.push(a);
 
        cout << children.front() << ' ';
 
        children.pop();
    }

    cout << endl;
}
 
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}