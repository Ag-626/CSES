#include <iostream>
#include <vector>
using namespace std;

// ---------- Solve one test case ----------
void solve() {
    int n;
    cin>>n;
    vector < int > arr(n, 0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long ans=0;
    for(int i=1;i<n;i++){
        if(arr[i]>=arr[i-1])
        continue;
        ans+=arr[i-1]-arr[i];
        arr[i]=arr[i-1];
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
