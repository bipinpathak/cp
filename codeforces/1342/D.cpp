#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n, k, x;
	cin>>n>>k;
	vector<int> limit(k+1), a(n);
	for(auto &i : a) {
		cin>>i;
	}
	for(int i=1; i<=k; i++) {
		cin>>limit[i];
	}
	sort(a.rbegin(), a.rend());
	vector<vector<int>> ans;
	int last=a.front(), i=0;
	for(auto array : a) {
		if(array!=last) {
			if(limit[last]!=limit[array]) {
				i=0;
			}
			last=array;
		}
		if(i==(int)ans.size()) {
			ans.push_back({});
		}
		ans[i].push_back(array);
		if(ans[i].size()==limit[array]) {
			i++;
		}
	}
	cout<<ans.size()<<endl;
	for(auto i : ans) {
		cout<<i.size()<<" ";
		for(auto j : i) {
			cout<<j<<" ";
		}
		cout<<endl;
	}
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

