#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, l;
    cin>>n>>l;
    vector<int> a(n), count(l);
    for(auto &i : a) {
        cin>>i;
        for(int j=0; j<l; j++) {
            if(i&(1<<j)) {
                count[j]++;
            }
        }
    }
    int ans=0;
    for(int j=0; j<l; j++) {
        if(2*count[j]>n) {
            ans+=1<<j;
        }
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

