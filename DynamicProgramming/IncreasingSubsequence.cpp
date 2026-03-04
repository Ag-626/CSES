#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector< int > arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector < int > ans;
    for(int i=0;i<n;i++){
        if((ans.empty()) || (arr[i]>ans.back())){
            ans.push_back(arr[i]);
        }else{
            auto it = lower_bound(ans.begin(), ans.end(), arr[i]);
            int indx = it-ans.begin();
            ans[indx]=arr[i];
        }
    }
    cout<<ans.size();
}