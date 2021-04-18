#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll fetch(int l, int r, vector<vector<ll>> &dp, vector<ll> &sum) {
    if(dp[l][r]==-1) {
        dp[l][r]=1e18;
        if(l==r) {
            dp[l][r]=0;
        } else {
            for(int i=l; i<r; i++) {
                ll offer=fetch(l, i, dp, sum)+fetch(i+1, r, dp, sum)+sum[r]-sum[l-1];
                dp[l][r]=min(dp[l][r], offer);
            }
        }
    }
    return dp[l][r];
}

void solve() {
    int n;
    cin>>n;
    vector<ll> sum(n+1);
    for(int i=1; i<=n; i++) {
        cin>>sum[i];
        sum[i]+=sum[i-1];
    }
    vector<vector<ll>> dp(n+1, vector<ll> (n+1, -1));
    cout<<fetch(1, n, dp, sum)<<endl;
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
    //cin >> t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

