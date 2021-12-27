#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int x, y;
    cin>>x>>y;
    int ans=x+(y%x);
    if(y>x) {
        int k=1;
        if(y>2*x) {
            k+=(y-2*x)/x;
        }
        ans=k*x;
        ans+=(y-ans)/2;
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

