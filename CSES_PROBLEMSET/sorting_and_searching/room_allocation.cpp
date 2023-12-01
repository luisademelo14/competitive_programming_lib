#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<char, int>> vpci;
typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef map<char, int> mci;
typedef map<string, int> msi;

 
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define ppb pop_back
#define all(c) (c).begin(), (c).end()

const int MAX_N = 1000000007;
 
struct customer{
    int a, d, index;
};
 
bool compare(customer customer1, customer customer2){
    return customer1.a < customer2.a;
}
 
void solve(){
    int n;
    cin >> n;
 
    vector <customer> customers (n);
 
    vector <int> ans (n);
 
    for(int i=0; i<n; i++){
        cin >> customers[i].a;
        cin >> customers[i].d;
        customers[i].index = i;
    }
 
    // ordenando pensando so na chegada
    sort(all(customers), compare);
 
    // fila de prioridade de minimo
 
    // a fila de prioridade guarda os horarios de saida dos
    // clientes que ja foram processados
    priority_queue <pii, vector<pii>, greater<pii>> pq;
 
    int curr_room = 0, rooms = 0;
 
    for(int i=0; i<n; i++){
        if(pq.empty()){
            // precisamos de outra sala
            curr_room++;
            pq.push({customers[i].d, curr_room});
            ans[customers[i].index] = curr_room;
        }
        else{
            auto minimum = pq.top();
            if(customers[i].a > minimum.f){
                // tirar da fila, pq agora a sala vai ser ocupada
                // por outro cliente
                pq.pop();
                pq.push({customers[i].d, minimum.s});
                ans[customers[i].index] = minimum.s;
            }
            else{
                // precisamos de outra sala
                curr_room++;
                pq.push({customers[i].d, curr_room});
                ans[customers[i].index] = curr_room;
            }
        }
        rooms = max(rooms, curr_room);
    }
    
    cout << rooms << endl;
 
    for(int i=0; i<n; i++){
        cout << ans[i];
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