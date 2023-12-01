#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<pair<int, int>> vpii;

#define endl '\n'
#define f first
#define s second
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()

const ll MAX_N = 1000000007;
 
// ideia do problema: imprimir as posicoes de dois elementos 
// do vetor cuja soma eh 'x' (ou imprimir "IMPOSSIBLE")
 
// resolver ordenando o vetor e usando two pointers
 
// guardar as posicoes originais dos elementos em um vetor de pairs
 
void solve(){
    int n, x, value;
    cin >> n >> x;
 
    vpii arr (n+1);
 
    for(int i=1; i<=n; i++){
        cin >> value;
        arr[i] = mp(value, i);
    }
 
    sort(all(arr));
 
    int l = 1;
    int r = n;
 
    while(l<r){
        // se a soma der maior que x -> andar com r
        if(arr[l].f+arr[r].f>x)
            r--;
        // se a soma der menor que x -> andar com l
        else if(arr[l].f+arr[r].f<x)
            l++;
        // se der igual a x -> achamos a resposta 
        else{
            cout << arr[l].s << ' ' << arr[r].s << endl;
            return;
        }
    }
    // se nao encontrar: impossivel

    cout << "IMPOSSIBLE" << endl;
}
 
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}