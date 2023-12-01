#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <ll> vll;

#define endl '\n'
#define pb push_back


void solve(){
    ll n;
    cin >> n;
    ll sum = ((1+n)*n)/2;
    if(sum%2){
        cout << "NO" << endl;
        return;
    }
    vi one;
    vi two;
    if(n%2){
        ll l1 = 1;
        ll r1 = n-1;
        int c1 = 1;
        two.pb(n);
        while(l1<r1){
            if(c1){
                one.pb(l1++);
                one.pb(r1--);
            }
            else{
                two.pb(l1++);
                two.pb(r1--);
            }
            c1 ^= 1;
        }
    }
    else{
        ll l2 = 1;
        ll r2 = n;
        int c2 = 1;
        while(l2<r2){
            if(c2){
                one.pb(l2++);
                one.pb(r2--);
            }
            else{
                two.pb(l2++);
                two.pb(r2--);
            }
            c2 ^= 1;
        }
    }
    cout << "YES" << endl;
    cout << one.size() << endl;
    cout << one[0];
    for(int i=1; i<one.size(); i++)
        cout << ' ' << one[i];
    cout << endl << two.size() << endl;
    cout << two[0];
    for(int i=1; i<two.size(); i++)
        cout << ' ' << two[i];
    cout << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}