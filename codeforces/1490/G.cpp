#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll go(ll x, vector<ll> &a) {
    ll low=0, high=a.size()-1, mid;
    while(low<high) {
        mid=low+(high-low)/2;
        if(a[mid]>=x) {
            high=mid;
        } else {
            low=mid+1;
        }
    }
    if(a[low]<x) {
        low=-1;
    }
    return low;

}

void solve() {
    ll n, m;
    cin>>n>>m;
    vector<ll> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    vector<ll> peak(n);
    ll sum=0;
    peak[0]=a[0];
    for(int i=0; i<n; i++) {
        if(i) {
            peak[i]=peak[i-1];
        }   
        sum+=a[i];
        peak[i]=max(peak[i], sum);
    }
    while(m--) {
        ll x, cycles=0;
        cin>>x;
        if(!(x<=peak[n-1] || sum<=0)) {
            cycles=(x-peak[n-1]+sum-1)/sum;
            cycles=max(cycles, (ll)0);
        }
        x-=sum*cycles;
        ll ans=go(x, peak);
        if(ans!=-1) {
            ans+=cycles*n;
        }
        cout<<ans<<" ";
    }
    cout<<endl;
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
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
