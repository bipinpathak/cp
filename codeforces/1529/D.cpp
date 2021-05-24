#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll p=998244353;

void solve() {
    ll n;
    cin>>n;
    vector<ll> factors(n+1, 0);
    for(ll i=1; i<=n; i++) {
        for(ll j=i; j<=n; j+=i) {
            factors[j]++;
        }
    }
    vector<vector<ll>> dp(n+1, vector<ll> (3));
    dp[1][0]=1;
    dp[1][2]=1;
    ll total=1;
    for(int i=2; i<=n; i++) {
        dp[i][0]=factors[i];
        dp[i][1]=total;
        dp[i][2]=(dp[i][0]+dp[i][1])%p;
        total=(total+dp[i][2])%p;
    }
    cout<<dp[n][2]<<endl;
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

