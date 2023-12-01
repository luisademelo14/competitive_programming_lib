#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
#define endl '\n'

#define pb push_back
#define ppb pop_back

const ll MAX_N = 1000000007;
 
// vetor com a resposta pros movimentos
vector<string> ans;
 
// funcao recursiva que calcula os movimentos
void hanoi(int n, int start, int end){
    // caso base: mover 1 disco pro destino
    if(n==1)
        ans.pb(to_string(start)+" "+to_string(end));
    else{
        // other = torre q nao eh start nem end
        int other = 6 - (start+end);
        hanoi(n-1, start, other);
        ans.pb(to_string(start)+" "+to_string(end));
        hanoi(n-1, other, end);
    }
}
 
void solve(){
    int n;
    cin >> n;
    hanoi(n, 1, 3);
    // qnt de movimentos
    cout << ans.size() << endl;
    for(auto u : ans){
        cout << u << endl;
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}