#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, q, k;
    cin>>n>>q>>k;
    vector<int> a(n+2, k+1);
    for(int i=1; i<=n; i++) {
        cin>>a[i];
    }
    a[0]=0;
    vector<int> options(n+1);
    for(int i=1; i<=n; i++) {
        options[i]=options[i-1]+a[i+1]-a[i-1]-2;
    }
    while(q--) {
        int l, r, ans=0;
        cin>>l>>r;
        if(r-l+1==1) {
            ans=k-1;
        } else if(r-l+1==2) {
            ans=k-a[l]+a[r]-3;
        } else {
            ans=k+a[l+1]-a[r-1]-3;
            ans+=options[r-1]-options[l];
        }
        cout<<ans<<endl;
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
    while(t--) {
        solve();
    }
    return 0;
}

