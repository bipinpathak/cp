#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,m,i,q;
	cin>>n>>m;
	string s[n],t[m];
	for(i=0;i<n;i++) {
		cin>>s[i];
	}
	for(i=0;i<m;i++) {
		cin>>t[i];
	}
	cin>>q;
	while(q--) {
		long int y;
		string ans;
		cin>>y;
		ans=s[(y-1)%n]+t[(y-1)%m];
		cout<<ans<<endl;
	}
}