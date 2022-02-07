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
    int ans=0;
    for(int i=0; i+1<n; i++) {
        if(min(a[i], a[i+1])==1) {
            ans+=max(a[i], a[i+1])+1;
        } else {
            cout<<"Infinite"<<endl;
            return;
        }
    }
    for(int i=0; i+2<n; i++) {
        if(a[i]==3 && a[i+1]==1 && a[i+2]==2) {
            ans--;
        }
    }   
    cout<<"Finite"<<endl;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

