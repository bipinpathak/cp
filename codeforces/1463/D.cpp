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
	int open=0, change=0, ans=n+1;
	for(int i=0; i<2*n; i++) {
		if(a[i]) {
			open++;
		} else {
			open--;
		}
		change=max(change, -open);
	}
	//change=min number of pairs required to be of max type
	ans-=change;
	change=open=0;
	reverse(a.begin(), a.end());
	for(int i=0; i<2*n; i++) {
		if(a[i]) {
			open++;	
		} else {
			open--;
		}
		change=max(change, -open);
	}
	//change=min number of pairs required to be of min type
	ans-=change;
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

