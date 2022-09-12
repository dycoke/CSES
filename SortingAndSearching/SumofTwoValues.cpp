#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, x; cin >> n >> x;
	map<int, vector<int>> num_index;
	vector<int> numbers(n);
	for(int i = 0; i < n; i++) {
		int num; cin >> num;
		num_index[num].push_back(i);
		numbers[i] = num;
	}
	for(int i = 0; i < n; i++) {
		int search = x - numbers[i];
		if(!num_index.count(search)) {
			continue;
		}
		else {
			if(numbers[i] == search) {
				if(num_index[search].size() > 1) {
					cout << i + 1 << ' ' << num_index[search][1] + 1 << '\n';
				} else {
					continue;
				}
			} else {
				cout << i + 1 << ' ' << num_index[search][0] + 1 << '\n';
			}
			return 0;
		}
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}