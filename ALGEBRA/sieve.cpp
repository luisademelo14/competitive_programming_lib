#include <bits/stdc++.h>
 
using namespace std;

const int N = 1e5 + 9;

// sieve prime factors
int spf[N];

vector<int>primes; // vetor com os primos ate N

void sieve(){
    for(int i=2; i<N; i++){
        if(spf[i]==0){ // nao foi marcado ainda (eh primo)
            spf[i] = i;
            primes.push_back(i);
        }
        int sz = (int) primes.size();
        for(int j=0; j<sz && i*primes[j]<N && primes[j]<=spf[i]; j++){
            spf[i*primes[j]] = primes[j];
        }
    }
}