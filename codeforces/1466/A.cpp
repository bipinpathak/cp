#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin>>n;
	vector<int> a(n);
	for(auto &i : a) {
		cin>>i;
	}
	set<int> area;
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			if(a[i]!=a[j]) {
				area.insert(a[j]-a[i]);
			}
		}
	}
	cout<<area.size()<<endl;
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

