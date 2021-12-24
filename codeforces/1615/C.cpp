#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    string a, b;
    cin>>n>>a>>b;
    int diff=0;
    for(int i=0; i<n; i++) {
        diff+=a[i]!=b[i];
    }
    int ans=n+1;
    if((n-diff)&1) {
        int one=0, zero=0;
        for(int i=0; i<n; i++) {
            if(a[i]==b[i]) {
                if(a[i]=='1') {
                    one++;
                } else {
                    zero++;
                }
            }
        }   
        if(one==zero || one==zero+1) {
            ans=n-diff;
        }
    }
    if((diff&1)==0) {
        int one=0, zero=0;
        for(int i=0; i<n; i++) {
            if(a[i]!=b[i]) {
                if(a[i]=='1') {
                    one++;
                } else {
                    zero++;
                }
            }
        }   
        if(one==zero || one==zero+1) {
            ans=min(ans, diff);
        }
    }
    if(ans==n+1) {
        ans=-1;
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

