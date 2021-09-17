#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, m, k;
    cin>>n>>m>>k;
    vector<ll> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    vector<vector<ll>> bonus(n, vector<ll> (n));
    while(k--) {
        int x, y, c;
        cin>>x>>y>>c;
        x--, y--;
        bonus[x][y]=c;
    }
    int last=(1<<n);
    vector<vector<ll>> dp(last, vector<ll> (n));
    ll ans=0;
    for(int curr=0; curr<last; curr++) {
        if(__builtin_popcount(curr)==m) {
            for(auto &i : dp[curr]) {
                ans=max(ans, i);
            }
            continue;
        }
        for(int add=0; add<n; add++) {
            if((curr&(1<<add))) {
                continue;
            }
            ll offer=0;
            for(int i=0; i<n; i++) {
                if((curr&(1<<i))) {
                    offer=max(offer, dp[curr][i]+bonus[i][add]);
                }
            }
            offer+=a[add];
            int next=curr+(1<<add);
            dp[next][add]=max(dp[next][add], offer);
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
    int t = 1;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

