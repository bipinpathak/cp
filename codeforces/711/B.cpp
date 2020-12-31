#include <bits/stdc++.h>
using namespace std;
typedef	long long ll;

void solve() {
	int n;
	cin>>n;
	ll a[n][n];
	for(auto &i : a) {
		for(auto &j : i) {
			cin>>j;
		}
	}
	if(n==1) {
		cout<<1<<endl;
		return;
	}
	int x, y;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(!a[i][j]) {
				x=i, y=j;
			}
		}
	}
	ll sum=0;
	for(int i=0; i<n; i++) {
		if(i!=x) {
			for(auto j : a[i]) {
				sum+=j;
			}
			break;
		}
	}
	ll copy=sum;
	for(int j=0; j<n; j++) {
		if(a[x][y]>=copy) {
			cout<<-1<<endl;
			return;
		}
		copy-=a[x][j];
	}
	a[x][y]=copy;
	for(auto &i : a) {
		copy=0;
		for(auto &j : i) {
			if(j<=0) {
				cout<<-1<<endl;
				return;
			}
			copy+=j;
		}
		if(copy!=sum) {
				cout<<-1<<endl;
				return;
		}
	}
	for(int j=0; j<n; j++) {
		copy=0;
		for(int i=0; i<n; i++) {
			copy+=a[i][j];
		}
		if(copy!=sum) {
			cout<<-1<<endl;
			return;
		}
	}
	copy=0;
	for(int i=0; i<n; i++) {
		copy+=a[i][i];
	}
	if(copy!=sum) {
				cout<<-1<<endl;
				return;
	}
	copy=0;
	for(int i=0; i<n; i++) {
		copy+=a[i][n-1-i];	
	}
	if(copy!=sum) {
				cout<<-1<<endl;
				return;
	}
	cout<<a[x][y]<<endl;
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


