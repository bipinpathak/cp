#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll l=0, r=1, m, t=60;
	string res;
	while(t--) {
		cout<<"? "<<l<<" "<<r<<endl;
		cin>>res;
		if(res=="y") {
			l=r;
			r*=2;
		} else {
			break;
		}
	}
	while(l<r && t--) {
		m=l+(r-l)/2;
		cout<<"? "<<r<<" "<<m<<endl;
		cin>>res;
		if(res=="y") {
			l=m;
		} else {
			r=m;
		}
	}
	cout<<"! "<<l+1<<endl;
	return;
}

int main() {
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	string t;
	cin>>t;
	while(t=="start") {
		solve();
		cin>>t;
	}
    return 0;
}


