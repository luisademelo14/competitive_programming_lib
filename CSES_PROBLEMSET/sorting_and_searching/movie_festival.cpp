#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<pair<int, int>> vpii;
 
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define all(c) (c).begin(), (c).end()

const ll MAX_N = 1000000007;
 
// um dos problemas mais classicos de guloso: quantas tarefas
// conseguimos completar no maximo, dado o inicio e o fim de cada uma 
 
// estrategia gulosa: sempre priorizar aquelas que terminam mais cedo
 
// ordenar pelo final e so pegar a atual se inicio for maior ou igual
// ao final da anterior
 
void solve(){
    int n, start, end;
    cin >> n;
 
    vpii a;
 
    for(int i=0; i<n; i++){
        cin >> start >> end;
        a.pb({end, start});
    }
 
    sort(all(a));
 
    int curr = 0;
    int ans = 0;
 
    for(int i=0; i<n; i++){
        if(a[i].s >= curr){
            ans++;
            curr = a[i].f;
        }
    }
 
    cout << ans << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}