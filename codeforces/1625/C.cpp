#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, l, k;
    cin>>n>>l>>k;
    vector<int> d(n), a(n);
    for(auto &i : d) {
        cin>>i;
    }
    for(auto &i : a) {
        cin>>i;
    }
    d.push_back(l);
    vector<vector<int>> dp(n+1, vector<int> (k+1, 1e9));
    dp[0][0]=0;
    for(int i=0; i<=n; i++) {
        for(int j=1; j<=k; j++) {
            dp[i][j]=min(dp[i][j], dp[i][j-1]);
        }
        for(int j=i+1; j<=n; j++) {
            int skips=j-i-1; 
            for(int curr=0; curr+skips<=k; curr++) {
                dp[j][curr+skips]=min(dp[j][curr+skips], dp[i][curr]+a[i]*(d[j]-d[i]));
            }
        }
    }
    cout<<dp[n][k]<<endl;
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

