#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    double h;
    cin>>h;
    h*=(h+12800000);
    h=sqrt(h);
    cout<<fixed<<setprecision(7);
    cout<<h<<endl;
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

