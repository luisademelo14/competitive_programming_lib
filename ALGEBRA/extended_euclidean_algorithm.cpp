#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;



// o algoritmo de euclides calcula apenas o gcd entre dois numeros

// a versao extendida calcula gcd(a,b) e (x,y), onde:
// a*x = b*y = gcd(a,b)

// x e y sao passados como parametros na funcao e sao alterados
// ao longo da execucao do algoritmo (passar o ponteiro)


// usando recursao
int extended_euclides(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extended_euclides(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}


// na sua forma iterativa (um pouco mais rapido)
int extended_euclides_iterative(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

