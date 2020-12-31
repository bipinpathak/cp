#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n, k;
	cin>>n>>k;
	vector<int> a(n);
	set<int> have;
	for(auto &i : a) {
		cin>>i;
		have.insert(i);
	}
	if((int)have.size()>k) {
		cout<<-1<<endl;
		return;
	}
	vector<int> ans;
	have.clear();
	for(auto i : a) {
		if(have.find(i)==have.end()) {
			have.insert(i);
			ans.push_back(i);
		}
	}
	for(int i=1; i<=n && (int)ans.size()<k; i++) {
		if(have.find(i)==have.end()) {
			have.insert(i);
			ans.push_back(i);
		}
	}
	cout<<n*k<<endl;
	while(n--) {
		for(auto i : ans) {
			cout<<i<<" ";
		}
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

