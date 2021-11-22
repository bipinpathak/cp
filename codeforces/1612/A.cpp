#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int x, y;
    cin>>x>>y;
    int ax=-1, ay=-1;
    if(x%2 == y%2) {
        ax=0, ay=0;
        ax=x/2;
        if(x&1) {
            ay++;
        }
        ay+=y/2;
    }
    cout<<ax<<" "<<ay<<endl;
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

