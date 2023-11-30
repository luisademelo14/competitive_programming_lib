#include <bits/stdc++.h>
 
using namespace std;

const int max_n = 1000000007;

// retorna o vetor com os valores de z para cada elemento da string

// complexidade O(n+m), onde n eh o tamanho da string e m eh o 
// tamanho do padrao

// explicacao do algoritmo otimizado:
// caso 1) i >= r
    // a posicao atual esta fora da parte que ja foi processada
    // nao ha prefixo da string que comeca antes de i e termina depois de i
    // fazer a comparacao do jeito trivial
    // compara str[0...] com str[i...] 
    // temos como resultado: z[i] = r-l+1

// caso 2) i < r
    // neste caso, z[i] >= min(z[i-l], r-i+1)
    // usamos valores ja calculados de z para inicializar z[i] e, com isso, diminuir o numero de iteracoes do algoritmo
    // i esta em algum intervalo [l, r) que sabemos que eh prefixo
    // neste caso, sabemos que as substrings str[0...r-l) e str[l...r) dao match
    // z[i] = min(z[i-l], r-i)
    // com certeza, r-i chars vao bater com o prefixo da string
    // z[i-l] pode ser muito grande e passar do tamanho da string (por isso usar minimo)
    // subcaso a) i + z[i] <= r
        // o intervalo [l, r] continua o mesmo
    // subcaso b) i + z[i] > r
        // atualizamos o intervalo [l, r] (outro padrao foi encontrado)


vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}