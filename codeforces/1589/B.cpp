#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int calc(int n, int m) {
    int ans=n*(m/3);
    m%=3;
    ans+=m*(1+(n-1)/3);
    return ans;
}

void solve() {
    int n, m;
    cin>>n>>m;
    int ans=min(calc(n, m), calc(m, n));
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

