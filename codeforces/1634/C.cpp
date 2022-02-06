#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin>>n>>k;
    if(k>1 && (n&1)) {
        cout<<"NO"<<endl;
        return;
    } 
    cout<<"YES"<<endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<k; j++) {
            cout<<(i+1)+j*n<<" ";
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

