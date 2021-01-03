#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool solve() {
	ll a, b, c, d, x, y, x1, x2, y1, y2;
	cin>>a>>b>>c>>d>>x>>y>>x1>>y1>>x2>>y2;
	if((x1==x2 && (a || b)) || (y1==y2 && (c || d))) {
		return false;
	}
	ll common=min(a, b);
	a-=common;
	b-=common;
	common=min(c, d);
	c-=common;
	d-=common;
	x=x+b-a;
	y=y+d-c;
	if(x<x1 || x>x2 || y<y1 || y>y2) {
		return false;
	}
    return true;
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
        if(solve()) {
			cout<<"YES"<<endl;
        } else {
			cout<<"NO"<<endl;
		}
    }
    return 0;
}

