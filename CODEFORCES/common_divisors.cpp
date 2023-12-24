#include <bits/stdc++.h>
#include <unordered_map>
 
using namespace std;

typedef long long ll;

// https://codeforces.com/problemset/problem/182/D

// ideia do problema: calcular o numero
// de divisores comuns entre duas strings

bool is_divisor(int prefix_sz, string &str){
    int n = (int) str.size();
    for(int i=prefix_sz; i<n; i+=prefix_sz){
        for(int j=0; j<prefix_sz; j++){
            if(str[i+j]!=str[j])
                return false;
        }
    }
    return true;
}

int common_divisors(string &s1, string &s2){
    int common = 0;
    // pegar o comprimento da menor string
    int n = min((int)s1.size(), (int)s2.size());
    for(int i=0; i<n; i++){
        if(s1[i]!=s2[i])
            return common;
        if((int)s1.size() % (i+1)==0 && (int)s2.size() % (i+1)==0 &&
        is_divisor(i+1, s1) && is_divisor(i+1, s2))
            common++;
    }

    return common;
}

void solve(){
    string s1, s2;
    cin >> s1 >> s2;
    cout << common_divisors(s1, s2) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}