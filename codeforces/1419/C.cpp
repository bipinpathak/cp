#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n, x, sum=0, count=0, ans=0;
	cin>>n>>x;
	vector<int> ratings(n);
	for(auto &i : ratings) {
		cin>>i;
		if(i==x) count++;
		sum+=i;;
	}
	if(count<n) {
		ans=1;
		if(sum!=n*x && count==0) {
			ans++;
		}
	}
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

