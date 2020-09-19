#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n, i, j, count1=0, count2=0;
	cin>>n;
	vector<int> a(n), ans1(n), ans2(n);
	for(auto &i : a) cin>>i;
	sort(a.begin(), a.end());
	j=n-1;
	for(i=0; i<n; i+=2) ans1[i]=a[j--];
	for(i=1; i<n; i+=2) ans1[i]=a[j--];
	for(i=1; i<n-1; i++) {
		if(ans1[i]<ans1[i+1] && ans1[i]<ans1[i-1]) {
			count1++;
		}
	}
	j=n-1;
	for(i=1; i<n; i+=2) ans2[i]=a[j--];
	for(i=0; i<n; i+=2) ans2[i]=a[j--];
	for(i=1; i<n-1; i++) {
		if(ans2[i]<ans2[i+1] && ans2[i]<ans2[i-1]) {
			count2++;
		}
	}
	if(count2>count1) {
		count1=count2;
		ans1=ans2;
	}
	cout<<count1<<endl;
	for(auto i : ans1) cout<<i<<" ";
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
