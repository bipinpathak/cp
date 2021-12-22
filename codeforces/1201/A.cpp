#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> count(m, vector<int> (5));
    while(n--) {
        string s;
        cin>>s;
        for(int i=0; i<m; i++) {
            count[i][s[i]-'A']++;
        }
    }   
    int ans=0;
    for(int i=0; i<m; i++) {
        int x, c=0;
        cin>>x;
        for(auto &j : count[i]) {
            c=max(c, j);
        }
        ans+=c*x;
    }
    cout<<ans<<endl;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

