#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rec(int indx, vector < int > &nums, long long &ans, int &n, long long &tsum, long long sum){
    if(indx==n){
        if(sum!=tsum || sum!=0){
            ans=min(ans, abs(sum-(tsum-sum)));
        }
        return;
    }
    rec(indx+1, nums, ans, n, tsum, sum+nums[indx]);
    rec(indx+1, nums, ans, n, tsum, sum);
}

void solve() {
    int n;
    cin>>n;
    vector < int > nums(n);
    long long sum=0;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        sum+=1LL*nums[i];
    }
    long long ans=1e18;
    rec(0, nums, ans, n, sum, 0);
    cout<<ans<<'\n';
}

int main() {
    solve();
    return 0;
}
