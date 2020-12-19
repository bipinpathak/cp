#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin>>n;
	int ans=0;
	for(int x=-n; x<=n; x++) {
		for(int y=-n; y<=n; y++) {
			int i=abs(x), j=abs(y), poss=n/2;
			if((i<=poss && (poss-i)%2==0 && j<=n-poss && (n-poss-j)%2==0)) {
				ans++;
			} else {
				swap(i, j);
				if((i<=poss && (poss-i)%2==0 && j<=n-poss && (n-poss-j)%2==0)) {
					ans++;
				}
			}
		}
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
    while(t--) {
        solve();
    }
    return 0;
}

