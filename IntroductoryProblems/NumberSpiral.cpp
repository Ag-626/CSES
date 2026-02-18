#include <iostream>
#include <vector>
using namespace std;
long long compute(int n){
    long long ans;
    ans = 1LL+1LL*n*(2+1LL*(n-1));
    return ans;
}

// ---------- Solve one test case ----------
void solve() {
    int x, y;
    cin>>x>>y;
    int diagonal = max(x, y);
    if(diagonal==1){
        cout<<1<<'\n';
        return;
    }
    long long val = compute(diagonal-1);
    if(diagonal%2){
        cout<<(val+y-x)<<'\n';
    }
    else{
        cout<<(val+x-y)<<'\n';
    }
}

int main() {

    int T = 1;
    // Uncomment if multiple test cases:
    cin >> T;

    while (T--) solve();
    return 0;
}
