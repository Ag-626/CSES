#include <bits/stdc++.h>
using namespace std;

const long long INF = (long long)4e18;

long long recDiff(int i, int j, vector<vector<long long>> &dp, const vector<long long> &arr) {
    if (i == j) return arr[i];
    if (dp[i][j] != INF) return dp[i][j];

    long long takeLeft  = arr[i] - recDiff(i + 1, j, dp, arr);
    long long takeRight = arr[j] - recDiff(i, j - 1, dp, arr);

    return dp[i][j] = max(takeLeft, takeRight);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> arr(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    vector<vector<long long>> dp(n, vector<long long>(n, INF));

    long long diff = recDiff(0, n - 1, dp, arr);     // first - second
    long long first = (sum + diff) / 2;              // max first score

    cout << first << "\n";
    return 0;
}