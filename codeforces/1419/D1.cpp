#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n, i, j, count=0;
	cin>>n;
	vector<int> a(n), ans(n);
	for(auto &i : a) cin>>i;
	sort(a.begin(), a.end());
	j=n-1;
	for(i=0; i<n; i+=2) ans[i]=a[j--];
	for(i=1; i<n; i+=2) ans[i]=a[j--];
	for(i=1; i<n-1; i++) {
		if(ans[i]<ans[i+1] && ans[i]<ans[i-1]) {
			count++;
		}
	}
	cout<<count<<endl;
	for(auto i : ans) cout<<i<<" ";
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

