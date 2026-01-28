#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n;
    cin >> n;

    if (n % 4 == 0 || n % 4 == 3) {
        long long target = 1LL * n * (n + 1) / 4;

        vector<int> set1, set2;
        int num = n;

        while (target > 0) {
            if (target >= num) {
                target -= num;
                set1.push_back(num);
            } else {
                set1.push_back((int)target);
                break;
            }
            num--;
        }

        for (int i = 1; i <= num; i++) {
            if (i == target) continue;
            set2.push_back(i);
        }

        sort(set1.begin(), set1.end());

        cout << "YES\n";
        cout<<set1.size()<<'\n';
        for (size_t i = 0; i < set1.size(); i++) cout << set1[i] << ' ';
        cout << "\n";
        cout<<set2.size()<<'\n';
        for (size_t i = 0; i < set2.size(); i++) cout << set2[i] << ' ';
        cout << "\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    solve();
    return 0;
}
