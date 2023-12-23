#include <bits/stdc++.h>
#include <unordered_map>
 
using namespace std;

typedef long long ll;

// usando multiset pq pode haver repeticao de elementos

int n, k;
multiset<int> low;
multiset<int> up;

// inserindo elemento nos multisets
void ins(int val){
    // mediana ate o momento
    int curr_med = *low.rbegin();
    if(val>curr_med){
        up.insert(val);
        // caso de estrapolar o limite do multiset
        // passar o menor valor pro low
        if((int)up.size()>k/2){
            low.insert(*up.begin());
            up.erase(up.find(*up.begin()));
        }
    }
    else{
        low.insert(val);
        if((int)low.size()>(k+1)/2){
            up.insert(*low.rbegin());
            low.erase(low.find(*low.rbegin()));
        }
    }
}

// removendo elemento dos multisets
void remove(int val){
    // lembrar que o parametro da funcao erase do multiset
    // eh um itarator pro elemento que sera removido
    if(up.find(val)!=up.end())
        up.erase(up.find(val));
    else
       low.erase(low.find(val)); 
    // o multiset low nao pode ficar vazio, nele vai estar a resposta
    if(low.empty()){
        low.insert(*up.begin());
        up.erase(up.find(*up.begin()));
    }
}

void solve(){
    cin >> n >> k;
    vector<int> arr(n);

    for(int i=0; i<n; i++)
        cin >> arr[i];

    low.insert(arr[0]);

    for(int i=1; i<k; i++){
        ins(arr[i]);
    }
    
    cout << *low.rbegin() << ' ';

    // lembrar de tratar o caso em que k=1 separadamente

    for(int i=k; i<n; i++){
        if(k==1){
            ins(arr[i]);
            remove(arr[i-k]);
        }
        else{
            remove(arr[i-k]);
            ins(arr[i]);
        }
        cout << *low.rbegin() << ' ';
    }
    cout << endl;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}