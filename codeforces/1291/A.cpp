#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n;
	string s;
	cin>>n>>s;
	int ans=0;
	for(auto i: s) {
		int num=i-'0';
		if(i%2) {
			ans=ans*10+num;
		}
		if(ans>10) {
			break;
		}
	}
	if(ans<=10) {
		ans=-1;
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
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

