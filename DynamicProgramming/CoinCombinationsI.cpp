#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int mod = 1e9+7;

int rec(vector < int > &dp, vector < int > &c, int val, int n){
    if(val<0){
        return 0;
    }
    if(val==0){
        return 1;
    }
    if(dp[val]!=-1)
    return dp[val];
    int ans=0;
    for(int i=0;i<n;i++){
        ans=(ans+rec(dp, c, val-c[i], n))%mod;
    }
    dp[val]=ans;
    return ans;
}

void solve() {
    int n, x;
    cin>>n>>x;
    vector < int > c(n);
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    vector < int > dp(x+1, 0);
    dp[0]=1;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i>=c[j]){
                dp[i]=(dp[i]+dp[i-c[j]])%mod;
            }
        }
    }
    // int ans = rec(dp, c, x, n);
    cout<<dp[x]<<'\n';
}

int main() {
    solve();
    return 0;
}
