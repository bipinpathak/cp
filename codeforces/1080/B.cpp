#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int sum(int x) {
    int ans=x/2;
    if(x%2) {
        ans-=x;
    }
    return ans;
}

void solve() {
    int l, r;
    cin>>l>>r;
    cout<<sum(r)-sum(l-1)<<endl;
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

