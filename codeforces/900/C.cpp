#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void add(int index, ll val, vector<ll> &a) {
    int n=(int)a.size();
    while(index<n) {
        a[index]+=val;
        index+=index&-index;
    }
    return;
}

ll get(int index, vector<ll> &a) {
    ll ans=0;
    while(index) {
        ans+=a[index];
        index-=index&-index;
    }
    return ans;
}

void solve() {
    int n;
    cin>>n;
    vector<ll> a(n), big(n), have(n+1), seen(n+1);
    for(auto &i : a) {
        cin>>i;
    }   
    for(int i=0; i<n; i++) {
        big[i]=i-get(a[i], have);
        add(a[i], 1, have);
    }   
    ll ans=n, count=-5;
    for(int i=n-1; i>=0; i--) {
        ll offer=0;
        if(big[i]==0) {
            offer--;
        }
        offer+=get(a[i], seen);
        if(offer>count) {
            count=offer;
            ans=a[i];
        }
        if(offer==count) {
            ans=min(ans, a[i]);
        }
        if(big[i]==1) {
            add(a[i], 1, seen);
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
    int t = 1;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

