#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin>>n;
	vector<int> ans(n+1);
	ll time=0;
	for(int i=1; i<=n; i++) {
		ans[i]=i-1;
		if(i>1) {
			time+=(ll)pow(max(i-1, n-i), 2);
		}
	}
	ans[n/2+1]=n;
	ans[n]=n/2;
	ans[1]=n-1;
	if(n==2) {
		ans[1]=2;
		ans[2]=1;
	}
	cout<<time<<endl;
	for(int i=1; i<=n; i++) {
		cout<<ans[i]<<" ";
	}
	cout<<endl<<n-1<<endl;
	for(int i=n/2; i>1; i--) {
		cout<<i<<" "<<n<<endl;
	}
	for(int i=n-1; i>n/2; i--) {
		cout<<i<<" "<<1<<endl;
	}
	cout<<1<<" "<<n<<endl;
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
	cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

