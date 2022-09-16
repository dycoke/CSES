#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000;

int row_num, col_num;
bool visited[MAX_N][MAX_N];

void floodfill(int r, int c){
	if ((r < 0 || r >= row_num || c < 0 || c >= col_num) || visited[r][c])
        return;

	visited[r][c] = 1;
	floodfill(r, c + 1);
	floodfill(r, c - 1);
	floodfill(r - 1, c);
	floodfill(r + 1, c);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> row_num >> col_num;
	for(int i = 0; i < row_num; i++) {
		string row; cin >> row;
		for(int j = 0; j < col_num; j++) {
			visited[i][j] = row[j] == '#';
		}
	}
	int ans = 0;
	for (int i = 0; i < row_num; i++) {
		for (int j = 0; j < col_num; j++) {
			if (!visited[i][j]) {
				ans++;
				floodfill(i, j);
			}
		}
	}
	cout << ans << '\n';
	return 0;
}