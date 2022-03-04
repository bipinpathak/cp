#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll count(ll n) {
    ll ans=0;
    while(n) {
        ans+=n&1;
        n>>=1;
    }
    return ans;
}

void solve() {
    ll n;
    cin>>n;
    ll curr=1;
    vector<vector<ll>> have;
    for(int i=2; curr<=n; i++) {
        int m=have.size();
        for(int j=0; j<m; j++) {
            if(have[j][0]+curr<=n) {
                have.push_back(have[j]);
                have.back().back()++;
                have.back().front()+=curr;
            }
        }
        have.push_back({curr, (ll)1});
        curr*=i;
    }
    ll ans=count(n);
    for(auto &i : have) {
        ans=min(ans, i[1]+count(n-i[0]));
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

