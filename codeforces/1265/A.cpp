#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n,i,ans=0;
		string s;
		cin>>s;
		n=s.length();
		for(i=1;i<n;i++) {
			if(s[i]!='?' && s[i]==s[i-1]) {
				ans=-1;
			}
		}
		if(ans) {
			cout<<ans<<endl;
		}
		else {
			for(i=0;i<n;i++) {
				if(s[i]=='?') {
					if(i==0) {
						if(s[i+1]=='a') {
							s[i]='b';
						}
						else if(s[i+1]=='b') {
							s[i]='c';
						}
						else {
							s[i]='a';
						}
					}
					else if(i==n-1) {
						if(s[i-1]=='a') {
							s[i]='b';
						}
						else if(s[i-1]=='b') {
							s[i]='c';
						}
						else {
							s[i]='a';
						}
					}
					else {
						if(s[i-1]=='a') {
							if(s[i+1]=='b') {
								s[i]='c';
							}
							else {
								s[i]='b';
							}
						}
						if(s[i-1]=='b') {
							if(s[i+1]=='c') {
								s[i]='a';
							}
							else {
								s[i]='c';
							}
						}
						if(s[i-1]=='c') {
							if(s[i+1]=='a') {
								s[i]='b';
							}
							else {
								s[i]='a';
							}
						}
					}
				}
			}
			cout<<s<<endl;
		}
	}
}