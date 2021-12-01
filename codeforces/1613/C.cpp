#include "bits/stdc++.h"
using namespace std;
using ll = long long;

bool possible(ll k, vector<ll> &a, ll h) {
    ll curr=0;
    for(auto &i : a) {
        if(i<=curr) {
            h+=curr-i+1;
        }
        h-=k;
        curr=i+k-1;
        if(h<=0) {
            return true;
        }
    }
    return false;
}

void solve() {
    int n;
    ll h;
    cin>>n>>h;
    vector<ll> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    ll low=1, high=h;
    while(low<high) {
        ll mid=low+(high-low)/2;
        if(possible(mid, a, h)) {
            high=mid;
        } else {
            low=mid+1;
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

