#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int x, y, ans, add;
	cin>>x>>y;
	ans=x+y;
	add=max(x, y)-min(x, y)-1;
	ans+=max(0, add);
	cout<<ans<<endl;
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

