#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin>>n;
    ll limit=1;
    while(limit*limit<=n) {
        limit++;
    }
    vector<int> possible(limit);
    ll ans=n;
    for(ll i=2; i<limit; i++) {
        if(!possible[i]) {
            ll curr=i*i;
            while(curr<=n) {
                if(curr<limit) {
                    possible[curr]=1;
                }
                ans--;
                curr*=i;
            }
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
    while(t--) {
        solve();
    }
    return 0;
}

