#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll a, b;
    cin>>a>>b;
    int d=35;
    vector<int> n(d), m(d), x(d);
    for(int i=0; i<d; i++) {
        n[i]=a&1;
        a>>=1;
        m[i]=b&1;
        b>>=1;
    }
    bool done=false;
    for(int i=d-1; i>=0; i--) {
        if(m[i]==n[i]) {
            continue;
        }
        if(m[i]==0) {
            done=true;
            break;
        }
        x[i]++;
    }
    if(!done) {
        for(int i=0; i<d; i++) {
            if(m[i]==0 && n[i]==0) {
                x[i]++;
                done=true;
                break;
            }
            x[i]=0;
        }
    }
    ll ans=0;
    for(int i=d-1; i>=0; i--) {
        ans<<=1;
        ans+=x[i];
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

