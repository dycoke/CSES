#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 1e9 + 7;

ll binpow(ll x, ll y) {
	ll res = 1; x %= MOD;
	while (y) {
		if (y & 1) {
			res *= x; res %= MOD; 
		}
		x *= x; x %= MOD;
		y >>= 1;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n, m; cin >> n >> m;
	vector<ll> factorial(n + m), ifactorial(n + m);
	factorial[0] = 1; ifactorial[0] = 1;
	for(int i = 1; i < n+m; i++) {
		factorial[i] = (factorial[i-1] * i) % MOD;
		ifactorial[i] = binpow(factorial[i], MOD - 2);
	}
	ll ans = factorial[n+m-1];
	ans *= ifactorial[n-1]; ans %= MOD;
	ans *= ifactorial[m]; ans %= MOD;
	cout << ans << '\n';
	return 0;
}