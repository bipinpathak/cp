#include <bits/stdc++.h>
using namespace std;
typedef long double ll;

void solve() {
	int q;
	vector<ll> a, b;
	cin>>q; 
	cout << fixed << setprecision(10);
	while(q--) {
		int t;
		cin>>t;
		if(t==1) {
			ll x;
			cin>>x;
			a.push_back(x);
			b.push_back((b.size()?b.back():0)+x);
			continue;
		} 
		if(a.size()==1) {
			cout<<0<<endl;
			continue;
		}
		int left=0, right=a.size()-1, mid;
		while(left<right) {
			mid=(right+left+1)/2;
			ll avg=(b[mid]+a.back())/(mid+2);
			if(avg<=a[mid]) {
				right=mid-1;
			} else {
				left=mid;
			}
		}
		ll avg=(b[left]+a.back())/(left+2);
		cout<<a.back()-avg<<endl;
	}
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

