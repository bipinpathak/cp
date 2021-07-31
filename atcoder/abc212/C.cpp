#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll go(vector<ll> &a, vector<ll> &b) {
    int n=(int)a.size(), m=(int)b.size();
    ll ans=1e9;
    int i=0, j=0;
    while(i<n) {
        while(j<m && a[i]>=b[j]) {
            ans=min(ans, a[i]-b[j]);
            j++;
        }
        i++;
    }
    return ans;
}   

void solve() {
    int n, m;
    cin>>n>>m;
    vector<ll> a(n), b(m);
    for(auto &i : a) {
        cin>>i;
    }
    for(auto &i : b) {
        cin>>i;
    }   
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll ans=1e9;
    ans=min(ans, go(a, b));
    ans=min(ans, go(b, a));
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
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

