#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool intersection(int a, int b, int c, int d) {
	if(b<c || d<a) {
		return 0;
	}
	return 1;
}

void combine(int &l , int &h, int a, int b, int c, int d) {
	l=max(a, c);
	h=min(b, d);
}

bool solve() {
	int n, k;
	cin>>n>>k;
	vector<int> h(n);
	for(auto &i: h) {
		cin>>i;
	}
	int low=h[0]+1, high=h[0]+k;
	for(int i=1; i<n-1; i++) {
		if(!intersection(low, high, h[i]+1, h[i]+2*k-1)) {
			return 0;
		}
		combine(low, high, low-k+1, high+k-1, h[i]+1, h[i]+2*k-1);
	}
    return intersection(low, high, h[n-1]+1, h[n-1]+k);
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

