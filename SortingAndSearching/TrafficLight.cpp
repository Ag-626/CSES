#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, n;
    cin >> x >> n;

    set<int> pos;
    multiset<int> len;

    pos.insert(0);
    pos.insert(x);
    len.insert(x);

    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;

        auto it = pos.lower_bound(p);
        int hi = *it;
        int lo = *prev(it);

        // remove old segment length (hi - lo) once
        auto oldIt = len.find(hi - lo);
        len.erase(oldIt);

        // add new segments
        len.insert(p - lo);
        len.insert(hi - p);

        // add new light position
        pos.insert(p);

        // maximum segment length is the last element in multiset
        if (i) cout << ' ';
        cout << *len.rbegin();
    }
    cout << "\n";
    return 0;
}
