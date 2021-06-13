#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    vector<int> b(n);
    for(int i=0; i<n; i++) {
        b[i]=min(a[i], max(i?a[i-1]:0, (i+1)<n?a[i+1]:0));
    }
    ll ans=0;
    for(int i=0; i<n; i++) {
        ans+=a[i]-b[i];
        ans+=2*b[i];
        ans-=min(b[i], i?b[i-1]:0);
        ans-=min(b[i], (i+1<n)?b[i+1]:0);
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

