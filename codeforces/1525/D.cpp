#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin>>n;
    vector<vector<int>> a(2);
    for(int i=0; i<n; i++) {
        int x;
        cin>>x;
        a[x].push_back(i);
    }
    n=(int)a[1].size(), m=(int)a[0].size();
    vector<vector<int>> dp(n, vector<int> (m, 1e8));
    for(int i=0; i<n; i++) {
        for(int j=i; j<m; j++) {
            int prev=i?dp[i-1][j-1]:0;
            dp[i][j]=min(dp[i][j], prev+abs(a[1][i]-a[0][j]));
        }
        for(int j=1; j<m; j++) {
            dp[i][j]=min(dp[i][j], dp[i][j-1]);
        }
    }
    int ans=0;
    if(n && m) {
        ans=dp[n-1][m-1];
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

