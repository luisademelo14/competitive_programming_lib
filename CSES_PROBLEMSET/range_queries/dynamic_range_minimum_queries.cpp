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
 
int n, q;
 
int tree [400005];
 
// lembrar que o array original eh 0-indexado e a seg
// eh 1-indexada
 
 
// atualizar valor na posicao k para u
void update(int k, int u){
    k+=n; // mudando para o indx na arvore
 
    tree[k] = u; // atualizando o valor
    k/=2; // subindo 1 nivel na arvore
 
    while(k>=1){
        tree[k] = min(tree[2*k+1], tree[2*k]); // atualizando a partir 
                                               // do valor dos filhos
        k/=2; // subindo 1 nivel na arvore
    }
}
 
// retorna o minimo de um range do array original
int min_querie(int a, int b){
    // mudando para o indx na arvore
    a+=n; 
    b+=n;
 
    int ans = MAX_N;
 
    while(a<=b){
        if(a%2) ans = min(ans, tree[a++]); // a eh filho direito
        if(!(b%2)) ans = min(ans, tree[b--]); // b eh filho esquerdo
        // subindo 1 nivel na arvore
        a/=2; 
        b/=2;
    }
 
    return ans;
}
 
 
void solve(){
    int num;
    cin >> n >> q;
 
    for(int i=0; i<n; i++){
        cin >> num;
        update(i, num);
    }
 
    while(q--){
        int op, a, b;
        cin >> op >> a >> b;
 
        if(op==1){
            update(a-1, b);
        }
        else{
            cout << min_querie(a-1, b-1) << endl;
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}