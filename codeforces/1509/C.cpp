#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll fetch(int l, int r, vector<ll> &a, vector<vector<ll>> &dp) {
    if(dp[l][r]==-1) {
        dp[l][r]=a[r]-a[l];
        if(l!=r) {
            dp[l][r]+=min(fetch(l+1, r, a, dp), fetch(l, r-1, a, dp));
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
    sort(a.begin(), a.end());
    vector<vector<ll>> dp(n, vector<ll> (n, -1));
    cout<<fetch(0, n-1, a, dp)<<endl;
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

