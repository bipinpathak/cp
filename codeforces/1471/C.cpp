#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n, m;
	cin>>n>>m;
	vector<ll> friends(n+1), gifts(m+1);
	for(int i=1; i<=n; i++) {
		cin>>friends[i];
	}
	for(int i=1; i<=m; i++) {
		cin>>gifts[i];
	}
	sort(friends.begin(), friends.end());
	int giftsUsed=0;
	ll ans=0;
	for(int i=1; i<=n; i++) {
		ans+=gifts[friends[i]];
	}
	for(int i=n; i && giftsUsed<m; i--) {
		if(gifts[friends[i]]>gifts[giftsUsed+1]) {
			giftsUsed++;
			ans+=gifts[giftsUsed]-gifts[friends[i]];
		} else {
			break;
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
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

