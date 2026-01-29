#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    string s;
    cin>>s;

    int len=s.length();
    vector < int > freq(26, 0);
    string ans="";
    for(int i=0;i<len;i++){
        freq[s[i]-'A']++;
    }
    int flag=0;
    char c=' ';
    for(int i=0;i<26;i++){
        if(freq[i]%2){
            flag++;
            c=(char)(i+65);
        }
    }
    if(flag>1){
        cout<<"NO SOLUTION"<<'\n';
        return;
    }
    for(int i=0;i<26;i++){
        for(int j=0;j<freq[i]/2;j++){
            ans.push_back((char)(i+65));
        }
    }

    string finalans=ans;
    if(c!=' ')
    finalans.push_back(c);
    reverse(ans.begin(), ans.end());
    finalans+=ans;
    cout<<finalans<<'\n';
}

int main() {
    solve();
    return 0;
}
