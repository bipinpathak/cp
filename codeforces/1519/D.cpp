#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll fetch(int i, int j, vector<ll> &a, vector<ll> &b, vector<vector<ll>> &dp) {
    if(i>j) {
        return 0;
    } else if(i==j) {
        return a[i]*b[j];
    }
    if(dp[i][j]==-1) {
        dp[i][j]=a[i]*b[j]+a[j]*b[i]+fetch(i+1, j-1, a, b, dp);
    }
    return dp[i][j];
}

void solve() {
    int n;
    cin>>n;
    vector<ll> a(n), b(n);
    for(auto &i : a) {
        cin>>i;
    }
    for(auto &i : b) {
        cin>>i;
    }
    vector<vector<ll>> dp(n, vector<ll> (n, -1));
    ll ans=0, left=0;
    for(int i=0; i<n; i++) {
        ll right=0;
        for(int j=n-1; j>=i; j--) {
            ll mid=fetch(i, j, a, b, dp);
            ans=max(ans, left+mid+right);
            right+=a[j]*b[j];
        }
        left+=a[i]*b[i];
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
    auto start=clock();
    int t = 1;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

