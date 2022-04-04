#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int b, p, f, h, c;
    cin>>b>>p>>f>>h>>c;
    b/=2;
    int ans=0, x=0, y=0;
    x=min(b, p);
    y=min(b-x, f);
    ans=h*x+c*y;
    y=min(b, f);
    x=min(b-y, p);
    ans=max(ans, h*x+c*y);
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

