#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin>>n>>m;
    vector<int> seen(n);
    while(m--) {
        int a, b, c;
        cin>>a>>b>>c;
        seen[--b]=1;
    }
    int root=-1;
    for(int i=0; i<n; i++) {
        if(!seen[i]) {
            root=i;
            break;
        }
    }
    for(int i=0; i<n; i++) {
        if(i==root) {
            continue;
        }
        cout<<i+1<<" "<<root+1<<endl;
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

