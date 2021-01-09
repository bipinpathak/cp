#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n, k;
	cin>>n>>k;
	string s;
	cin>>s;
	vector<int> pattern(k, -1);
	for(int i=0; i<n; i++) {
		int curr=s[i]-'0';
		if(pattern[i%k]==-1) {
			pattern[i%k]=curr;
		} else if(pattern[i%k]!=curr) {
			if(pattern[i%k]<curr) {
				bool changed=0;
				for(int j=k-1; j>=0 && !changed; j--) {
					if(pattern[j]==9) {
						pattern[j]=0;
					} else {
						pattern[j]++;
						changed=true;
					}
				}
				for(int j=0; j<k && !changed; j++) {
					pattern[j]=9;
				}
			}
			break;
		}
	}
	cout<<n<<endl;
	for(int i=0; i<n; i++) {
		cout<<pattern[i%k];
	}
	cout<<endl;
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

