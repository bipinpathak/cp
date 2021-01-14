#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n, m;
	string s;
	cin>>n>>m>>s;
	vector<int> a;
	a.push_back(0);
	for(auto i : s) {
		int curr=a.back();
		if(i=='-') {
			curr--;
		} else {
			curr++;
		}
		a.push_back(curr);
	}
	vector<int> leftHigh(n+1), leftLow(n+1), rightHigh(n+1), rightLow(n+1);
	int low=0, high=0;
	for(int i=1; i<=n; i++) {
		high=max(high, a[i]);
		low=min(low, a[i]);
		leftHigh[i]=high;
		leftLow[i]=low;
	}
	low=a[n], high=a[n];
	for(int i=n; i; i--) {
		high=max(high, a[i]);
		low=min(low, a[i]);
		rightHigh[i]=high;
		rightLow[i]=low;
	}
	for(int c=1; c<=m; c++) {
		int l, r;
		cin>>l>>r;
		if(r==n) {
			low=leftLow[l-1];
			high=leftHigh[l-1];
		} else {
			int LeftUP=leftHigh[l-1], LeftDown=leftLow[l-1], RightUp=rightHigh[r+1], RightDown=rightLow[r+1], diff=a[r]-a[l-1];	
			RightUp-=diff;
			RightDown-=diff;
			low=min(RightDown, LeftDown);
			high=max(LeftUP, RightUp);
		}
		cout<<high-low+1<<endl;
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

