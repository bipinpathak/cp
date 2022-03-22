#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int x, y;
    cin>>x>>y;
    int ans=2;
    ans-=x==0;
    ans-=y==0;
    if(ans==2) {
        int d=x*x+y*y, r=0;
        while(r*r<=d) {
            r++;
        }
        r--;
        if(r*r==d) {
            ans=1;
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

