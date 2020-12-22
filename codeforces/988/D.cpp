#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin>>n;
	set<ll> have;
	while(n--) {
		ll x;
		cin>>x;
		have.insert(x);
	}
	ll left=1, right=-1;
	for(auto x : have) {
		ll d=1;
		while(d<=2e9) {
			int count=0;
			if(have.find(x+d)!=have.end()) {
				count++;
				left=x, right=x+d;
			}
			if(have.find(x-d)!=have.end()) {
				count++;
				left=x-d, right=x;
			}
			if(count) {
				if(count==2) {
					cout<<3<<endl<<x-d<<" "<<x<<" "<<x+d<<endl;
					return;
				}
			}
			d=d<<1;
		}
	}
	if(left<right) {
		cout<<2<<endl<<left<<" "<<right;
	} else {
		cout<<1<<endl<<*have.begin();
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

