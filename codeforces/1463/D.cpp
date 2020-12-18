#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin>>n;
	vector<bool> a(2*n);
	for(int i=0; i<n; i++) {
		int x; cin>>x;
		a[--x]=1;
	}
	int open=0, mandatoryMaxPairs=0, mandatoryMinPairs=0;
	for(int i=0; i<2*n; i++) {
		if(a[i]) {
			open++;
		} else {
			open--;
		}
		mandatoryMaxPairs=max(mandatoryMaxPairs, -open);
	}
	open=0;
	reverse(a.begin(), a.end());
	for(int i=0; i<2*n; i++) {
		if(a[i]) {
			open++;
		} else {
			open--;
		}
		mandatoryMinPairs=max(mandatoryMinPairs, -open);
	}
	int ans=(n-mandatoryMaxPairs)-(mandatoryMinPairs)+1;
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

