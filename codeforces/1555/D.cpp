#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    string s;
    cin>>n>>m>>s;
    vector<vector<int>> dp(n, vector<int> (3)), dp2;
    dp2=dp;
    for(int i=0; i<n; i++) {
        if(i) {
            dp[i]=dp[i-1];
        }
        int curr=s[i]-'a';
        for(int j=0; j<3; j++) {
            dp[i][j]+=curr!=(i+j)%3;
        }
        if(s[i]=='b') {
            s[i]='c';
        } else if(s[i]=='c') {
            s[i]='b';
        }
    }
    for(int i=0; i<n; i++) {
        if(i) {
            dp2[i]=dp2[i-1];
        }
        int curr=s[i]-'a';
        for(int j=0; j<3; j++) {
            dp2[i][j]+=curr!=(i+j)%3;
        }
    }
    while(m--) {
        int l, r;
        cin>>l>>r;
        l--, r--;
        int ans=1e9;
        for(int i=0; i<3; i++) {
            int offer=dp[r][i];
            if(l) {
                offer-=dp[l-1][i];
            }
            ans=min(ans, offer);
            offer=dp2[r][i];
            if(l) {
                offer-=dp2[l-1][i];
            }
            ans=min(ans, offer);
        }
        cout<<ans<<endl;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

