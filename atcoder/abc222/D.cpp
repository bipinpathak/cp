#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, m=0, mod=998244353;
    cin>>n;
    vector<int> a(n), b(n);
    for(auto &i : a) {
        cin>>i;
        m=max(m, i);
    }
    for(auto &i : b) {
        cin>>i;
        m=max(m, i);
    }
    vector<int> counts(m+1);
    counts[0]=1;
    for(int i=0; i<n; i++) {
        int active=0;
        for(int j=0; j<=m; j++) {
            active=(active+counts[j])%mod;
            counts[j]=0;
            if(a[i]<=j && j<=b[i]) {
                counts[j]=active;
            }
        }
    }
    int ans=0;
    for(auto &i : counts) {
        ans=(ans+i)%mod;
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

