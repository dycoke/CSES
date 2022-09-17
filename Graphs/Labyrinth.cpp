#include <bits/stdc++.h>
using namespace std;
 
const int MAX_N = 1000;
 
int row_num, col_num;
bool visited[MAX_N][MAX_N];
int reached[MAX_N][MAX_N];
vector<int> dx({1, -1, 0, 0}), dy({0, 0, 1, -1});
string directions = "RLDU";
 
void floodfill(int r, int c) {
    queue<pair<int, int>> q;
    q.push({r, c});
    while(!q.empty()) {
        r = q.front().first;
        c = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nr = r + dy[i], nc = c + dx[i];
            if ((nr < 0 || nr >= row_num || nc < 0 || nc >= col_num) || visited[nr][nc])
                continue;
            q.push({nr, nc});
            reached[nr][nc] = i;
            visited[nr][nc] = 1;
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> row_num >> col_num;
    int ax, ay, bx, by;
    for(int i = 0; i < row_num; i++) {
        string row; cin >> row;
        for(int j = 0; j < col_num; j++) {
            if(row[j] == 'A') {
                ax = i; ay = j;
            } else if(row[j] == 'B') {
                bx = i; by = j;
            }
            visited[i][j] = row[j] == '#';
        }
    }
    floodfill(ax, ay);
    if(visited[bx][by]) {
        cout << "YES\n";
        vector<char> ans;
        while(bx != ax || by != ay) {
            int reach = reached[bx][by];
            ans.push_back(directions[reach]);
            bx -= dy[reach]; by -= dx[reach];
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for(char& c : ans) {
            cout << c;
        }
        cout << '\n';
    } else {
        cout << "NO\n";
    }
    return 0;
}