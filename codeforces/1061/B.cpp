#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin>>n>>m;
    vector<ll> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    a.push_back(0);
    sort(a.rbegin(), a.rend());
    ll total=0, high=a[0]+1;
    for(int i=0; i<n; i++) {
        total+=a[i];
        ll use=high-a[i+1]-1;
        if(use<=0) {
            use=1;
        }   
        high-=use;
        total-=use;
    }
    cout<<total<<endl;
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

