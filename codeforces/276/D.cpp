#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    ll l, r;
    cin>>l>>r;
    ll ans=0, curr=((ll)1<<62);
    while(curr) {
        if((l&curr)!=(r&curr)) {
            break;
        }
        curr>>=1;
    }
    while(curr) {
        ans+=curr;
        curr>>=1;
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
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

