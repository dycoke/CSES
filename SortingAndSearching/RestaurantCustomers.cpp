#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	vector<pair<int, int>> customers;
	for(int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		customers.push_back({a, 1});
		customers.push_back({b, -1});
	}
	sort(customers.begin(), customers.end());
	for(int i = 0; i < 2*n; i++) {
		customers[i].first = i + 1;
	}
	vector<int> prefix(2*n + 1);
	for(pair<int, int>& customer : customers) {
		prefix[customer.first] += customer.second;
	}
	int ans = 0;
	for(int i = 1; i <= 2*n; i++) {
		prefix[i] += prefix[i-1];
		ans = max(ans, prefix[i]);
	}
	cout << ans << '\n';
	return 0;
}