#include "bits/stdc++.h"
using namespace std;
using ll = long long;

bool check(int n) {
    for(int i=2; i*i<=n; i++) {
        if(n%i==0) {
            return false;
        }
    }
    return true;
}

void solve() {
    int a, b, c, d;
    cin>>a>>b>>c>>d;    
    string ans="Aoki";
    for(int i=a; i<=b; i++) {
        bool found=false;
        for(int j=c; j<=d && !found; j++) {
            found=check(i+j);
        }
        if(!found) {
            ans="Takahashi";
            break;
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
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

