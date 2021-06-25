#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<vector<ll>> a(n, vector<ll> (2));
    for(int i=0; i<n; i++) {
        cin>>a[i][0];
        a[i][1]=i+1;
    }
    sort(a.begin(), a.end());
    ll ans=0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n && a[i][0]*a[j][0]<=2*n; j++) {
            if(a[i][0]*a[j][0]==a[i][1]+a[j][1]) {
                ans++;
            }
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

