#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> all;
    while(n) {
        all.push_back(n%10);
        n/=10;
    }
    sort(all.rbegin(), all.rend());
    ll a=0, b=0;
    for(auto i : all) {
        if(a>b) {
            swap(a, b);
        }
        a=a*10+i;
    }
    cout<<a*b<<endl;
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

