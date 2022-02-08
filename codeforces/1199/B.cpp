#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    double h, l;
    cin>>h>>l;
    double ans=l*l-h*h;
    ans/=2*h;
    cout<<fixed<<setprecision(6);
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

