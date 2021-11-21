#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    int lowestHigh=1e9, highestLow=1;
    while(n--) {
        int low, high;
        cin>>low>>high;
        lowestHigh=min(lowestHigh, high);
        highestLow=max(highestLow, low);
        int ans=0;
        if(lowestHigh<highestLow) {
            ans=(highestLow-lowestHigh+1)/2;
        }
        cout<<ans<<endl;
    }
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
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

