#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll calc(ll x, ll y, ll a, ll b, ll t) {
    return min((x-t*(a-b))/b, (y+t*(a-b))/a);
}

void solve() {
    ll x, y, a, b, ans=0;
    cin>>x>>y>>a>>b;

    if(a==b) {
        ans=min(x, y)/a;
    } else {
       ll t=(a*x-b*y)/((a+b)*(a-b)); 
       t=max(t, (ll)0);
       t=min(t, min(x/a, y/b));
       ans=max(ans, calc(x, y, a, b, t));
       t++;
       if(a*t<=x && b*t<=y) {
            ans=max(ans, calc(x, y, a, b, t));
       }
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

