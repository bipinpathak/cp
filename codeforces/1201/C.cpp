#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin>>n>>k;
    vector<ll> a(n);
    for(auto &i : a) {
        cin>>i;
    }   
    sort(a.begin(), a.end());
    ll ans=0, sum=k, count=0;
    for(int i=n/2; i<n; i++) {
        sum+=a[i];
        count++;
        ll offer=sum/count;
        if(i+1<n && offer>a[i+1]) {
            offer=a[i+1];
        }
        if(offer<a[i]) {
            break;
        }
        ans=max(ans, offer);
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

