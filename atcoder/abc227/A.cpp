#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, k, a;
    cin>>n>>k>>a;
    int ans=(a-2+k+n)%n;
    ans++;
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

