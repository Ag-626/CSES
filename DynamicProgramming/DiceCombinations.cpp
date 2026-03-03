#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int mod = 1e9+7;

int rec(vector < int > &dp, int val){
    if(val<0)
    return 0;
    if(val==0)
    return 1;
    if(dp[val]!=-1){
        return dp[val];
    }
    int ans=0;
    for(int i=1;i<=6;i++){
        ans=(ans+rec(dp, val-i))%mod;
    }
    dp[val]=ans;
    return ans;
}

void solve() {
    
    int n;
    cin>>n;
    vector < int > dp(n+1, -1);
    int ans=rec(dp, n);
    cout<<ans<<'\n';
}

int main() {
    solve();
    return 0;
}
