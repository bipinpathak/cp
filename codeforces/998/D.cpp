#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll n, ans=0;
	cin>>n;
	set<vector<ll>> dirty;
	for(ll a=0; a<9; a++) {
		for(ll b=0; b<49; b++) {
			for(ll ax=0; ax<9; ax++) {
				for(ll bx=0; bx<49; bx++) {
					ll diff=4*(a-ax)+9*(b-bx);
					if(diff>0 && diff%49==0) {
						dirty.insert({a, b});
					}
				}
			}
		}
	}
	for(ll a=0; a<9; a++) {
		for(ll b=0; b<49; b++) {
			ll c=n-a-b;
			if(c<0 || dirty.find({a, b})!=dirty.end()) {
				continue;
			}
			ans+=c+1;
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
    while(t--) {
        solve();
    }
    return 0;
}

