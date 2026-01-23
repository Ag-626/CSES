#include <iostream>
#include <vector>
using namespace std;

// ---------- Solve one test case ----------
void solve() {
    int n;
    cin>>n;
    vector < int > nums(n, n+1);
    int num;
    for(int i=0;i<n-1;i++){
        cin>>num;
        nums[i]=num;
    }
    int ans=-1;
    for(int i=0;i<n-1;i++){
        nums[abs(nums[i])-1] = -1*nums[abs(nums[i])-1];
    }
    for(int i=0;i<n;i++){
        if(nums[i]>0)
        ans=i+1;
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
