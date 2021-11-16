#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll ask(ll low, ll high) {
    cout<<"? "<<low<<" "<<high<<endl;
    ll res;
    cin>>res;
    return res;
}

void solve() {
    int low=1, high;
    cin>>high;
    while(low<high) {
        int mid=low+(high-low)/2;
        ll res=ask(mid, high);
        if(res) {
            low=mid+1;
        } else {
            high=mid; 
        }
    }
    ll k=high;
    ll total=ask(1, high);
    ll j=k-total+ask(1, high-1);
    ll i=j-1-ask(1, j-1)+ask(1, j-2);
    cout<<"! "<<i<<" "<<j<<" "<<k<<endl;
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

