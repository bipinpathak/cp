#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    int g=0, curr=1;
    while(curr<(1<<30)) {
        int count=0;
        for(auto i : a) {
            if(i&curr) {
                count++;
            }
        }   
        g=__gcd(g, count);
        curr<<=1;
    }
    for(int i=1; i<=n; i++) {
        if(g%i==0) {
            cout<<i<<" ";
        }
    }
    cout<<endl;
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

