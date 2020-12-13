#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll d, k, n=0;
	cin>>d>>k;
	while(2*n*n*k*k<=d*d) {
		n++;
	}
	n--;
	if(k*k*(2*n*n+2*n+1)<=d*d) {
		cout<<"Ashish"<<endl;
	} else {
		cout<<"Utkarsh"<<endl;
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
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

