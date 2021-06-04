#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int go(int parts, vector<int> &prev) {
    int n=(int)prev.size()-1;
    vector<vector<int>> dp(n+1, vector<int> (parts+1, n));
    vector<int> options(parts+1, n);
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=parts; j++) {
            dp[i][j]=i;
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=min(parts, i+1); j++) {
            dp[i][j]=min(dp[i][j], min(dp[prev[i]][j-1], i+options[j]));
            options[j]=min(options[j], dp[i][j]-i);
        }
    }
    return dp[n][parts];
}

void solve() {
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    sort(a.begin(), a.end());
    vector<int> prev(n+1);
    int curr=n-1;
    for(int i=n-1; i>=0; i--) {
        while(curr>=0 && a[curr]>a[i]/2) {
            curr--;
        }
        prev[i+1]=curr+1;
    }
    for(int taka=0; taka<=30; taka++) {
        int aoki=go(taka, prev);
        if(aoki<=k) {
            cout<<taka<<" "<<aoki<<endl;
            return;
        }
    }
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
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

