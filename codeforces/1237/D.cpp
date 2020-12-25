#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin>>n;
	vector<ll> a(n), ans(n, -1);
	for(auto &i : a) {
		cin>>i;
	}
	queue<int> active;
	deque<int> high;
	for(int i=0; i<3*n; i++) {
		while(high.size() && active.size() && a[high.front()%n]>2*a[i%n]) {
			ans[active.front()%n]=i-active.front();
			active.pop();
			if(active.size()==0 || high.front()<active.front()) {
				high.pop_front();	
			}
		}
		while(high.size() && a[high.back()%n]<a[i%n]) {
			high.pop_back();
		}
		high.push_back(i);
		if(i<n) {
			active.push(i);
		}
	}
	for(auto i : ans) {
		cout<<i<<" ";
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
    while(t--) {
        solve();
    }
    return 0;
}

