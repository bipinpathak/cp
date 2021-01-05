#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll u, v;
	cin>>u>>v;
	if(v<u || (v-u)%2) {
		cout<<-1<<endl;
		return;
	}
	v-=u;
	if(v==0) {
		if(u) {
			cout<<1<<endl<<u<<endl;
		} else {
			cout<<0<<endl;
		}
		return;
	}
	ll a, b;
	a=u;
	b=v/2;
	if((a&b)==0) {
		cout<<2<<endl<<a+b<<" "<<b<<endl;
	} else {
		cout<<3<<endl<<a<<" "<<b<<" "<<b<<endl;
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

