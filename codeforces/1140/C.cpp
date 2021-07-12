#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin>>n>>k;
    vector<vector<ll>> a(n, vector<ll> (2));
    for(auto &i : a) {
        cin>>i[1]>>i[0];
    }
    sort(a.begin(), a.end());
    map<ll, ll> active;
    ll ans=0, sum=0;
    for(int i=n-1; i>=0; i--) {
        active[a[i][1]]++;
        sum+=a[i][1];
        if(n-i>k) {
            sum-=active.begin()->first;
            active.begin()->second--;
            if(active.begin()->second==0) {
                active.erase(active.begin());
            }
        }
        ans=max(ans, sum*a[i][0]);
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

