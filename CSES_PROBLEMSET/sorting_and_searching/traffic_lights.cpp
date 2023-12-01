#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef set<int> si;
 
#define endl '\n'

#define pb push_back

const ll MAX_N = 1000000007;
 
// ideia do problema: imprimir o maior intervalo da rua que nao tem
// semaforo, para cada semaforo que eh adicionado
 
// criar um set com os semaforos que tem ate agora
 
// criar um multiset com os intervalos entre os semaforos (a resposta
// vai ser sempre o ultimo elemento do multiset -> que eh o maior)
 
// usar busca binaria (upper_bound) para achar onde vamos colocar o proximo
// semaforo
 
// apagar do multiset o intervalo de antes e adicionar os dois novos intervalos
// gerados pelo posicionamento do semaforo
 
// complexidade da solucao: O(n log(n))
 
void solve(){
    int x, n;
    cin >> x >> n;
 
    // comecando o set com os dois limites para os intervlos
    // em que vamos colocar os semaforos
    si lights {0, x};
 
    // comecando o multiset com um elemento, que eh o proprio
    // comprimento da rua
    multiset <int> distances {x};
 
    for(int i=0; i<n; i++){
        int light;
        cin >> light;
 
        // achando os limites entre os quais o semaforo sera 
        // colocado
        auto r = lights.upper_bound(light);
        auto l = r;
        l--;
 
        distances.erase(distances.find(*r-*l));
        distances.insert(light-*l);
        distances.insert(*r-light);
        lights.insert(light);
 
        auto maximum = distances.end();
        maximum--;
 
        cout << *maximum;
 
        if(i<n-1)
            cout << ' ';
    }
    cout << endl;
}
 
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}