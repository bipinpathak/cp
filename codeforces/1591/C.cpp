#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin>>n>>k;
    vector<int> a;
    while(n--) {
        int x;
        cin>>x;
        if(x) {
            a.push_back(x);
        }
    }
    n=(int)a.size();
    sort(a.begin(), a.end());
    ll ans=0;
    for(int i=0; i<n && a[i]<0; i++) {
        if(i%k==0) {
            ans+=abs(a[i]);
            if(i) {
                ans+=abs(a[i]);
            }
        }
    }
    for(int i=n-1; i>=0 && a[i]>0; i--) {
        if((n-1-i)%k==0) {
            ans+=2*abs(a[i]);
        }
    }
    ll offer=0;
    reverse(a.begin(), a.end());
    for(int i=0; i<n && a[i]>0; i++) {
        if(i%k==0) {
            offer+=abs(a[i]);
            if(i) {
                offer+=abs(a[i]);
            }
        }
    }
    for(int i=n-1; i>=0 && a[i]<0; i--) {
        if((n-1-i)%k==0) {
            offer+=2*abs(a[i]);
        }
    }
    ans=min(ans, offer);
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

