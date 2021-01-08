#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n, m, d, left;
	cin>>n>>m>>d;
	vector<int> c(m), gaps;
	left=n;
	for(auto &i : c) {
		cin>>i;
		left-=i;
	}
	while(left && (int)gaps.size()<=m+1) {
		gaps.push_back(min(left, d-1));
		left-=gaps.back();
	}
	if((int)gaps.size()>m+1) {
		cout<<"NO"<<endl;
		return;
	}
	cout<<"YES"<<endl;
	vector<int> ans;
	int key=0;
	while(key<m || gaps.size()) {
		while(gaps.size() && gaps.back()) {
			ans.push_back(0);
			gaps.back()--;
		}
		if(gaps.size()) {
			gaps.pop_back();
		}
		while(key<m && c[key]) {
			ans.push_back(key+1);
			c[key]--;
		}
		key++;
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



