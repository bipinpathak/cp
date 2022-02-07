#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> r(n), b(n);
    for(auto &i : r) {
        cin>>i;
    }
    for(auto &i : b) {
        cin>>i;
    }
    int rOnly=0, bOnly=0;
    for(int i=0; i<n; i++) {
        if(r[i]^b[i]) {
            rOnly+=r[i];
            bOnly+=b[i];
        }
    }
    int ans=-1;
    if(rOnly) {
        int extra=bOnly-rOnly+1;
        extra=max(extra, 0);
        ans=1+(extra+rOnly-1)/rOnly;
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

