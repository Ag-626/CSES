#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int mod = 1e9+7;

long long dp[20][10][2][2];

void reset(){

    for(int i=0;i<20;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<2;k++){
                for(int t=0;t<2;t++){
                    dp[i][j][k][t]=-1;
                }
            }
        }
    }
}

string toString(long long a){
    string s;
    while(a>0){
        s.push_back((char)(a%10+48));
        a=a/10;
    }
    reverse(s.begin(), s.end());
    return s;
}
long long rec(int indx, string &s, int len, int ld, int tight, int start){
    if(len==indx)
    return 1;
    if(dp[indx][ld][tight][start]!=-1)
    return dp[indx][ld][tight][start];

    long long ans=0;
    if(start==0){
        ans=ans+rec(indx+1, s, len, 0, 0, 0);
        if(tight==1){
            int num = (int)(s[indx]-48);
            for(int i=1;i<num;i++){
                ans=(ans+rec(indx+1, s, len, i, 0, 1));
            }
            ans=(ans+rec(indx+1, s, len, num, 1, 1));
        }
        else{
            for(int i=1;i<=9;i++){
                ans=(ans+rec(indx+1, s, len, i, 0, 1));
            }
        }
    }else{
        if(tight==1){
            int num = (int)(s[indx]-48);
            for(int i=0;i<num;i++){
                if(i!=ld)
                ans=(ans+rec(indx+1, s, len, i, 0, 1));
            }
            if(num!=ld)
            ans=(ans+rec(indx+1, s, len, num, 1, 1));
        }
        else{
            for(int i=0;i<=9;i++){
                if(i!=ld)
                ans=(ans+rec(indx+1, s, len, i, 0, 1));
            }
        }
    }
    dp[indx][ld][tight][start]=ans;
    return ans;
}

void solve() {
    long long a; long long b;
    cin>>a>>b;
    if(a==0 && b==0)
    cout<<"1"<<'\n';
    else{
        reset();
        long long ways1 = 0;
        if(a!=0){
            string s1=toString(max(a-1, 1LL*0));
            ways1 = rec(0, s1, s1.length(), 0, 1, 0);
        }
        string s2=toString(b); 
        reset();
        long long ways2 = rec(0, s2, s2.length(), 0, 1, 0);
        cout<<(ways2-ways1)<<'\n';
    }
}

int main() {
    solve();
    return 0;
}
