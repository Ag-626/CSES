#include <iostream>
#include <vector>
using namespace std;

// ---------- Solve one test case ----------
void solve() {
    int n;
    cin>>n;
    if(n==1){
        cout<<1;
        return;
    }
    if(n==2 || n==3){
        cout<<"NO SOLUTION";
        return;
    }
    vector < int > ans;
    if(n%2){
        for(int i=n;i>=1;i-=2){
            ans.push_back(i);
        }
        for(int i=(n-1);i>=1;i-=2){
            ans.push_back(i);
        }
    }
    else{
        for(int i=(n-1);i>=1;i-=2)
        ans.push_back(i);
        for(int i=n;i>=1;i-=2)
        ans.push_back(i);
    }
    for(int i=0;i<(n-1);i++){
        cout<<ans[i]<<" ";
    }
    cout<<ans[n-1];
}

int main() {

    int T = 1;
    // Uncomment if multiple test cases:
    // cin >> T;

    while (T--) solve();
    return 0;
}
