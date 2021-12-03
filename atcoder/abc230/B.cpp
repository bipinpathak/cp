#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    string s, t="oxx";
    cin>>s;
    int n=(int)s.size();
    for(int shift=0; shift<3; shift++) {
        bool good=true;
        for(int i=0; i<n && good; i++) {    
            if(s[i]!=t[(i+shift)%3]) {
                good=false;
            }
        }
        if(good) {
            cout<<"Yes"<<endl;
            return;
        }
    }
    cout<<"No"<<endl;
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

