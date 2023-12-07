#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;


// seja m = m1 * m2 * ... * mk (fatores coprimos entre si)

// temos o seguinte sistema de congruencias pra resolver:

/*
    a ≅ a1 (mod m1)
    a ≅ a2 (mod m2)
    :
    :
    a ≅ ak (mod mk)
*/ 
// ai sao constantes dadas
// esse sistema sempre possui solucao unica modulo m para 'a'

// consequencia importante do teorema chines do resto:
    // a equacao x ≅ a (mod m) eh equivalente ao seguinte sistema:
    /*
        x ≅ a1 (mod m1)
        x ≅ a2 (mod m2)
        :
        :
        x ≅ ak (mod mk)
    */

//      k
// x ≅  ∑  ai*Mi*M(inv)i  (mod m1*m2***mk)
//     i=1

// entendendo os parametros da funcao:
    // vetor a com as constantes do sistema
    // vetor n com os fatores primos de N

ll chinese_remainder_theorem(vector<ll> a, vector<ll>n){ 
    int size = (int)a.size();
    ll x = 0; // variavel do sistema

    ll N = 1; // numero formado a partir dos primos 

    vector<ll> m (size); // vetor com as constantes mi pra solucao
    vector<ll> minv (size); // vetor com os inversos modulares de mi


    for(int i=0; i<size; i++){
        N *= n[i]; // N = n1 * n2 * ....
    }

    for(int i=0; i<size; i++){
        m[i] = N/n[i]; // m1 = N/n1 , m2=N/n2,..... 
    }

    for(int i=0; i<size; i++){
        int z = 0;
        int x = m[i];
        while((z*x)%n[i]!=1){
            z++;
        }
        minv[i] = z; // minv1 * m1 ≅ 1 mod n1 , minv2 * m2 ≅ 1 mod n2,..... 
    }

    for(int i=0; i<size; i++){
        x += (a[i]*m[i]*minv[i]); // calculando resultado final 
    }

    x = x%N; // pegando o modulo pra garantir que eh menor que N

    return x; // retorna a solucao unica do sistema
}
