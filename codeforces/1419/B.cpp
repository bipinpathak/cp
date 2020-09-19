#include <bits/stdc++.h>
using namespace std;
void solve() {
	long long x, ans=0, p=1, s, cost;
	cin>>x;
	while(x) {
		p*=2;
		s=p-1;
		cost=s*(s+1)/2;
		x-=cost;
		if(x>=0) ans++;
		if(x<=0) break;
	}
	cout<<ans<<endl;
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

