#include <bits/stdc++.h>
using namespace std;

struct Project {
    int a, b;
    long long p;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Project> pr(n);
    for (int i = 0; i < n; i++) cin >> pr[i].a >> pr[i].b >> pr[i].p;

    sort(pr.begin(), pr.end(), [](const Project& x, const Project& y) {
        return x.b < y.b; // sort by end day
    });

    vector<int> ends(n);
    for (int i = 0; i < n; i++) ends[i] = pr[i].b;

    vector<long long> dp(n + 1, 0); // dp[0]=0
    for (int i = 1; i <= n; i++) {
        int start = pr[i-1].a;
        long long reward = pr[i-1].p;

        // find last project j that ends < start
        int j = lower_bound(ends.begin(), ends.end(), start) - ends.begin(); 
        // j is count of projects with end < start
        dp[i] = max(dp[i-1], dp[j] + reward);
    }

    cout << dp[n] << "\n";
    return 0;
}