#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll w, h, x1, y1, x2, y2, addw, addh;
    cin>>w>>h>>x1>>y1>>x2>>y2>>addw>>addh;
    if(addw+x2-x1>w && addh+y2-y1>h) {
        cout<<-1<<endl;
        return;
    }
    ll ans=1e18;
    if(addw+x2-x1<=w) {
        ans=min(ans, max((ll)0, x2-(w-addw)));
        ans=min(ans, max((ll)0, addw-x1));
    }
    if(addh+y2-y1<=h) {
        ans=min(ans, max((ll)0, y2-(h-addh)));
        ans=min(ans, max((ll)0, addh-y1));
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

