#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100000;

vector<int> adj[MAX_N];
bool visited[MAX_N];

void dfs(int node) {
    stack<int> s;
    s.push(node);
    while(!s.empty()) {
        node = s.top(); s.pop();
        for(int& n : adj[node]) {
            if(!visited[n])
                s.push(n);
            visited[n] = 1;
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
    vector<int> components;
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i);
            components.push_back(i);
        }
    }
    cout << components.size() - 1 << '\n';
    for(int i = 1; i < components.size(); i++)
        cout << components[i] + 1 << ' ' << components[i-1] + 1 << '\n';
    return 0;
}