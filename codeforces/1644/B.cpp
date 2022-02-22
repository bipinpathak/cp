#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    if(n==3) {
        cout<<"3 2 1"<<endl;
        cout<<"1 3 2"<<endl;
        cout<<"3 1 2"<<endl;
        return;
    }
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        a[i]=n-i;
    }
    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            cout<<a[(i+k)%n]<<" ";
        }
        cout<<endl;
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

