#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll a, b, c, r;
    cin>>a>>b>>c>>r;
    if(a>b) {
        swap(a, b);
    }
    ll ans=b-a;
    ll start, end;
    start=max(a, c-r);
    end=min(b, c+r);
    if(start<=end) {
        ans-=end-start;
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

