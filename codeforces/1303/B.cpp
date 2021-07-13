#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, g, b;
    cin>>n>>g>>b;
    ll ans=n;
    n-=n/2;
    ll full=((n+g-1)/g)-1, left=n-full*g;
    ans=max(ans, full*(g+b)+left);
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

