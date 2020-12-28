#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool solve() {
	string s;
	cin>>s;
	int open=0, close=0, n=s.size();
	queue<int> extra;
	for(int i=0; i<n; i++) {
		if(s[i]=='(') {
			open++;	
		} else if(s[i]==')') {
			close++;
		} else {
			extra.push(i);
		}
		if(close>open && extra.size()) {
			s[extra.front()]='(';
			extra.pop();
			open++;
		}
		if(close>open) {
			return 0; 
		}
	}
	reverse(s.begin(), s.end());
	open=close=0;
	while(extra.size()) {
		extra.pop();
	}
	for(int i=0; i<n; i++) {
		if(s[i]==')') {
			open++;	
		} else if(s[i]=='(') {
			close++;
		} else {
			extra.push(i);
		}
		if(close>open && extra.size()) {
			s[extra.front()]=')';
			extra.pop();
			open++;
		}
		if(close>open) {
			return 0; 
		}
	}
	return (extra.size()%2==0);
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

