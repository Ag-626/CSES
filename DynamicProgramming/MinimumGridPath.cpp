#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n;
    cin>>n;
    vector<string> grid(n);
    for(int i=0;i<n;i++){
        cin>>grid[i];
    }
    vector<char> ans;
    ans.push_back(grid[0][0]);
    vector<pair<int, int>> cur;
    cur.push_back(make_pair(0,0));
    int stamp=0;
    vector<int> mark(n*n);

    for(int i=0;i<(2*n-2);i++){
        char best = 'Z' + 1;
        for(auto &v: cur){
            int r=v.first;
            int c=v.second;
            if(((r+1)<n))
            best = min(best, grid[r+1][c]);
            if(((c+1)<n))
            best = min(best, grid[r][c+1]);
        }
        ans.push_back(best);

        vector<pair<int,int>> nxt;
        stamp++;
        for(auto &v: cur){
            int r=v.first;
            int c=v.second;
            if(((r+1)<n) && grid[r+1][c]==best){
                int key = (r+1)*n + c;
                if(mark[key]!=stamp){
                    mark[key]=stamp;
                    nxt.push_back(make_pair(r+1, c));
                }
            }
            if(((c+1)<n) && grid[r][c+1]==best){
                int key = (r)*n + c;
                if(mark[key]!=stamp){
                    mark[key]=stamp;
                    nxt.push_back(make_pair(r, c+1));
                }
            }
        }
        cur.swap(nxt);
    }
    string finalans;
    for(int i=0;i<2*n-1;i++){
        finalans.push_back(ans[i]);
    }
    cout<<finalans<<'\n';
}