#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll calc(int g, vector<ll> &prefix, map<int, int> &index) {
    ll ans=0;
    int curr=0, next, n=(int)prefix.size(), val=0;
    while(curr<n) {
        val+=g;
        next=n;
        auto it=index.upper_bound(val);
        if(it!=index.end()) {
            next=it->second;
        }
        if(curr<next) {
            ans+=(ll)(next-curr)*val;
            ans-=prefix[next-1];
            ans+=curr?prefix[curr-1]:0;
            curr=next;
        }
    }
    return ans;
}

void solve() {
    ll n, k;
    cin>>n>>k;
    vector<int> a(n);
    ll total=0;
    for(auto &i : a) {
        cin>>i;
        total+=i;
    }
    sort(a.begin(), a.end());
    ll ans=1;
    if(k+total>=a.back()*n) {
        ans=(k+total)/n;
    } else {
        vector<ll> prefix(n);
        map<int, int> index;
        for(int i=0; i<n; i++) {
            prefix[i]=a[i]+(i?prefix[i-1]:0);
            if(!index.count(a[i])) {
                index[a[i]]=i;
            }
        }
        for(int i=a.back()-1; i; i--) {
            ll cost=calc(i, prefix, index); 
            if(cost<=k) {
                ans=i;
                break;
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
    int t = 1;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

