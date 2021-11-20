#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, x;
    cin>>n>>x;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
        i--;
    }   
    vector<int> know(n);
    x--;
    int ans=0;
    while(!know[x]) {
        know[x]=1;
        x=a[x];
        ans++;
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

