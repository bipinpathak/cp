#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin>>n>>k;
    vector<ll> a(n);
    ll low=0, high=0;
    for(auto &i : a) {
        cin>>i;
        high+=i;
    }
    high/=k;
    while(low<high) {
        ll mid=(low+high+1)/2;
        ll have=0;
        for(auto i : a) {
            have+=min(i, mid);
        }
        if(have>=mid*k) {
            low=mid;
        } else {
            high=mid-1;
        }
    }
    cout<<low<<endl;
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
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

