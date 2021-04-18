#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin>>n>>k;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++) {
        cin>>a[i];
    }
    vector<vector<ll>> dp(n+1, vector<ll> (k+1));
    dp[0][0]=1;
    ll p=1e9+7;
    for(int i=1; i<=n; i++) {
        ll pre=0;
        for(int j=0; j<=k; j++) {
            pre+=dp[i-1][j];
            if(j-a[i]-1>=0) {
                pre-=dp[i-1][j-a[i]-1];
            }
            pre%=p;
            if(pre<0) {
                pre+=p;
            }
            dp[i][j]=pre;
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

