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
    if(a[n-2]>a[n-1]) {
        cout<< -1<<endl;
        return;
    }
    auto b=a;
    sort(b.begin(), b.end());
    if(a==b) {
        cout<<0<<endl;
        return;
    }
    if(a[n-1]<0) {
        cout<< -1<<endl;
        return;
    }
    cout<<n-2<<endl;
    for(int i=n-3; i>=0; i--) {
        cout<<i+1<<" "<<i+2<<" "<<n<<'\n';
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

