#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool solve() {
	int n;
	cin>>n;
	vector<int> a(n), b(n);
	for(auto &i : a) {
		cin>>i;
	}
	for(auto &i : b) {
		cin>>i;
	}
	int up=0, down=0;
	for(int i=0; i<n; i++) {
		if((b[i]>a[i] && !up) || (b[i]<a[i] && !down)) {
			return false;
		}
		if(a[i]<0) {
			down++;
		}
		if(a[i]>0) {
			up++;
		}
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

