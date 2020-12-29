#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool solve() {
	string s;
	int n;
	cin>>s;
	n=s.size();
	return (n%2==0 && s[0]!=')' && s[n-1]!='(');
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

