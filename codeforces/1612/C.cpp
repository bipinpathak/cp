#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    ll k, x;
    cin>>k>>x;  
    x--;
    ll ans=0;
    if(x>=k*k) {
        ans=2*k-1;
    } else {
        if(x<(k*(k+1))/2) {
            ll low=1, high=k;
            while(low<high) {
                ll mid=low+(high-low)/2;
                if((mid*(mid+1))/2<=x) {
                    low=mid+1;
                } else {
                    high=mid;
                }
            }
            ans=low;
        } else {
            x-=(k*(k+1))/2;
            ans=k;
            ll low=1, high=k-1;
            while(low<high) {
                ll mid=low+(high-low)/2;
                if((mid*(2*k-1-mid))/2<=x) {
                    low=mid+1;
                } else {
                    high=mid;
                }
            }
            ans+=low;
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

