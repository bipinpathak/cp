#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<ll> c(n);
    for(auto &i : c) {
        cin>>i;
    }
    ll ans=1e18;
    ll evensum=0, oddsum=0, evenlow=1e9, oddlow=1e9, evencount=0, oddcount=0;
    for(int i=0; i<n; i++) {
        if(i%2) {
            oddsum+=c[i];
            oddlow=min(oddlow, c[i]);
            oddcount++;
        } else {
            evensum+=c[i];
            evenlow=min(evenlow, c[i]);
            evencount++;
        }
        if(!i) {
            continue;
        }
        ll curr=oddsum+(n-oddcount)*oddlow+evensum+(n-evencount)*evenlow;
        ans=min(ans, curr);
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
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

