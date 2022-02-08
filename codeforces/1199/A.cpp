#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, x, y;
    cin>>n>>x>>y;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }   
    for(int i=0; i<n; i++) {
        int left, right;
        left=right=1e9+1;
        for(int j=1; i+j<min(n, i+y+1); j++) {
            right=min(right, a[i+j]);
        }
        for(int j=1; i-j>max(-1, i-y-1); j++) {
            right=min(right, a[i-j]);
        }
        if(a[i]<min(left, right)) {
            cout<<i+1<<endl;
            break;
        }
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

