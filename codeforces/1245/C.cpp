#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod=1e9+7;

void solve() {
    string s;
    cin>>s;
    int n=(int)s.size();
    vector<ll> dp(n+1);
    dp[0]=dp[1]=1;
    for(int i=2; i<=n; i++) {
        dp[i]=(dp[i-1]+dp[i-2])%mod;
    }
    int u=0;
    n=0;
    ll ans=1;
    for(auto i : s) {
        if(i!='u') {
            ans=(ans*dp[u])%mod;
            u=0;
        }
        if(i!='n') {
            ans=(ans*dp[n])%mod;
            n=0;
        }
        if(i=='u') {
            u++;
        }
        if(i=='n') {
            n++;
        }
        if(i=='w' || i=='m') {
            ans=0;
        }
    }
    ans=(ans*dp[u])%mod;
    ans=(ans*dp[n])%mod;
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

