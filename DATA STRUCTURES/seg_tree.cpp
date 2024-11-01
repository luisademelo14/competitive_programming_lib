// TEORIA

// estrutura de dados que guarda informações sobre intervalos de um array
// possibilita responder queries de forma rápida
// possibilita atualizações rápidas no array
// complexidade para resolver uma query: O(log(n))
// cada nó da árvore é um intervalo -> vai dividindo o tamanho dos intervalos em 2
// as folhas são os próprios elementos do array original 

// PROCESSO DE CONSTRUÇÃO
// pensar no valor a ser armazenado nos vértices (depende da query)
// e no tipo de operação de merge pra fazer (também depende da query)
// para um vértice específico, que não é uma folha: recursivamente construir
// os valores dos filhos e dar merge para chegar no valor desse vértice atual 
// complexidade da construção: O(nlog(n))

// SUM QUERIES
// soma de um segmento a[l...r]
// dado um vértice que representa um intervalo, temos 3 opções: é o próprio intervalo,
// tem interseção com os dois filhos ou tem interseção com apenas um lado
// se tem alguma interseção (e não é o próprio intervalo), pegar o meio e calcular a partir dele (pra 
// esquerda até chegar em l e pra direita até chegar em r)
// complexidade da query: O(log(n))

// UPDATE QUERIES
// função recursiva que vai atualizando apenas os vértices da seg que tem a[i] (o elemento que será atualizado)
// complexidade da query: O(log(n))


// CÓDIGO

#include <bits/stdc++.h>
#include <unordered_map>
 
using namespace std;

// definindo filhos (dir e esq)
#define R(x) ((x<<1)+1)
#define L(x) (x<<1)

int n, v[100005];
long long seg3[4*100005];

// função auxiliar para queries de soma em intervalos do array
long long join(long long a, long long b){
	return a+b;
}

// construção da seg
void build(int id,int l,int r){
	if(l==r){
		seg3[id]=v[l];
		return;
	}
	int meio=(l+r)>>1;
	build(L(id),l,meio);
	build(R(id),meio+1,r);
	seg3[id]=join(seg3[L(id)],seg3[R(id)]);
}

// querie de atualização -> soma val ao elemento
void update(int id,int l,int r,int i,int val){
	if(l==r && l==i){
		seg3[id]+=val;
		return;
	}
	int meio=(l+r)>>1;
	if(meio>=i) update(L(id),l,meio,i,val);
	else update(R(id),meio+1,r,i,val);
	
	seg3[id]=join(seg3[L(id)],seg3[R(id)]);
}

// queries de mínimo (dá pra mudar pra máximo se precisar)
int min_query (int node, int i, int j, int ini, int fim) {
	if (i > fim || j < ini) return INT_MAX;
	if (i >= ini && j <= fim) return arvore[node];
	else {
		int meio = (i+j)/2;
		int resp1 = min_query (2*node, i, meio, ini, fim);
		int resp2 = min_query (2*node+1, meio+1, j, ini, fim);
		return min(resp1, resp2);
	}
}

// busca binária -> achar o primeiro elemento maior que x no array
int query_binary_search(int v, int tl, int tr, int l, int r, int x) {
    if (l > r)
        return INF;
    if (l == tl && r == tr) {
        pos = lower_bound(t[v].begin(), t[v].end(), x);
        if (pos != t[v].end())
            return *pos;
        return INF;
    }
    int tm = (tl + tr) / 2;
    return min(query(v*2, tl, tm, l, min(r, tm), x), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r, x));
}

// update específico para o problema da busca binária na seg
void update_binary_search(int v, int tl, int tr, int pos, int new_val) {
    t[v].erase(t[v].find(a[pos]));
    t[v].insert(new_val);
    if (tl != tr) {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
    } else {
        a[pos] = new_val;
    }
}

// queries de somas em intervalos 
long long sum_query(int id,int l,int r,int i,int j){
	if(i<=l && r<=j) return seg3[id];
	if(r<i || j<l) return 0;
	int meio=(l+r)>>1;
	return join(query(L(id),l,meio,i,j),query(R(id),meio+1,r,i,j));
}