#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin>>n>>m;
    if(m==0) {
        cout<<1<<endl;
        return;
    }
    vector<int> active(n, 1);
    int curr=0;
    while(m--) {
        while(!active[curr]) {
            curr=(curr+1)%n;
        }
        curr=(curr+1)%n;
        while(!active[curr]) {
            curr=(curr+1)%n;
        }
        active[curr]=0;
    }
    int ans=0;
    for(int i=0; i<n; i++) {
        if(active[i] && (i==0 || active[i-1]==0)) {
            ans++;
        }
    }
    if(active[0] && active[n-1]) {
        ans--;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

