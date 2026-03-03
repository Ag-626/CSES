

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int rec(int indx, int prev, vector<vector<int>> &dp, vector<int> &arr, int n, int m){
    if((prev<=0)||(prev>m))
    return 0;
    if(indx==n)
    return 1;
    if(dp[indx][prev]!=-1)
    return dp[indx][prev];

    int ans=0;
    if(arr[indx]==0){
        ans=(ans+rec(indx+1, prev-1, dp, arr, n, m))%mod;
        ans=(ans+rec(indx+1, prev, dp, arr, n, m))%mod;
        ans=(ans+rec(indx+1, prev+1, dp, arr, n, m))%mod;
    }else{
        if(abs(arr[indx]-prev)>1)
        ans=0;
        else{
            ans=rec(indx+1, arr[indx], dp, arr, n, m)%mod;
        }
    }
    dp[indx][prev]=ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int m;
    cin>>n>>m;
    vector < int > arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<int>> dp(n, vector<int> (m+1, -1));
    int ans=0;
    if(arr[0]==0){
        for(int i=1;i<=m;i++){
            ans=(ans+rec(1, i, dp, arr, n, m))%mod;
        }
    }else{
        ans=rec(1, arr[0], dp, arr, n, m)%mod;
    }
    cout<<ans<<'\n';
    return 0;
}
