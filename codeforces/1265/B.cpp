#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n,i,ans=0;
		cin>>n;
		int a[n+1]={0},b,m[n+1];
		for(i=1;i<n+1;i++) {
			cin>>b;
			a[b]=i;
		}
		m[0]=n+1;
		for(i=1;i<n+1;i++) {
			m[i]=min(m[i-1],a[i]);
			a[i]+=a[i-1];
			if(i+2*a[i]==i*(i+2*m[i])) {
				cout<<"1";
			}
			else {
				cout<<"0";
			}
		}
		cout<<endl;
	}
}