#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll x, y, a, b;
	cin>>x>>y>>a>>b;
	b=min(b, 2*a);
	cout<<min((x+y)*a, b*min(x, y)+a*abs(x-y))<<endl;
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

