#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, m, x;
    cin>>n>>m>>x;
    x--;
    ll row=x%n, col=x/n, ans=row*m+col+1;
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
    cin >> t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

