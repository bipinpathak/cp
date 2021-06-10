#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll calc(ll a) {
    ll ans=0;
    while(a) {
        ans+=a;
        a/=10;
    }
    return ans;
}

void solve() {
    ll l, r;
    cin>>l>>r;
    cout<<calc(r)-calc(l)<<endl;
    return;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    auto start=clock();
    int t = 1;
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

