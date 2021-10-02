#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    string a, b;
    cin>>a>>b;
    int n=(int)a.length();
    for(int i=0; i+1<n; i++) {
        if(a[i]!=b[i]) {
            swap(a[i], a[i+1]);
            break;
        }
    }
    string ans=(a==b)?"Yes":"No";
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
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

