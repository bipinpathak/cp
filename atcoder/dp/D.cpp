#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, w;
    cin>>n>>w;
    vector<ll> optimal(w+1);
    while(n--) {
        int wi;
        ll vi;
        cin>>wi>>vi;
        for(int i=w-wi; i>=0; i--) {
            optimal[i+wi]=max(optimal[i+wi], optimal[i]+vi);
        }
    }
    ll ans=0;
    for(auto i : optimal) {
        ans=max(ans, i);
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

