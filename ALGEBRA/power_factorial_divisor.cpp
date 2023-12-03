#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

// dados dois numeros: n e k

// encontrar a maior potencia de k (x) tal que n! eh divisivel por k^x

// complexidade do algoritmo: O(log n) -> base do log = k

int fact_pow (int n, int k) {
	int res = 0;
	while (n) {
		n /= k;
		res += n;
	}
	return res;
}
