#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100000;

vector<int> adj[MAX_N];
bool visited[MAX_N], colors[MAX_N];

bool dfs(int node, bool color) {
    stack<int> s;
    s.push(node);
    colors[node] = color;
    while(!s.empty()) {
        node = s.top();
        s.pop();
        for(int& n : adj[node]) {
            if(visited[n]) {
                if(colors[n] == colors[node])
                    return 0;
            } else {
                s.push(n);
                visited[n] = 1;
                colors[n] = !colors[node];
            }
        }
    }
    return 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(!dfs(i, 0)) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << colors[i] + 1 << ' ';
    }
    cout << '\n';
    return 0;
}