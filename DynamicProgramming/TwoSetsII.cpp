#include <bits/stdc++.h>
using namespace std;

const long long INF = (long long)4e18;
const int mod = 1e9+7;
const int INV2 = 500000004;

int rec(int indx, int sum, int n, vector<vector<int>> &dp, int &tsum) {
    if(2*sum>(tsum))
    return 0;
    if(2*sum==(tsum))
    return 1;
    if(indx>n){
        return 0;
    }
    if(dp[indx][sum]!=-1)
    return dp[indx][sum];

    int ans=0;
    ans=(ans+rec(indx+1, sum+indx, n, dp, tsum))%mod;
    ans=(ans+rec(indx+1, sum, n, dp, tsum))%mod;
    dp[indx][sum]=ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    int sum = n*(n+1)/2;
    vector<vector<int>> dp(n+1, vector<int>(sum/2 + 5, -1));
    int ans = rec(1, 0, n, dp, sum);
    cout<<(1LL*ans*INV2)%mod<<'\n';

    return 0;
}