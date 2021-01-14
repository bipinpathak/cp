#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	string s, t, S, T;
	cin>>s>>t;
	int n=s.length(), m=t.length(), ansLength=(n*m)/(__gcd(n, m));
	while((int)S.length()<ansLength) {
		S+=s;
	}
	while((int)T.length()<ansLength) {
		T+=t;
	}
	if(T!=S) {
		T="-1";
	}
	cout<<T<<endl;
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

