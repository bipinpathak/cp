#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int x;
    cin>>x;
    if(x<40) {
        cout<<40-x<<endl;
    } else if(x<70) {
        cout<<70-x<<endl;
    } else if(x<90) {
        cout<<90-x<<endl;
    } else {
        cout<<"expert"<<endl;
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
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

