#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int mod = 1e9+7;

int rec(vector < int > &dp, vector < int > &c, int val, int n){
    if(val<0){
        return 1e9;
    }
    if(val==0){
        return 0;
    }
    if(dp[val]!=-1)
    return dp[val];
    int ans=2e9;
    for(int i=0;i<n;i++){
        ans=min(ans, 1+rec(dp, c, val-c[i], n));
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
    vector < int > dp(x+1, -1);
    int ans = rec(dp, c, x, n);
    if(ans>=(1e9))
    cout<<"-1"<<'\n';
    else{
        cout<<ans<<'\n';
    }
}

int main() {
    solve();
    return 0;
}
