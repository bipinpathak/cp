#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll total=0, prefix=0;
void update(ll &a, ll &f) {
    if(f) {
        total+=f*prefix;
        total+=(a*f*(f+1))/2;
        prefix+=f*a;
    }
    return;
}

void solve() {
    int n, m;
    cin>>n>>m;
    ll ans=-4;
    total=0, prefix=0;
    for(int i=0; i<n; i++) {
        ll a, f;
        cin>>a>>f;
        if(i==0) {
            ans=max(ans, a);
        }
        if(a<0 && prefix+a>0) {
            ll temp=prefix/-a;
            temp=min(temp, f);
            update(a, temp);
            ans=max(ans, total);
            f-=temp;
        }
        update(a, f);
        ans=max(ans, total);
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

