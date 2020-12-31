#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin>>n;
	vector<ll> weight(n);
	ll ans=0;
	for(auto &i : weight) {
		cin>>i;
		ans+=i;
	}
	vector<int> edges(n, -1);
	for(int i=1; i<n; i++) {
		int x, y;
		cin>>x>>y, x--, y--;
		edges[x]++, edges[y]++;
	}
	priority_queue<pair<ll, int>, vector<pair<ll, int>>> a; 
	for(int i=0; i<n; i++) {
		if(edges[i]) {
			a.push({weight[i], edges[i]});
		}
	}
	cout<<ans<<" ";
	for(int i=2; i<n; i++) {
		auto best=a.top();
		a.pop();
		ans+=best.first;
		best.second--;
		if(best.second) {
			a.push(best);
		}
		cout<<ans<<" ";
	}
	cout<<endl;
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

