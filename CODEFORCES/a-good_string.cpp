#include <bits/stdc++.h>
#include <unordered_map>
 
using namespace std;
typedef long long ll;

// https://codeforces.com/problemset/problem/1385/D

int n;
string str;

int min_cost(int l, int r, char c){
    // caso base da recursao
    if(l==r){
        if(str[l]==c)
            return 0;
        else
            return 1;
    }
    int mid = (l+r)/2;
    int left_cost = 0;
    int right_cost = 0;

    // custo pra transformar a primeira metade em c-good string
    for(int i=l; i<=mid; i++){
        if(str[i]!=c)
            left_cost++;
    }


    // custo pra transformar a segunda metade em c-good string
    for(int i=mid+1; i<=r; i++){
        if(str[i]!=c)
            right_cost++;
    }

    // passar a primeira metade pra (c+1)-good string
    // ou passar a segunda metade pra (c+1)-good string
    return min(left_cost+min_cost(mid+1, r, c+1), right_cost+min_cost(l, mid, c+1));

}

void solve(){
    cin >> n >> str;
    cout << min_cost(0, n-1, 'a') << endl;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}