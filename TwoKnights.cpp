#include <iostream>
#include <vector>
using namespace std;

// ---------- Solve one test case ----------
void solve(int i) {
    long long ans=0;
    ans=(1LL*i*1LL*(1LL*i*i-1)*1LL*i)/2 - 4*1LL*(i-1)*1LL*(i-2);
    cout<<ans<<'\n';
}

int main() {

    int T = 1;
    // Uncomment if multiple test cases:
    cin >> T;
    int i=1;
    while (T--){
        solve(i);
        i++;
    } 
    return 0;
}
