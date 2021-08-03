#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    string s;
    cin>>n>>s;
    int m=9*100;
    vector<vector<int>> dp(m+1, {0, 0});
    for(int i=0; i<n; i++) {
        for(int j=0; j<=m; j++) {
            dp[j][1]+=s[i]-'0';
            if(dp[j][1]==j) {
                dp[j][0]++;
                dp[j][1]=0;
            }
        }
    }
    string ans="NO";
    for(int i=0; i<=m; i++) {
        if(dp[i][0]>1 && dp[i][1]==0) {
            ans="YES";
            break;
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

