#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }   
    ll ans=0;
    int odd=0;
    for(int i=1; i<n-1; i++) {
        ans+=a[i]/2;
        odd+=a[i]&1;
    }
    for(int i=1; i<n-1 && odd==n-2; i++) {
        if(a[i]>=2) {
            if(i+1<n-1) {
                a[i+1]++;
                odd--;
            } else if(i-1>0) {
                a[i-1]++;
                odd--;
            }
            a[i]-=2;
            ans++;
        }
    }
    if(odd==n-2) {
        ans=-1;
    } else {
        ans+=odd;
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

