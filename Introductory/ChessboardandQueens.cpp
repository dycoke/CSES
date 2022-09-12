#include <bits/stdc++.h>
using namespace std;

bool check(vector<vector<int>>& checks, vector<int>& order) {
	for(int i = 0; i < 8; i++) {
		for(int& check: checks[i]) {
			if(order[i] == check) {
				return 0;
			}
		}
	}
	for(int i = 0; i < 7; i++) {
		for(int j = i + 1; j < 8; j++) {
			if(j - i == abs(order[i] - order[j])) {
				return 0;
			}
		}
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<int>> checks(8);
	for(int i = 0; i < 8; i++) {
		string row; cin >> row;
		for(int j = 0; j < 8; j++) {
			if(row[j] == '*') {
				checks[i].push_back(j);
			}
		}
	}
	vector<int> order({0, 1, 2, 3, 4, 5, 6, 7});
	int ans = 0;
	do {
		if(check(checks, order)) {
			ans++;
		}
	} while(next_permutation(order.begin(), order.end()));
	cout << ans << '\n';
	return 0;
}