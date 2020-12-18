#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n, k, count=0;
	cin>>n>>k;
	vector<int> a(n);
	for(auto &i : a) {
		cin>>i;
		if(i==k) {
			count++;
		}
		if(i<k) {
			i=0;
		} else {
			i=1;
		}
	}
	if(count) {
		if(n==1) {
			cout<<"YES"<<endl;
			return;
		}
		for(int i=0; i<n; i++) {
			for(int j=i+1; j<=i+2 && j<n; j++) {
				if(a[i] && a[j]) {
					cout<<"YES"<<endl;
					return;
				}
			}
		}
	}
	cout<<"NO"<<endl;
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

