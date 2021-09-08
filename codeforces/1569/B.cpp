#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    string s;
    cin>>n>>s;
    vector<int> win;
    for(int i=0; i<n; i++) {
        if(s[i]=='2') {
            win.push_back(i);
        }
    }
    int m=(int)win.size();
    if(m>0 && m<=2) {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    vector<vector<char>> ans(n, vector<char> (n, '='));
    for(int i=0; i<m; i++) {
        int x=win[i], y=win[(i+1)%m];
        ans[x][y]='+';
        ans[y][x]='-';
    }
    for(int i=0; i<n; i++) {
        ans[i][i]='X';
    }
    for(auto i : ans) {
        for(auto j : i) {
            cout<<j;
        }
        cout<<endl;
    }
    return;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

