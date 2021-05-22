#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int a, b;
    ll k;
    cin>>a>>b>>k;
    vector<vector<ll>> dp(a+1, vector<ll> (b+1));
    for(int i=0; i<=a; i++) {
        dp[i][0]=1;
    }
    for(int j=0; j<=b; j++) {
        dp[0][j]=1;
    }
    for(int i=1; i<=a; i++) {
        for(int j=1; j<=b; j++) {
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    string ans="";
    while(a || b) {
        char chose='a';
        if(a==0) {
            chose='b';
        } else if(b) {
           if(dp[a-1][b]<k) {
                chose='b';
                k-=dp[a-1][b];
           }
        }
        ans.push_back(chose);
        a-=chose=='a';
        b-=chose=='b';
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

