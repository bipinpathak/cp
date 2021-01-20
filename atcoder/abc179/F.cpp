#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, q, lastRow, lastCol;
	cin>>n>>q;
	vector<int> top(n+1, n-1), left(n+1, n-1);
	ll ans=(ll)(n-2)*(n-2);
	lastCol=lastRow=n-1;
	while(q--) {
		int t, x;
		cin>>t>>x;
		if(t==1) {
			ans-=max(0, ((x>lastCol)?top[x]:lastRow)-1);
			if(x<=lastCol) {
				for(int col=x+1; col<=lastCol; col++) {
					top[col]=lastRow;
				}
				lastCol=x-1;
			}
		} else {
			ans-=max(0, ((x>lastRow)?left[x]:lastCol)-1);
			if(x<=lastRow) {
				for(int row=x+1; row<=lastRow; row++) {
					left[row]=lastCol;
				}
				lastRow=x-1;
			}
		}
	}
	cout<<ans<<endl;
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

