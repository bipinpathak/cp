#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll fetch(int l, int r, vector<vector<ll>> &dp, vector<ll> &a, int n) {
    if(l>r) {
        return 0;
    }
    if(dp[l][r]==-1) {
        int move=n-(r-l+1);
        if(move%2==0) {
            dp[l][r]=-1e18;
            dp[l][r]=max(dp[l][r], a[l]+fetch(l+1, r, dp, a, n));
            dp[l][r]=max(dp[l][r], a[r]+fetch(l, r-1, dp, a, n));
        } else {
            dp[l][r]=1e18;
            dp[l][r]=min(dp[l][r], fetch(l+1, r, dp, a, n)-a[l]);
            dp[l][r]=min(dp[l][r], fetch(l, r-1, dp, a, n)-a[r]);
        }
    }
    return dp[l][r];
}

void solve() {
    int n;
    cin>>n;
    vector<ll> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    vector<vector<ll>> dp(n, vector<ll> (n, -1));
    cout<<fetch(0, n-1, dp, a, n)<<endl;
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

