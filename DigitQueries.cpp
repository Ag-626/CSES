#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

string toString(long long num){
    string ans="";
    while(num>0){
        int rem = num%10;
        ans.push_back((char)(48+rem));
        num=num/10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
} 

// ---------- Solve one test case ----------
void solve(long long k, vector < long long > &digits) {
    int indx=0;
    for(int i=1;i<=18;i++){
        if((k>digits[i-1])&&(digits[i]>=k)){
            indx=i;
        }
    }
    // cout<<" INDX "<<indx<<'\n';
    long long left = k-digits[indx-1];
    long long pow10=1;
    for(int i=1;i<indx;i++){
        pow10=10LL*pow10;
    }
    // cout<<" POW "<<indx<<'\n';
    if(left%indx){
        long long q=left/indx;
        pow10+=q;
        int rem = left%indx;
        string num = toString(pow10);
        // cout<<left<<" "<<q<<" "<<indx<<" "<<rem<<" "<<num<<" "<<pow10<<'\n';
        cout<<num[rem-1]<<'\n';
    }
    else{
        long long q=left/indx;
        pow10+=q-1;
        cout<<pow10%10<<'\n';
    }
}

int main() {

    int T = 1;
    // Uncomment if multiple test cases:
    cin >> T;
    long long k;

    vector < long long > digits(19, 0);
    long long pow10=1;
    for(int i=1;i<18;i++){
        digits[i]=pow10*9LL*i+digits[i-1];
        pow10=10LL*pow10;
    }
    digits[18]=1000000000000000000;
    // for(int i=1;i<=18;i++){
    //     cout<<digits[i]<<'\n';
    // }
    while (T--){
        cin>>k;
        solve(k, digits);
    } 
    return 0;
}
