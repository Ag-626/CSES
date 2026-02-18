#include <iostream>
#include <vector>
using namespace std;

// ---------- Solve one test case ----------
void solve() {
    string s;
    cin>>s;
    int n = s.length();
    int i=0;
    int ans=0;
    while(i<n){
        int tmp=1;
        while(((i+1)<n) && (s[i]==s[i+1])){
            tmp++;
            i++;
        }
        ans=max(ans, tmp);
        i++;
    }
    cout<<ans;
}

int main() {

    int T = 1;
    // Uncomment if multiple test cases:
    // cin >> T;

    while (T--) solve();
    return 0;
}
