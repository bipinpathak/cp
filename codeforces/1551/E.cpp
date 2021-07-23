#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
        i--;
    }
    vector<vector<int>> dp(n+1, vector<int> (n+1));
    int ans=n+1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i+1; j++) {
            if(i) {
                dp[i][j]=dp[i-1][j];
            }
            if(a[i]==i-j) {
                dp[i][j]++;
            }
            if(i && j) {
                dp[i][j]=max(dp[i][j], dp[i-1][j-1]);
            }
            if(dp[i][j]>=k) {
                ans=min(ans, j);
            }
        }
    }
    if(ans==n+1) {
        ans=-1;
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

