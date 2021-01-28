#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool has(int x, int d) {
	while(x) {
		if(x%10==d) {
			return true;
		}
		x/=10;
	}
	return false;
}

bool go(int x, int d) {
	for(int i=0; i<=x; i+=d) {
		if(has(x-i, d)) {
			return true;
		}
	}
	return false;
}

void solve() {
	int q, d;
	cin>>q>>d;
	while(q--) {
		int x;
		cin>>x;
		bool found=false;
		if(has(x, d) || x%d==0 || x/d>=10) {
			found=true;
		}
		if(!found) {
			found=go(x, d);
		}
		if(!found) {
			cout<<"NO"<<endl;
		} else {
			cout<<"YES"<<endl;
		}
	}
    return;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
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

