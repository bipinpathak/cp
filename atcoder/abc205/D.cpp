#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, q;
    cin>>n>>q;
    vector<ll> a(n);
    for(auto &i :a) {
        cin>>i;
    }
    while(q--) {
        ll k;
        cin>>k;
        ll low=1, high=(ll)1e18+(ll)2*n;
        while(low<high) {
            ll mid=low+(high-low)/2;
            ll rank=mid-(upper_bound(a.begin(), a.end(), mid)-upper_bound(a.begin(), a.end(), 0));
            if(rank>=k) {
                high=mid;
            } else {
                low=mid+1;
            }
        }
        cout<<low<<endl;
    }
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

