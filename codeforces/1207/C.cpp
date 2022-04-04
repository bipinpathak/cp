#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    ll a, b;
    string s;
    cin>>n>>a>>b>>s;
    vector<vector<ll>> dp(n+1, vector<ll> (2, 1e18));
    dp[0][0]=b;
    for(int i=1; i<=n; i++) {
        vector<int> allowed={!((i<n && s[i]=='1') || (s[i-1]=='1')), (i<n)};
        for(int k=0; k<2; k++) {
            if(!allowed[k]) {
                continue;
            }   
            dp[i][k]=min(dp[i-1][0]+(1+k)*a, dp[i-1][1]+(1+!k)*a)+(k+1)*b;
        }
    }
    cout<<dp[n][0]<<endl;
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

