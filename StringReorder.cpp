#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = (int)s.size();

    vector<int> cnt(26, 0);
    for (char c : s) cnt[c - 'A']++;

    auto maxCount = [&]() {
        int mx = 0;
        for (int x : cnt) mx = max(mx, x);
        return mx;
    };

    // Global feasibility check
    if (maxCount() > (n + 1) / 2) {
        cout << "-1\n";
        return 0;
    }

    string ans;
    ans.reserve(n);
    int prev = -1;

    for (int pos = 0; pos < n; pos++) {
        bool placed = false;
        for (int ch = 0; ch < 26; ch++) {
            if (cnt[ch] == 0) continue;
            if (ch == prev) continue;

            // Try placing ch
            cnt[ch]--;
            int rem = n - pos - 1;

            // Feasible if max remaining count <= ceil(rem/2)
            if (maxCount() <= (rem + 1) / 2) {
                ans.push_back(char('A' + ch));
                prev = ch;
                placed = true;
                break;
            }

            // Undo if not feasible
            cnt[ch]++;
        }

        if (!placed) { // should not happen if initial feasibility holds, but safe
            cout << "-1\n";
            return 0;
        }
    }

    cout << ans << "\n";
    return 0;
}
