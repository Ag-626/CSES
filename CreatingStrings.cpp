#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void rec(int indx, set < string > &ans, vector < int > &freq, int n, string &str){
    if(indx==n){
        ans.insert(str);
        return;
    }
    for(int i=0;i<26;i++){
        if(freq[i]>0){
            freq[i]--;
            str.push_back((char)(i+97));
            rec(indx+1, ans, freq, n, str);
            str.pop_back();
            freq[i]++;
        }
    }
}


int main() {

    string s;
    cin>>s;
    int n = s.length();
    set < string > ans;
    vector < int > freq(26, 0);
    for(int i=0;i<26;i++){
        freq[s[i]-'a']++;
    }
    string str="";
    rec(0, ans, freq, n, str);
    cout<<ans.size()<<'\n';
    for(auto &v: ans){
        cout<<v<<'\n';
    }

}
