#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<ll> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    sort(a.begin(), a.end());
    for(int i=0; i+1<n; i++) {
        a[i]=a[i+1]-a[i];
    }
    a.back()=2e18;
    sort(a.begin(), a.end());
    vector<ll> prefix(n);
    for(int i=0; i<n; i++) {
        prefix[i]=a[i]+(i?prefix[i-1]:0);
    }
    int q;
    cin>>q;
    while(q--) {
        ll l, r, range, low, ans;
        cin>>l>>r;
        range=r-l+1;
        low=(upper_bound(a.begin(), a.end(), range)-a.begin());
        ans=(n-low)*range;
        if(low) {
            ans+=prefix[low-1];
        }   
        cout<<ans<<" ";
    }
    cout<<endl;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

