#include <bits/stdc++.h>
 
using namespace std;
 
void solve(){
    int n, contador = 0;
    cin >> n;
    if(n==1)
        cout << 1;
    else if(n==4)
        cout << "2 4 1 3";
    else if(n<4)
        cout << "NO SOLUTION";
    else{
        for(int i=1; i<=n; i+=2){
            contador++;
            cout << i;
            if(contador<n)
                cout << ' ';
        }
        for(int i=2; i<=n; i+=2){
            contador++;
            cout << i;
            if(contador<n)
                cout << ' ';
        }
    }
    cout << '\n';
}
 
int main(){
    solve();
    return 0;
}