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
    int shift=0;
    vector<vector<int>> operations;
    for(int i=n-1; i>=0; i--) {
        a[i]+=shift;
        a[i]%=n;
        if(a[i]!=i) {
            operations.push_back({1, i+1, n+i-a[i]});
            shift+=n+i-a[i];
            shift%=n;
        }
    }
    cout<<operations.size()+1<<endl;
    for(auto &i : operations) {
        for(auto &j : i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<"2 "<<n<<" "<<n<<endl;
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

