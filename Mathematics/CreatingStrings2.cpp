#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 1e9 + 7;
 
ll exp(ll x, ll y) {
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
    string a; cin >> a;
	vector<int> characters(26);
	for(int i = 0; i < a.size(); i++) {
		characters[a[i] - 'a']++;
	}
	vector<ll> factorial(a.size() + 1);
	vector<ll> ifactorial(a.size() + 1);
	factorial[0] = 1;
	ifactorial[0] = 1;
	for(ll i = 1; i <= a.size(); i++) {
		factorial[i] = (factorial[i - 1] * i) % MOD;
		ifactorial[i] = exp(factorial[i], MOD - 2);
	}
	ll ans = factorial[a.size()];
	for(int i = 0; i < 26; i++) {
		ans *= (ifactorial[characters[i]] % MOD);
		ans %= MOD;
	}
	cout << ans % MOD << '\n';
}