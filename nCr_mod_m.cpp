/* ref: (https://ikatakos.com/pot/programming_algorithm/number_theory/mod_combination) */

#include <cstdio>
using namespace std;
typedef long long ll;
static const int mod = 998244353;

ll *fact, *inv;

ll combi(int n, int r) {
    if (n < 0 || r < 0 || r > n) { return 0; }
    if (r > n / 2) { r = n - r; }
    return fact[n] * inv[r] % mod * inv[n-r] % mod;
}

ll extpow(ll x, ll y) {
    if (y == 0) { return 1; }
    else if (y == 1) { return x % mod; }
    else {
        ll part = extpow(x, y/2);
        if (y % 2 == 0) {
            return part * part % mod;
        } else { 
            return part * part % mod * x % mod;
        }
    }
}

void init(int n) {
    fact = new ll[n+1];
    inv = new ll[n+1];

    fact[0] = 1;
    for (int i = 1; i < n + 1; i++) {
        fact[i] = i * fact[i-1] % mod;
    }

    inv[n] = extpow(fact[n], mod - 2);
    for (int i = n - 1; i >= 0; i--) {
        inv[i] = inv[i+1] * (i+1) % mod;
    }
}

int main() {
    int n, r;
    scanf("%d %d", &n, &r);

    init(n);

    printf("%lld\n", combi(n, r));
}