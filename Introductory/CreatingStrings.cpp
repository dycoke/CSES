#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string s; cin >> s;
	sort(s.begin(), s.end());
	vector<string> permutations;
	do {
		permutations.push_back(s);
	} while(next_permutation(s.begin(), s.end()));
	cout << permutations.size() << '\n';
	for(string& permutation : permutations) {
		cout << permutation << '\n';
	}
	return 0;
}