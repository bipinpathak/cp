#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll n, l, r, start=0;
	cin>>n>>l>>r;
	while(start*(2*n-1-start)<l && start<n) {
		start++;
	}
	ll index=(start-1)*(2*n-start)+1, i=start, j=start+1;
	while(index<=r && i<n) {
		if(index>=l) {
			if(index%2) {
				cout<<i<<" ";
			}	else {
				cout<<j<<" ";
			}
		}
		if(index%2==0) {
			j++;
		}
		index++;
		if(j>n) {
			i++;
			j=i+1;
		}
	}
	if(index==r) {
		cout<<1;
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
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

