#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, x, y;
    cin>>n>>x>>y;
    vector<vector<int>> a(n, vector<int> (2));
    for(auto &i : a) {
        for(auto &j : i) {
            cin>>j;
        }
    }
    vector<vector<int>> dp(x+1, vector<int> (y+1, n+1));
    dp[0][0]=0;
    for(auto curr : a) {
        auto update=dp;
        for(int i=0; i<=x; i++) {
            int ni=min(x, i+curr[0]);
            for(int j=0; j<=y; j++) {
                int nj=min(y, j+curr[1]);
                update[ni][nj]=min(update[ni][nj], dp[i][j]+1);
            }
        }
        dp=update;
    }
    if(dp[x][y]>n) {
        dp[x][y]=-1;
    }
    cout<<dp[x][y]<<endl;
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
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

