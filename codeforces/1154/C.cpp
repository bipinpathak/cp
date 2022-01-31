#include "bits/stdc++.h"
using namespace std;
using ll = long long;

bool possible(ll f, ll r, ll c, string days, ll target) {
    ll whole, partial;
    whole=target/7;
    partial=target%7;
    f-=whole*3;
    r-=whole*2;
    c-=whole*2;
    for(ll i=0; i<partial; i++) {
        if(days[i]=='r') {
            r--;
        } else if(days[i]=='c') {
            c--;
        } else {
            f--;
        }
    }
    return (f>=0 && r>=0 && c>=0);
}

void solve() {
    ll f, r, c;
    cin>>f>>r>>c;
    string days="frcfcrf";
    days+=days;
    ll ans=0;
    for(ll i=0; i<7; i++) {
        string curr="";
        for(ll j=0; j<7; j++) {
            curr+=days[i+j];
        }
        ll low=0, high=1e12;
        while(low<high) {
            ll mid=(low+high+1)/2;
            if(possible(f, r, c, curr, mid)) {
                low=mid;
            } else {
                high=mid-1;
            }
        }
        ans=max(ans, low);
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
    ll t = 1;
    for(ll i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

