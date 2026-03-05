#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

void generate_next_masks(int current_mask, int i, int next_mask, int n,
                         vector<int>& next_masks){
    if(i == n + 1){
        next_masks.push_back(next_mask);
        return;
    }

    if(current_mask & (1 << i)) {
        generate_next_masks(current_mask, i + 1, next_mask, n, next_masks);
        return; // IMPORTANT: if already filled, don't try other placements
    }

    // vertical domino in current column
    if(i != n && !(current_mask & (1 << (i+1)))) {
        generate_next_masks(current_mask, i + 2, next_mask, n, next_masks);
    }

    // horizontal domino to next column
    generate_next_masks(current_mask, i + 1, next_mask | (1 << i), n, next_masks);
}

int solve(int col, int mask, int m, int n, vector<vector<int>> &dp){
    if(col == m + 1) return (mask == 0);

    int &res = dp[col][mask];
    if(res != -1) return res;

    long long answer = 0;
    vector<int> next_masks;
    generate_next_masks(mask, 1, 0, n, next_masks);

    for(int next_mask: next_masks){
        answer = (answer + solve(col + 1, next_mask, m, n, dp)) % mod;
    }
    return res = (int)answer;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    if(n > m) swap(n, m);              // keep n small for bitmask

    int MASK = 1 << (n + 1);           // because you use bits 1..n
    vector<vector<int>> dp(m + 2, vector<int>(MASK, -1));

    cout << solve(1, 0, m, n, dp) << "\n";
    return 0;
}