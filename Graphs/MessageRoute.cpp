#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100000;

vector<int> adj[MAX_N];
bool visited[MAX_N];
int reached[MAX_N];

void bfs(int node) {
    queue<int> q;
    q.push(node);
    while(!q.empty()) {
        node = q.front(); q.pop();
        for(int& n : adj[node]) {
            if(!visited[n]) {
                visited[n] = 1;
                reached[n] = node;
                q.push(n);
            }
        }
    }
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
    bfs(0);
    if(visited[--n]) {
        vector<int> path({n});
        while(n != 0) {
            n = reached[n];
            path.push_back(n);
        }
        reverse(path.begin(), path.end());
        cout << path.size() << '\n';
        for(int& p : path) {
            cout << p + 1 << ' ';
        }
        cout << '\n';
    } else {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}