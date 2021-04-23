#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    string a, b;
    cin>>n>>m>>a>>b;
    vector<vector<int>> dp(n, vector<int> (m));
    int ans=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int x, y, z;
            x=y=z=0;
            if(i) {
                x=dp[i-1][j];
            }
            if(j) {
                y=dp[i][j-1];
            }
            if(i && j) {
                z=dp[i-1][j-1];
            }
            dp[i][j]=max(x-1, y-1);
            if(a[i]==b[j]) {
                dp[i][j]=max(dp[i][j], z+2);
            }   
            dp[i][j]=max(dp[i][j], 0);
            ans=max(ans, dp[i][j]);
        }
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

