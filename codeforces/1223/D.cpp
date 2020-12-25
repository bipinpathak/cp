#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin>>n;
	map<int, int> first, last;
	for(int i=0; i<n; i++) {
		int x;
		cin>>x;
		if(first.find(x)==first.end()) {
			first[x]=i;
		}
		first[x]=min(first[x], i);
		last[x]=max(last[x], i);
	}
	int ans=0, count=0, low=-1;
	for(auto i : first) {
		int x=i.first;
		if(i.second<low) {
			count=0;
		}
		count++;
		low=last[x];
		ans=max(ans, count);
	}
	ans=first.size()-ans;
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

