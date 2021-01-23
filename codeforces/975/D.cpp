#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	ll a, b;
	cin>>n>>a>>b;
	vector<vector<ll>> x(n, vector<ll> (3));
	ll ans=0;
	map<ll, ll> f;
	map<vector<ll>, ll> duplicate;
	for(auto &i : x) {
		for(auto &j : i) {
			cin>>j;
		}
		ll curr=a*i[1]-i[2];
		reverse(i.begin(), i.end());
		i.pop_back();
		duplicate[i]++;
		f[curr]++;
	}
	for(auto i: f) {
		ans+=(i.second-1)*i.second;
	}
	for(auto i : duplicate) {
		ans-=(i.second-1)*i.second;
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
    while(t--) {
        solve();
    }
    return 0;
}

