#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool solve() {
	int n, d;
	cin>>n>>d;
	vector<int> a(n);
	for(auto &i : a) {
		cin>>i;
	}
	sort(a.begin(), a.end());
	if(a[0]>d) {
		return 0;
	}
	if(a[n-1]>d && a[0]+a[1]>d) {
		return 0;
	}
    return 1;
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

