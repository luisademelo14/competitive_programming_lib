#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <ll> vll;
 
#define endl '\n'

const ll MAX_N = 1000000007;
 
void solve(){
    vll pow_10 (19, 1);
 
    // criando o vetor com as potencias de 10
    for(int i=1; i<19; i++){
        pow_10[i] = pow_10[i-1]*10;
    }
 
    ll q, k;
    cin >> q;
 
    while(q--){
        cin >> k;
 
        // qntos digitos tem cada numero do intervalo
        ll num_dig = 0;
 
        // qnt total de algarismos no intervalo
        ll cnt_dig = 0;
 
        // qnt de algarismos que vem antes desse intervalo
        ll prev_dig = 0;
 
        // vamos achar o intervalo de numeros em que a posicao k esta
        for(int i=1; i<19; i++){
            cnt_dig += (pow_10[i] - pow_10[i-1]) * i;
 
            if(cnt_dig >= k){
                // achamos o intervalo
                num_dig = i;
                break;
            }
            // fica com o valor de logo antes de entrar no "if"
            prev_dig = cnt_dig;
        }
 
        // limites para a busca binaria
        ll l = pow_10[num_dig-1];
        ll r = pow_10[num_dig] - 1;
 
        // numero que contem o digito na posicao k
        ll ans = 0;
 
        // em qual posicao comeca esse numero (ans)
        ll start_pos_ans = 0;
 
        // busca binaria
        while(l<=r){
            // chutamos um numero de num_dig digitos que pode conter k 
            ll mid = (l+r)/2;
 
            // conta pra chegar em qual posicao comeca esse numero
            ll start_pos = prev_dig + num_dig*(mid-pow_10[num_dig-1]) + 1;
 
            if(start_pos<=k){
                ans = mid;
                start_pos_ans = start_pos;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
 
        // passando o numero achado pra uma string
        string found_number = to_string(ans);
 
        // pegamos o digito do numero que esta na posicao k
        cout << found_number[k-start_pos_ans] << endl;
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}