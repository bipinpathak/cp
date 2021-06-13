#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<ll> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    vector<ll> prefix(n), suffix(n);
    for(int i=0; i<n; i++) {
        prefix[i]=a[i]-(i?prefix[i-1]:0);
    }
    for(int i=n-1; i>=0; i--) {
        suffix[i]=a[i]-((i+1<n)?suffix[i+1]:0);
    }
    vector<int> donePrefix(n), doneSuffix(n);
    for(int i=0; i<n; i++) {
        donePrefix[i]=1;
        if(prefix[i]<0) {
            break;
        }
    }
    for(int i=n-1; i>=0; i--) {
        doneSuffix[i]=1;
        if(suffix[i]<0) {
            break;
        }
    }
    string ans="NO";
    if(suffix[0]==0 && doneSuffix[0]) {
        ans="YES";
    }
    for(int i=0; i+1<n && ans=="NO"; i++) {
        ll left=a[i]-prefix[i], right=a[i+1]-suffix[i+1];
        if(a[i+1]-left==a[i]-right && donePrefix[i] && doneSuffix[i+1] && a[i+1]-left>=0) {
            ans="YES";
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
    auto start=clock();
    int t = 1;
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

