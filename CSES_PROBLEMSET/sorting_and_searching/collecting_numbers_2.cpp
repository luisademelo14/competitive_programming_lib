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
 
// ideia do problema: eh dado um array de tamanho n com numeros
// de 1 ate n 
 
// cada rodada: pegamos os numeros em ordem crescente
 
// dizer quantas rodadas sao necessarias pra pegar todos os numeros
// do array
 
// para resolver: criar um array pos em que pos[num] eh a posicao do
// numero "num" no array original
 
// percorrer esse array sob o seguinte condicional: se pos[i]<pos[i-1]
// ans++;
 
// a resposta comeca com 1
 
// temos que responder queries para cada troca de valores no array
// uma dupla troca de posicao a cada querie
 
void solve(){
    int n, q, num, pos1, pos2;
    cin >> n >> q;
 
    vi pos (n+2, 0);
 
    vi a (n+1);
 
    for(int i=1; i<=n; i++){
        cin >> num;
        a[i] = num;
        pos[num] = i;
    }
 
    int ans = 1;
 
    for(int i=1; i<=n; i++){
        if(pos[i]<pos[i-1])
            ans++;
    }
 
    while(q--){
        cin >> pos1 >> pos2;
 
        int num1 = a[pos1];
        int num2 = a[pos2];
 
        swap(a[pos1], a[pos2]);
 
        // basta analisar o que acontece com os vizinhos
        // de num1 e num2 (no que tange as posicoes relativas
        // entre eles)
 
        if(pos[num1-1]<=pos[num1] && pos2<pos[num1-1]) ans++;
        if(pos[num1-1]>=pos[num1] && pos2>pos[num1-1]) ans--;
        if(pos[num1+1]>=pos[num1] && pos2>pos[num1+1]) ans++;
        if(pos[num1+1]<=pos[num1] && pos2<pos[num1+1]) ans--;
 
        pos[num1] = pos2;
 
        if(pos[num2-1]<=pos[num2] && pos1<pos[num2-1]) ans++;
        if(pos[num2-1]>=pos[num2] && pos1>pos[num2-1]) ans--;
        if(pos[num2+1]>=pos[num2] && pos1>pos[num2+1]) ans++;
        if(pos[num2+1]<=pos[num2] && pos1<pos[num2+1]) ans--;
 
        pos[num2] = pos1;
 
        cout << ans << endl;
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}