#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int go(int a, int b) {
    int ans=0;
    ans=min(a, b);
    a-=ans;
    b-=ans;
    ans+=a/2 + b/2;
    return ans;
}

void solve() {
    int n, k1, k2, w, b;
    cin>>n>>k1>>k2>>w>>b;
    if(w<=go(k1, k2) && b<=go(n-k1, n-k2)) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
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
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

