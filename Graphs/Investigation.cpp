#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<long long> dist(n + 1, INF);
    vector<int> ways(n + 1, 0);
    vector<int> mn(n + 1, (int)1e9);
    vector<int> mx(n + 1, -(int)1e9);

    priority_queue<
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>
    > pq;

    dist[1] = 0;
    ways[1] = 1;
    mn[1] = 0;
    mx[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &[v, w] : adj[u]) {
            long long nd = d + w;

            if (nd < dist[v]) {
                dist[v] = nd;
                ways[v] = ways[u];
                mn[v] = mn[u] + 1;
                mx[v] = mx[u] + 1;
                pq.push({dist[v], v});
            } else if (nd == dist[v]) {
                ways[v] = (ways[v] + ways[u]) % MOD;
                mn[v] = min(mn[v], mn[u] + 1);
                mx[v] = max(mx[v], mx[u] + 1);
            }
        }
    }

    cout << dist[n] << " " << ways[n] << " " << mn[n] << " " << mx[n] << '\n';
    return 0;
}