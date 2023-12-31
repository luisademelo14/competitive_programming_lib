#include <bits/stdc++.h>
#include <unordered_map>
 
using namespace std;
typedef long long ll;

// dividir o array de tamanho n em k subarrays
// tal que a maior soma entre os subarrays seja a menor possivel

int n, k;

vector<int> a;

// usar estrategia gulosa aquii
bool is_possible(ll max_sum, ll k){
    int qnt_subarrays = 1;
    ll curr_sum = 0;
    for(int i=0; i<(int)a.size(); i++){
        if(a[i]>max_sum)
            return false;
        curr_sum += a[i];
        if(curr_sum>max_sum){
            qnt_subarrays++;
            curr_sum = a[i];
        }
    }
    return (qnt_subarrays<=k);
}

// busca binaria pra achar a resposta
ll best_split(int k){
    ll low = 0;
    ll high = 1e18;
    ll curr_best = high;
    while(low<=high){
        ll mid = low + (high-low)/2;
        if(is_possible(mid, k)){
            curr_best = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return curr_best;
}

void solve(){
    cin >> n >> k;

    a = vector<int> (n);

    for(int i=0; i<n; i++)
        cin >> a[i];
    
    cout << best_split(k) << endl;

}




int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}