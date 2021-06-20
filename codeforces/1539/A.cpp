#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, x, t;
    cin>>n>>x>>t;
    ll one=t/x, ans=0;
    ll temp=min(one, n);
    ans+=(temp*(temp-1))/2;
    n-=temp;
    ans+=n*one;
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

