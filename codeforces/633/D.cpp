#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n=1000;
vector<ll> a(1000);
map<ll, int> have;

int fetch(ll a, ll b) {
	int ans=2;
	if(have[a+b]) {
		have[a+b]--;
		ans=1+fetch(b, a+b);
		have[a+b]++;
	}
	return ans;
}

void solve() {
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>a[i];
		have[a[i]]++;
	}
	int ans=2;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(i==j) {
				continue;
			}
			if(a[i]==0 && a[j]==0) {
				ans=max(ans, have[0]);
				continue;
			}
			have[a[i]]--;
			have[a[j]]--;
			ans=max(ans, fetch(a[i], a[j]));
			have[a[i]]++;
			have[a[j]]++;
		}
	}
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
    while(t--) {
        solve();
    }
    return 0;
}


