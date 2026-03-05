#include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

void add(int indx, int &rnk, int l, int r, long long val, vector<long long> &segTree){
    if(rnk<l || rnk>r)
    return;
    if(l==r){
        segTree[indx]=(segTree[indx]+val)%mod;
        return;
    }
    int mid = (l+r)/2;
    add(2*indx+1, rnk, l, mid, val, segTree);
    add(2*indx+2, rnk, mid+1, r, val, segTree);
    segTree[indx]=(segTree[2*indx+1]+segTree[2*indx+2])%mod;
}

long long query(int indx, int l, int r, int lo, int high, vector<long long> &segTree){
    if(high<l || lo>r)
    return 0;
    if(lo<=l && r<=high)
    return segTree[indx];
    int mid =(l+r)/2;
    long long ans=(query(2*indx+1, l, mid, lo, high, segTree) + query(2*indx+2, mid+1, r, lo, high, segTree))%mod;
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<int> arr(n);
    vector<int>sarr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sarr[i]=arr[i];
    }
    sort(sarr.begin(), sarr.end());
    int rnk=1;
    map<int, int> rankmapping;
    for(int i=0;i<n;i++){
        if(rankmapping.find(sarr[i])==rankmapping.end()){
            rankmapping[sarr[i]]=rnk;
            rnk++;
        }
    }
    vector<long long> segTree(4*rnk, 0);
    add(0, rankmapping[arr[0]], 0, rnk, 1, segTree);
    vector<long long> dp(n, 0);
    dp[0]=1;
    long long ans=1;
    for(int i=1;i<n;i++){
        long long wayless = query(0, 0, rnk, 0, rankmapping[arr[i]]-1, segTree);
        dp[i]=(1+wayless)%mod;
        add(0, rankmapping[arr[i]], 0, rnk, dp[i], segTree);
        ans=(ans+dp[i])%mod;
    }
    cout<<ans<<'\n';
}