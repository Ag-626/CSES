

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<int> coins(n);
    int totalsum=0;
    for(int i=0;i<n;i++){
        cin>>coins[i];
        totalsum+=coins[i];
    }
    vector<bool>dp(totalsum+1, false);
    dp[0]=true;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=coins[i];
        for(int j=sum;j>=coins[i];j--){
            dp[j]=(dp[j]|dp[j-coins[i]]);
        }
    }
    int ans=0;
    vector<int>anssum;
    for(int i=1;i<=totalsum;i++){
        if(dp[i]){
            ans++;
            anssum.push_back(i);
        }
    }
    cout<<ans<<'\n';
    for(auto &v: anssum)
    cout<<v<<' ';
    cout<<'\n';


    return 0;
}
