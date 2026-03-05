#include <bits/stdc++.h>
using namespace std;

struct SegTreeMax {
    int n;
    vector<int> seg;
    SegTreeMax(int m=0) { init(m); }
    void init(int m) {
        n = 1;
        while (n < m) n <<= 1;
        seg.assign(2*n, 0);
    }
    void update(int pos, int val) { // set seg[pos] = max(seg[pos], val)
        int i = pos + n;
        seg[i] = max(seg[i], val);
        for (i >>= 1; i >= 1; i >>= 1) {
            seg[i] = max(seg[i<<1], seg[i<<1|1]);
        }
    }
    int query(int l, int r) const { // max on [l,r]
        if (l > r) return 0;
        l += n; r += n;
        int res = 0;
        while (l <= r) {
            if (l & 1) res = max(res, seg[l++]);
            if (!(r & 1)) res = max(res, seg[r--]);
            l >>= 1; r >>= 1;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    // 1) Compute L[i] = previous index with height >= h[i]
    vector<int> L(n), R(n);
    {
        vector<int> st;
        st.reserve(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && h[st.back()] < h[i]) st.pop_back();
            L[i] = st.empty() ? -1 : st.back();
            st.push_back(i);
        }
    }

    // 2) Compute R[i] = next index with height >= h[i]
    {
        vector<int> st;
        st.reserve(n);
        for (int i = n-1; i >= 0; i--) {
            while (!st.empty() && h[st.back()] < h[i]) st.pop_back();
            R[i] = st.empty() ? n : st.back();
            st.push_back(i);
        }
    }

    // 3) Process indices by increasing height (group equal heights)
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int a, int b){
        if (h[a] != h[b]) return h[a] < h[b];
        return a < b;
    });

    SegTreeMax seg(n);
    vector<int> dp(n, 1);

    int ans = 1;
    for (int p = 0; p < n; ) {
        int q = p;
        while (q < n && h[idx[q]] == h[idx[p]]) q++;

        // compute dp for this height using only smaller heights (already in seg)
        for (int t = p; t < q; t++) {
            int i = idx[t];
            int bestLeft  = seg.query(L[i] + 1, i - 1);
            int bestRight = seg.query(i + 1, R[i] - 1);
            dp[i] = 1 + max(bestLeft, bestRight);
            ans = max(ans, dp[i]);
        }

        // then update seg with these dp (so equal heights don't interact)
        for (int t = p; t < q; t++) {
            int i = idx[t];
            seg.update(i, dp[i]);
        }

        p = q;
    }

    cout << ans << "\n";
    return 0;
}