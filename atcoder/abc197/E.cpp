#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> p(n+2, vector<int> (2));
    for(int i=1; i<=n; i++) {
        p[i][0]=1e9+1;
        p[i][1]=-1e9-1;
    }
    for(int i=0; i<n; i++) {
        int x, c;
        cin>>x>>c;
        p[c][0]=min(p[c][0], x);
        p[c][1]=max(p[c][1], x);
    }
    vector<vector<ll>> dp(n+2, vector<ll> (2, 1e18));
    dp[0]={0, 0};
    for(int i=1; i<=n+1; i++) {
        if(p[i][0]>p[i][1]) {
            p[i]=p[i-1];
            dp[i]=dp[i-1];
            continue;
        }
        for(int curr=0; curr<2; curr++) {
            for(int prev=0; prev<2; prev++) {
                dp[i][curr]=min(dp[i][curr], dp[i-1][prev]+abs(p[i-1][prev]-p[i][!curr])+abs(p[i][!curr]-p[i][curr]));    
            }
        }
    }
    cout<<min(dp[n+1][0], dp[n+1][1])<<endl;
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

