#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin>>n;
	vector<int> f(n+1);
	while(n--) {
		int x;
		cin>>x;
		f[x]++;
	}
	int ans=0;
	for(auto i : f) {
		ans=max(ans, i);
	}
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
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

