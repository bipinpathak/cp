#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin>>n;
	vector<int> a(n);
	map<int, vector<int>> indexes;
	for(int i=0; i<n; i++) {
		cin>>a[i];
		indexes[a[i]].push_back(i);
	}
	int x, count=n;
	for(auto i : indexes) {
		vector<int> curr=i.second;
		int offer=curr.front()?1:0;
		for(int j=1; j<(int) curr.size(); j++) {
			if(curr[j]-curr[j-1]-1) {
				offer++;
			}
		}
		offer+=(n-curr.back()-1)?1:0;
		if(offer<count) {
			count=offer;
			x=i.first;
		}
	}
	cout<<count<<endl;
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

