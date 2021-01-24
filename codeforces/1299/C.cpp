#include <bits/stdc++.h>
using namespace std;
using ll = double;

void solve() {
	int n;
	cin>>n;
	vector<ll> a(n+1), prefix(n+1);
	vector<int> f(n+1);
	stack<int> small;
	for(int i=1; i<=n; i++) {
		int x;
		cin>>x;
		a[i]=x;
		prefix[i]=a[i]+prefix[i-1];
		while(small.size() && (prefix[i]-prefix[small.top()])<a[small.top()]*(i-small.top())) {
			small.pop();
		}
		int left=0;
		if(small.size()) {
			left=small.top();
		}
		f[i]=i-left;
		a[i]=(prefix[i]-prefix[left])/(ll)f[i];
		small.push(i);
	}
	int count=0;
	ll curr=0;
	for(int i=n; i; i--) {
		if(count==0) {
			count=f[i];
			curr=a[i];
		}
		a[i]=curr;
		count--;
	}
	cout<<fixed<<setprecision(9);
	for(int i=1; i<=n; i++) {
		cout<<a[i]<<"\n";
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
    while(t--) {
        solve();
    }
    return 0;
}


