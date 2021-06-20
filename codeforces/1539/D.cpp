#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<vector<ll>> a(n, vector<ll> (2));
    for(auto &i : a) {
        cin>>i[1]>>i[0];
    }
    sort(a.begin(), a.end());
    int l=0, r=n-1;
    ll ans=0, count=0;
    while(l<=r) {
        if(count<a[l][0]) {
            ll need=a[l][0]-count;
            ll use=min(need, a[r][1]);
            ans+=2*use;
            count+=use;
            a[r][1]-=use;
            if(a[r][1]==0) {
                r--;
            }
        } else {
            ll use=a[l][1];
            ans+=use;
            count+=use;
            a[l][1]-=use;
            l++;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

