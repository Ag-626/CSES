#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector < string > storebits(n+1);
    vector < string > ans(1<<n);
    for(int i=1;i<=n;i++){
        string s1="";
        string s2="";
        int k=1<<(i-1);
        for(int j=0;j<2*k;j++){
            if(j/k==0)
            s1.push_back('0');
            else
            s1.push_back('1');
        }
        s2=s1;
        reverse(s1.begin(), s1.end());
        storebits[i]=s2+s1;
    }
    int j=1<<n;
    for(int i=0;i<j;i++){
        string s="";
        for(int k=n;k>=1;k--){
            int len=storebits[k].length();
            s.push_back(storebits[k][i%len]);
        }
        ans[i]=s;
    }
    for(int i=0;i<j;i++){
        cout<<ans[i]<<'\n';
    }
}

int main() {
    solve();
    return 0;
}
