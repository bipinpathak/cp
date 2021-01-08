#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll x1, y1, x2, y2;
	cin>>x1>>y1>>x2>>y2;
	cout<<1+(x2-x1)*(y2-y1)<<endl;
    return;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

