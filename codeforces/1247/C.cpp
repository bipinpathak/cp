#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int count(int a) {
    int ans=0;
    while(a) {
        ans+=a&1;
        a>>=1;
    }
    return ans;
}

void solve() {
    int n, p;
    cin>>n>>p;
    if(p==0) {
        cout<<count(n)<<endl;
        return;
    } 
    int ans=0;
    while(ans<=n) {
        if(count(n)<=ans) {
            break;
        }
        n-=p;
        ans++;
    }   
    if(n>0 && count(n)<=ans && ans<=n) {
        cout<<ans<<endl;
        return;
    }
    cout<<-1<<endl;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

