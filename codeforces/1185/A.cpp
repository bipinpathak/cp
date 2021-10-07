#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    vector<int> a(3);
    for(auto &i : a) {
        cin>>i;
    }
    int d;
    cin>>d;
    sort(a.begin(), a.end());
    ll ans=0;
    if(a[0]>a[1]-d) {
        ans+=a[0]-a[1]+d;
    }
    if(a[2]<a[1]+d) {
        ans+=a[1]+d-a[2];
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

