#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    string s;
    cin>>n>>s;
    int m=(int)s.length();
    int x=0, y=0;
    for(auto &i : s) {
        if(i=='D') {
            x++;
        } else {
            y++;
        }
    }
    ll ans=1; 
    int cx=0, cy=0;
    bool right=false, down=false;
    for(int i=0; i<m; i++) {
        ans++;
        if(s[i]=='D') {
            down=true;
            cx++;
            x--;
        } else {
            right=true;
            cy++;
            y--;
        }
        if(right && (i+1==m || s[i+1]=='D')) {
            int add=n-1-cy-y;
            add=max(add, 0);
            ans+=add;
        }
        if(down && (i+1==m || s[i+1]=='R')) {
            int add=n-1-cx-x;
            add=max(add, 0);
            ans+=add;
        }
    }
    if(right && down) {
        cx=n-1-cx;
        cy=n-1-cy;
        cx=max(cx, 0);
        cy=max(cy, 0);
        ans+=(ll)cx*cy;
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

