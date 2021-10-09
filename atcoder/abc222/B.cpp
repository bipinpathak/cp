#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, p;
    cin>>n>>p;
    int ans=0;
    while(n--) {
        int a;
        cin>>a;
        ans+=a<p;
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

