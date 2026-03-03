

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    // combinations (order doesn't matter)
    for (int coin : c) {
        for (int sum = coin; sum <= x; sum++) {
            dp[sum] += dp[sum - coin];
            if (dp[sum] >= MOD) dp[sum] -= MOD;
        }
    }

    cout << dp[x] << "\n";
    return 0;
}
