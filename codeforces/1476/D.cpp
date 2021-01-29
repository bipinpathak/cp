#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	string s;
	cin>>n>>s;
	vector<int> largest(n+1, 1);
	int last=0, curr=1;
	for(int i=0; i<n; i++) {
		if(i && s[i]==s[i-1]) {
			if(s[last]=='R') {
				largest[last]=max(curr, largest[last]);
			} 
			last++;
			while(last<i) {
				if(s[last]=='R' || s[last-1]=='L') {
					largest[last]=max(curr, largest[last]);
				}
				last++;
			}
			if(s[last-1]=='L') {
				largest[last]=max(largest[last], curr);
			}
			curr=1;
		}
		curr++;
	}
	if(last<n) {
		if(s[last]=='R') {
			largest[last]=max(curr, largest[last]);
		} 
		last++;
		while(last<n) {
			if(s[last]=='R' || s[last-1]=='L') {
				largest[last]=max(curr, largest[last]);
			}
			last++;
		}
		if(s[last-1]=='L') {
			largest[last]=max(largest[last], curr);
		}
		last++;
	}
	largest[n]=1;
	char a='L', b='R';
	for(int i=n-1; i>=0; i--) {
		if(s[i]==a) {
			swap(a, b);
			largest[n]++;
		} else {
			break;
		}
	}
	for(int i=0; i<=n; i++) {
		cout<<largest[i]<<" ";
	}
	cout<<endl;
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

